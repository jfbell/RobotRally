//
//  Deck.h
//  RobotRally
//
//  Created by James Bell on 30/04/2014.
//  Copyright (c) 2014 BellDesign. All rights reserved.
//

#ifndef __RobotRally__Deck__
#define __RobotRally__Deck__

#include <iostream>
#include "Card.h"
#include <vector>
#include "CardLoader.h"

class Deck {
private:
	std::vector<Card*> cardSet;
	
public:
	Deck(CardLoader* loader);
	Card* issueCard();
	void shuffelDeck();
	std::vector<Card*> getCards();
	int cardsLeft();
	std::string toString();
};

#endif /* defined(__RobotRally__Deck__) */


