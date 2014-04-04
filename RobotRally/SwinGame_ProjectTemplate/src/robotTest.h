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
	std::string dir_to_Str(_direction d);
	void	testHealth(robot *bruce);
	
	void TestHeading(robot *burce);
    
public:
    robotTest();
    
    void mainTest();
    
    
};
#endif /* defined(__RobotRally__robotTest__) */
