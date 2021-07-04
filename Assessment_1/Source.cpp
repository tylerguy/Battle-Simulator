#include <iostream>
#include <string>
#include <stdlib.h>    
#include <time.h>
#include<windows.h>


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
int playersecondturn = 0;
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


 //attack variables
 int attackhitchance = 80;
 int sphitchance = 50;

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
		 std::cout << "3) Heal \n";
		 std::cout << "4) Recharge \n";
		 std::cout << "5) Dodge \n";
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

		 while (playersecondturn = 0);
		 {
			 if (playerhealused = 1)
			 {
				 playersecondturn = 1;
				 std::cout << "Second Move: " << std::endl;
				 std::cin >> playermove;
			 }

			 switch (playermove)
			 {
			 case 1:

				 if (enemydodgeused = 1)
				 {

					 playerchancemodifier = -30;

				 }

				 playerhitchance = (rand() % 100 + 1) + playerchancemodifier;

				 if (playerhitchance <= attackhitchance)
				 {

					 std::cout << "You successfully attacked" << std::endl;
					 enemyhealth -= (rand() % 10 + 1);
					 Sleep(200);

				 }

				 else
				 {

					 std::cout << "You Failed your turn" << std::endl;
					 Sleep(200);

				 }

				 break;


			 case 2:

				 if (playerenergy <= 0)
				 {
					 std::cout << "You don't have enough energy to do this move" << std::endl;
					 std::cout << "pls choose another option" << std::endl;
					 Sleep(200);
					 std::cin >> playermove;

				 }


				 else {

					 playerhitchance = ((rand() % 100) + 1) - playerchancemodifier;

					 if (playerhitchance <= sphitchance)
					 {
						 if (playerenergy <= 0)
						 {
							 std::cout << "You don't have enough energy to do this move" << std::endl;
							 std::cout << "pls choose another option" << std::endl;
							 Sleep(200);
							 std::cin >> playermove;

						 }
						 else
						 {
							 std::cout << "You successfully attacked" << std::endl;
							 enemyhealth -= ((rand() % 20) + 1);
							 playerenergy -= 50;
							 Sleep(200);
						 }
					 }
				 }

				 if (playerhitchance > sphitchance)
				 {

					 std::cout << "You Failed your turn" << std::endl;
					 Sleep(200);

				 }
				 break;

			 case 3:
				 if (playerhealused == 1)
				 {
					 std::cout << "You've already healed this turn" << std::endl;
					 Sleep(200);
				 }

				 else if (playerhealth == 100)

				 {
					 std::cout << "You're already at full health" << std::endl;
					 Sleep(200);
				 }

				 else {
					 playerhealthincrease = playerenergy / 2;
					 playerenergy -= playerhealthincrease;
					 playerhealthincrease += playerhealth;

					 std::cout << "You have been healed!" << std::endl;
					 Sleep(200);
					 playerhealused = 1;
				 }


				 if (playerhealth > maxHealth)
				 {
					 playerhealth = maxHealth;
				 }


			 case 4:

				 playerrechargerate = 4;

				 break;

			 case 5:

				 playerrechargerate = 0.5;
				 playerdodgeused = 1;

				 break;

			 default:
				 std::cout << "Invalid Input..." << std::endl;
				 break;
			 }
 
		 }




		 std::cout << "Enemy is Attacking..." << std::endl;
		 Sleep(2000);

		 while (enemyhealused == 0)
		 {
			 enemymove = (rand() % 5 + 1);

			 switch (enemymove) {
			 case 1:

				 enemyhitchance = ((rand() % 100) + 1) - enemychancemodifier;

				 if (enemyhitchance <= attackhitchance)

				 {

					 enemyhealth -= ((rand() % 10) + 1);

				 }
			 case 2:

				 enemyhitchance = ((rand() % 100) + 1) - enemychancemodifier;

				 if (enemyhitchance <= sphitchance)
				 {
					 if (enemyenergy >= 50)
					 {
						 playerhealth -= ((rand() % 20) + 1);
						 enemyenergy -= 50;
					 }
				 }

			 case 3:

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

			 case 4:
				 enemyrechargerate = 4;

			 case 5:
				 enemyrechargerate = 0.5;
				 enemydodgeused = 1;
			 }
			 playersecondturn = 0;
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
			 playerhealth = 0;
		 }

		 if (playerhealth == 0)
		 {
			 break;
		 }
		 else if (enemyhealth == 0)
		 {
			 break;
		 }

		 if (playerhealth = 0) {

			 std::cout << "You Died" << std::endl;
			 Sleep(1000);
		 }
		 else if (enemyhealth = 0)
		 {
			 std::cout << "You Killed the Enemy" << std::endl;
		 }


	 } while (playerhealth > 0 && enemyhealth > 0);

	 exit;
 }
 
		 
	  
 
