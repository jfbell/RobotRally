//
//  CardLoader.cpp
//  RobotRally
//
//  Created by James Bell on 30/04/2014.
//  Copyright (c) 2014 BellDesign. All rights reserved.
//

#include "CardLoader.h"
#include "Card.h"
#include "Move.h"
#include "Turn.h"
#include "Robot.h"
#include "TileLoader.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


CardLoader::CardLoader(){
	std::srand(std::time(NULL));
	
}

std::vector<Card*> CardLoader::buildCards(){
	
	std::vector<Card*> Deck = {};
	
	for ( int noMoveCards = 30; noMoveCards > 0 ; noMoveCards--) {
		int steps = ((rand() % 10) - 5); //produces a random number between -5 and 5
		Deck.push_back(new Move(steps));
	}
	
	for ( 	int noTurnCards = 10; noTurnCards > 0 ; noTurnCards--) {
		_rotate turn = randomTurn();
		Deck.push_back(new Turn(turn));
	}
	return Deck;
}

std::vector<Card*> CardLoader::Cards(){
	return buildCards();
}

_rotate CardLoader::randomTurn(){
	
	int rand_rotate = rand() % 3;
	
	switch (rand_rotate) {
		case 0:
			return turnRight;
			break;
		case 1:
			return turnLeft;
			break;
		case 2:
			return Uturn;
			break;
		default:
			return Uturn;
			break;
			
	}
}