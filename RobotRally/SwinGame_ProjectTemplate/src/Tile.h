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
#include <vector>


class tile {
private:
	int tileID;
	
    robot* _visitor;
    
    tile* northTile;
    tile* southTile;
    tile* eastTile;
    tile* westTile;
	
	std::vector<tile*> connections; // { north, east, south, west }
	
	bool use_connections;
    
public:
		//constructor
    tile();
	tile(int ID);
    tile(robot* visitor);
    
		//methods
    tile* getTile(_direction position);
    robot* getVisitor();
    bool removeRobot(robot* aVisitor);
    void setTile ( tile* aTile, _direction position);
    void setVisitor(robot* guest);
    std::string toString();
	
	void use_connections_vector();
	void do_not_use_connections_vector();
    
};

#endif /* defined(__RobotRally__Tile__) */
