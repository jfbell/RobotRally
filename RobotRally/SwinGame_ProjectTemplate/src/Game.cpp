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
	player = &r;
	
	tileSet = loader->getTiles();
}

Game::Game (){
	robot r = *new robot();
	player = &r;
	
	TileLoader tl =	*new TileLoader();
	tileSet = tl.getTiles();
}

robot* Game::Player(){
	return player;
}

std::vector<tile*>	Game::getTiles(){
	return tileSet;
}

int Game::GameMain(){
	char input;
	
	while (input != '7' || 'q') {
		
		cout << "What now" << endl; 		//	introduction printed to terminal
		
			//	request input (cin)
		
		switch (input) {
			case '1':
					//Build Game
				break;
			case '2':
					//Move n steps
				break;
			case '3':
					//rotate robot
				break;
			case '4':
					//move and rotate according to a sequence typ input, "1,3,N,2,-1"
				break;
			case '5':
					//toString for robot
				break;
			case '6':
					//show the board
				break;
			case '7':
					//Exit
				break;
			default:
				break;
		}
	}
	return 0;
}