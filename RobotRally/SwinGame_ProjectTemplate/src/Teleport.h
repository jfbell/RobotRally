//
//  Teleport.h
//  RobotRally
//
//  Created by James Bell on 20/05/2014.
//  Copyright (c) 2014 BellDesign. All rights reserved.
//

#ifndef __RobotRally__Teleport__
#define __RobotRally__Teleport__

#include <iostream>
#include "Tile.h"

class Teleport : public tile {
	
public:
	Teleport();
	void Invoke();
	_direction RandomDirection();
	
};

#endif /* defined(__RobotRally__Teleport__) */
