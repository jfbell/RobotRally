	//
	//  Tile.cpp
	//  RobotRally
	//
	//  Created by James Bell on 6/04/2014.
	//  Copyright (c) 2014 BellDesign. All rights reserved.
	//

#include "Tile.h"
#include <strstream>

#include "pivot.h"
#include "Pit.h"
#include "Teleport.h"

	//constructor
tile::tile(){
    _visitor = NULL;
    
    northTile = NULL;
    southTile = NULL;
    eastTile = NULL;
    westTile = NULL;
	
	connections = { NULL, NULL, NULL, NULL };
	
	use_connections = false;
}

tile::tile(int ID){
	
	tileID = ID;
	
    _visitor = NULL;
    
    northTile = NULL;
    southTile = NULL;
    eastTile = NULL;
    westTile = NULL;
	
	connections = { NULL, NULL, NULL, NULL };
	
	use_connections = false;
}

tile::tile(robot* visitor){
    _visitor = visitor;
    
    northTile = NULL;
    southTile = NULL;
    eastTile = NULL;
    westTile = NULL;
	
	connections = { NULL, NULL, NULL, NULL };
	
	use_connections = false;
}

	//methods
tile* tile::getTile(_direction position){
	
    if (use_connections == false) {
		switch (position) {
			case North:
				return northTile;
				break;
			case South:
				return southTile;
				break;
			case East:
				return eastTile;
				break;
			case West:
				return westTile;
				break;
			default:
				return NULL;
				break;
		}
	}else{
		switch (position) {
			case North:
				return connections[North];
				break;
			case South:
				return connections[South];
				break;
			case East:
				return connections[East];
				break;
			case West:
				return connections[West];
				break;
			default:
				return NULL;
				break;
		}
	}
}
robot* tile::getVisitor(){
    return _visitor;
}
bool tile::removeRobot(robot* aVisitor){
    _visitor = NULL;
    if (_visitor == NULL) {
        return true;
    }else{
        return false;
    }
}
void tile::setTile( tile* aTile, _direction position){
    switch (position) {
        case North:
            northTile = aTile;
			connections[North] = aTile;
            break;
        case South:
            southTile = aTile;
			connections[South] = aTile;
            break;
        case East:
            eastTile = aTile;
			connections[East] = aTile;
			break;
        case West:
            westTile = aTile;
			connections[West] = aTile;
			break;
    }
}
void tile::setVisitor(robot* guest){
    _visitor = guest;
}
std::string tile::toString(){
    std::strstream s;
	
	if (use_connections == true) {
		northTile = connections[North];
		southTile = connections[South];
		eastTile = connections[East];
		westTile = connections[West];
	}
	
	s << "Tile: " << this << "\t TileID: ["<< tileID << "]"<< std::endl;
	
	s << "Tile type: ";
	s << "Normal" << std::endl;

		
//	} else	if ( dynamic_cast<Pit*>(this)) {
//		s << "Pit" << std::endl;
//	} else	if ( dynamic_cast<pivot*>(this)) {
//		s << "Pivot" << std::endl;
//	} else	if ( dynamic_cast<Teleport*>(this)) {
//		s << "Teleport" << std::endl;
//	} else {
//		s << "No type found? " << std::endl;
//	(void)std::cin;
//	}
	
    if (_visitor != NULL) {
        s << "Tile full, robot " << _visitor << " visiting" << std::endl;
    }else{
        s << "Tile is empty" << std::endl;
    }
    
    if (northTile != NULL) {
        s << "North tile :" << northTile << std::endl;
    }else{
        s << "North tile not connected" << std::endl;
    }
    
    if (southTile != NULL) {
        s << "South tile :" << southTile << std::endl;
    }else{
        s << "South tile not connected" << std::endl;
    }
    
    if (eastTile != NULL) {
        s << "East tile :" << eastTile << std::endl;
    }else{
        s << "East tile not connected" << std::endl;
    }
    
    if (westTile != NULL) {
        s << "West tile :" << westTile << std::endl;
    }else{
        s << "West tile not connected" << std::endl;
    }
	
	s << std::endl;
	
    return s.str();
}

void tile::use_connections_vector(){
	use_connections = true;
}
void tile::do_not_use_connections_vector(){
	use_connections = false;
}

void tile::setTileID(int ID){
	tileID = ID;
}

void tile::Invoke(){
	
}
