//
//  CardLoader.h
//  RobotRally
//
//  Created by James Bell on 30/04/2014.
//  Copyright (c) 2014 BellDesign. All rights reserved.
//

#ifndef __RobotRally__CardLoader__
#define __RobotRally__CardLoader__

#include <iostream>
#include <vector>
#include "Card.h"

class CardLoader {
	std::vector<Card*> buildCards();
	_rotate randomTurn();

public:
	CardLoader();
	std::vector<Card*>	Cards();
};

#endif /* defined(__RobotRally__CardLoader__) */
