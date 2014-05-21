//
//  Teleport.cpp
//  RobotRally
//
//  Created by James Bell on 20/05/2014.
//  Copyright (c) 2014 BellDesign. All rights reserved.
//

#include "Teleport.h"
#include "TileLoader.h"
#include "Tile.h"
#include "Robot.h"


Teleport::Teleport() {
	
}
void Teleport::Invoke(){
	robot r = *this->getVisitor();
	
}
