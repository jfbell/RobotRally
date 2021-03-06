//
//  main.cpp
//  RobotRally
//
//  Created by James Bell on 25/03/2014.
//  Copyright (c) 2014 BellDesign. All rights reserved.
//

#include <iostream>
#include <stdio.h>
//#include "SwinGame.h"
#include "robotTest.h"
#include "tileTest.h"



int main(void) //int argc, const char * argv[])
{
    
    robotTest *rt = new robotTest;
    
    rt->mainTest();
    
    delete rt;
    
    testTile *t = new testTile();
    
    t->mainTileTest();
    
    delete t;
    
    return 0;
}
