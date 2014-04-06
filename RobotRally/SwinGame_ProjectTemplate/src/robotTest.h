//
//  robotTest.h
//  RobotRally
//
//  Created by James Bell on 29/03/2014.
//  Copyright (c) 2014 BellDesign. All rights reserved.
//

#ifndef __RobotRally__robotTest__
#define __RobotRally__robotTest__

#include "Robot.h"

class robotTest
{
    
private:
	void testHealth(robot *bruce);
	void TestHeading(robot *burce);
    void testBuildDirection();
    
public:
    robotTest();
    
    void mainTest();
    
    
};
#endif /* defined(__RobotRally__robotTest__) */
