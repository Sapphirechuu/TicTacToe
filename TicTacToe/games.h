#pragma once
//!!!MOST DESCRIPTIONS ARE MORE IN DEPTH IN THE CODE FILE RATHER THAN IN THE HEADER FILE!!!
//intro for a 1 player game
void onePlayerGameStart();
//intro for a 2 player game
void twoPlayerGameStart();
//adds the users inputted number into the array and converts it into a "1" or "2" 
void addSpot(int addVals[], int x, int turn, bool comGame);
//computers random move
void comMove(int values[], bool com);
//Player 1's move
void p1Move(int values [], bool com);
//Player 2's move
void p2Move(int values[]);
//Checks the board to make sure there's no winner
void checkWin(int updatedWinVals[], int turn, bool com);
//Keeps the game from just stopping; keeps it moving
void keepGameMoving(int updValues[], int turn, bool com, bool quit);