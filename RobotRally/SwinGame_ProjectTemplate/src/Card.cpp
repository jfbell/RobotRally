//
//  Card.cpp
//  RobotRally
//
//  Created by James Bell on 29/04/2014.
//  Copyright (c) 2014 BellDesign. All rights reserved.
//

#include <strstream>
#include "Card.h"

std::string Card::toString(){
	std::strstream s;
	
	s << "Not defined in Child Class" << std::endl;
	
	return s.str();
}



