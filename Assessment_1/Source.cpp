#include <iostream>
#include <string>
#include <stdlib.h>    
#include <time.h>
#include <windows.h>

 //declare variables

const int maxHealth = 100;
const int maxEnergy = 100;
int gamestarted = 0;

int invalidinput = 0;

//player variables;
int playerhitchance;
int playerchancemodifier;
bool playerhealused = 0;
int playerrechargerate = 1;
int playerhealth = 100;
int playerenergy = 100;
int playerdodgeused = 0;
int playerhealthincrease = 0;
int playersecondturn;
int playermove;

// enemy variables;
 int enemychancemodifier;
 int enemyhealused = 0;
 int enemyrechargerate = 1;
 int enemyhealth = 100;
 int enemyenergy = 100;
 int enemydodgeused = 0;
 int enemymove;
 int enemyhealthincrease = 0;
 int enemymaxenergy = 100;
 int enemymaxhealth = 100;
 int enemyhitchance;
 int enemysecondturn;


 //attack variables
const int attackhitchance = 80;
const int sphitchance = 50;

int main() {
	do
	{
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
		gamestarted = 1;
		invalidinput = 0;

		enemychancemodifier = 0;
		playerchancemodifier = 0;

		playerenergy += (10 * playerrechargerate);
		enemyenergy += (10 * enemyrechargerate);
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
				Sleep(200);
				std::cin >> playermove;

			}
			break;

		case 3:
			playerrechargerate = 4;
			enemyhitchance = 10;
			break;
		case 4:

			enemyhitchance = -30;
			playerrechargerate = 0.5;
			break;

		case 5:

			if (playerhealused == 1)
			{
				std::cout << "You've already healed this turn" << std::endl;
				Sleep(200);
			}
			if (playersecondturn = 0)
			{
				playersecondturn = 1;
				playerhealth = playerhealth + (playerenergy / 2);
			}
			else if (playersecondturn = 1)
			{
				playerhealused = 1;
			}
			break;

		default:
			std::cout << "Invalid Input..." << std::endl;
			break;
		}
	}
		//enemy move

		while (enemyhealused = 0) {

			if (enemyhealth < 50)
			{
				enemymove = 3;
			}
			else if (enemyenergy < 50)
			{
				enemymove = 4;
			}
			else if (enemymove = 1)
			{
				if (playermove = 2)
				{
					enemymove = 5;
				}
				else
				{
					enemymove = 1;
				}
			}
			else if (enemymove = 2)
			{
				enemymove = 4;
			}
			else if (enemymove = 5)
			{
				enemymove = 1;
			}
			else if (playerhealth > 50)
			{
				enemymove = 1;
			}
			else
			{
				enemymove = 2;
			}

			switch (enemymove)
			{
			case 1:


			case 2:


			case 3:
				enemyrechargerate = 4;
				playerhitchance = 10;
			case 4:
				playerhitchance = -30;
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

		

		if (playerhealth = 0) {

			std::cout << "You Died" << std::endl;
			Sleep(1000);
			break;
		}
		else if (enemyhealth = 0)
		{
			std::cout << "You Killed the Enemy" << std::endl;
			break;
		}

		
		

	} while (playerhealth > 0 && enemyhealth > 0);

}
 
