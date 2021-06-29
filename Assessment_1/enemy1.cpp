#include <iostream>
#include <string>
#include <stdlib.h>    
#include <time.h>

if (playermove == 1) {

	if (enemydodgeused = 1) {
		playerchancemodifier = -30;


	}

	playerattackchancehit = (rand() % 100 + 1) + playerchancemodifier;

	if (playerattackchancehit <= 80)

	{

		std::cout << "You successfully attacked" << std::endl;
		enemyhealth -= (rand() % 10 + 1);

	}

	else
	{

		std::cout << "You Failed your turn" << std::endl;

	}
}