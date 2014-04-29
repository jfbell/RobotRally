	//
	//  Game.cpp
	//  RobotRally
	//
	//  Created by James Bell on 15/04/2014.
	//  Copyright (c) 2014 BellDesign. All rights reserved.
	//

#include "Game.h"

using namespace std;


Game::Game (TileLoader* loader){
	robot r = *new robot();
	_player = &r;
	
	tileSet = loader->getTiles();
}

Game::Game (){
	robot r = *new robot();
	_player = &r;
	
	TileLoader tl =	*new TileLoader();
	tileSet = tl.getTiles();
}

robot* Game::Player(){
	return _player;
}

std::vector<tile*>	Game::getTiles(){
	return tileSet;
}

int Game::GameMain(){
	char input;
	
//	std::cout << "would you like to play? (Y/N)" << endl;
//	input = cin.get();
//	cin.clear();
//	if (input == 'Y' || input == 'y') {
//		Game game = *new Game();
//		
//	}else if(input == 'N' || input == 'n'){
//		return 0;
//	}
	
	do {
			//	introduction printed to terminal
		cout << "----------------------------------" << endl;
		cout << "Menu:" << endl;
		cout << "1: Build Game" << endl;
		cout << "2: Move Robot" << endl;
		cout << "3: Turn Robot" << endl;
		cout << "4: Execute a move sequence" << endl;
		cout << "5: Print your Robots status" << endl;
		cout << "6: Print the Board" << endl;
		cout << "7: Exit" << endl;
		cout << "----------------------------------" << endl;
		
			//
		input = NULL;		//to clear the input
		cin.clear();		//clear the cin buffer
//		input = cin.get();	//set input to cin
		cin >> input;
		
		
		switch (input) {
			case '1':{
				Game game = *new Game();
				break;}
			case '2':
			{
				cout << "How many steps? ";
						cin.clear();
				int n =	0;
				cin >> n;
				_player->move(n);
				cout << endl;
				_player->toString();
				break;
			}
			case '3':
			{
				cout << "Which why do you want to turn? (R, L, U) ";
				char turn_c;
				cin >> turn_c;
				bool result = false;
				switch (turn_c) {
					case 'R':
						result = _player->rotate(turnRight);
						break;
					case 'L':
						result = _player->rotate(turnLeft);
						break;
					case 'U':
						result = _player->rotate(Uturn);
						break;
					default:
						result = false;
						break;
				}
				if (result) {
					cout <<	"Turn was sucessful, now facing " << _player->toString(_player->getHeading()) << endl;
				}else{
					cout <<	"Turn failed, still facing" << _player->toString(_player->getHeading()) << endl;
					cout << "check your input was one character ether R, L, or U." << endl;
				}
				
				cout << endl;
				_player->toString();
				cout << endl;
				break;
			}
			case '4':{
					//move and rotate according to a sequence typ input, "1,3,N,2,-1"
				cout << "Coming soon to software near you!" << endl;
				
				break;}
			case '5':{
				cout << _player->toString();
				break;}
			case '6':{
					//show the board
				for (int i = 0; i < tileSet.size(); i++) {
					tileSet[i]->toString();
					cout << "_____________________________" << endl;
				}
				break;}
			case '7':{
				cout << "Bye Bye"<< endl << endl ;
				return 0;
				break;}
			default:{
				cout << "invalid input" << endl;
				break;}
		}
	} while (input != '7' || 'q');
	return 0;
}