	//
	//  Deck.cpp
	//  RobotRally
	//
	//  Created by James Bell on 30/04/2014.
	//  Copyright (c) 2014 BellDesign. All rights reserved.
	//

#include "Deck.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Deck::Deck(CardLoader* loader){
	std::srand(std::time(NULL)); //required for shuffling
	cardSet = loader->Cards();
}

Card* Deck::issueCard(){
	Card* c = cardSet.back();
	cardSet.pop_back();
	return c;
}

/**
 * This method rearranges the cards in the internal
 * cardSet vector.
 * We use the Fisher & Yates shuffling method for this purpose, where
 * n is the size of the Deck.
 * method from BullsAndCows project, Technical Software Development
 */
void Deck::shuffelDeck(){
	int n = cardSet.size();
	while ( n > 1)
	{
			// new random index in the range 0 to n
		int k = rand() % n;
		n--;					// n last pertinent index
		std::swap( cardSet[n], cardSet[k] );	// algorithm library
	}
}

std::vector<Card*> Deck::getCards(){
	return cardSet;
}

int Deck::cardsLeft(){
	return cardSet.size();
}

std::string Deck::toString(){
	std::strstream s;
	s << std::endl << "The Deck" << std::endl;
	
	for (int i = 0 ; i < cardSet.size() ; i++) {
		s << cardSet[i]->toString() << std::endl;
	}
	
	return s.str();
}