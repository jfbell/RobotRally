//
//  tileTest.h
//  RobotRally
//
//  Created by James Bell on 8/04/2014.
//  Copyright (c) 2014 BellDesign. All rights reserved.
//

#ifndef __RobotRally__tileTest__
#define __RobotRally__tileTest__

#include <iostream>
#include <vector>

#include "Tile.h"
#include "Robot.h"
//class tile;
//class Robot;

using namespace std;

class testTile {
private:
    robot* testRobot;
    tile* startTile;
    
    void buildRobot();
    vector<tile*> buildTiles();
    bool connect2tiles(tile *A, tile *B, _direction dir);
    tile* connectTile();
    void placeRobotOnTile();
    bool moveRobot(int move);
    void showResult(vector<tile*> showThis);
    void testSetUp();
    void testValidMove();
    void testInvalidStepCount();
    void testInvalidDirection();
    void testGetToEnd();
    void testTileGetMethods();
    void testTileSetMethods();
    void testWhenRobotNull();
    
public:
    void mainTileTest( vector<string> args );

};



#endif /* defined(__RobotRally__tileTest__) */
