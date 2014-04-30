//
//  Turn.h
//  RobotRally
//
//  Created by James Bell on 30/04/2014.
//  Copyright (c) 2014 BellDesign. All rights reserved.
//

#ifndef __RobotRally__Turn__
#define __RobotRally__Turn__

#include <iostream>
#include "Card.h"
#include "Robot.h"
class Turn : public  Card
{
private:
	_rotate	turnTo;
	
public:
	Turn(_rotate turn);
	void executeCard(robot* executeOn);
	std::string toString();
};
#endif /* defined(__RobotRally__Turn__) */
