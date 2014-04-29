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
#include <math.h>

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

void TileLoader::connectTiles(std::vector<tile*> tileset, _direction dir){
    
	int	boardSize = tileset.size();
	
	for (int i = 0 ; i < boardSize; i++) {
        if (i == (tileset.size() - 1)) {
			std::cout << "Finished Connecting Tiles" << std::endl;
			break;
		}
		bool result = false;
		result = connect2tiles(tileset[i], tileset[i+1],dir);
        if (result == false) break;
    }
}

/*void TileLoader::connectTilesAsBoard(std::vector<tile*> tileset)
 {
 
 int	boardSize = tileset.size();
 
 int SquareDimentions = sqrt(boardSize);
 
 for (int i = 0 ; i < (SquareDimentions-1); i++) {//count through 1 to 11 leaving 12 disconnected on the east
 for (int j = 0 ; j < (SquareDimentions); j++) {
 bool result = false;
 result = connect2tiles(tileset[i*12+j], tileset[i*12+j+1],East);
 
 if (result == false) {
 std::cout << "Connection " << i*12+j << " failed while connecting East"<< std::endl;
 break;
 }
 }
 }
 for (int j = 0 ; j < (SquareDimentions-1); j++) {//count through 1 to 11 leaving 12 disconnected on the east
 for (int i = 0 ; i < (SquareDimentions-1); i++) {
 bool result = false;
 result = connect2tiles(tileset[i*12+j], tileset[i*12+j+1],South);
 
 if (result == false) {
 std::cout << "Connection " << i*12+j << " failed while connecting South"<< std::endl;
 break;
 }
 }
 }
 }*/

void TileLoader::connectTilesAsBoard(std::vector<tile*> tileset){
		//	int x_dimension = 12;
		//	int y_dimension = 12;
	
		//todo to many magic numbers
		//todo not sure this is yet working
	
	
	connectTiles(tileset, East);
	
	for (int i = 0; i < tileset.size(); i += 12) {
		
			//break link
		tileset[i]->setTile(NULL, West);
		
		if (i+12 < 144) {
			tileset[i+12]->setTile(NULL, East);
			
				//connect board row below
			for (int j = 0 ; j < 12; j++) {
				
				connect2tiles(tileset[i+j], tileset[i+12+j], South);
//				std::cout << tileset[i+j]->toString() << std::endl;
//				std::cout << tileset[i+12+j]->toString() << std::endl;
			}
		}
	}
/*
	0	1	2	3	4	5	6	7	8	9	10	11
	12	13	14	15	16	17	18	19	20	21	22	23
	24	25	26	27	28	29	30	31	32	33	34	35
	36	37	38	39	40	41	42	43	44	45	46	47
	48	49	50	51	52	53	54	55	56	57	58	59
	60	61	62	63	64	65	66	67	68	69	70	71
	72	73	74	75	76	77	78	79	80	81	82	83
	84	85	86	87	88	89	90	91	92	93	94	95
	96	97	98	99	100	101	102	103	104	105	106	107
	108	109	110	111	112	113	114	115	116	117	118	119
	120	121	122	123	124	125	126	127	128	129	130	131
	132	133	134	135	136	137	138	139	140	141	142	143
*/
}
std::vector<tile*> TileLoader::getTiles(){
	
	std::vector<tile*> board = buildTiles();
	
		//	connectTiles(board);
    connectTilesAsBoard(board);
	
    return board;
}