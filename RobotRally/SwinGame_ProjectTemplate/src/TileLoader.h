//
//  TileLoader.h
//  RobotRally
//
//  Created by James Bell on 14/04/2014.
//  Copyright (c) 2014 BellDesign. All rights reserved.
//

#ifndef __RobotRally__TileLoader__
#define __RobotRally__TileLoader__

#include <iostream>
#include <vector>
#include "Tile.h"
#include "Robot.h"

class TileLoader {
private:    
    std::vector<tile*> buildTiles();
    void connectTiles(std::vector<tile*> tileset);
    void connectTiles(std::vector<tile*> tileset, _direction direction);
	void connectTilesAsBoard(std::vector<tile*> tileset);
    _direction RandomDirection();
    bool connect2tiles(tile *A, tile *B, _direction dir);
    
public:
    TileLoader();
    std::vector<tile*> getTiles();
};

#endif /* defined(__RobotRally__TileLoader__) */
