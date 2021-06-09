#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Board.h"
#include "Dice.h"
#include "Player.h"
#include "Game.h"


void Game::Options(Board b, Dice d1, Dice d2, Dice d3, Dice d4, Dice d5, int valid[14])
{



	std::cout << "The options are: " << std::endl;


	if (valid[1] == 0)
		std::cout << "(1)One: " << b.One(d1, d2, d3, d4, d5) << std::endl;

	if (valid[2] == 0)
		std::cout << "(2)Two: " << b.Two(d1, d2, d3, d4, d5) << std::endl;
	if (valid[3] == 0)
		std::cout << "(3)Three: " << b.Three(d1, d2, d3, d4, d5) << std::endl;
	if (valid[4] == 0)
		std::cout << "(4)Four: " << b.Four(d1, d2, d3, d4, d5) << std::endl;
	if (valid[5] == 0)
		std::cout << "(5)Five: " << b.Five(d1, d2, d3, d4, d5) << std::endl;
	if (valid[6] == 0)
		std::cout << "(6)Six: " << b.Six(d1, d2, d3, d4, d5) << std::endl;
	if (valid[7] == 0)
		std::cout << "(7)Three of a Kind: " << b.ThreeOfaKind(d1, d2, d3, d4, d5) << std::endl;
	if (valid[8] == 0)
		std::cout << "(8)Four of a kind " << b.FourOfaKind(d1, d2, d3, d4, d5) << std::endl;
	if (valid[9] == 0)
		std::cout << "(9)Full House: " << b.FullHouse(d1, d2, d3, d4, d5) << std::endl;
	if (valid[10] == 0)
		std::cout << "(10)Small Straight: " << b.SmallStraight(d1, d2, d3, d4, d5) << std::endl;
	if (valid[11] == 0)
		std::cout << "(11)Large Straight: " << b.LargeStraight(d1, d2, d3, d4, d5) << std::endl;
	if (valid[12] == 0)
		std::cout << "(12)Yatzhee: " << b.Yatzhee(d1, d2, d3, d4, d5) << std::endl;
	if (valid[13] == 0)
		std::cout << "(13)Chance: " << b.Chance(d1, d2, d3, d4, d5) << std::endl;



}

void Game::Run()
{
	std::cout << "Welcome to Yahtzee!\n\n";
	bool special = true;
	int hint = 5;
	Board board;
	board.SetBoard();
	srand(time(NULL));
	bool gameInProgress = true;
	std::vector<Dice> dices;
	Dice dice;
	std::cout << "Please enter the name of the player ";
	std::string playerName;
	std::getline(std::cin, playerName);
	Player player(playerName);

	std::cout << "Hello " << playerName;
	std::cout << "\n";

	std::cout << "\nThese are the rules of the game:\n\n";

	std::cout << "To begin with, roll all the dices.\n";
	std::cout << "After that, you can either score the current roll (as seen below), or re-roll whichever dices you prefer.\n";
	std::cout << "Each turn consists of a maximum of three rolls.\n";
	std::cout << "Next, you have to decide which dice combo you are going for (it doesn't have to be after the 3rd roll). \n\n";
	std::cout << "You have 5 hints per game that may help you decide your strategy. Use them wiseley.\n\n";


	std::cout << "Are you ready to start the game? yes/no\n\n";
	char checkpoint[30];
	//std::cin.get();
	std::cin.getline(checkpoint, sizeof(checkpoint));
	while (strcmp(checkpoint, "yes") && strcmp(checkpoint, "no")&& strcmp(checkpoint, "YES") && strcmp(checkpoint, "NO"))
	{
		std::cout << "Please choose yes/no!\n";
		std::cin.getline(checkpoint, sizeof(checkpoint));
	}
	int x = 0;
	int cp[14];
	for (int i = 0; i < 14; i++)
		cp[i] = 0;
	if (strcmp(checkpoint, "yes") == NULL)
	{
		bool check1 = false, check2 = false, check3 = false, check4 = false, check5 = false, check6 = false;
		bool check3ok = false, check4ok = false, house = false, smalls = false, larges = false, chance = false, yatz = false;
		bool specialBns = false;

		do {
			for (int step = 0; step < 13; step++)
			{
				bool hinturi = true;
				bool roll = true;
				std::cout << "Your score is: " << player.getScore() << std::endl;
				for (auto i = 0; i < 5; i++)
					dices.push_back(dice.Roll());
				for (int i = 0; i < dices.size(); i++)
					dices[i].PrintDice(dices[i]), dices[i].Kept(false);
			
				if (hint != 0)
				{
					std::cout << "Do you need a hint?\n";
					std::cout << "Chose yes/no\n";

					char msg[10];

					std::cin.getline(msg, 10);
					while (strcmp(msg, "yes") && strcmp(msg, "no") && strcmp(msg, "YES") && strcmp(msg, "NO"))
					{
						std::cout << "Please Choose yes/no!\n";
						std::cin.getline(msg, sizeof(msg));
					}


					if (strcmp(msg, "no") == 0)
					{
						hinturi == false;
					}
					if (strcmp(msg, "yes") == 0 || strcmp(msg, "YES") == 0)
					{
						board.Hints(dices[0], dices[1], dices[2], dices[3], dices[4], roll);
						hinturi == false;
						hint--;
					}
				}

				Options(board, dices[0], dices[1], dices[2], dices[3], dices[4], cp);

				std::cout << "Roll again? yes/no! \n";

				char checkpoint[30];
				fflush;
				std::cin.getline(checkpoint, sizeof(checkpoint));
				while (strcmp(checkpoint, "yes") && strcmp(checkpoint, "no") && strcmp(checkpoint, "YES") && strcmp(checkpoint, "NO"))
				{
					std::cout << "Please Choose yes/no!\n";
					std::cin.getline(checkpoint, sizeof(checkpoint));
				}
				bool no = false;

				if (strcmp(checkpoint, "yes") == 0)
					for (int j = 0; j < 2; j++)
					{
						char a[20];
						int aa = -1;
						std::cout << "How many dices do you want to keep?\n";
						while (aa < 0 || aa>5)
						{
							aa = 0;
							std::cin.getline(a, sizeof(a));
							for (int i = 0; i < strlen(a); i++)
								if (!isdigit(a[i]))
								{
									std::cout << "Insert an integer!\n";
									fflush;
									std::cin.getline(a, sizeof(a));
									i = -1;
								}
							for (int i = 0; i < strlen(a); i++)
								aa = (a[i] - '0') + aa * 10;
							if (aa > 5)
								std::cout << "Insert a value between 0 and 5!\n";
						}
						std::cout << "List the kept dices:\n";
						for (int i = 0; i < aa; i++)
						{
							int x = -1;
							while (x < 1 || x>5)
							{
								x = 0;
								std::cin.getline(a, sizeof(a));
								for (int i = 0; i < strlen(a); i++)
									if (!isdigit(a[i]))
									{
										std::cout << "Insert an integer!\n";
										fflush;
										std::cin.getline(a, sizeof(a));
										i = -1;
									}
								for (int i = 0; i < strlen(a); i++)
									x = (a[i] - '0') + x * 10;
								if (x < 1 || x>5)
									std::cout << "Insert a number between 1 and 5!\n";
							}
							switch (x)
							{
							case 1:
								dices[--x].Kept(true);
								break;
							case 2:
								dices[--x].Kept(true);
								break;
							case 3:
								dices[--x].Kept(true);
								break;
							case 4:
								dices[--x].Kept(true);
								break;
							case 5:
								dices[--x].Kept(true);
								break;
							default:
								break;
							}
							x++;
							board.Keyboard(x, dices[0], dices[1], dices[2], dices[3], dices[4]);
						}
						for (int i = 0; i < 5; i++)
							if (dices[i].IsKept() == 0)
								dices[i] = dices[i].Roll();
						for (int i = 0; i < dices.size(); i++)
							dices[i].PrintDice(dices[i]), dices[i].Kept(false);
						if (j < 1)
						{

							if (hint != 0)
							{
								std::cout << "Do you need a hint?\n";
								std::cout << "Chose yes/no\n";

								char msg[10];

								std::cin.getline(msg, 10);
								while (strcmp(msg, "yes") && strcmp(msg, "no"))
								{
									std::cout << "Please Choose yes/no!\n";
									std::cin.getline(msg, sizeof(msg));
								}


								if (strcmp(msg, "no") == 0)
								{
									hinturi = false;

								}
								if (strcmp(msg, "yes") == 0 || strcmp(msg, "YES") == 0)
								{
									board.Hints(dices[0], dices[1], dices[2], dices[3], dices[4], false);
									hint--;

								}

							}


							Options(board, dices[0], dices[1], dices[2], dices[3], dices[4], cp);

							std::cout << "Roll again? yes/no! \n";
							char checkpoint[30];
							std::cin.getline(checkpoint, sizeof(checkpoint));
							while (strcmp(checkpoint, "yes") != 0 && strcmp(checkpoint, "no") != 0)
							{
								std::cout << "Please Choose yes/no!\n";
								std::cin.getline(checkpoint, sizeof(checkpoint));
							}
							if (strcmp(checkpoint, "no") == 0)
							{

								no = true;
								break;
							}
						}
					}
				else
				{
					no = true;
					hinturi = false;
				}

				if (no == false)
				{
					
					Options(board, dices[0], dices[1], dices[2], dices[3], dices[4], cp);
					if (hint != 0 )
					{
						std::cout << "Do you need a hint?\n";
						std::cout << "Choose yes/no\n";

						char msg[10];

						std::cin.getline(msg, 10);
						while (strcmp(msg, "yes") && strcmp(msg, "no"))
						{
							std::cout << "Please Choose yes/no!\n";
							std::cin.getline(msg, sizeof(msg));
						}


						if (strcmp(msg, "no") == 0)
						{
							

						}
						if (strcmp(msg, "yes") == 0 || strcmp(msg, "YES") == 0)
						{
							board.Hints(dices[0], dices[1], dices[2], dices[3], dices[4], false);
							hint--;

						}

					}

					hinturi = false;
				}

				if (board.CheckYatzhe() == true)
					player.setScore(100);

				if (hint != 0 && hinturi == true)
				{
					std::cout << "Do you need a hint?\n";
					std::cout << "Choose yes/no\n";

					char msg[10];

					std::cin.getline(msg, 10);
					while (strcmp(msg, "yes") && strcmp(msg, "no"))
					{
						std::cout << "Please choose yes/no!\n";
						std::cin.getline(msg, sizeof(msg));
					}


					if (strcmp(msg, "no") == 0)
					{
						hinturi = false;
					}
					if (strcmp(msg, "yes") == 0)
					{
						board.Hints(dices[0], dices[1], dices[2], dices[3], dices[4], false);
						hint--;
					}

				}

				std::cout << "Choose the option!\n";
				char function[3];
				int optiune;

				bool ok_Optiune = true;
				do
				{
					char check[25];
					std::cin.getline(check, 25);
					for (int i = 0; i < strlen(check); i++)
					{
						if (!isdigit(check[i]))
						{
							std::cout << "Please enter an integer!\n";
							fflush;
							std::cin.getline(check, sizeof(check));

							i = -1;
						}
					}
					optiune = 0;

					for (int i = 0; i < strlen(check); i++)
					{
						optiune = (check[i] - '0') + optiune * 10;
					}

					while (optiune < 1 || optiune>13)
					{
						std::cout << "Insert a valid option!\n";
						std::cin.getline(check, 25);
						for (int i = 0; i < strlen(check); i++)
						{
							if (!isdigit(check[i]))
							{
								std::cout << "Please enter an integer!\n";
								fflush;
								std::cin.getline(check, sizeof(check));

								i = -1;
							}
						}
						optiune = 0;
						for (int i = 0; i < strlen(check); i++)
						{
							optiune = (check[i] - '0') + optiune * 10;
						}
					}

					if (optiune == 1 && check1 == true)
					{
						ok_Optiune = true;
						std::cout << "You can't choose this column because it was previously chosen.Please choose another one" << std::endl;
					}
					else if (optiune == 2 && check2 == true)
					{
						ok_Optiune = true;
						std::cout << "You can't choose this column because it was previously chosen.Please choose another one" << std::endl;
					}
					else if (optiune == 3 && check3 == true)
					{
						ok_Optiune = true;
						std::cout << "You can't choose this column because it was previously chosen.Please choose another one" << std::endl;
					}
					else if (optiune == 4 && check4 == true)
					{
						ok_Optiune = true;
						std::cout << "You can't choose this column because it was previously chosen.Please choose another one" << std::endl;
					}
					else if (optiune == 5 && check5 == true)
					{
						ok_Optiune = true;
						std::cout << "You can't choose this column because it was previously chosen.Please choose another one" << std::endl;
					}
					else if (optiune == 6 && check6 == true)
					{
						ok_Optiune = true;
						std::cout << "You can't choose this column because it was previously chosen.Please choose another one" << std::endl;
					}
					else if (optiune == 7 && check3ok == true)
					{
						ok_Optiune = true;
						std::cout << "You can't choose this column because it was previously chosen.Please choose another one" << std::endl;
					}
					else if (optiune == 8 && check4ok == true)
					{
						ok_Optiune = true;
						std::cout << "You can't choose this column because it was previously chosen.Please choose another one" << std::endl;
					}
					else if (optiune == 9 && house == true)
					{
						ok_Optiune = true;
						std::cout << "You can't choose this column because it was previously chosen.Please choose another one" << std::endl;
					}
					else if (optiune == 10 && smalls == true)
					{
						ok_Optiune = true;
						std::cout << "You can't choose this column because it was previously chosen.Please choose another one" << std::endl;
					}
					else if (optiune == 11 && larges == true)
					{
						ok_Optiune = true;
						std::cout << "You can't choose this column because it was previously chosen.Please choose another one" << std::endl;
					}
					else if (optiune == 12 && yatz == true)
					{
						ok_Optiune = true;
						std::cout << "You can't choose this column because it was previously chosen.Please choose another one" << std::endl;
					}
					else if (optiune == 13 && chance == true)
					{
						ok_Optiune = true;
						std::cout << "You can't choose this column because it was previously chosen.Please choose another one" << std::endl;
					}
					else ok_Optiune = false;

				} while (ok_Optiune == true);

				if (optiune == 1)
				{
					player.setScore(board.One(dices[0], dices[1], dices[2], dices[3], dices[4]));
					check1 = true;
					player.setSpecialScore(board.One(dices[0], dices[1], dices[2], dices[3], dices[4]));
					if (specialBns == false)
					{
						if (player.Special_Bonus() == true)
						{
							board.SetSpecial();
							board.Elemente(1, dices[0], dices[1], dices[2], dices[3], dices[4]);
							specialBns = true;
						}

						else
						{

							board.Elemente(1, dices[0], dices[1], dices[2], dices[3], dices[4]);
							std::cout << "Your special bonus could not be delivered this round. Keep going !" << std::endl;
						}
					}
					else board.Elemente(1, dices[0], dices[1], dices[2], dices[3], dices[4]);

				}

				else if (optiune == 2)
				{
					player.setScore(board.Two(dices[0], dices[1], dices[2], dices[3], dices[4]));
					check2 = true;
					player.setSpecialScore(board.Two(dices[0], dices[1], dices[2], dices[3], dices[4]));
					if (specialBns == false)
					{
						if (player.Special_Bonus() == true)
						{
							board.SetSpecial();
							board.Elemente(2, dices[0], dices[1], dices[2], dices[3], dices[4]);
							specialBns = true;
						}


						else
						{

							board.Elemente(2, dices[0], dices[1], dices[2], dices[3], dices[4]);
							std::cout << "Your special bonus could not be delivered this round. Keep going !" << std::endl;
						}
					}
					else board.Elemente(2, dices[0], dices[1], dices[2], dices[3], dices[4]);


				}

				else if (optiune == 3)
				{
					player.setScore(board.Three(dices[0], dices[1], dices[2], dices[3], dices[4]));
					check3 = true;
					player.setSpecialScore(board.Three(dices[0], dices[1], dices[2], dices[3], dices[4]));
					if (specialBns == false)
					{
						if (player.Special_Bonus() == true)
						{
							board.SetSpecial();
							board.Elemente(3, dices[0], dices[1], dices[2], dices[3], dices[4]);
							specialBns = true;
						}


						else
						{

							board.Elemente(3, dices[0], dices[1], dices[2], dices[3], dices[4]);
							std::cout << "Your special bonus could not be delivered this round. Keep going !" << std::endl;
						}
					}
					else board.Elemente(3, dices[0], dices[1], dices[2], dices[3], dices[4]);


				}

				else if (optiune == 4)
				{
					player.setScore(board.Four(dices[0], dices[1], dices[2], dices[3], dices[4]));
					check4 = true;
					player.setSpecialScore(board.Four(dices[0], dices[1], dices[2], dices[3], dices[4]));
					if (specialBns == false)
					{
						if (player.Special_Bonus() == true)
						{
							board.SetSpecial();
							board.Elemente(4, dices[0], dices[1], dices[2], dices[3], dices[4]);
							specialBns = true;
						}


						else
						{

							board.Elemente(4, dices[0], dices[1], dices[2], dices[3], dices[4]);
							std::cout << "Your special bonus could not be delivered this round. Keep going !" << std::endl;
						}
					}
					else board.Elemente(4, dices[0], dices[1], dices[2], dices[3], dices[4]);


				}

				else if (optiune == 5)
				{
					player.setScore(board.Five(dices[0], dices[1], dices[2], dices[3], dices[4]));
					check5 = true;
					player.setSpecialScore(board.Five(dices[0], dices[1], dices[2], dices[3], dices[4]));
					if (specialBns == false)
					{
						if (player.Special_Bonus() == true)
						{
							board.SetSpecial();
							board.Elemente(5, dices[0], dices[1], dices[2], dices[3], dices[4]);
							specialBns = true;
						}


						else
						{

							board.Elemente(5, dices[0], dices[1], dices[2], dices[3], dices[4]);
							std::cout << "Your special bonus could not be delivered this round. Keep going !" << std::endl;
						}
					}
					else board.Elemente(5, dices[0], dices[1], dices[2], dices[3], dices[4]);


				}

				else if (optiune == 6)
				{
					player.setScore(board.Six(dices[0], dices[1], dices[2], dices[3], dices[4]));

					check6 = true;
					player.setSpecialScore(board.Six(dices[0], dices[1], dices[2], dices[3], dices[4]));
					if (specialBns == false)
					{
						if (player.Special_Bonus() == true)
						{
							board.SetSpecial();
							board.Elemente(6, dices[0], dices[1], dices[2], dices[3], dices[4]);
							specialBns = true;
						}


						else
						{

							board.Elemente(6, dices[0], dices[1], dices[2], dices[3], dices[4]);
							std::cout << "Your special bonus could not be delivered this round. Keep going !" << std::endl;
						}
					}
					else board.Elemente(6, dices[0], dices[1], dices[2], dices[3], dices[4]);

				}

				else if (optiune == 7)
				{
					player.setScore(board.ThreeOfaKind(dices[0], dices[1], dices[2], dices[3], dices[4]));
					board.Elemente(7, dices[0], dices[1], dices[2], dices[3], dices[4]);
					check3ok = true;
				}

				else if (optiune == 8)
				{
					player.setScore(board.FourOfaKind(dices[0], dices[1], dices[2], dices[3], dices[4]));
					board.Elemente(8, dices[0], dices[1], dices[2], dices[3], dices[4]);
					check4ok = true;
				}

				else if (optiune == 9)
				{
					player.setScore(board.FullHouse(dices[0], dices[1], dices[2], dices[3], dices[4]));
					board.Elemente(9, dices[0], dices[1], dices[2], dices[3], dices[4]);
					house = true;
				}

				else if (optiune == 10)
				{
					player.setScore(board.SmallStraight(dices[0], dices[1], dices[2], dices[3], dices[4]));
					board.Elemente(10, dices[0], dices[1], dices[2], dices[3], dices[4]);
					smalls = true;
				}

				else if (optiune == 11)
				{
					player.setScore(board.LargeStraight(dices[0], dices[1], dices[2], dices[3], dices[4]));
					board.Elemente(11, dices[0], dices[1], dices[2], dices[3], dices[4]);
					larges = true;
				}

				else if (optiune == 12)
				{
					player.setScore(board.Yatzhee(dices[0], dices[1], dices[2], dices[3], dices[4]));
					board.Elemente(12, dices[0], dices[1], dices[2], dices[3], dices[4]);
					yatz = true;
				}

				else if (optiune == 13)
				{
					player.setScore(board.Chance(dices[0], dices[1], dices[2], dices[3], dices[4]));
					board.Elemente(13, dices[0], dices[1], dices[2], dices[3], dices[4]);
					chance = true;
				}

				if (check1 == true && check2 == true && check3 == true && check4 == true && check5 == true && check6 == true)
					player.Special_Bonus();

				dices.clear();

				x = optiune;
				cp[x] = 1;

			}
			gameInProgress = false;
		} while (gameInProgress);
		std::cout << "Your score is: " << player.getScore() << " .Good job! xD" << std::endl;
	}
	else
	{
		std::cout << "Next time, maybe :(.\n";
	}

	std::fstream f("Highscore.txt");
	int highScore;
	f >> highScore;
	if (highScore < player.getScore())
	{
		f.close();
		std::fstream f("Highscore.txt");
		f << playerName << " ";
		f << player.getScore() << " ";
		time_t result = time(NULL);
		char str[26];
		ctime_s(str, sizeof str, &result);
		f << str;

	}
	std::ofstream history;
	history.open("GameHistory.txt", std::ofstream::out | std::ofstream::app);
	history << playerName << " ";
	history << player.getScore() << " ";
	time_t result = time(NULL);
	char str[26];
	ctime_s(str, sizeof str, &result);
	history << str;

	history.close();
	f.close();

}