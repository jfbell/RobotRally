//
//  Pit.cpp
//  RobotRally
//
//  Created by James Bell on 20/05/2014.
//  Copyright (c) 2014 BellDesign. All rights reserved.
//

#include "Pit.h"
#include "Robot.h"

pit::pit(){
	
}

bool pit::Invoke(){
	robot r = *this->getVisitor();
	r.decrementHealth(1);
	r.goToStart();

	return true;
}