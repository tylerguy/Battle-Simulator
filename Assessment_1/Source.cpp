#include <iostream>
#include <string>
#include <stdlib.h>    
#include <time.h>      


 //declare variables

const int maxHealth = 100;
const int maxEnergy = 100;
int gamestarted = 0;

int invalidinput = 0;
std::string gamestate;

//player variables;
int playerchancemodifier;
int playerattackchancehit = 80;
int playerspchancehit = 50;
int playerhealused = 0;
int playerrechargerate = 1;
int playerhealth = 100;
int playerenergy = 100;
int playerdodgeused = 0;
int playermove = 0;
int playerhealthincrease = 0;

//enemy variables;
int enemychancemodifier;
int enemychancehit = 0;
int enemyhealused = 0;
int enemyrechargerate = 1;
int enemyhealth = 100;
int enemyenergy = 100;
int enemydodgeused = 0;
int enemymove = 0;
int enemyhealthincrease = 0;

int main()
{
	do
	{
		std::cout << " " << std::endl;
		std::cout << "1) Attack \n";
		std::cout << "2) Special Attack \n";
		std::cout << "3) Heal \n";
		std::cout << "4) Recharge \n";
		std::cout << "5) Dodge \n";
		std::cout << "" << std::endl;

		std::cout << "Take your move: \n";
		std::cin >> playermove;
		gamestarted = 1;
		playerhealused = 1;
		
		
		
		enemychancemodifier = 0;
		
		//player turn


		//player attack

		
		

		if (playermove == 1) {

			if (enemydodgeused = 1) {
				playerchancemodifier = -30;


			}
			
			playerattackchancehit = ((rand() % 100) + 1) + playerchancemodifier;

			if (playerattackchancehit <= 80)

			{

				std::cout << "You successfully attacked" << std::endl;
				enemyhealth -= ((rand() % 10) + 1);

			}

			else
			{

				std::cout << "You Failed your turn" << std::endl;

			}
		}

		//end of player attack

		//player special attack

		else if (playermove == 2)
		{

			playerspchancehit = ((rand() % 100) + 1) - playerchancemodifier;

			if (playerspchancehit <= 50)
			{
				if (playerenergy == 0)
				{
					std::cout << "You don't have enough energy to do this move" << std::endl;
					std::cout << "pls choose another option" << std::endl;
					std::cin >> playermove;
				}
				else
				{
					std::cout << "You successfully attacked" << std::endl;
					enemyhealth -= ((rand() % 100) + 1);
					playerenergy -= 50;
					if (playerenergy == 0);
				}
			}

			else if (playerspchancehit >= 0)
			{

				std::cout << "You Failed your turn" << std::endl;

			}
			if (playerenergy == 0)
			{
				std::cout << "You don't have enough energy to do this move" << std::endl;
				std::cout << "pls choose another option" << std::endl;
				std::cin >> playermove;
			}

		}

		//end of player special attack


		//player heal

		else if (playermove == 3) {
			if (playerhealused = 0)
			{

				playerhealthincrease = playerenergy / 2;
				playerhealthincrease += playerhealth;

				std::cout << "You have been healed!" << std::endl;
				playerhealused = 1;
			}

			if (playerhealth > maxHealth)
			{
				playerhealth = maxHealth;
			}

		}

		else if (playerhealth == 100)
		{
			std::cout << "You're already at full health";
		}

		//end of player heal

		//player recharge

		else if (playermove == 4)
		{
			playerrechargerate = 4;
		}

		//player dodge

		else if (playermove == 5)
		{
			
			playerrechargerate = 0.5;
			playerdodgeused = 1;
		}

		//end of player dodge

		else if (playermove != 1 or playermove != 2 or playermove != 3 or playermove != 4 or playermove != 5)

		{

			std::cout << "Invalid Input..." << std::endl;
			int invalidinput = 1;


		}


		//enemy logic

		enemymove = ((rand() % 5) + 1);

		//enemy attack

		if (enemymove == 1) {

			int hitchance = 80;
			enemychancehit = ((rand() % 100) + 1) - enemychancemodifier;

			if (enemychancehit <= 80)

			{

				enemyhealth -= ((rand() % 10) + 1);

			}

			else
			{



			}
		}

		//end of enemy attack

		//enemy special attack

		else if (enemymove == 2)
		{

			int enemyhitchance = 50;
			enemychancehit = ((rand() % 100) + 1) - enemychancemodifier;

			if (enemychancehit <= 50)
			{


				playerhealth -= ((rand() % 100) + 1);
				enemyenergy -= 50;

			}

			else
			{



			}
		}

		//end of enemy special attack

		else if (enemymove == 3) {

			if (enemyhealused = 0)
			{

				enemyhealthincrease = enemyenergy / 2;
				enemyhealthincrease += enemyhealth;


				enemyhealused = 1;
			}

			if (enemyhealth > maxHealth)
			{
				enemyhealth = maxHealth;
			}

		}

		else if (enemyhealth == 100)
		{


		}


		else if (playermove == 4)
		{
			enemyrechargerate = 4;
		}

		else if (playermove == 5)
		{
			
			enemyrechargerate = 0.5;
			enemydodgeused = 1;
		}

		if (enemyenergy < 0) {
			enemyenergy = maxEnergy;
		}
		if (enemyhealth < 0) {
			enemyhealth = 0;
		}
		if (playerenergy < 0) {
			playerenergy = maxEnergy;
		}
		if (playerhealth < 0) {
			playerhealth = 0
				;
		}


		std::system("CLS");
		std::cout << "Current Stats:" << std::endl;
		std::cout << "Player Health: " << playerhealth << std::endl;
		std::cout << "Player Energy: " << playerenergy << std::endl;
		std::cout << "Enemy Health: " << enemyhealth << std::endl;
		std::cout << "Enemy Energy: " << enemyenergy << std::endl;

		if (playerhealth == 0)
		{
			break;
		}
		else if (enemyhealth == 0)
		{
			break;
		}
	}
	
	while (playerhealth > 0 || enemyhealth > 0);

	exit;
}
	