//
//  Robot.cpp
//  RobotRally
//
//  Created by James Bell on 29/03/2014.
//  Copyright (c) 2014 BellDesign. All rights reserved.
//

#include "Robot.h"

/////////////////constructors
/** 
 Builds standard robot facing North with full health
 */
robot::robot(){
    health = 6;
    heading = South;
}
/**
 Builds  robot facing towards param face with full health
 @param face what direction to face at start
 */
robot::robot(_direction face){
    health = 6;
}

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
int robot::decrementHealth(int amount){
    if ((health - amount) > 0) {
        health = health - amount;
        return health;
    }else{
        health = 0;
        std::cout << "This robot is not feeling too good :( Health: " << health << std::endl;
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
bool robot::rotate(_rotate turn){       //TODO why does this method require type _rotate and all other enums use the direction not _direction??
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
                    std::cout << "U-turn failing" << std::endl;
                    return false;
            }
        default:
            std::cout << "turn failing" << std::endl;
            return false;
    }
}
/**
 Returnes a status string
 @return string
 */
std::string robot::toString(){
    return "help i dont want to be a robot anymore, i want to be a lumber jack!";
}
