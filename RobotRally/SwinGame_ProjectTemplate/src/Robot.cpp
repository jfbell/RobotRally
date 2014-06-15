	//
	//  Robot.cpp
	//  RobotRally
	//
	//  Created by James Bell on 29/03/2014.
	//  Copyright (c) 2014 BellDesign. All rights reserved.
	//

#include "Robot.h"
#include <strstream>
#include "Tile.h"
#include <stdexcept>

	/////////////////constructors
/**
 Builds standard robot facing South with full health
 */
robot::robot(){
    health = 6;
    heading = South;
    currentTile = NULL;
}
/**
 Builds  robot facing towards param face with full health
 @param face what direction to face at start
 */
robot::robot(_direction face){
	heading = face;
    health = 6;
    currentTile = NULL;
}


	// TODO deconstructor ???
	//robot::~robot(){
	//	delete [] robot;
	//};


	/////////////////private methods
/**
 Remove one from health
 @return bool true if health can be decremented ie doing so will not push health below 0
 */
bool robot::decrementHealth(){
    if (health > 0) {
        health--;
        return true;
    }else{
        std::cout << "Health too low :(" << std::endl;
        return false;
    }
}
/**
 Sets heading according to param face
 @param face type _direction
 */
void robot::setHeading(_direction face){
    heading = face;
}

	/////////////////public methods
/**
 Removes health by passed amount, won't decrement below 0
 @param amount how much health to remove
 @return health, current health
 */
	// included decrementHealth() not sure its created properly
int robot::decrementHealth(int amount){
    if ((health - amount) > 0) {
        while (amount > 0) {
			decrementHealth();
			amount--;
		}
        return health;
    }else{
        health = 0;
			//		std::cout << "This robot is not feeling too good :( Health: " << health << std::endl;
        return health;
    }
}
/**
 Returnes current heading
 @return heading
 */
_direction robot::getHeading(){
    return heading;
}
/**
 returnes health
 @return health
 */
int robot::getHealth(){
    return health;
}
/**
 Rotates robot
 @param turn can be left, right or Uturn
 @return true if sucessful, false if test conditions not meet and robot didnt turn
 */
bool robot::rotate(_rotate turn){
		//TODO why does this method require type _rotate and all
		//other enums use the direction not _direction??
    switch (turn) {
        case turnLeft:
            if (heading == North) {
                heading = West;
                return true;
            } else {
                heading = (_direction)((int)heading - 1);
                return true;
            }
        case turnRight:
            if (heading == West) {
                heading = North;
                return true;
            } else {
                heading = (_direction)((int)heading + 1);
                return true;
            }
        case Uturn:
            switch (heading) {
                case North:
                    heading = South;
                    return true;
                case East:
                    heading = West;
                    return true;
                case South:
                    heading = North;
                    return true;
                case West:
                    heading = East;
                    return true;
                default:
                    std::cout << "U-turn failed" << std::endl;
                    return false;
            }
        default:
            std::cout << "turn failed" << std::endl;
            return false;
    }
}
/**
 to_string is overloaded to report the values of the enums
 correctly depending on what is passed in, making the output of
 different status messages human readable.
 @param direction
 @return std::string
 */
std::string robot::toString(_direction d)
{
    switch (d) {
		case North:
			return "North";
			break;
		case East:
			return "East";
			break;
		case South:
			return "South";
			break;
		case West:
			return "West";
			break;
			
		default:
			return "Direction Failed";
			break;
	}
}

/**
 Returnes a status string
 @return string
 */
std::string robot::toString(){
    std::strstream a;
    a << "Robot " << this << " status:"<<std::endl;
    a << "\tHealth: " << health << std::endl;
	a << "\tHeading: " << toString(heading) << std::endl;
	if (currentTile != NULL) {
		a << "\tCurrent Tile: \n" << currentTile->toString() << std::endl;
    }else{
		a << "\tCurrent Tile: " << "NULL" << std::endl;
	}
		// report health and heading as a string
    return a.str();
}

	//Tile interface
bool robot::moveOneSpot(){
   
	if (currentTile->getTile(heading) != NULL) {
        
		currentTile->setVisitor(NULL);
        
		setCurrentTile(currentTile->getTile(heading));
        
		currentTile->setVisitor(this);
        
		return true;
    }else{
        return false;
    }
}

void robot::setCurrentTile(tile* tile){
    currentTile = tile;
}

tile* robot::getCurrentTile(){
    return currentTile;
}

bool robot::move(int steps){
    bool result = false;
    
	try {
		if (steps > 0) {
			for (int i = steps; i > 0; i--) {
				result = moveOneSpot();
				if(result == false){throw std::logic_error("Can't Move");}
			}
		}else{
			rotate(Uturn);
			for (int i = -steps; i > 0; i--) {
				result = moveOneSpot();
				if(result == false){throw std::logic_error("Can't Move");}
			}
			result = rotate(Uturn);
		}
	} catch (std::exception &e) {
		std::cout << "Exception : ---> " << e.what() << std::endl;
		result = false;
	}
	
	if (result == false) {
		std::cout << "No tile infront turn befor trying to move again" << std::endl;
	}
	//Invoke the Tile if it has anything to do
	currentTile->Invoke();
	return result;
	
}

void robot::setStartTile(tile* tile){
     startTile = tile;
	
}

void robot::goToStart(){
	currentTile->setVisitor(NULL);
	
	setCurrentTile(startTile);
	
	startTile->setVisitor(this);
}