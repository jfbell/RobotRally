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
	robot r = *new robot(South);
	_player = &r;
	
	tileSet = loader->getTiles();
	CardLoader cl = *new CardLoader();
	
	_gameDeck = new Deck(&cl);
}

Game::Game (){
	robot r = *new robot(South);
	
	TileLoader tl =	*new TileLoader();
	tileSet = tl.getTiles();
	
	startTile = tileSet[0];
	r.setStartTile(startTile);
	r.setCurrentTile(startTile);
	_player = &r;
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
	
	Game g = *this;
	robot p = *this->Player();
	
	do {
			//	introduction printed to terminal
		cout << "----------------------------------" << endl;
		cout << "Menu:" << endl;
		cout << "1: Build Game" << endl;
		cout << "2: Draw one card" << endl;
		cout << "3: Draw multipul card" << endl;
		cout << "4: Print your Robots status" << endl;
		cout << "5: Print the Board" << endl;
		cout << "6: Exit" << endl;
		cout << "----------------------------------" << endl;
		
			//
		input = NULL;		//to clear the input
		cin.clear();		//clear the cin buffer
							//		input = cin.get();	//set input to cin
		cin >> input;
		
		
		switch (input) {
			case '1':{
				g = *new Game();
				p = *g.Player(); // this seems recursive like im adding another game for no reason instead of using "this"
				
				break;}
			case '2':
			{
				_gameDeck->issueCard()->executeCard(&p);
				cout << endl;
				cout << p.toString();
				break;
			}
			case '3':
			{
				cout << "Draw how many cards? ";
				int draw_number;
				cin >> draw_number;
				
				for (int i = draw_number; 0 < i  ; i--) {
					
					_gameDeck->issueCard()->executeCard(&p);
					cout << endl;
					cout << p.toString();
				}
				
				break;
			}
			case '4':{
				cout << p.toString();
				cout << p.getCurrentTile()->toString();
				break;
			}
				
			case '5':{
				cout << "I'll be back";
				break;}
			case '6':{
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