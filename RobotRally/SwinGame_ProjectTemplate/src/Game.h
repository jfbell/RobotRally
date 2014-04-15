//
//  Game.h
//  RobotRally
//
//  Created by James Bell on 15/04/2014.
//  Copyright (c) 2014 BellDesign. All rights reserved.
//

#ifndef __RobotRally__Game__
#define __RobotRally__Game__

#include <iostream>
#include "Robot.h"
#include "Tile.h"
#include "TileLoader.h"

class Game {
	robot player;
	std::vector<tile*>	tileSet;
	
public:
	Game (TileLoader* loader);
	robot* Player();
	std::vector<tile*>	getTiles();
};


#endif /* defined(__RobotRally__Game__) */