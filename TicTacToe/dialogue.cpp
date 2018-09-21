//includes the diaglogue.h header file
#include "dialogue.h"
//includes the games.h header file
#include "games.h"
//iostream
#include <iostream>
//uses limits
#include <limits>
//uses strings (primarly used for printing strings in this code
#include <string>

//GameStartup function
void gameStartup()
{
	//Takes and validates the users input.
	checkValid(0,"Would you like to play a one or two player game?", 2, 0, false, false, 0);
}
//Displays the gameboard (int dispVal[] = the game data being displayed
void gameBoardDisp(int dispVal[])
{
	//This displays the current game board at any given state. Repeats 3 times. One for each row.
	for (int i = 0; i < 9; i += 3)
	{
		//Placeholders for the temp Values that will be printed
		std::string temp1 = " ";
		std::string temp2 = " ";
		std::string temp3 = " ";
		//If value at [index] is 0, the value shown is "-"
		if (dispVal[i] == 0)
		{
			temp1 = std::to_string(dispVal[i]);
			temp1 = "-";
		}
		//If value is 1, this means player one has used that spot, value shown is "X"
		else if (dispVal[i] == 1)
		{
			temp1 = std::to_string(dispVal[i]);
			temp1 = "X";
		}
		//If value is 2, this means player two has used that spot, value shown is "O"
		else if (dispVal[i] == 2)
		{
			temp1 = std::to_string(dispVal[i]);
			temp1 = "O";
		}
		//If value at [index] is 0, the value shown is "-"
		if (dispVal[i + 1] == 0)
		{
			temp2 = std::to_string(dispVal[i + 1]);
			temp2 = "-";
		}
		//If value is 1, this means player one has used that spot, value shown is "X"
		else if (dispVal[i + 1] == 1)
		{
			temp2 = std::to_string(dispVal[i + 1]);
			temp2 = "X";
		}
		//If value is 2, this means player two has used that spot, value shown is "O"
		else if (dispVal[i + 1] == 2)
		{
			temp2 = std::to_string(dispVal[i + 1]);
			temp2 = "O";
		}
		//If value at [index] is 0, the value shown is "-"
		if (dispVal[i + 2] == 0)
		{
			temp3 = std::to_string(dispVal[i + 2]);
			temp3 = "-";
		}
		//If value is 1, this means player one has used that spot, value shown is "X"
		else if (dispVal[i + 2] == 1)
		{
			temp3 = std::to_string(dispVal[i + 2]);
			temp3 = "X";
		}
		//If value is 2, this means player two has used that spot, value shown is "O"
		else if (dispVal[i + 2] == 2)
		{
			temp3 = std::to_string(dispVal[i + 2]);
			temp3 = "O";
		}

		std::cout << temp1 << temp2 << temp3 << std::endl;
	}
}
//Tells when the input is invalid and redirects back to the proper function
void invalidIn(int valVals[], std::string dia, int a, int turn, bool comGame, bool restart, int ran)
{
	//If it is a 1 player game and is the computer's turn, it will return to the comMove function for it to choose a new number
	if (comGame && (turn == 2))
	{
		//Returns to comMove function
		comMove(valVals, comGame);
	}
	//Tells user that the input was invalid
	std::cout << "I'm sorry, that was not a valid response. Please try again." << std::endl;
	//Rechecks new input
	checkValid(valVals, dia, a, turn, comGame, restart, ran);
}
//Shows initial board setup
void boardSetup()
{
	std::cout << "The gameboard will be setup like this: \n7	8	9\n\n4	5	6\n\n1	2	3" << std::endl;
}
//Checks if user input and computer input is valid and in an empty space
void checkValid(int valVals[], std::string dia, int a, int turn, bool comGame, bool restart, int ran)
{
	//If it is either Player 1 (the user) or a two player game
	if ((comGame == true && (turn == 1 || turn == 0)) || (comGame == false && turn == 2) || (comGame == false && (turn == 1 || turn == 0)))
	{
		//Declares x which is input
		int x;
		//Declares valid Bool
		bool valid = false;
		//Do this while valid is false
		do
		{
			//Prints dia (dialogue) given when function was called.
			std::cout << dia << std::endl;
			//Take user input
			std::cin >> x;
			//Checks if the input is an int
			if (!(valid = std::cin.good()))
			{
				//If not, tells user and clears the error flag to go back to the beginning of the loop. Without clearing error, there would be infinite invalidIn loop
				invalidIn(valVals, dia, a, turn, comGame, restart, ran);
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			}
		} while (!valid);

		//If a is 2. a is an integer declared when calling the function and determines the number of valid options. In this case, 1 and 2 are valid
		if ((a == 2) && (restart == false))
		{
			//if input = 1
			if (x == 1)
			{
				//Start player one game
				onePlayerGameStart();
			}
			//if input = 2
			else if (x == 2)
			{
				//Start two player game
				twoPlayerGameStart();
			}
			//otherwise input is invalid
			else
			{
				invalidIn(valVals, dia, a, turn, comGame, restart, ran);
			}
		}
		//If a is 2 and the game is asking the user whether or not it wants to restart
		else if ((a == 2) && (restart == true))
		{
			//If 1, it will restart
			if (x == 1)
			{
				std::cout << "Restarting..." << std::endl;
				gameStartup();
			}
			//if 2, it will quit
			else if (x == 2)
			{
				exit(1);
			}
			//otherwise input is invalid
			else
			{
				invalidIn(valVals, dia, a, turn, comGame, restart, ran);
			}
		}
		//If a = 9. This is when the user is choosing a spot
		else if (a == 9)
		{
			//If input is not 1-9, it is invalid
			if (!(x == 1 ||
				x == 2 ||
				x == 3 ||
				x == 4 ||
				x == 5 ||
				x == 6 ||
				x == 7 ||
				x == 8 ||
				x == 9))
			{
				invalidIn(valVals, dia, a, turn, comGame, restart, ran);
			}
			//otherwise switch x values (for keyboard setup) and add spot if space is empty
			else
			{
				if (x == 9)
				{
					x = 3;
				}
				else if (x == 8)
				{
					x = 2;
				}
				else if (x == 7)
				{
					x = 1;
				}
				else if (x == 3)
				{
					x = 9;
				}
				else if (x == 2)
				{
					x = 8;
				}
				else if (x == 1)
				{
					x = 7;
				}
				//checks if spot is empty
				if (valVals[x - 1] == 0)
				{
					addSpot(valVals, x, turn, comGame);
				}
				//otherwise, input is invalid
				else
				{
					invalidIn(valVals, dia, a, turn, comGame, restart, ran);
				}
			}
		}
	}
	//If it's the computer's turn in a one player game
	else if ((comGame == true) && (turn == 2))
	{
		//Switches x value (not necesasary in computer input but perferred)
		if (ran == 9)
		{
			ran = 3;
		}
		else if (ran == 8)
		{
			ran = 2;
		}
		else if (ran == 7)
		{
			ran = 1;
		}
		else if (ran == 3)
		{
			ran = 9;
		}
		else if (ran == 2)
		{
			ran = 8;
		}
		else if (ran == 1)
		{
			ran = 7;
		}
		//Checks if spot is empty
		if (valVals[ran - 1] == 0)
		{
			addSpot(valVals, ran, turn, comGame);
		}
		//Otherwise invalid
		else
		{
			invalidIn(valVals, dia, a, turn, comGame, restart, ran);
		}
	}
}
//Asks user if they want to restart game
void restart()
{
	checkValid(0, "Would you like to restart?", 2, 0, false, true, 0);
}
