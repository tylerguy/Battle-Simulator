#include <iostream>
#include <string>
#include <stdlib.h>    
#include <time.h>
#include <windows.h>

//declare variables

const int maxHealth = 100;
const int maxEnergy = 100;
int gamestarted = 0;

//player variables;
int playerhitchance;
int playerchancemodifier;
bool playerhealused = 0;
int playerrechargerate = 1;
int playerhealth = 100;
int playerenergy = 100;
int playerdodgeused = 0;
int playerhealthincrease = 0;
bool playersecondturn = 0;
int playermove;
int playerenergydecrease;

// enemy variables;
int enemychancemodifier;
int enemyhealused = 0;
int enemyrechargerate = 1;
int enemyhealth = 100;
int enemyenergy = 100;
int enemydodgeused = 0;
int enemymove;
int enemymaxenergy = 100;
int enemymaxhealth = 100;
int enemyhitchance;
bool enemysecondturn = 0;
int enemyenergydecrease;


//attack variables
const int attackhitchance = 80;
const int sphitchance = 50;

//other variables
int option;
int diff;

int main() {
	do {

		std::cout << "Welcome to Battle Simulator, a Text Based RPG Game" << std::endl;
		std::cout << std::endl;

		std::cout << "What would you like to do ?" << std::endl;
		std::cout << std::endl;

		std::cout << "1 >> Start Game" << std::endl;
		std::cout << "2 >> Change Difficulty" << std::endl;
		std::cout << "3 >> Quit Game" << std::endl;
		std::cin >> option;

		if (option == 1)
		{
			gamestarted == 1;
			break;
		}
		if (option == 2)
		{
			std::cout << "Difficulty: " << std::endl;
			std::cout << std::endl;

			std::cout << "1 - Easy" << std::endl;
			std::cout << "2 - Medium" << std::endl;
			std::cout << "3 - Hard" << std::endl;
			std::cin >> diff;

			switch (diff)
			{
			case 1:
				enemymaxhealth = 100;
				enemyhealth = 100;
				enemyenergy = 100;
				enemymaxenergy = 100;
				break;

			case 2:
				enemymaxhealth = 150;
				enemyhealth = 150;
				enemyenergy = 150;
				enemymaxenergy = 150;
				break;

			case 3:
				enemymaxhealth = 250;
				enemyhealth = 250;
				enemyenergy = 250;
				enemymaxenergy = 250;
				break;

			}

		}
		if (option == 3)
		{
			return 0;
		}

	} while (gamestarted == 0);






	do {


		std::system("CLS");
		std::cout << "Current Stats:" << std::endl;
		std::cout << "Player Health: " << playerhealth << std::endl;
		std::cout << "Player Energy: " << playerenergy << std::endl;
		std::cout << std::endl;
		std::cout << "Enemy Health: " << enemyhealth << std::endl;
		std::cout << "Enemy Energy: " << enemyenergy << std::endl;
		Sleep(500);

		std::cout << " " << std::endl;
		std::cout << "1) Attack \n";
		std::cout << "2) Special Attack \n";
		std::cout << "3) Recharge \n";
		std::cout << "4) Dodge \n";
		std::cout << "5) Heal \n";
		std::cout << "" << std::endl;
		Sleep(500);

		std::cout << "Take your move: \n";
		std::cin >> playermove;

		playerenergy += (10 * playerrechargerate);
		enemyenergy += (10 * enemyrechargerate);
		int playerrechargerate = 1;
		int enemyrechargerate = 1;
		int enemychancemodifier = 0;
		int playerchancemodifier = 0;
		if (playerenergy > maxEnergy)
		{
			playerenergy = maxEnergy;
		}
		if (enemyenergy > maxEnergy)
		{
			enemyenergy = maxEnergy;
		}

		//player move
		while (playerhealused = 0)
		{
			switch (playermove)
			{
			case 1:

				break;

			case 2:

				if (playerenergy <= 0)
				{
					std::cout << "You don't have enough energy to do this move" << std::endl;
					std::cout << "pls choose another option" << std::endl;
					Sleep(1000);
					std::cin >> playermove;

				}
				else
				{
					playerenergy = playerenergy - 50;
				}
				break;

			case 3:
				std::cout << "You used Recharge" << std::endl;
				playerrechargerate = 4;
				enemyhitchance = 10;
				break;
			case 4:
				std::cout << "You dodged the enemy's Attack" << std::endl;
				enemychancemodifier = -30;
				playerrechargerate = 0.5;
				break;

			case 5:

				if (playerhealused = 1)
				{
					std::cout << "You've already healed this turn" << std::endl;
					Sleep(1000);
				}
				if (playersecondturn == 0)
				{
					playersecondturn = 1;
					playerhealth = playerhealth + (playerenergy / 2);
					playerenergy = playerenergy / 2;
					std::cout << "You healed" << std::endl;
				}
				else if (playersecondturn == 1)
				{
					playerhealused = 1;
				}
				break;

			default:
				std::cout << "Invalid Input..." << std::endl;
				Sleep(1000);
				break;
			}
		}
		//enemy move

		while (enemyhealused == 0) {

			if (enemyhealth < 50)
			{
				enemymove = 5;
				break;
			}
			else if (enemyenergy < 50)
			{
				enemymove = 3;
				break;
			}
			else if (enemymove == 1)
			{
				if (playermove == 2)
				{
					enemymove = 4;
					break;
				}
				else
				{
					enemymove = 1;
					break;
				}
				break;
			}
			else if (enemymove == 2)
			{
				enemymove = 3;
				break;
			}
			else if (enemymove == 4)
			{
				enemymove = 1;
				break;
			}
			else if (playerhealth > 50)
			{
				enemymove = 1;
				break;
			}
			else
			{
				enemymove = 2;
				break;
			}


			switch (enemymove)
			{
			case 1:


			case 2:


			case 3:
				enemyrechargerate = 4;
				playerchancemodifier = 10;

			case 4:
				playerchancemodifier = -30;
				enemyrechargerate = 0.5;


			case 5:

				if (enemysecondturn = 0)
				{
					enemysecondturn = 1;
					enemyhealth = enemyhealth + (enemyenergy / 2);
				}
				else if (enemysecondturn = 1)
				{
					enemyhealused = 1;
				}

			}
		}

		//action processing

		//player move
		do {
			if (playermove == 1)
			{
				playerhitchance = ((rand() % 100) + 1) + playerchancemodifier;
				if (playerhitchance < attackhitchance)
				{
					std::cout << "You successfully hit the enemy" << std::endl;
					enemyhealth -= ((rand() % 10) + 1);
					Sleep(1000);
				}
				else
				{
					std::cout << "You failed to hit the enemy" << std::endl;
					Sleep(1000);

				}
				break;
			}
			if (playermove == 2)
			{
				playerhitchance = ((rand() % 100) + 1) + playerchancemodifier;
				if (playerhitchance < sphitchance)
				{
					std::cout << "You successfully hit the enemy" << std::endl;
					enemyhealth -= ((rand() % 5) + 16);
					Sleep(1000);
					playerenergy = playerenergy / 2;
				}
				else
				{
					std::cout << "You failed to hit the enemy" << std::endl;
					Sleep(1000);
				}
			}
			if (playermove == 3)
			{

			}
			if (playermove == 4)
			{

			}
			if (playermove == 5)
			{

			}
			break;
		} while (playerhealth > 0 && enemyhealth > 0);
		//enemy move
		if (enemymove == 1)
		{
			enemyhitchance = ((rand() % 100) + 1) + enemychancemodifier;
			if (enemyhitchance < attackhitchance)
			{
				playerhealth -= ((rand() % 10) + 1);
			}
		}
		if (enemymove == 2)
		{
			enemyhitchance = ((rand() % 100) + 1) + enemychancemodifier;
			if (enemyhitchance < sphitchance)
			{
				playerhealth -= ((rand() % 5) + 16);
				enemyenergy = enemyenergy / 2;

			}

		}

		switch (enemymove)
		{
		case 1:
			std::cout << "The enemy used attack" << std::endl;
			Sleep(1000);
			break;
		case 2:
			std::cout << "The enemy used special attack" << std::endl;
			Sleep(1000);
			break;
		case 3:
			std::cout << "The enemy recharged their energy" << std::endl;
			Sleep(1000);
			break;
		case 4:
			std::cout << "The enemy dodged your attack" << std::endl;
			Sleep(1000);
			break;
		case 5:
			std::cout << "The enemy healed for " << enemymaxhealth - enemyhealth << " health." << std::endl;
			Sleep(1000);
			break;
		}
		playerhealused = 0;
		enemyhealused = 0;



		if (playerhealth == 0) {

			std::cout << "You Died" << std::endl;
			Sleep(1000);
			exit;
		}
		else if (enemyhealth == 0)
		{
			std::cout << "You Killed the Enemy" << std::endl;
			exit;
		}



	} while (playerhealth > 0 && enemyhealth > 0);
}