//
//  tileTest.cpp
//  RobotRally
//
//  Created by James Bell on 8/04/2014.
//  Copyright (c) 2014 BellDesign. All rights reserved.
//

#include "tileTest.h"
#include "Tile.h"
#include "Robot.h"
#include "TileLoader.h"

#define NO_TILES 5

testTile::testTile(){
}

/**
 Creats the testRobot
 calls test robots toString function printing its starting
 condition to the consuol
 takes and returns nothing
 */
void testTile::buildRobot(){
    testRobot = new robot();
    std::cout << testRobot->toString();
}
/**
 Creates a board of tiles and returns them through a vector,
 number of tiles currently #define NO_TILES
 @return board, a vector of tiles
 */
std::vector<tile*> testTile::buildTiles(){
    
    std::vector<tile*> board = {};
    
    for (int i = 0 ; i < NO_TILES; i++) {
    
        board.push_back(new tile);// = new tile;
    }
    
    startTile = board.at(0);
    
    connect2tiles(board.at(0), board.at(1), South);
    connect2tiles(board.at(1), board.at(2), South);
    connect2tiles(board.at(2), board.at(3), East);
    connect2tiles(board.at(3), board.at(4), East);
    
    return board;
}

bool testTile::connect2tiles(tile *A, tile *B, _direction dir){
    switch (dir) {
        case North:
            A->setTile(B, North);
            B->setTile(A, South);
            return true;
            break;
        case South:
            A->setTile(B, South);
            B->setTile(A, North);
            return true;
            break;
        case East:
            A->setTile(B, East);
            B->setTile(A, West);
            return true;
            break;
        case West:
            A->setTile(B, West);
            B->setTile(A, East);
            return true;
            break;
        default:
            return false;
            break;
    }
    
}

//tile* testTile::connectTile(){
//    return
//}

void testTile::placeRobotOnTile(){
    
    if (testRobot != NULL && startTile != NULL) {
        startTile->setVisitor(testRobot);
        testRobot->setCurrentTile(startTile);
    }
}

bool testTile::moveRobot(int move){
    return testRobot->move(move);
}
void testTile::showResult(vector<tile*> showThis){
    for(int i = 0; i < showThis.size(); i++){
        showThis[i]->toString();
    }
}
void testTile::testSetUp(){
    
    showResult(buildTiles());
    buildRobot();
    placeRobotOnTile();
    
}
void testTile::testValidMove(){
    _direction heading = testRobot->getHeading();
    while (heading != South) {
        testRobot->rotate(turnRight);
        heading = testRobot->getHeading();
    }
    testRobot->move(1);
    
    tile *find = startTile->getTile(South);
    
    if(find->getVisitor() == testRobot){
        std::cout << "Robot found 1 move south" << std::endl;
    }else{
        std::cout << "Valid move failed" << std::endl;
    }
}
void testTile::testInvalidStepCount(){
    
} //???
/**
 Tests an invalid move in a direction no tile is
 can be called from anytile*/

void testTile::testInvalidDirection(){
    tile *currentTile = testRobot->getCurrentTile();
    int antiLoopCounter = 0;
    while (currentTile->getTile(testRobot->getHeading()) != NULL) {
        antiLoopCounter++;
        if (antiLoopCounter > 5) {
            std::cout << "testInvalidDirection() failed, tile is connected in all directions" << std::endl;
            break;
        }
        testRobot->rotate(turnLeft);
    }
}

void testTile::testGetToEnd(){
    tile *currentTile = testRobot->getCurrentTile();
    bool result = true;
    while (currentTile->getTile(South)!= NULL && result != false) {
       result = testRobot->move(1);
    }
    do {
        testRobot->rotate(turnLeft);
    } while (testRobot->getHeading() != West);
    while (currentTile->getTile(West)!= NULL) {
        testRobot->move(1);
    }
    std::cout << "On last tile" << std::endl;
    
    
}

void testTile::testTileGetMethods(){
    tile    *Atile = startTile->getTile(South);
    std::cout << "Start Tile: " << startTile << std::endl;
    std::cout << "North Tile: " << Atile->getTile(North) << std::endl;
    std::cout << "Start tile and North tile should be the same" << endl;
    std::cout << "South Tile: " << Atile->getTile(South) << std::endl;
    std::cout << "East Tile: " << Atile->getTile(East) << std::endl;
    std::cout << "West Tile: " << Atile->getTile(West) << std::endl;
}

void testTile::testTileSetMethods(){
    std::cout << "Start Tile: " << startTile << std::endl;
    tile *_StartTile = startTile;
    tile *SouthTile = _StartTile->getTile(South);
    
    std::cout << "South Tile: " << _StartTile->getTile(South) << std::endl;
    std::cout << "Setting Start tile to one tile to south ... " << std::endl;
    _StartTile = _StartTile->getTile(South);
    
    if (SouthTile == _StartTile) {
        std::cout << "Start Tile is now: " << _StartTile;
        std::cout << " the change was a sucess" << std::endl;
    }else{
        std::cout << "Set tile failed, oops! but its ok the startTile was preserved" << endl;
    }
}

void testTile::testWhenRobotNull(){
    std::cout << "test when robot Null " << startTile->getVisitor() << std::endl;
    // why is this ever useful
    
}

void testTile::mainTileTest(){
    
    testSetUp();
    
    testValidMove();
    
    testInvalidStepCount();
    
    testInvalidDirection();
    
    testGetToEnd();
    
    testTileGetMethods();
    testTileSetMethods();
    testWhenRobotNull();
	
	
		//Test Tile Loader
	
	TileLoader *tl = new TileLoader();
	
	std::vector<tile*> board = {};
	
	board = tl->getTiles();
	
	for (int i = 0; i < board.size(); i++) {
		std::cout << board[i]->toString();
		
		if ((i+1)%10 == 0 && i != 0) { //step through 10 at a time
			std::cout << "------------------------------------------ "
				<< i+1 <<std::endl
			<< "press the ""any"" key to continue" << std::endl << "press 's' to skip to the end" << std::endl;
			

			char s = std::cin.get(); // press the "any" key to continue
									 //TODO implement a skip of this function
			if (s == 's') {
				break;
			}
		}
	}
    
	delete tl;
	
	for (int i = 0; i < board.size(); i++) {
		delete board[i];
	}
    
    
    
}