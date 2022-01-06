#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
	if(argc==1)
		srand(time(NULL));
	else
		srand(atoi(argv[1]));

	//Intilialization
	int inputNumber = 0;
	int dealerWorth = 0;
	int playerWorth = 0;

	//Generating random player and dealer cards
	int dealerCardNumber = rand() % 13 + 1;
	int playerCardNumber = rand() % 13 + 1;

	//Providing the values of the first cards
	printf ("First cards: player %d, ", playerCardNumber);
	printf ("dealer %d\n", dealerCardNumber);
	
	//Equating 10, 11, 12, 13 to the value of 10
	if (playerCardNumber >= 10) {
		playerCardNumber = 10;
	}
	if (dealerCardNumber >= 10) {
		dealerCardNumber = 10;
	}
	
	//Determing the total worth of each person's cards
	playerWorth = playerCardNumber;
	dealerWorth = dealerCardNumber;
	
	do 
	{
		//Requesting player to either hit or stay
		printf ("Type 1 for Hit, 0 to Stay:");
		scanf ("%d", &inputNumber);
		
		//When the user input is equal to 1, another random card is generated
		if (inputNumber == 1) {
			int playerCardNumber = rand() % 13 + 1;
			printf ("Player gets a %d, ", playerCardNumber);
			
			//Equating 10, 11, 12, 13 to the value of 10
			if (playerCardNumber >= 10) {
				playerCardNumber = 10;
			}
			
			//Calculating and outputting the Player's new worth
			playerWorth = (playerWorth + playerCardNumber);
			printf ("worth is %d\n", playerWorth);
			
			//Making the input Number 0 again, so if the user enters 1, it doesn't add on to make 2, etc.
			inputNumber = (0);
		}
		
		//This runs in the case that the user enters 0, or something else other than 1
		else {
			break;//this helps break the do-while loop from continuing
		}
	}
	while (playerWorth <= 21);//allows the loop to only run under the provided condition
	
	//This is determined here, so that the the rest of the code does not run
	if (playerWorth > 21) {
		printf ("Player over 21, Dealer wins\n");
	}
	
	if (playerWorth <= 21) { //Allows the rest of the code to only run if the Player does not exceed 21
		printf ("Dealer gets:");
		do
		{
			int dealerCardNumber = rand() % 13 + 1;
			printf (" %d", dealerCardNumber);
			if (dealerCardNumber >= 10) {
				dealerCardNumber = 10;
			}
			dealerWorth = (dealerWorth + dealerCardNumber);
		}
		while (dealerWorth < 17);
		printf ("\n");
	}
	
	if (playerWorth == dealerWorth) {
		printf ("Tie!\n"); }
		
	else if (dealerWorth > 21) {
		printf ("Dealer over 21, Player wins\n"); }

	else if (dealerWorth > playerWorth) {
		 if (21 >= dealerWorth) { //Included an if statement in an else-if statement, to allow two conditions
			printf ("Dealer better than Player, Dealer wins\n");
		 }
	}
	
	else if (playerWorth > dealerWorth) {
		if (21 >= playerWorth) {
			printf ("Player better than Dealer, Player wins\n");
		}
	}
	
	else {
		; //Helpful syntax when there is no expression to be put where a statement is necessary
	}
	
	return 0;
	
}
