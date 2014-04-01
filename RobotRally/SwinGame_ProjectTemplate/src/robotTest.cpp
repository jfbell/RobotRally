//
//  robotTest.cpp
//  RobotRally
//
//  Created by James Bell on 29/03/2014.
//  Copyright (c) 2014 BellDesign. All rights reserved.
//

#include "robotTest.h"


robot *_testRobot;

void robotTest::buildStdRobot(){
    robot testRobot = robot();
}
void robotTest::buildFacingRobot(){
    robot testRobot_E = robot(East);
    robot testRobot_W = robot(West);
    robot testRobot_N = robot(North);
    robot testRobot_S = robot(South);
    
    std::cout << "Testing facing robots ....." << std::endl;
    std::cout << "East robot is facing " << testRobot_E.getHeading() << std::endl;
    std::cout << "West robot is facing " << testRobot_W.getHeading() << std::endl;
    std::cout << "North robot is facing " << testRobot_N.getHeading() << std::endl;
    std::cout << "South robot is facing " << testRobot_S.getHeading() << std::endl;

}

//list of tests
void robotTest::testStdRobotDir(){
    std::cout << "Standard robot is facing " << testRobot->getHeading() << std::endl;
}

/////////////////public methods
/**
 Description
 @param
 @return
 */
int robotTest::mainTest(int argc, const char * argv[]){
    
    
}