//
//  Turn.cpp
//  RobotRally
//
//  Created by James Bell on 30/04/2014.
//  Copyright (c) 2014 BellDesign. All rights reserved.
//

#include "Turn.h"

Turn::Turn(_rotate turn){
	turnTo = turn;
}
void Turn::executeCard(robot* executeOn){
	executeOn->rotate(turnTo);
}
std::string Turn::toString(){
	std::strstream s;
	s << "Card: Turn " << turnTo << std::endl;//todo turn toString Left Right Uturn
	return s.str();
}