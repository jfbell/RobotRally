	//
	//  robotTest.cpp
	//  RobotRally
	//
	//  Created by James Bell on 29/03/2014.
	//  Copyright (c) 2014 BellDesign. All rights reserved.
	//

#include "robotTest.h"

using namespace std;

robotTest::robotTest(){}

/**
 Tests the health methods of a robot.
 @param bruce will be the robot under test
 */
void robotTest::testHealth(robot *bruce){
	
	cout << "Health Test"<< endl << "Current Health: " << bruce->getHealth() << endl;
	
	cout << "Decrement Health Test" << endl;
	do {
		bruce->decrementHealth(1);
		cout <<	"Current Health: " << bruce->getHealth() << endl;
	} while (bruce->getHealth() != 0);
	
		//	Silly input tests
	bruce->decrementHealth(-1);
	cout << "Silly test input (-1) : " << bruce->getHealth() << endl;
	
	bruce->decrementHealth(0);
	cout << "Silly test input (0) : " << bruce->getHealth() << endl;
	
	bruce->decrementHealth(10);
	cout << "Silly test input (10) : " << bruce->getHealth() << endl;
	
	bruce->decrementHealth('a');
	cout << "Silly test input ('a') : " << bruce->getHealth() << endl;
	
	bruce->decrementHealth(-10);
	cout << "Silly test input (-10) : " << bruce->getHealth() << endl;
	
}

/**
 Tests heading methords and handeling of the heading enum, 
 esp. through transisitions around the various directions
 @param bruce will be the robot under test
 */
void robotTest::TestHeading(robot *bruce){
	// TODO creat a self test with a pass fail, ie an array that get ticked
	//off when each sequence of each test is passed.
    
		//	enum PassFail {
		//		Fail = 0,
		//		Pass
		//	};
		//	PassFail scoreCard[] = {Fail};
	
	cout << "Heading and Rotation Test"<< endl <<
	"now facing: " << bruce->toString((bruce->getHeading())) << endl;
	
		//	test right rotate
	cout << "Rotating robot right ... ";
	do {
		bruce->rotate(turnRight);
		cout << "now facing: " << bruce->toString(bruce->getHeading()) << endl;
	} while (bruce->getHeading() != South);
	
		//	test left rotate
	cout << "Rotating robot left ... ";
	do {
		bruce->rotate(turnLeft);
		cout << "now facing: " << bruce->toString(bruce->getHeading()) << endl;
	} while (bruce->getHeading() != South);
	
		//  test Uturn
	cout << "Performing U-Turn ... " << endl;
	bruce->rotate(Uturn);
	cout << "now facing: " << bruce->toString(bruce->getHeading()) << endl;
	bruce->rotate(turnLeft);
	cout << "Left Turn now facing: " << bruce->toString(bruce->getHeading()) << endl;
	cout << "Performing next U-Turn" << endl;
	bruce->rotate(Uturn);
	cout << "now facing: " << bruce->toString(bruce->getHeading()) << endl;
}

/**
 Testing for building robots heading in perticular directions, 
 robots are built and destroied as needed with in the program.
 Also contians a score card feature that reports sucess or 
 failular of the procedure
 */
void robotTest::testBuildDirection(){

    char result[] = {0,0,0,0};
    const char PassResult[] = {'N','E','S','W'};
    
    robot *n = new robot(North);
    robot *s = new robot(South);
    robot *e = new robot(East);
    robot *w = new robot(West);

    if (n->getHeading() == North) {
        result[North] = 'N';
    }
    if (s->getHeading() == South) {
        result[South] = 'S';
    }
    if (e->getHeading() == East) {
        result[East] = 'E';
    }
    if (w->getHeading() == West) {
        result[West] = 'W';
    }
    
    if (result[0] == PassResult[0] &&
        result[1] == PassResult[1] &&
        result[2] == PassResult[2] &&
        result[3] == PassResult[3]) {
        cout << "Direction Build: PASS" << endl;
    }else{
        cout << "Direction Build: Fail" << endl;
    }
    
    delete n;
    delete s;
    delete e;
    delete w;
    
}

/**
 Builds robot to be tested, reports initial conditions then runs the battery
 of tests above and is responsibe for destroying the est robot at the end.
 */
void robotTest::mainTest(){
    cout << "Creating robot object" << endl;
    robot *r = new robot();
    
    cout << "new robot is facing: " << r->toString(r->getHeading()) << endl;
    cout << "and has health: " << r->getHealth() << endl << endl;
    
	TestHeading( r );
	testHealth( r );
	
    testBuildDirection();
    
	cout << "Testing Complete" << endl << endl;
    
	delete r;

}