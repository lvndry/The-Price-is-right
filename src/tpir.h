/*** 
	 The price is right
     Author : Monga Landry 
	 August 2017 
***/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#define LEVEL1 100
#define LEVEL2 200
#define LEVEL3 300
#define LEVEL4 400
#define LEVEL5 500
#define LEVEL6 600
#define LEVEL7 700
#define LEVEL8 800
#define LEVEL9 900
#define LEVEL10 1000

#define MIN 1

int available(int random);	//Check if number has never been used before
int chooseMode();	//Choose game mode solo or duo
int game(int random);	//Launch the game
int getAletNumber(int MAX); 
int getRandom(int mode);	//Returns a number depending on the mode
int isBestScore(int max);
int level();	//returns the chosen level
int max(int level); //returns max value depending on the level
void printBestScores();	//print all best scores
void putNum(int random);	 //Makes a number unavailabe for next times
void registerScore(char *name, int score);	 //register a new best score
