//
//  Game.cpp
//  RobotRally
//
//  Created by James Bell on 15/04/2014.
//  Copyright (c) 2014 BellDesign. All rights reserved.
//

#include "Game.h"

Game::Game (TileLoader* loader){
	
}

Game::Game (){
	
	tileSet = getTiles();

	Player();
	
}

robot* Game::Player(){
//	robot();
	return new robot();
}

std::vector<tile*>	Game::getTiles(){

	TileLoader tl =	*new TileLoader(); //when to delete this?
									   //is it deleted because its made in a method
	return tl.getTiles();
}