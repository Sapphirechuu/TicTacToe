//iostream
#include <iostream>
//includes the diaglogue header file
#include "dialogue.h"
//ctime is used for making the seed. Uses the current real world time
#include <ctime>

//Main function
int main()
{
	//Initializes the "seed" for the random number generator. This ensures the same sequence won't repeat each time the game is executed
	srand(time(NULL));
	//Prints "Welcome" message
	std::cout << "Welcome to Tic Tac Toe! \n\nRefer to the README document for instructions and rules.\n" << std::endl;
	while (true)
	{
		//Goes to gameStartup function where it will take the rest of the game
		gameStartup();
	}
	//Quits the game
	return 0;
}