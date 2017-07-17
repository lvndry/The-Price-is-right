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

#include "tpir.h"

int main(int argc, char const *argv[])
{
	char begin, name[20];
	unsigned int finded = 0, random = 0, mode;

	srand(time(NULL)); //Used for choose a random number
	
	printf("====== WELCOME TO THE PRICE IS RIGHT GAME ======\n");
	printf("You have to guess what number I'm thinking about!\nAre you ready ?\n");
	printf("Press 'O' to begin\n\n");

	while(toupper(begin = getchar()) != 'O'); //The game doesnt start before user press 'o' or 'O'
	
	do{
		unsigned int score = 0;
		finded = 0;
	
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		
		mode = chooseMode(); //Choose solo or duo mode
		
		for (int i = 0; i < 100; ++i)
			printf("\n");

		int random = getRandom(mode); //Returns a number, random if solo mode, a chosen number if duo mode
		//printf("%d\n", random);
		putNum(random); //Makes this number unavaible for next time
		
		for(int i = 0; i < 200; i++)
			printf("\n");

		do{
			finded = game(random); //Launch the game, returns 1 if random is guessed
			score++;
		}while(finded == 0);

		printf("\n\n\n");
		printf("Congrats you've found what number I was thinking about!! You are more intelligent than I though\n");
		
		printf("===== LAST SCORES =====\n");
		 	printBestScores();

		printf("\n\n\n\n");

		if(isBestScore(score))
			printf("======= NEW BEST SCORE =======\n\n");

		printf("Your name : ");
		scanf("%s", name);
		getchar();

		registerScore(name, score);

		printf("Do you want to play again ?\n");
		printf("Press 'Enter' to replay et 'q' to quit\n");

	}while(getchar() != 'q' && getchar() == '\n');

	return 0;
}
