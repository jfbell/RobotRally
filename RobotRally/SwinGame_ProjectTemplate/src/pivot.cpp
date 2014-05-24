//
//  pivot.cpp
//  RobotRally
//
//  Created by James Bell on 24/05/2014.
//  Copyright (c) 2014 BellDesign. All rights reserved.
//

#include "pivot.h"

#include "Robot.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <strstream>



pivot::pivot(){
	std::srand(std::time(NULL));
}

pivot::pivot(int Index){
	std::srand(std::time(NULL));
	this->setTileID(Index);
}

void pivot::Invoke(){
	robot r = *this->getVisitor();
	for (int i = 0; i < (rand()%3); i++) {
		r.rotate(turnLeft);
	}
}
