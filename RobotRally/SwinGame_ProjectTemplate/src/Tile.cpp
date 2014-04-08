//
//  Tile.cpp
//  RobotRally
//
//  Created by James Bell on 6/04/2014.
//  Copyright (c) 2014 BellDesign. All rights reserved.
//

#include "Tile.h"
#include <strstream>

//constructor
tile::tile(){
    _visitor = NULL;
    
    northTile = NULL;
    southTile = NULL;
    eastTile = NULL;
    westTile = NULL;
}
tile::tile(robot* visitor){
    _visitor = visitor;
    
    northTile = NULL;
    southTile = NULL;
    eastTile = NULL;
    westTile = NULL;
}

//methods
tile* tile::getTile(_direction position){
    
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
            break;
        case South:
            southTile = aTile;
            break;
        case East:
            eastTile = aTile;
            break;
        case West:
            westTile = aTile;
            break;
    }
}
void tile::setVisitor(robot* visitor){
    _visitor = visitor;
}
std::string tile::toString(){
    std::strstream s;
    if (_visitor != NULL) {
        s << "Tile full, robot " << _visitor << "visiting" << std::endl;
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
    return s.str();
}