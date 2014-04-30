//
//  Move.h
//  RobotRally
//
//  Created by James Bell on 29/04/2014.
//  Copyright (c) 2014 BellDesign. All rights reserved.
//

#ifndef __RobotRally__Move__
#define __RobotRally__Move__

#include <iostream>
#include <strstream>
#include "Robot.h"
#include "Card.h"


class Move : public Card
{
	int numberOfSteps;
	
public:
	
	Move(int steps);
	void executeCard(robot* executeOn);
	std::string	toString();
	
};

#endif /* defined(__RobotRally__Move__) */
