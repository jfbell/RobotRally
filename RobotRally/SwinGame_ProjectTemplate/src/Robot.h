	//
	//  Robot.h
	//  RobotRally
	//
	//  Created by James Bell on 29/03/2014.
	//  Copyright (c) 2014 BellDesign. All rights reserved.
	//

#ifndef __RobotRally__Robot__
#define __RobotRally__Robot__

#include <iostream>
#include <string>

class tile;

enum _direction {
    North = 0,
    East,
    South,
    West,
} ;

enum _rotate {
    turnLeft = 0,
    turnRight,
    Uturn,
} ;

class robot {
private:
		//    instance variables
    int health;                 //health can be a value between 0 and 6 only
    _direction heading;          //direction defined by direction  enum _direction
    tile* currentTile;
    
		//    private methods
    bool decrementHealth();
    
    
    bool moveOneSpot();
    
public:
		//constructors
    robot();
    robot(_direction face);
	
		//destructors
		//	~robot();
    
		//public methods
    int decrementHealth(int amount);
    _direction getHeading();
    int getHealth();
    bool rotate(_rotate turn);
	void setHeading(_direction face);
	
	std::string toString();
	std::string toString(_direction d); //overloaded function, genious!
    
		//Tile interface
    void setCurrentTile(tile* tile);
    tile* getCurrentTile();
		//    void move(int steps);
    bool move(int steps);
};


#endif /* defined(__RobotRally__Robot__) */