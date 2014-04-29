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
	
		
public:
	robot* _player;
	std::vector<tile*>	tileSet;

	Game (TileLoader* loader);
	Game();
	robot* Player();
	std::vector<tile*>	getTiles();
	
	int	GameMain();
};


#endif /* defined(__RobotRally__Game__) */
