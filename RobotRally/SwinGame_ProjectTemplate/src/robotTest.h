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


class robotTest {
    
private:
    robot *testRobot;
    
    void buildStdRobot();
    void buildFacingRobot();

    
    //list of tests
    void testStdRobotDir();
    
public:
    int mainTest(int argc, const char * argv[]);
    
};
#endif /* defined(__RobotRally__robotTest__) */
