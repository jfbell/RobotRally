//
//  Card.h
//  RobotRally
//
//  Created by James Bell on 29/04/2014.
//  Copyright (c) 2014 BellDesign. All rights reserved.
//

#ifndef __RobotRally__Card__
#define __RobotRally__Card__

#include <iostream>
#include <strstream>
#include "Robot.h"

class Card {
public:
	virtual void ExecuteCard(robot* executeOn) = 0;
	std::string toString();
};


#endif /* defined(__RobotRally__Card__) */
