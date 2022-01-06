#include <stdio.h>
#include "project_reversi_skeleton.h" // DO NOT modify this line

void flipTiles(char board[][26], int n, char row, char col, char colour);
void didPlayerWin(char board[ ][26], int n, char playerColour);
int scoreMove(char board[ ][26], int n, char row, char col, char colour);
int scoreMoveInDirection(char board[ ][26], int n, char row, char col, char colour, int deltaRow, int deltaCol);
void flipTilesInDirection(char board[ ][26], int n, char row, char col, char colour, int deltaRow, int deltaCol);
bool areMovesAvailable(char board[ ][26], int n, char colour);
bool checkValidity(char board[ ][26], int n, char row, char col, char colour);
void printColLabels (int n);
void makeMoveAI(char board[ ][26], int n, char colour);
void makeMoveAIAI(char board[ ][26], int n, char colour);

//PRINTING THE BOARD BEFORE INTIAL CONFIGURATION

// the function which prints out the board
void printBoard(char board[ ][26], int n)
{
    // declaring local variables
    int rowCounter, colCounter;
    
    // calls another function to print out the labels for each column
    printColLabels(n);
    
    // two nested for loops to go through each column and each row to print the contents of each cell in the array
    for(rowCounter = 0; rowCounter < n; rowCounter++){
         printf("%c " , (char) (97+rowCounter));
         for(colCounter = 0; colCounter < n; colCounter++){
             printf("%c", board[rowCounter][colCounter]);
         }
        printf("\n");
    }
}

// the function which prints the labels for each column
void printColLabels(int n)
{
    // declaring local variables
    int counter;
    printf("  ");
    
    // for loop to print each letter above the board
    for(counter = 0; counter < n; counter++){
        printf("%c", (char) (97+counter));
    }
    printf("\n");
    return;
}

 //CHECKING IF IT IS A LEGAL POSITION IN THE DIRECTION
bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol)
{
	char opponentColour = '\0';
	if(colour == 'W')
	{
		opponentColour = 'B';
    }
	else if(colour == 'B')
	{
		opponentColour = 'W';
	}
    
	//The for loop helps ensure that we are still within the bounds of the board
	for (int rowIntCounter = row, colIntCounter = col; 0 <= rowIntCounter && rowIntCounter < n && 0 <= colIntCounter && colIntCounter < n; rowIntCounter = rowIntCounter + deltaRow, colIntCounter = colIntCounter + deltaCol)
	{
		//Checking in the direction if the colour is the opponent's colour
		if (board[row + deltaRow][col + deltaCol] == opponentColour)
		{
            if (board[rowIntCounter + deltaRow][colIntCounter + deltaCol] == colour)
			{
				return true; //Here, we return true if we hit our own colour making it a legal move
			}
			else if (board[rowIntCounter + deltaRow][colIntCounter + deltaCol] == 'U')
			{
				return false;//Here, we return false if we hit an unoccupied postion
			}
		}
	}
	return false;
}

//THIS FUNCTION CHECKS IF THE MOVE IS WITHIN THE BOUNDS OF THE BOARD
bool positionInBounds(int n, int row, int col)
{
	if( row < n && col < n)
	{
		return true; //We return true if it is within the bounds
	}
	else
	{
		return false; //We return false if we are not within the bounds
	}
}

//THIS FUNCTION CHECKS THE VALIDITY OF A MOVE AT A CERTAIN SPOT ON AN ARRAY
bool checkValidity(char board[ ][26], int n, char row, char col, char colour)
{
	int rowInt = ((int)row - 97);
	int colInt = ((int)col - 97);
	//First, we check if the spot is unnoccupied, as if it is occupied, it is not a valid place to make a move
	if (board[rowInt][colInt] == 'U')
	{
	//Now we are calling the checkLeganInDirection function to check if it is legal in 1 of the 8 directions
	//If it is legal in at least one of the directions, then it makes it a legal move
		if (checkLegalInDirection(board, n, rowInt, colInt, colour, -1, -1))
		{
			return true;
		}
		else if (checkLegalInDirection(board, n, rowInt, colInt, colour, -1, 0))
		{
			return true;
		}
		else if (checkLegalInDirection(board, n, rowInt, colInt, colour, -1, 1))
		{
			return true;
		}
		else if (checkLegalInDirection(board, n, rowInt, colInt, colour, 0, -1))
		{
			return true;
		}
		else if (checkLegalInDirection(board, n, rowInt, colInt, colour, 0, 1))
		{
			return true;
		}
		else if (checkLegalInDirection(board, n, rowInt, colInt, colour, 1, -1))
		{
			return true;
		}
		else if (checkLegalInDirection(board, n, rowInt, colInt, colour, 1, 0))
		{
			return true;
		}
		else if (checkLegalInDirection(board, n, rowInt, colInt, colour, 1, 1))
		{
			return true;
		}
		else
		{
			return false;
        }
		//returning true at least once means it is legal in at least one direction, and returning false means it is illegal in all directions
	}
	else
	{
		return false; //This is if the space is occupied, and returns false to indicate it is an illegal place to move
    }
}

//CHECKS IF THERE ARE ANY AVAILABLE MOVES FOR THE PLAYER
bool areMovesAvailable(char board[ ][26], int n, char colour)
{
	int rowCounter, colCounter;
	
	//We are checking if there are any valid moves for the player by going through each space in the array
	for(rowCounter = 0; rowCounter < n; rowCounter++)
	{
		for(colCounter = 0; colCounter < n; colCounter++)
		{
			if(checkValidity(board, n, rowCounter + 'a', colCounter + 'a', colour)) //row + 'a' gives us zero, and it slowly increases
			//We call the check validity function and sees if it returns true meaning there is a valid move
			{
				return true;//returning true means that the check validity function has returned true
				//Then this will return true back to the main function indicating there are valid moves
			}
		}
	}
	return false;
}

//THIS FUNCTION CALLS ANOTHER FUNCTION TO FLIP IN A CERTAIN DIRECTION
void flipTiles(char board[][26], int n, char row, char col, char colour)
{
	flipTilesInDirection(board, n, row, col, colour, -1, -1);
	flipTilesInDirection(board, n, row, col, colour, -1, 0);
	flipTilesInDirection(board, n, row, col, colour, -1, 1);
	flipTilesInDirection(board, n, row, col, colour, 0, -1);
	flipTilesInDirection(board, n, row, col, colour, 0, 1);
	flipTilesInDirection(board, n, row, col, colour, 1, -1);
	flipTilesInDirection(board, n, row, col, colour, 1, 0);
	flipTilesInDirection(board, n, row, col, colour, 1, 1);    
}

//THIS FUNCTION FLIPS THE TILES IN A SPECIFIC DIRECTION
void flipTilesInDirection(char board[ ][26], int n, char row, char col, char colour, int deltaRow, int deltaCol)
{
	int rowInt = ((int) row) - 97;
	int colInt = ((int) col) - 97;
	int counter;
	char oppColour;
	//We can use these if statements to help determine which colour is the player
	if(colour == 'W')
	{
		oppColour = 'B';
	}
	else if(colour == 'B')
	{
		oppColour = 'W';
	}
	
	if(board[rowInt][colInt] == 'U')
	{
		//Here we are checking if there is a legal move in the direction from the function this was called from
		if(checkLegalInDirection(board, n, rowInt, colInt, colour, deltaRow, deltaCol))
		{
			for(counter = 1; ; counter ++)
			{
				if(board[rowInt + deltaRow*counter][colInt + deltaCol*counter] == oppColour)
				{
					//Here we are flipping the tiles as we proceed in our direction to the player colour
					board[rowInt + deltaRow*counter][colInt + deltaCol*counter] = colour;
				}
				else if(board[rowInt + deltaRow*counter][colInt + deltaCol*counter] == colour)
				{
					return; //This else if statement is to break the loop as soon as we hit our own colour
				}
			}
		}
		else
		{
			//This means that we are not legal in that direction, so we do nothing
			//The fliptiles function will call this function again to check the next direction
			return;
		}
	}
	return;
}


int makeMoveMove (char board [][26], int dimension, int *row, int *col, char playerColour)
{
	flipTiles(board, dimension, *row, *col, playerColour);
	return (0);
}

void makeMoveAI(char board[ ][26], int n, char colour)
{
    // initializing and declaring local variables
    int rowCounter, colCounter, bestRow = 0, bestCol = 0;
    double score = 0, maxScore = 0;
    
    // nested for loops to go through the board
    for(rowCounter = 0; rowCounter < n; rowCounter++) {
        for(colCounter = 0; colCounter < n; colCounter++) {
            if(board[rowCounter][colCounter] == 'U' && checkValidity(board, n, rowCounter + 'a', colCounter + 'a', colour)) {
                // when a cell is a valid move, it is scored based on how many opposing tiles it would flip
                score = (scoreMove(board, n, rowCounter + 'a', colCounter + 'a', colour));
                // the score is then weighted based on the region of the board where the AI would place the tile; values were experimentally derived
                if((rowCounter == 0 || rowCounter == n -1) && (colCounter == 0 || colCounter == n-1)) {
                    score = score*4;
                } else if(((rowCounter == 1 || rowCounter == n-2) && (colCounter == 0 || colCounter == 1|| colCounter == n - 2 || colCounter == n-1)) || ((rowCounter == 0 || rowCounter == n-1) && (colCounter == 1 || colCounter == n-2))) {
                    score = score*0.25;
                } else if(rowCounter == 1 || rowCounter == n - 2 || colCounter == 1 || colCounter == n - 2) {
                    score = score*0.8;
                } else if(rowCounter == 0 || rowCounter == n-1 || colCounter == 0 || colCounter == n-1) {
                    score = score*2;
                }
                // save the index of that position only if it is greater than any score so far
                if(score > maxScore) {
                    maxScore = score;
                    bestRow = rowCounter;
                    bestCol = colCounter;
                }
            }
        }
    }
    // place the move at the position calculated above, and print a message to inform the player
    flipTiles(board, n, bestRow + 'a', bestCol + 'a', colour);
    board[bestRow][bestCol] = colour;
    printf("Computer places %c at %c%c.\n", colour, bestRow + 'a', bestCol + 'a');
}

// the function which decides where the AI will place a move
void makeMoveAIAI(char board[ ][26], int n, char colour)
{
    // initializing and declaring local variables
    int rowCounter, colCounter, bestRow = 0, bestCol = 0;
    double score = 0, maxScore = 0;
    
    // nested for loops to go through the board
    for(rowCounter = 0; rowCounter < n; rowCounter++) {
        for(colCounter = 0; colCounter < n; colCounter++) {
            if(board[rowCounter][colCounter] == 'U' && checkValidity(board, n, rowCounter + 'a', colCounter + 'a', colour)) {
                // when a cell is a valid move, it is scored based on how many opposing tiles it would flip
                score = (scoreMove(board, n, rowCounter + 'a', colCounter + 'a', colour));
                // the score is then weighted based on the region of the board where the AI would place the tile; values were experimentally derived
                if((rowCounter == 0 || rowCounter == n -1) && (colCounter == 0 || colCounter == n-1)) {
                    score = score*4;
                } else if(((rowCounter == 1 || rowCounter == n-2) && (colCounter == 0 || colCounter == 1|| colCounter == n - 2 || colCounter == n-1)) || ((rowCounter == 0 || rowCounter == n-1) && (colCounter == 1 || colCounter == n-2))) {
                    score = score*0.25;
                } else if(rowCounter == 1 || rowCounter == n - 2 || colCounter == 1 || colCounter == n - 2) {
                    score = score*0.8;
                } else if(rowCounter == 0 || rowCounter == n-1 || colCounter == 0 || colCounter == n-1) {
                    score = score*2;
                }
                // save the index of that position only if it is greater than any score so far
                if(score > maxScore) {
                    maxScore = score;
                    bestRow = rowCounter;
                    bestCol = colCounter;
                }
            }
        }
    }
    // place the move at the position calculated above, and print a message to inform the player
    flipTiles(board, n, bestRow + 'a', bestCol + 'a', colour);
    board[bestRow][bestCol] = colour;
    printf("Computer places %c at %c%c.\n", colour, bestRow + 'a', bestCol + 'a');
}

//MAKES MOVES FOR THE COMPUTER COLOUR
int makeMove(const char board[26][26], int n, char turn, int *row, int *col)
{
	
	//for (int i = 0; i < 26; i++)
	//{
	//	for (int j = 0; j < 26; j++)
	//	{
	//		printf ("%s\n", &board [i][j]);
	//	}
	//	printf ("\n");
	//}
	//char copyBoard [n][n];
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		copyBoard [i][j] = board [i][j];
	//	}
	//}
	makeMoveAIAI ((char(*)[26])board, n, turn);
	/*
	int rowCounter, colCounter, bestRow = 0, bestCol = 0;
	double score = 0, maxScore = 0;
	char copyBoard [n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			copyBoard [i][j] = board [i][j];
		}
	}
	//These for loops goes through the entire board to find the best move to execute
	for(rowCounter = 0; rowCounter < n; rowCounter++)
	{
		for(colCounter = 0; colCounter < n; colCounter++)
		{
			if(copyBoard[rowCounter][colCounter] == 'U' && checkValidity(copyBoard, n, rowCounter, colCounter, turn)) 
			{
				//Here, we are checking if the spot is unoccupied and if it is a valid spot
				//We are then calling another function which determines the score (number of flipped tiles) for that move
				score = scoreMove(copyBoard, n, rowCounter, colCounter, turn);
				if(score > maxScore) //This compares the newly found score to any previously found scores
				{
					//Initially, the maxScore was 0 so the first found score will be higher and assigned to maxScore
					//We then go through all possible moves, and if one of the moves determines a higher score, it will replace the pre-existing maxScore
					maxScore = score;
					bestRow = rowCounter; //This assigns that maxScore row to bestRow to have the move placed there
					bestCol = colCounter; //This assigns that maxScore column to bestCol to have the move placed ther
				}
			}
		}
		//row = &bestRow; //assigning the address of the best row value to the row pointer
		//col = &bestCol; //assigning the address of the best column value to the col pointer
		
		
		
	}
	flipTiles(copyBoard, n, bestRow, bestCol, turn); //This calls the flipTiles function to start flipping tiles in the direction
		//makeMoveMove (copyBoard, n, row, col, turn);
		//(char (*)[26]) = turn;
		//(char (*)[26])*board[bestRow][bestCol] = turn; //This prints 
		printf("Computer places %c at %c%c.\n", turn, bestRow + 'a', bestCol + 'a'); //This lets the players know where the move has been placed
	return (0);
	*/
	return (0);
}

//DETERMINES THE SCORE IN THE SPECIFIED DIRECTION IN THE CALLING FUNCTION
int scoreMoveInDirection(char board[ ][26], int n, char row, char col, char colour, int deltaRow, int deltaCol)
{
	int rowInt = ((int) row)-97;
	int colInt = ((int) col)-97;
	int counter;
	int score = 0;
	char oppColour;
	
	//Here we are determining which colour belongs to which player
	if(colour == 'W')
	{
		oppColour = 'B';
	}
	else if(colour == 'B')
	{
		oppColour = 'W';
	}
    
	//Initially we ensure the spot is unoccupied to ensure it is a valid move spot
	if(board[rowInt][colInt] == 'U')
	{
		//We check if the spot is valid in the specific direction which was determined in the calling function
		if(checkLegalInDirection(board, n, rowInt, colInt, colour, deltaRow, deltaCol))
		{
			for(counter = 1; ; counter ++) //This for loops continues to walk in the specified direction if it is a legal move
			{
				if(board[rowInt + deltaRow*counter][colInt + deltaCol*counter] == oppColour) 
				{
					score++; //We continue to increase the score for every opponent colour we meet as this will be flipped
				}
				else if(board[rowInt + deltaRow*counter][colInt + deltaCol*counter] == colour)
				{
					return score; //Once we hit our own colour, we stop flipping tiles so we stop increasing the score and return it
				}
            }
        }
		else
		{
			//This is in the case that the spot is occupied, hence it is an illegal move
			return 0;
		}
	}
	return 0;
	
}


//THIS FUNCTION CALCULATES THE BEST SCORE FOR THE COMPUTER IN ALL DIRECTIONS 
int scoreMove(char board[ ][26], int n, char row, char col, char colour)
{
	//We call the scoreMoveInDirection to calculate the score (number of flipped tiles) in all directions
	//The final score is the score in all directions added up, as when placing a tile in a certain spot, it may be valid in multiple directions
	int score;
	score = scoreMoveInDirection(board, n, row, col, colour, -1, -1) +
	scoreMoveInDirection(board, n, row, col, colour, -1, 0) +
	scoreMoveInDirection(board, n, row, col, colour, -1, 1) +
	scoreMoveInDirection(board, n, row, col, colour, 0, -1) +
	scoreMoveInDirection(board, n, row, col, colour, 0, 1) +
	scoreMoveInDirection(board, n, row, col, colour, 1, -1) +
	scoreMoveInDirection(board, n, row, col, colour, 1, 0) +
	scoreMoveInDirection(board, n, row, col, colour, 1, 1);
	return score; //this returns the total score to the calling function
}

//THIS FUNCTION DETERMINES WHO WON THE GAME OR IF IT WAS A DRAW
void didPlayerWin(char board[ ][26], int n, char playerColour)
{

	int playerScore = 0;
	int compScore = 0;
	char compColour;
    
	//These if statements help determine which colour is which player
	if(playerColour == 'B')
	{
		compColour = 'W';
	}
	else if(playerColour == 'W')
	{
		compColour = 'B';
	}

	for(int rowCounter = 0; rowCounter < n; rowCounter++)
	{
		for(int colCounter = 0; colCounter < n; colCounter++)
		{
			//Here we are going through the entire board to count the total of each score
			if(board[rowCounter][colCounter] == playerColour)
			{
				playerScore++; //If the array character is the player colour, the player's score goes up by one
			}
			else if(board[rowCounter][colCounter] == compColour)
			{
				compScore++; //If the array character is the computer colour, the computer's score goes up by one
			}
		}
	}
	
	if(playerScore > compScore)
	{
		printf("%c player wins.\n", playerColour); //If the player score is higher, the player wins
		return;
	}
	else if(playerScore == compScore)
	{//If both the player nad computer got the same score, then it is a draw
		printf("Draw!\n");
		return;
	}
	else
	{
		printf("%c player wins.\n", compColour); //If the computer score is lower, the computer wins
		return;
	}
	return;
}

#ifndef COMPETE_MODE // DO NOT DELETE THIS LINE
//MAIN FUNCTION
int main(void)
{
	int dimension, rowCounter, colCounter;
	char compColour= '\0';
	char playerColour= '\0';
	char moveRow, moveCol;
	int moveRowInt, moveColInt;

	printf ("Enter the board dimension: ");
	scanf ("%d", &dimension);
	char board [26][26];
	
	// setting the board so that it matches initial conditions of a Reversi game
    for(rowCounter = 0; rowCounter < dimension; rowCounter++){
        for(colCounter = 0; colCounter < dimension; colCounter++){
            board[rowCounter][colCounter] = 'U';
        }
    }
    board[(dimension-1)/2][(dimension-1)/2] = 'W';
    board[(dimension+1)/2][(dimension+1)/2] = 'W';
    board[(dimension-1)/2][(dimension+1)/2] = 'B';
    board[(dimension+1)/2][(dimension-1)/2] = 'B';
	
	
	 printf("Computer plays (B/W) : ");
	scanf(" %c", &compColour);
    
    // assigning the player's colour
    if (compColour == 'B')
	{
		playerColour = 'W';
		printBoard(board, dimension);
		makeMove(board, dimension, compColour, &moveRowInt, &moveColInt);
	}
	else if (compColour == 'W')
	{
		playerColour = 'B';
    }
    
    // printing the board befre the player's first move
	printBoard (board, dimension);
	//configurateBoard (board, boardDimension);
	//checkAvailableMoves (board, boardDimension, 'W'); //Checks available moves for white
	//checkAvailableMoves (board, boardDimension, 'B'); //Checks available moves for black

	do
	{
		//Calling the available moves function to see if the player has any available moves
		if(areMovesAvailable(board, dimension, playerColour))
		{
			printf("Enter move for colour %c (RowCol): ", playerColour);
			scanf(" %c%c", &moveRow, &moveCol);
			moveRowInt = ((int) moveRow) - 97; //Here we are casting the character type into an integer
			//printf ("%c\n", moveRow);
			//printf ("%d\n", moveRowInt);
			moveColInt = ((int) moveCol) - 97; //Here we are casting the character type into an integer
           // printf ("%c\n", moveCol);
			//printf ("%d\n", moveColInt);
			
			//Now we are checking whether the move is valid by checking both validity and if it is within the bounds of the board
			if(checkValidity(board, dimension, moveRow, moveCol, playerColour) && positionInBounds(dimension, moveRowInt, moveColInt))
			{
				//If both the validity and the positionInBounds functions return true, we will call the flipTiles function to make the move
				flipTiles(board, dimension, moveRow, moveCol, playerColour);
				board[moveRowInt][moveColInt] = playerColour;
				printBoard(board, dimension);
			}
			else
			{
				//Here, if the user entered move is an invalid move, the game will move and the computer player will win.
				printf("Invalid move.\n%c player wins.", compColour);
				return 0;
			}
			
			//This else if will run only if the initial if statement calling the available moves function returns false
		}
		else if (areMovesAvailable(board, dimension, compColour))
		{
			//The available moves function returning false means the player has no valid moves. 
			printf("%c player has no valid move.\n", playerColour);
		}
        
        if(areMovesAvailable(board, dimension, compColour))//Here, we are checking if the computer has any available moves
		{
			//Since we do, we call the makeMove function to execute the best move for the computer
			makeMove(board, dimension, compColour, &moveRowInt, &moveColInt);
			
			printBoard(board, dimension);
			//This else if will run only if the intial if statement calling the available moves function returns false
        }
		else if(areMovesAvailable(board, dimension, playerColour))
		{
			//The available moves function returning flase means the computer has no available moves.
			printf("%c player has no valid move.\n", compColour);
        }
		
		//This do while loop only runs as long as either one of the players have available moves. 
	}
	while(areMovesAvailable(board, dimension, playerColour) || areMovesAvailable(board, dimension, compColour));
    
	//Exiting the do-while loops means neither player has availabe moves, so now we determine who is the winner, or if it is a draw.
	didPlayerWin(board, dimension, playerColour);
	return 0;
}

#endif // DO NOT DELETE THIS LINE