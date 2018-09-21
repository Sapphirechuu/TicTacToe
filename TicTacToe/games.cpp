//games.h header file
#include "games.h"

//iostream
#include <iostream>

//dialogue.h header file
#include "dialogue.h"

#include <cstdlib>

//Right after selecting one player
void onePlayerGameStart()
{
	//Starting values of the array (an empty game board)
	int startVals[] = { 0,0,0,0,0,0,0,0,0 };
	//Prints words in " "
	std::cout << "You have selected a one player game against the computer." << std::endl;
	//board setup function - Shows how the board is showed up in relation to the spots and numbers the user will use
	boardSetup();
	//Prints words in " "
	std::cout << "As the user, you have the first move. " << std::endl;
	//Takes player 1 input. Uses starting values and "true" bool means it is a one player game against the computer
	p1Move(startVals, true);

}
//After selecting two players
void twoPlayerGameStart()
{
	//Starting values of the array (an empty game board)
	int startVals[] = { 0,0,0,0,0,0,0,0,0 };
	//Prints words in " "
	std::cout << "You have selected a two player game." << std::endl;
	//board setup function - Shows how the board is showed up in relation to the spots and numbers the user will use
	boardSetup();
	//Prints words in " "
	std::cout << "Player one, you have the first move." << std::endl;
	//Takes player 1 input. Uses starting values and "false" bool means that it is a game against another player
	p1Move(startVals, false);
}

/*Adds the users mark into the chosen spot. 
(int addVals = a holder for the games current values [the game array with the board data,
int x = a placeholder value determinded in the checkValid function where the number inputted by the user is validated,
int turn = which players turn it is (1 = player 1, 2 = player 2)
bool comGame = true if playing a one player game against the computer)*/
void addSpot(int addVals[], int x, int turn, bool comGame)
{
	
	//Place holder array for the updated data
	int updatedVals[] = { 0,0,0,0,0,0,0,0,0 };
	//Makes the new array (updatedVals[]) equal to the addVals array (the current game array)
	for (int i = 0; i < 9; i++)
	{
		updatedVals[i] = addVals[i];
	}
	//puts a "1", if player 1, or a "2", if player 2, in the space the user has chosen
	updatedVals[x - 1] = turn;
	//Displays the updated game board
	gameBoardDisp(updatedVals);
	//checks if the win condition has been met
	checkWin(updatedVals, turn, comGame);
}
//A.I. that randomly will select an unused spot to fill. No difficulty or strategy used
void comMove(int values[], bool com)
{
	//Initializes Random integer
	int randNum = (rand() % 9);
	//Checks to make sure the integer is valid (the space is empty) before adding it to the data
	checkValid(values, "", 9, 2, com, false, randNum);
}
/*Player 1 move.
(int values = the game board values in the array,
bool com = tells whether or not this is a one player game against the computer or not*/
void p1Move(int values[], bool com)
{
	//Prints what's in " "
	std::cout << "Player one, it's your turn. Here's a look at the board: " << std::endl;
	//Displays the current game board
	gameBoardDisp(values);
	//Checks and validates the users input
	checkValid(values, "P1: Where would you like to put your marker?", 9, 1, com, false, 0);
}
/*Player 2 move.
(int values = the game board values in the array)*/
void p2Move(int values[])
{
	//Prints what's in " "
	std::cout << "Player two, it's your turn. Here's a look at the board: " << std::endl;
	//Displays the current game board
	gameBoardDisp(values);
	//Checks and validates the users input
	checkValid(values, "P2: Where would you like to put your marker?", 9, 2, false, false, 0);
}
/*Checks if the win condition has been met
(int updatedWinVals[] = the updated game values,
int turn = who's turn it is (1 or 2),
bool comGame = whether or not it's a game against the computer*/
void checkWin(int updatedWinVals[], int turn, bool comGame)
{
	//True when a player wins, false until then
	bool p1Winner = false;
	bool p2Winner = false;
	bool tie = false;

	//Do While there is no winner
	do
	{
		/*if any of these sequences:
		X X X 
		     
			 ,
		X    
		  X  
		    X,
		X     
		X
		X    .
		happen for either player AND those vaules have something in them (are not 0)*/
		if (((((updatedWinVals[0] == updatedWinVals[1]) && (updatedWinVals[0] == updatedWinVals[2])) &&
			((updatedWinVals[0] != 0) &&
			 (updatedWinVals[1] != 0) &&
			 (updatedWinVals[2] != 0))) ||
			(((updatedWinVals[0] == updatedWinVals[4]) && (updatedWinVals[0] == updatedWinVals[8])) &&
			((updatedWinVals[0] != 0) &&
			 (updatedWinVals[4] != 0) &&
			 (updatedWinVals[8] != 0)))) ||
			((updatedWinVals[0] == updatedWinVals[3] && (updatedWinVals[0] == updatedWinVals[6])) && 
			((updatedWinVals[0] != 0) &&
			 (updatedWinVals[3] != 0) &&
			 (updatedWinVals[6] != 0))))
			
		{
			//THEN (depending on player turn) there is a winner. Winner bool changes to true and it prints "Winner" then breaks the loop.
			if (turn == 1)
			{
				std::cout << "Winner" << std::endl;
				p1Winner = true;
				break;
			}
			else if (turn == 2)
			{
				std::cout << "Winner" << std::endl;
				p2Winner = true;
				break;
			}
		}
		/*If this sequence:
		
		X X X
		     .
		happens for either player*/
		if ((((updatedWinVals[3] == updatedWinVals[4]) && (updatedWinVals[5] == updatedWinVals[3]))) &&
			((updatedWinVals[3] != 0) &&
			 (updatedWinVals[4] != 0) &&
			 (updatedWinVals[5] != 0)))
		{
			//Then there is a winner. Winner bool changes to true and it prints "Winner" then breaks the loop.
			if (turn == 1)
			{
				std::cout << "Winner" << std::endl;
				p1Winner = true;
				break;
			}
			else if (turn == 2)
			{
				std::cout << "Winner" << std::endl;
				p2Winner = true;
				break;
			}
		}
		/*If this sequence:
		
		
		X X X.
		happens for either player*/
		if (((((updatedWinVals[6] == updatedWinVals[7]) && (updatedWinVals[6] == updatedWinVals[8]))) &&
			((updatedWinVals[6] != 0) &&
			 (updatedWinVals[7] != 0) &&
			 (updatedWinVals[8] != 0))))
		{
			//Then there is a winner. Winner bool changes to true and it prints "Winner" then breaks the loop.
			if (turn == 1)
			{
				std::cout << "Winner" << std::endl;
				p1Winner = true;
				break;
			}
			else if (turn == 2)
			{
				std::cout << "Winner" << std::endl;
				p2Winner = true;
				break;
			}
		}
		/*If either of these sequences:
		    X 
		  X  
		X    ,
		    X
			X
			X.
		happen for either player*/
		if ((((updatedWinVals[2] == updatedWinVals[4]) && (updatedWinVals[6] == updatedWinVals[2])) &&
			((updatedWinVals[2] != 0) &&
			(updatedWinVals[4] != 0) &&
			(updatedWinVals[6] != 0))) ||
			((updatedWinVals[2] == updatedWinVals[5]) && (updatedWinVals[8] == updatedWinVals[2]) &&
			((updatedWinVals[2] != 0) &&
			(updatedWinVals[5] != 0) &&
			(updatedWinVals[8] != 0))))
		{
			//Then there is a winner. Winner bool changes to true and it prints "Winner" then breaks the loop.
			if (turn == 1)
			{
				std::cout << "Winner" << std::endl;
				p1Winner = true;
				break;
			}
			else if (turn == 2)
			{
				std::cout << "Winner" << std::endl;
				p2Winner = true;
				break;
			}
		}
		/*If this sequence:
		  X
		  X
		  X  .
		happens for either player*/
		if (((updatedWinVals[1] == updatedWinVals[4]) && (updatedWinVals[1] == updatedWinVals[7])) &&
			((updatedWinVals[1] != 0) &&
			 (updatedWinVals[4] != 0) &&
			 (updatedWinVals[7] != 0)))
		{
			//Then there is a winner. Winner bool changes to true and it prints "Winner" then breaks the loop.
			if (turn == 1)
			{
				std::cout << "Winner" << std::endl;
				p1Winner = true;
				break;
			}
			else if (turn == 2)
			{
				std::cout << "Winner" << std::endl;
				p2Winner = true;
				break;
			}
		}
		if (updatedWinVals[0] != 0 &&
			updatedWinVals[1] != 0 &&
			updatedWinVals[2] != 0 &&
			updatedWinVals[3] != 0 &&
			updatedWinVals[4] != 0 &&
			updatedWinVals[5] != 0 &&
			updatedWinVals[6] != 0 &&
			updatedWinVals[7] != 0 &&
			updatedWinVals[8] != 0)
		{
			tie = true;
			break;
		}
		//If there are no winners (none of the conditions above are valid other than the do-while loop) then this keeps the game moving
		keepGameMoving(updatedWinVals, turn, comGame, false);

	}while ((!p1Winner && !p2Winner) && !true);

	//Print the game results
	std::cout << "P1: " << p1Winner << std::endl;
	std::cout << "P2: " << p2Winner << std::endl;
	//"Restart" user prompt
	restart();
}

/*Keeps the game moving (from stopping midway)
(int updValues[] = updated game values for the game board,
int turn = who's turn,
bool comGame = if it's a game against the computer or not,
bool quit = if the user has decided to quit the game rather than restart.*/
void keepGameMoving(int updValues[], int turn, bool comGame, bool quit)
{
	if ((turn == 1) && (comGame == false))
	{
		p2Move(updValues);
	}
	else if ((turn == 2) && (comGame == false))
	{
		p1Move(updValues, comGame);
	}
	else if (turn == 1 && comGame == true)
	{
		std::cout << "It's the computer's turn now." << std::endl;
		comMove(updValues, comGame);
	}
	else if (turn == 2 && comGame == true)
	{
		p1Move(updValues, comGame);
	}
}