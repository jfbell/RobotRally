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
}

Game::Game (){
	robot r = *new robot(South);
	
	TileLoader tl =	*new TileLoader();
	tileSet = tl.getTiles();
	
	tile* startTile = tileSet[0];
	
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
				g = *new Game();
				p = *g.Player(); // this seems recursive like im adding another game for no reason instead of using "this"
				
				break;}
			case '2':
			{
				cout << "How many steps? ";
				cin.clear();
				int n =	0;
				cin >> n;
				p.move(n);
				
					//_player->move(n);
				cout << endl;
				cout << p.toString();
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
						result = p.rotate(turnRight);
						break;
					case 'L':
						result = p.rotate(turnLeft);
						break;
					case 'U':
						result = p.rotate(Uturn);
						break;
					default:
						result = false;
						break;
				}
				if (result) {
					cout <<	"Turn was sucessful, now facing " << p.
					toString(p.getHeading()) << endl;
				}else{
					cout <<	"Turn failed, still facing" << p.toString(p.getHeading()) << endl;
					cout << "check your input was one character ether R, L, or U." << endl;
				}
				
				cout << endl;
				p.toString();
				cout << endl;
				break;
			}
			case '4':{
					//move and rotate according to a sequence typ input, "1,3,N,2,-1"
				cout << "Coming soon to software near you!" << endl;
				/*	//TODO
				cout << "Input instruction string directions N, S, E or W or moves -9 to 0 to 9 moves " << endl;
				
				string s;
				std::getline (std::cin,s);
				
				do {
					
					int comma = s.find(',');
					
					char command[20];
					size_t length = s.copy( command , 0 , comma);
					
					command[length] = '\0';
				
					switch (command[]) {
						case 'L':
							;
							break;
						case 'l':
							<#statements#>
							break;
						case 'R':
							<#statements#>
							break;
						case 'r':
							<#statements#>
							break;
						case 'U':
							<#statements#>
							break;
						case 'u':
							<#statements#>
							break;
						case '':
							<#statements#>
							break;
						case 'L':
							<#statements#>
							break;
							
						default:
							break;
							
							cout << s << endl; // TODO remove after testing complete
							
							s.erase ( s.begin() , s.begin() + comma );
					}
				} while (!s.empty());
				
				*/
				
				break;}
			case '5':{
				cout << p.toString();
				break;}
			case '6':{
					//TODO show the board
				for (int i = 0; i < tileSet.size(); i++) {
					cout << tileSet[i]->toString();
				}
				/*
				 robot MappingRobot = *new robot(East);
				 
				 MappingRobot.setCurrentTile(tileSet[0]);
				 
				 tile currentTile;
				 _direction heading;
				 
				 do {
				 currentTile = *MappingRobot.getCurrentTile();
				 heading = MappingRobot.getHeading();
				 
				 MappingRobot.move(1);
				 
				 if (heading == East){
				 cout << "[x]";
				 }
				 
				 if (currentTile.getTile(heading) == NULL ) {
				 if (heading == East) {
				 MappingRobot.rotate(Uturn);
				 //							MappingRobot.move(1);
				 //							MappingRobot.rotate(turnRight);
				 }else if (heading == West){
				 MappingRobot.rotate(turnLeft);
				 MappingRobot.move(1);
				 MappingRobot.rotate(turnLeft);
				 }
				 }
				 
				 } while (currentTile.getTile(East) != NULL && currentTile.getTile(South) != NULL);
				 */
				
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