#include <stdio.h>
#include <stdbool.h>
//PRINTING THE BOARD BEFORE INTIAL CONFIGURATION
#define SIZE 4 
int valid_moves(char board[26][26], int moves[26][26], char player); 
void printBoard(char board[][26], int n)
{
printf("  ");
for(int i = 0; i < n; i++)
{
printf("%c",97+i); //unicodes for printing lowercase alphabet
    }
    printf("\n");

    for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
board[i][j]='U';
}
    }

    board [(n/2)-1] [(n/2)-1]='W'; //- 1 because think of the index values
    board [n/2] [n/2]='W';
    board [(n/2)-1] [n/2]='B';
    board [n/2] [(n/2)-1]='B';

    for(int i=0;i<n;i++)
{
        printf("%c ",97+i);
        for(int j = 0; j<n; j++)
{
            printf("%c", board[i][j]);
        }
printf("\n");
}
}

//HELPS CONFIGURATE THE BOARD FOR INITIAL SET-UP
void configurateBoard (char board [][26], int n)
{
printf ("Enter the board configuration: \n");
for (;;)
{
char colour;
char row;
char column;
scanf (" %c%c%c", &colour, &row, &column);

if (colour != '!' && row != '!' && column != '!')
{
//printf ("%d\n", ((row) - 'a'));//acquires the value of the row in the array
//printf ("%d\n", ((column) - 'a')); //acquires the value of the column in the array
board [(row) - 'a'][(column) - 'a'] = colour;
}
else
{
printf("  "); //prints the board after the updated configuration
for(int i=0;i<n;i++)
{
printf("%c",97+i);
}
printf("\n");

for(int i=0;i<n;i++)
{
printf("%c ",97+i);

for(int j=0;j<n;j++)
{
printf("%c",board[i][j]);
}
printf("\n");
}  
break;
}
}
}


 //CHECKING IF THE SPECIFIC SPOT IS WITHIN THE BOARD DIMENSIONS
bool positionInBounds(int n, int row, int col)
{
    if (row > 0 && row <= n && col > 0 && col<= n)
{
return true;
}
else
{
return false;
}
}

//Checks if neighbouring colour is not white and unoccupied position
bool neighbouringColourWhite (char board [][26], int row, int col)
{
if (board [row][col] != 'U' && board [row][col] != 'W')
{
return true;
}
else
{
return false;
}
}

//Checks if neighbouring colour is not black and unoccupied position
bool neighbouringColourBlack (char board [][26], int row, int col)
{
if (board [row][col] != 'U' && board [row][col] != 'B')
{
return true;
}
else
{
return false;
}
}

//Checks if the spot is at the edge of the board
//Need to Change this so it continues on
bool edgeOfTheBoard (int n, int row, int col)
{
if (row == n || col == n || row == 1 || col == 1)
{
return false;
}
else
{
return true;
}
}

bool walkingToDirection (char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol)
{
bool hello = false; //Initialization
int count = 0;
while ((positionInBounds (n, row + (count*deltaRow), col + (count*deltaCol))) && (board [row + (count*deltaRow)][col + (count*deltaCol)] != colour) && (board [row + (count*deltaRow)][col + (count*deltaCol)] != 'U'))
{
bool edge = false; //Initialization
edge = edgeOfTheBoard (n, row + (count*deltaRow), col + (count*deltaCol));
if (edge == true)
{
;
}
else
{
hello = false;
break;
}
count++;
}
while ((positionInBounds (n, row + (count*deltaRow), col + (count*deltaCol))))
{
if (board [row + (count*deltaRow)][col + (count*deltaCol)] == (colour))
{
hello = true;
}
if ((board [row + (count*deltaRow)][col + (count*deltaCol)] != 'U'))
{
hello = false;
}
count++;
}
return (hello);
}

 //CHECKING IF IT IS A LEGAL POSITION IN THE DIRECTION
bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol)
{
bool position = false; //Initialization
//This is for the neighbouring position only
position = positionInBounds (n, row + deltaRow, col + deltaCol);
bool white = false; //Initialization
bool black = false; //Initialization
bool returningValue = true;
if (colour == 'W')
{
white = neighbouringColourWhite (board, row + deltaRow, col + deltaCol);
}
else
{
black = neighbouringColourBlack (board, row + deltaRow, col + deltaCol);
}

bool edge = false; //Initialization
edge = edgeOfTheBoard (n, row + deltaRow, col + deltaCol);

bool walking = false;
walking = walkingToDirection (board, n, row, col, colour, deltaRow, deltaCol);

if (position == true && edge == true)
{
if (white == true || black == true)
{
if (walking == true)
{
returningValue = true;
}
}
}
else
{
returningValue = false;
}
return (returningValue);
}

void checkAvailableMoves (char board [][26], int n, char colour)
//You can use this similar process to check if the input of a move from the user is valid or invalid
{
printf ("Available moves for %c:\n", colour);
for (int i = 0; i < n; i++)
{
for (int j = 0; j < n; j++)
{
bool unoccupied = false;
if (board [i][j] != 'U')
{
unoccupied = false;
}
else
{
unoccupied = true;
}
if (board [i][j] == colour )
{
for (int deltaRow = -1; deltaRow <= 1; deltaRow++)
{
for (int deltaCol = -1; deltaCol <= 1; deltaCol++)
{
if (deltaRow != 0 && deltaCol != 0)
{
bool direction = false; //Initialization
direction = checkLegalInDirection (board, n, i, j, colour, deltaRow, deltaCol);
if (direction == true)
{
printf ("%c %c\n", (96+i), (96+j));
}
else
{
;
}
}
}
}
}
}
}
}

//RESERVED FOR SECOND LAB
//int makeMove(const char board[26][26], int n, char turn, int *row, int *col) {
	void make_move(char board[26][26], int n, int row, int col, char turn)
{
    int rowdelta = 0;                   /* Row increment              */
   int coldelta = 0;                   /* Column increment           */
   int x = 0;                          /* Row index for searching    */
   int y = 0;                          /* Column index for searching */
   char opponent = (turn == 'W')? 'B' : 'W';  /* Identify opponent */

   board[row][col] = turn;           /* Place the player counter   */

   /* Check all the squares around this square */
   /* for the opponents counter                */
   for(rowdelta = -1; rowdelta <= 1; rowdelta++)
     for(coldelta = -1; coldelta <= 1; coldelta++)
     { 
       /* Don't check off the board, or the current square */
       if(row + rowdelta < 0 || row + rowdelta >= n ||
          col + coldelta < 0 || col + coldelta >= n || 
                               (rowdelta==0 && coldelta== 0))
         continue;

       /* Now check the square */
       if(board[row + rowdelta][col + coldelta] == opponent)
       {
         /* If we find the opponent, search in the same direction */
         /* for a player counter                                  */
         x = row + rowdelta;        /* Move to opponent */
         y = col + coldelta;        /* square           */

         for(;;)
         {
           x += rowdelta;           /* Move to the      */
           y += coldelta;           /* next square      */ 

           /* If we are off the board give up */
           if(x < 0 || x >= SIZE || y < 0 || y >= SIZE)
             break;
 
           /* If the square is blank give up */
           if(board[x][y] == 'U')
             break;

           /* If we find the player counter, go backwards from here */
           /* changing all the opponents counters to player         */
           if(board[x][y] == turn)
           {
             while(board[x-=rowdelta][y-=coldelta]==opponent) /* Opponent? */
               board[x][y] = turn;    /* Yes, change it */
			   printf ("%c", board);
             break;                     /* We are done    */
           } 
         }
       }
     }
}

//Checks for the valid moves
int valid_moves(char board[26][26], int moves[26][26], char player)
{
   int rowdelta = 0;     /* Row increment around a square    */
   int coldelta = 0;     /* Column increment around a square */
   int row = 0;          /* Row index                        */
   int col = 0;          /* Column index                     */
   int x = 0;            /* Row index when searching         */
   int y = 0;            /* Column index when searching      */
   int no_of_moves = 0;  /* Number of valid moves            */

   /* Set the opponent            */
   char opponent = (player == 'W')? 'B' : 'W';    

   /* Initialize moves array to zero */
   for(row = 0; row < SIZE; row++)
     for(col = 0; col < SIZE; col++)
       moves[row][col] = 0;

   /* Find squares for valid moves.                           */
   /* A valid move must be on a blank square and must enclose */
   /* at least one opponent square between two player squares */
   for(row = 0; row < SIZE; row++)
     for(col = 0; col < SIZE; col++)
     {
       if(board[row][col] != 'U')   /* Is it a blank square?  */
         continue;                  /* No - so on to the next */

       /* Check all the squares around the blank square  */ 
       /* for the opponents counter                      */
       for(rowdelta = -1; rowdelta <= 1; rowdelta++)
         for(coldelta = -1; coldelta <= 1; coldelta++)
         { 
           /* Don't check outside the array, or the current square */
           if(row + rowdelta < 0 || row + rowdelta >= SIZE ||
              col + coldelta < 0 || col + coldelta >= SIZE || 
                                       (rowdelta==0 && coldelta==0))
             continue;

           /* Now check the square */
           if(board[row + rowdelta][col + coldelta] == opponent)
           {
             /* If we find the opponent, move in the delta direction  */
             /* over opponent counters searching for a player counter */
             x = row + rowdelta;                /* Move to          */
             y = col + coldelta;                /* opponent square  */

             /* Look for a player square in the delta direction */
             for(;;)
             {
               x += rowdelta;                  /* Go to next square */
               y += coldelta;                  /* in delta direction*/

               /* If we move outside the array, give up */
               if(x < 0 || x >= SIZE || y < 0 || y >= SIZE)
                 break;

               /* If we find a blank square, give up */ 
               if(board[x][y] == 'U')
                 break;
                /*  If the square has a player counter */
                /*  then we have a valid move          */
               if(board[x][y] == player)
               {
                 moves[row][col] = 1; 
                    printf ("%c%c\n",97+row,97+col);/* Mark as valid */
                 no_of_moves++;         /* Increase valid moves count */
                 break;                 /* Go check another square    */
               }
             } 
           } 
         }  
     }
   return no_of_moves; 
}
#ifndef COMPETE_MODE // DO NOT DELETE THIS LINE
//MAIN FUNCTION
 /* Board size - must be even */
int main(void)
{
//Seeking user input
int moves[26][26] = { 0 };
int boardDimension = 0;
printf ("Enter the board dimension: ");
scanf ("%d", &boardDimension);
char board [26][26];
printBoard (board, boardDimension);
configurateBoard (board, boardDimension);
printf ("Available moves for W:\n");
valid_moves(board,moves,'W');
printf ("Available moves for B:\n");
valid_moves(board,moves,'B');
//checkAvailableMoves (board, boardDimension, 'W'); //Checks available moves for white
//checkAvailableMoves (board, boardDimension, 'B'); //Checks available moves for black
   printf ("Enter a move:\n");
   char position;
   char row;
   char column;
   scanf ("%c%c%c", &position, &row, &column);
   int row2 = ((row) - 'a');
   int col2 = ((column) - 'a');
//printf ("%d\n", ((row) - 'a'));//acquires the value of the row in the array
//printf ("%d\n", ((column) - 'a')); //acquires the value of the column in the array
   make_move(board, boardDimension, row2, col2, position);
 return 0;
}
#endif // DO NOT DELETE THIS LINE