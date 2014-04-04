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
    
    //    private methods
    bool    decrementHealth();
    void setHeading(_direction face);
    
    
public:
    //constructors
    robot();
    robot(_direction face);
    
    //public methods
    int decrementHealth(int amount);
    _direction getHeading();
    int getHealth();
    bool rotate(_rotate turn);
    std::string toString();
};


#endif /* defined(__RobotRally__Robot__) */