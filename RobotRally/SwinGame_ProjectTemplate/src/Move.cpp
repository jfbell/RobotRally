//
//  Move.cpp
//  RobotRally
//
//  Created by James Bell on 29/04/2014.
//  Copyright (c) 2014 BellDesign. All rights reserved.
//

#include "Move.h"

Move::Move(int steps){
	numberOfSteps = steps;
}
void Move::executeCard(robot* executeOn){
	executeOn->move(numberOfSteps);
}
std::string	Move::toString(){
	std::strstream s;

	s << "Card: Move " << numberOfSteps << " steps."<< std::endl;
	
	return s.str();
}