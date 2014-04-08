//
//  Tile.h
//  RobotRally
//
//  Created by James Bell on 6/04/2014.
//  Copyright (c) 2014 BellDesign. All rights reserved.
//

#ifndef __RobotRally__Tile__
#define __RobotRally__Tile__

#include <iostream>
#include "Robot.h"

class tile {
private:
    robot* _visitor;
    
    tile* northTile;
    tile* southTile;
    tile* eastTile;
    tile* westTile;
    
public:
    //constructor
    tile();
    tile(robot* visitor);
    
    //methods
    tile* getTile(_direction position);
    robot* getVisitor();
    bool removeRobot(robot* aVisitor);
    void setTile ( tile* aTile, _direction position);
    void setVisitor(robot* visitor);
    std::string toString();
    
};

#endif /* defined(__RobotRally__Tile__) */
