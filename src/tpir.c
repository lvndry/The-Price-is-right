/*** 
	 The price is right
     Author : Monga Landry 
	 August 2017 
***/

#include "tpir.h"

int available(int random){ //Check if number has never been used before
	FILE* cancel = fopen("cancel.txt", "r");
	int nbr;

	if (random == 0)
		return 0;

	while(!feof(cancel)){
		fscanf(cancel, "%d", &nbr);
	
		if(nbr == random){
			fclose(cancel);
			return 0;
		}
	}
	fclose(cancel);
	return 1;
}

int chooseMode(){ //Choose game mode solo or duo
	unsigned int mode;
	
	printf("Solo mode or Duo mode ? :\n");
	printf("Press 1 or 2 : \n");
	unsigned int rep = scanf("%u", &mode); //scanf returns 0 if not a number
		
	while(!rep || mode < 1|| mode > 2){ // !rep --> rep == 0
		printf("NOT AVAILABLE VALUE!\n");
		printf("Solo mode or Duo mode ? :\n");
		printf("Press 1 or 2 : \n");
		rep = scanf("%d", &mode);
	}

	return mode;
}

int game(int random){ //Launch the game
	int guess;

	printf("Enter a number : ");
	int check = scanf("%d", &guess); //return 0 if not a number
	getchar();
	
	while(!check){
		printf("Numbers only!!! Watch out!!\n");
		printf("Enter a number \n");
		getchar();
		check = scanf("%d", &guess);	
	}

	//Says if you are about to find the word or if you are far away of the answer
	if(guess > random){
		if(guess-random > 15)
			printf("Cold! (Advise: I think about a lower number)\n");
		else if(guess-random <= 15 && guess-random > 5)
			printf("Almost but it still to high..\n");
		else printf("You are so close!! (Just a bit less)\n");
	}
			
	if(guess < random){
		if(random-guess > 15)
			printf("Cold! (Advise: I think about a higer number)\n");
		else if(random-guess <= 15 && random-guess > 5)
			printf("Almost but it still to low..\n");
		else printf("You are so close!! (Just a bit more)\n");
	}
	
	if(guess == random)
		return 1;

	return 0;
}

int getAletNumber(int MAX){ //return an alet number the max changes
	return (rand() % (MAX - MIN + 1)) + MIN;
}

int getRandom(int mode){ //Returns number depending on the mode
	int random;
	if(mode == 1){
		printf("Choose the level : \n");
			
		int lvl = level(); //returns the level
		int MAX = max(lvl); //returns the maximum number thant can be randomly chosen depending on the level

		while(!available(random)) //while the number is not available it choose an other one
			random = getAletNumber(MAX);

		printf("Well let me think...\n");
		sleep(2);
		printf("I have a number!\n\n");

	}

	else {
		printf("Player 1 choose a number :\n");
		scanf("%d", &random);
		getchar();
			
		while(!available(random)){ //Check if the number has never been chosen 
			printf("Number not available\n");
			printf("Player 1 choose an other number : ");
			scanf("%d", &random);
			getchar();
		}
	}

	return random;
}

int isBestScore(int max){ //check if max is the highest number
	FILE* score = fopen("score.txt", "r");
	int nbr;
	char name[20];

	while(!feof(score)){
		fscanf(score, "%s : %d", name, &nbr);
		
		if(nbr < max){
			fclose(score);
			return 0;
		}
	}

	fclose(score);
	return 1; 
}

int level(){ //returns the chosen level
	unsigned short level;

	printf("1- 1 to 100\n");
	printf("2- 1 to 200\n");
	printf("3- 1 to 300\n");
	printf("4- 1 to 400\n");
	printf("5- 1 to 500\n");
	printf("6- 1 to 600\n");
	printf("7- 1 to 700\n");
	printf("8- 1 to 800\n");
	printf("9- 1 to 900\n");
	printf("10- 1 to 1000\n");
	printf("\n");

	do{
		printf("Enter the desired level (1 to 10 only) :\n");
		scanf("%d", &level);
		getchar();
	}while(level < 1 || level > 10);

	return level;
}

int max(int level){ //returns a max depending on the level
	int MAX;

	switch(level){
		case 1 :
		MAX = LEVEL1;
		break;

		case 2 :
		MAX = LEVEL2;
		break;
		
		case 3: 
		MAX = LEVEL3;
		break;

		case 4: 
		MAX = LEVEL4;
		break;
				
		case 5: 
		MAX = LEVEL5;
		break;
				
		case 6: 
		MAX = LEVEL6;
		break;
				
		case 7: 
		MAX = LEVEL7;
		break;
				
		case 8: 
		MAX = LEVEL8;
		break;
				
		case 9: 
		MAX = LEVEL9;
		break;
				
		case 10: 
		MAX = LEVEL10;
		break;
	}
	return MAX;
}

void printBestScores(){ //print all best scores
	FILE* score = fopen("score.txt", "r");
	char name[20];
	int bscore, i = 1;

	rewind(score);

	while(!feof(score)){
		fscanf(score, "%s : %d", name, &bscore);
		printf("%d - %s : %d\n", i, name, bscore);
		i++;
	}
	fclose(score);
}

void putNum(int random){ //Makes a number unavailabe for next times
	FILE* cancel = fopen("cancel.txt", "a+");

	fprintf(cancel, "%d\n", random);

	fclose(cancel);
}

void registerScore(char *name, int score){ //register a new best score
	FILE* scorefile = fopen("score.txt", "a+");

	fprintf(scorefile, "%s : %d\n", name, score);

	fclose(scorefile);
}
