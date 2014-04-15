	//
	//  TileLoader.cpp
	//  RobotRally
	//
	//  Created by James Bell on 14/04/2014.
	//  Copyright (c) 2014 BellDesign. All rights reserved.
	//

#include "TileLoader.h"
#include <vector>
#include "Robot.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define NO_TILES 144

TileLoader::TileLoader(){
	std::srand(std::time(NULL));
}

std::vector<tile*> TileLoader::buildTiles(){
    
    std::vector<tile*> board = {};
    
    for (int i = 0 ; i < NO_TILES; i++) {
        
        board.push_back(new tile);// = new tile;
    }
    return board;
}

bool TileLoader::connect2tiles(tile *A, tile *B, _direction dir){
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

_direction TileLoader::RandomDirection(){
    
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


void TileLoader::connectTiles(std::vector<tile*> tileset){
    
	int	boardSize = tileset.size();
	
	
	for (int i = 0 ; i < boardSize; i++) {
        if (i == (tileset.size() - 1)) {
			std::cout << "Finished Connecting Tiles" << std::endl;
			break;
		}
		bool result = false;
		result = connect2tiles(tileset[i], tileset[i+1],RandomDirection());
        if (result == false) break;
    }
}



std::vector<tile*> TileLoader::getTiles(){
	
	std::vector<tile*> board = buildTiles();
	
	connectTiles(board);
    
    return board;
}