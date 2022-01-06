#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARDROWS 9
#define BOARDCOLS 11

bool dumpComputer = false; //causes dump of computer board before game if true (for debugging)

// boards. 0 means empty, non-zero means ship is there, number is size, -tive means hit on a ship
int playerBoard[BOARDROWS+1][BOARDCOLS+1];
int computerBoard[BOARDROWS+1][BOARDCOLS+1];
int compShotBoard[BOARDROWS+1][BOARDCOLS+1];

int getRand(int lowval,int highval){
    return (rand()%(highval+1-lowval) + lowval);
}

int getShot(bool fromUser, int board[BOARDROWS+1][BOARDCOLS+1]){

    int row,col;
    while(1){
        if(fromUser){
            printf("Give a shot (row, col):");
            scanf("%d%d",&row,&col);
            if(col<1 || col > BOARDCOLS || row < 1 || row > BOARDROWS)
                printf("Invalid input\n");
            else  //valid input
                break;
        }
        else { //computer generated
            row=getRand(1,BOARDROWS);
            col=getRand(1,BOARDCOLS);
            if(compShotBoard[row][col]==0) { //make sure haven't shot here before
                compShotBoard[row][col]=1; //valid shot
                break;
            }
        }
    } //will leave this loop with valid input

    if(board[row][col] != 0){
        if(board[row][col]>0)
            board[row][col]= -1*board[row][col]; //make sure is -tive
        return -1*board[row][col]; //a hit!
    }
    return 0; //miss
}


bool allShipsNotHit(int board[BOARDROWS+1][BOARDCOLS+1]){
    for(int i=1;i<=BOARDROWS;i++){
        for(int j=1;j<=BOARDCOLS;j++){
            if(board[i][j]>0) //ship and not hit
                return(true);
        }
    }
    return (false); //no ships found not all hit
}

bool noneLeft(int valueToFind,int board[BOARDROWS+1][BOARDCOLS+1]){
    for(int i=1;i<=BOARDROWS;i++){
	for(int j=1;j<=BOARDCOLS;j++){
            if(board[i][j]==valueToFind) //ship and not hit
			return(false);
        }
    }
    return (true); //no ships found, all hit
}

bool overlap (int shipRow, int shipColumn, int shipSize, int shipOrientation, int board [BOARDROWS+1][BOARDCOLS+1])
{
	bool hello = true;
	if (shipOrientation == 0)
	{
		for (int i = 0; i < shipSize; shipColumn++)
		{
			if (board [shipRow][shipColumn] == 0)
			{
				;
			}
			else
			{
				hello = false;
			}
		i++;
		}
	}
	

	else if (shipOrientation == 1)
	{
		for (int i = 0; i < shipSize; shipRow++)
		{
			if (board [shipRow][shipColumn] == 0)
			{
				;
			}
			else
			{
				hello = false;
			}
		i++;
		}
	}
	return (hello);
}


void populateBoard(bool getUserInput, int board[BOARDROWS+1][BOARDCOLS+1])
{
	//Initialization of variables
	int shipRow = 0;
	int shipColumn = 0;
	int shipOrientation = 0;

	if (getUserInput == true)
	{
		printf ("Rows are 1 - 9, Columns are 1 - 11\n");
		printf ("Orientation is 0 for across, 1 for down\n");
		//Seeking User Input
		
		for (int shipSize = 5; shipSize > 0; shipSize--)
			{
				printf ("Give starting row, starting column and orientation (3 inputs) for ship of size=%d:", shipSize);
				scanf ("%d %d %d", &shipRow, &shipColumn, &shipOrientation);
				
		
				if (shipRow >= 1 && shipRow <= 9 && shipColumn >= 1 && shipColumn <= 11)
				{
					bool invalidCheck = false;
					if (shipColumn + (shipSize - 1) > 11 && shipOrientation == 0)
					{
						invalidCheck = true;
						printf ("Invalid Input\n");
						shipSize++;
					}
					else if (shipRow + (shipSize - 1) > 9 && shipOrientation == 1)
					{
						invalidCheck = true;
						printf ("Invalid Input\n");
						shipSize++;
					}

					
					if (shipOrientation == 0 && invalidCheck == false)
					{
						bool compare = false;
						compare = overlap (shipRow, shipColumn, shipSize, shipOrientation, board);
						
						if (compare == true)
						{
							for (int j = 0; j < shipSize; shipColumn++)
							{
								board [shipRow][shipColumn] = shipSize;
								(j++);
							}
						}
						else
						{
							printf ("Conflicts with ship already placed\n");
							shipSize++;
							
						}
					}
	
					else if (shipOrientation == 1 &&  invalidCheck == false)
					{
						bool compare = false;
						compare = overlap (shipRow, shipColumn, shipSize, shipOrientation, board);
						
						if (compare == true)
						{
							for (int j = 0; j < shipSize; shipRow++)
							{
								board [shipRow][shipColumn] = shipSize;
								(j++);
							}
						}
						else
						{
							printf ("Conflicts with ship already placed\n");
							shipSize++;
							
						}
					}

					else if (shipOrientation != 1 && shipOrientation != 0)
					{
						printf ("Invalid Input\n");
						(shipSize++);
						
					}
				}
				else
				{
					printf ("Invalid Input\n");
					(shipSize++);
				}
			}
	}
	
	if (getUserInput == false)
	{
		for (int shipSize = 5; shipSize > 0; shipSize--)
		{
			//Random generated row
			int computerRow = 0;
			computerRow = getRand (1, 9);
		
			//Random generated column
			int computerColumn = 0;
			computerColumn = getRand (1, 11);
		
			//Random generated orientation
			int computerOrientation = 0;
			computerOrientation = getRand (0, 1);
			
			//Checking if it is going overboard
			bool computerCheck = false;
					if (computerColumn + (shipSize - 1) > 11 && computerOrientation == 0)
					{
						computerCheck = true;
						shipSize++;
					}
					else if (computerRow + (shipSize - 1) > 9 && computerOrientation == 1)
					{
						computerCheck = true;
						shipSize++;
					}
					
					if (computerOrientation == 0 && computerCheck == false)
					{
						bool hello = false;
						hello = overlap (computerRow, computerColumn, shipSize, computerOrientation, board);
						
						if (hello == true)
						{
							for (int j = 0; j < shipSize; computerColumn++)
							{
								board [computerRow][computerColumn] = shipSize;
								(j++);
							}
						}
						else
						{
							shipSize++;
							
						}
					}
					
					else if (computerOrientation == 1 &&  computerCheck == false)
					{
						bool hello = false;
						hello = overlap (computerRow, computerColumn, shipSize, computerOrientation, board);
						
						if (hello == true)
						{
							for (int j = 0; j < shipSize; computerRow++)
							{
								board [computerRow][computerColumn] = shipSize;
								(j++);
							}
						}
						else
						{
							shipSize++;
						}
					}
		}
		
	}
}






void showBoard(int board[BOARDROWS+1][BOARDCOLS+1]){
    printf("   Cols\n");
    printf("    1  2  3  4  5  6  7  8  9 10 11\n");
    printf("     ________________________________\n");
    for(int i=1;i<=BOARDROWS;i++){
        printf("R%d|",i);
	for(int j=1;j<=BOARDCOLS;j++){
        if(board[i][j]>=0)
			printf(" ");
            printf("%d ",board[i][j]);
        }
        printf("|\n");
    }
printf("  __________________________________\n");
}

int main(int argc, char **argv)
{
bool playerBoardOK,computerBoardOK;
    // initialize the seed randomly. 
     	srand(time(NULL)); 
    //init the boards

    for(int i=0;i<BOARDROWS;i++){
        for(int j=0;j<BOARDCOLS;j++){
            playerBoard[i][j]=0;
            computerBoard[i][j]=0;
            compShotBoard[i][j]=0;
        }
    }

    populateBoard(true,playerBoard);
    populateBoard(false,computerBoard);
    printf("Your board is\n");
    showBoard(playerBoard);
    if(dumpComputer){
        printf("\n\nComputer board is\n");
        showBoard(computerBoard);
    }



    // play starts here
    playerBoardOK=true;
    computerBoardOK=true;
    while(playerBoardOK && computerBoardOK){
        int hit=getShot(true,computerBoard); //shot from user
        if(hit){
            printf("HIT on size %d\n",hit);
            if(noneLeft(hit,computerBoard))
                printf("Sunk computer's %d\n",hit);
        }

        else
            printf("MISS!!\n");
        hit=getShot(false,playerBoard);
        if(hit){
            printf("Computer hits! Size=%d\n", hit);
            if(noneLeft(hit,playerBoard))
                printf("Sunk your %d\n",hit);
        }

        else
            printf("Computer miss!\n");
        playerBoardOK = allShipsNotHit(playerBoard);
        computerBoardOK = allShipsNotHit(computerBoard);
//    showBoard(playerBoard); //debug
//    showBoard(computerBoard); //debug
   }
   if(playerBoardOK)
       printf("You win!\n");
    else
        printf("You lose.\n");
    showBoard(computerBoard);
	return 0;
}

