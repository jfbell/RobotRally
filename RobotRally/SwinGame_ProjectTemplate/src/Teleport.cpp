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
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


Teleport::Teleport() {
	std::srand(std::time(NULL));
}
void Teleport::Invoke(){
	robot r = *this->getVisitor();
	r.setHeading(RandomDirection());
	r.move((rand()%5));
	r.setHeading(RandomDirection());
	r.move((rand()%5));
	
	std::cout << "Where am I?" << std::endl;
}


_direction Teleport::RandomDirection(){
    
	int rand_dir = rand() % 4;
	
    
    switch (rand_dir) {
        case 0:
            return North;
            break;
        case 1:
            return South;
            break;
        case 2:
            return East;
            break;
        case 3:
            return West;
            break;
        default:
            return South;
            break;
			
	}
}
