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

string robotTest::dir_to_Str(_direction d){
	switch (d) {
		case North:
			return "North";
			break;
		case East:
			return "East";
			break;
		case South:
			return "South";
			break;
		case West:
			return "West";
			break;
			
		default:
			return "Failed";
			break;
	}
}

void robotTest::testHealth(robot *bruce){
	
	cout << "Health Test"<< endl << "Current Health: " << bruce->getHealth() << endl;
	
	cout << "Decrement Health Test" << endl;
	do {
		bruce->decrementHealth(1);
		cout <<	"Current Health: " << bruce->getHealth() << endl;
	} while (bruce->getHealth() != 0);
	
	
		//	Silly tests
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


	// TODO creat a self test with a pass fail, ie an array that get ticked
	//off when each sequence of each test is passed.
	//
void robotTest::TestHeading(robot *bruce){
	
		//	enum PassFail {
		//		Fail = 0,
		//		Pass
		//	};
		//
		//	PassFail scoreCard[] = {Fail};
	
	cout << "Heading and Rotation Test"<< endl <<
	"now facing: " << dir_to_Str(bruce->getHeading()) << endl;
	
		//	test right rotate
	cout << "Rotating robot right ... ";
	do {
		bruce->rotate(turnRight);
		cout << "now facing: " << dir_to_Str(bruce->getHeading()) << endl;
	} while (bruce->getHeading() != South);
	
		//	test left rotate
	cout << "Rotating robot left ... ";
	do {
		bruce->rotate(turnLeft);
		cout << "now facing: " << dir_to_Str(bruce->getHeading()) << endl;
	} while (bruce->getHeading() != South);
	
		//	TODO test Uturn
	cout << "Performing U-Turn ... " << endl;
	bruce->rotate(Uturn);
	cout << "now facing: " << dir_to_Str(bruce->getHeading()) << endl;
	bruce->rotate(turnLeft);
	cout << "Left Turn now facing: " << dir_to_Str(bruce->getHeading()) << endl;
	cout << "Performing next U-Turn" << endl;
	bruce->rotate(Uturn);
	cout << "now facing: " << dir_to_Str(bruce->getHeading()) << endl;
}

void robotTest::mainTest(){
    cout << "Creating robot object" << endl;
    robot *r = new robot();
    
    cout << "new robot is facing: " << dir_to_Str(r->getHeading()) << endl;
    cout << "and has health: " << r->getHealth() << endl << endl;
    
	TestHeading( r );
	testHealth( r );
	
	cout << "Testing Complete" << endl << endl;
    
	delete r;

}
/*
 TODO
 make a robot object to apply the tests to,
 
 write test procrdures in methods to work against the created robot
 
 run the test mothods in the main test method call that from main
 */