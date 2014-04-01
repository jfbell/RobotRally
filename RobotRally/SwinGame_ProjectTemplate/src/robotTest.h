//
//  robotTest.h
//  RobotRally
//
//  Created by James Bell on 29/03/2014.
//  Copyright (c) 2014 BellDesign. All rights reserved.
//

#ifndef __RobotRally__robotTest__
#define __RobotRally__robotTest__

#include <iostream>
#include "Robot.h"
#include <vector>

class robotTest {
    
private:
    std::vector<robot *> _Robots;
    
    robot *underTestRobot;
    
    
    
    void buildStdRobot();
    void buildFacingRobot();
   
    //list of tests
    void testStdRobotDir();
    
public:
    robotTest();
    
    ~robotTest();
    
    int battery_of_tests();
    
};
#endif /* defined(__RobotRally__robotTest__) */
