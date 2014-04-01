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
    robot *testRobot = new robot();
}
void robotTest::buildFacingRobot(){
    robot *testRobot_E = new robot(East);
    robot *testRobot_W = new robot(West);
    robot *testRobot_N = new robot(North);
    robot *testRobot_S = new robot(South);
    
    std::cout << "Testing facing robots ....." << std::endl;
    std::cout << "East robot is facing " << testRobot_E->getHeading() << std::endl;
    std::cout << "West robot is facing " << testRobot_W->getHeading() << std::endl;
    std::cout << "North robot is facing " << testRobot_N->getHeading() << std::endl;
    std::cout << "South robot is facing " << testRobot_S->getHeading() << std::endl;

    delete testRobot_E;
    delete testRobot_W;
    delete testRobot_N;
    delete testRobot_S;
}

//list of tests
void robotTest::testStdRobotDir(){
    std::cout << "Standard robot is facing " << _testRobot->getHeading() << std::endl;
}

/////////////////public methods
/**
 Description
 @param
 @return
 */
int robotTest::mainTest(int argc, const char * argv[]){
    
    
}

/*
TODO

make a robot object to apply the tests to,

write test procrdures in methods to work against the created robot

run the test mothods in the main test method call that from main
 
 */