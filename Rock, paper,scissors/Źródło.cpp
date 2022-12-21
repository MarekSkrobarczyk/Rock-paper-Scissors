#include<iostream>
#include <cstdlib>
#include <ctime>
#include <string>


void mainTitle()
{
	std::cout << " Welcome to the game, Rock, Paper, Scissors ! \n\n";
	std::cout << " Choose one of the options: \n\n"
		<< " 1. Play ! !!! \n"
		<< " 2. WTF ?! - Instruction \n"
		<< " 3. Quit :( \n";

}

void instruction()
{
	char backToMenu;

	do {


		std::cout << " Seriously ? You really don't know the rules of this game? Okay... \n\n"

			<< " 1. A stone crushes scissors \n 2. Paper Crushes Stone\n"
			<< " 3. Scissors split the paper \n 4. Beer beats everyone \n\n";
		std::cout << " Press Q to return to main menu ";
		std::cin >> backToMenu;
	} while ((backToMenu != 'q') || (backToMenu != 'Q'));

	
	
}

bool gamePlayLogic(int player, int enemy)
{
	if ((player == 0 && enemy == 2) || (player == 1 && enemy == 0) || (player == 2 && enemy == 1) || (player == 3)) // Win conditions
	{
		std::cout << " You have won this round \n";
			
		if (player == 3 && enemy == 3)
		{
			std::cout << " You both have beer, so there is no losers"; // 0 = kamien, 1 papier, 2 nozyce, 3 piwo
		}
		return true;
	}

	else if (player == enemy)
	{
		std::cout << " \n We're tied, no point !";
		return true;
	}

	else
	{
		std::cout << " You loose :( Shit happens ";

	return false;
	}
}

void Play()
{
	short menuChoose;
	short playerChoose;
	short pointsPlayer = 0;
	short pointsEnemy = 0;
	mainTitle();


	std::cin >> menuChoose;

	switch (menuChoose)
	{
	case 1:
	{

		bool resault;

		//enum class Players { rock = 1, paper, Scissors, beer = 4 };

		do
		{
			srand(time(NULL));
			int number = (rand() % 4);
			std::string enemyChoose[]{ "Rock", "Paper", "Scissors", "Beer" };

			std::cout << " We play best of three, what do you choose? \n"
				<< " 1. Rock \n 2. Paper\n 3. Scissors\n 4. Beer \n\n";

			std::cin >> playerChoose;

			std::cout << "You chose a " << enemyChoose[playerChoose - 1] << " your opponent chose " << enemyChoose[number] << std::endl;

			resault = gamePlayLogic((playerChoose - 1), number);
			if ((resault == true) && (playerChoose - 1 != number))
			{
				pointsPlayer += 1;
			}

			else if ((resault == false) && (playerChoose - 1 != number))
			{
				pointsEnemy += 1;
			}

			std::cout << "\n\n\n\n player: " << pointsPlayer << " enemy:" << pointsEnemy << std::endl << std::endl;

		} while ((pointsEnemy <= 2) && (pointsPlayer <= 2));



		break;
	}

	case 2:

		instruction();
		break;

		//case 3:

		///	std::cout << " Option not available in demo version. Contact the manufacturer to purchase the full version. ";

	}

}

int main()

{
	Play();
	
	
	

	
}

