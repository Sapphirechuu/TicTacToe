#pragma once
//Needed for string
#include <iostream>
//Game startup function. First function after Welcome
void gameStartup();
//Displays the game board
void gameBoardDisp(int dispVal[]);
//Tells the user that their input was invalid
void invalidIn(int valVals[], std::string dia, int a, int turn, bool comGame, bool restart, int ran);
//Shows the user the setup of the board in relation with the keyboard
void boardSetup();
//Checks and validated the users input
void checkValid(int valVals[], std::string dia, int a, int turn, bool comGame, bool restart, int ran);
//Restarts the game
void restart();