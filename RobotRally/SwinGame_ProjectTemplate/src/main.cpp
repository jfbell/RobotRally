	//
	//  main.cpp
	//  RobotRally
	//
	//  Created by James Bell on 25/03/2014.
	//  Copyright (c) 2014 BellDesign. All rights reserved.
	//

#include <iostream>
#include <stdio.h>
#include "robotTest.h"
#include "tileTest.h"
#include "TileLoader.h"
#include "Game.h"
#include <string>
#include <stdexcept>


using namespace std;

int main(void)
{
    robotTest *rt = new robotTest;
	
    rt->mainTest();
	
    delete rt;
	
	
		//Tile Testing
	testTile *t = new testTile();
	
    t->mainTileTest();
	
    delete t;
	
	
		//Game
	
	TileLoader *loader = new TileLoader();
	
	Game game = *new Game(loader);
	
	return game.GameMain();
	
	return 0;
}