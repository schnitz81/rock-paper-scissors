//////////////////////////////////////////////////////////////////////////////////////////////////////////
//													//
//			Rock, Paper, Scissors								//
//									by Hackerman			//
//													//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum choice {ROCK, PAPER, SCISSORS};
enum players {HUMAN, CPU};
int playerscore=0, cpuscore=0;

void printScore()
{
	printf("\n  Player: %i    CPU: %i\n", playerscore, cpuscore);
}

int getCpuChoice() // Function to return a random number.
{
	int randNbr = (rand()%3);
	return randNbr;
}

int getPlayerChoice()
{
	char ch;
	printf("\n\n--------------------------------");
	printf("\n(R)ock (P)aper (S)cissors (Q)uit\n");
	printf("(1)    (2)     (3)\n");
	while(1){
		printf(">");
		scanf("%c",&ch);
		if(ch == 27 || ch == 'q' || ch == 'Q'){
			printf("\nGame Over.\n");
			printScore();
			exit(0);
		}
		else if(ch == '1' || ch == 'r' || ch == 'R')
			return ROCK;
		else if(ch == '2' || ch == 'p' || ch == 'P')
			return PAPER;
		else if(ch == '3' || ch == 's' || ch == 'S')
			return SCISSORS;
		else if(ch=='\n')
			printf("\b"); // consume newline from stdin
		else
			printf("Invalid choice.\n");
	}
}

void printChoice(const enum choice playerChoice)
{
	switch(playerChoice){
		case ROCK:
			printf("Rock");
			break;
		case PAPER:
			printf("Paper");
			break;
		case SCISSORS:
			printf("Scissors");
			break;
	}
}

void turnout(const enum choice humanChoice, const enum choice cpuChoice)
{
	printf("Player: ");
	printChoice(humanChoice);
	printf("   CPU: ");
	printChoice(cpuChoice);

	// Draw
	if(humanChoice == cpuChoice)
		printf("\n\n        Draw!\n");

	// Player wins
	else if((humanChoice == ROCK && cpuChoice == SCISSORS) || (humanChoice == SCISSORS && cpuChoice == PAPER) || (humanChoice == PAPER && cpuChoice == ROCK)){
		printf("\n\n    Player wins!\n");
		playerscore++;
	}

	// CPU wins
	else{
		printf("\n\n      CPU wins!\n");
		cpuscore++;
	}
}

int main()
{
	enum choice humanChoice;
	enum choice cpuChoice;
	int i,n;
	srand(time(NULL));  // Randomizing seed.
	printf("\n\nWarming up random number generator...");
	for(i=0;i<10;i++){  // Reducing entropy starvation.
		n=getCpuChoice();
		printf(" %i",n);
	}
	while(1){
		humanChoice = getPlayerChoice();
		cpuChoice = getCpuChoice();
		turnout(humanChoice,cpuChoice);
		printScore();
	}
}
