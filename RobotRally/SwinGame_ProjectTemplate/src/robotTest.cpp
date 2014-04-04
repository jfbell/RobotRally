//
//  robotTest.cpp
//  RobotRally
//
//  Created by James Bell on 29/03/2014.
//  Copyright (c) 2014 BellDesign. All rights reserved.
//

#include "robotTest.h"

using namespace std;

robotTest::robotTest(){
    
}

void robotTest::mainTest(){
    
    robot *r = new robot();
    
    cout << "robot is facing: " << r->getHeading() << endl;
    cout << "robot has health: " << r->getHealth() << endl;
    
    

}
/*
 TODO
 make a robot object to apply the tests to,
 
 write test procrdures in methods to work against the created robot
 
 run the test mothods in the main test method call that from main
 */