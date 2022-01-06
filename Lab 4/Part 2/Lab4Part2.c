#include <stdio.h>

int main(int argc, char **argv)
{
	//Initialization of variables
	int rows = 0;
	int i = 0;
	int j = 0;
	
	//Seeking and scanning user input
	printf ("Enter the number of rows in the triangle: ");
	scanf ("%d", &rows);
	
	if (1 <= rows && rows <=20)
	{
		//Loops the print for each row
	for (i = 1; i <= rows; i++)
	{
		//Prints the spaces in each line prior to the asterisks
		for (j = i; j < rows; j++)
		{
			printf (" ");
		}
		//Prints the asterisks and spaces in the triangle
		for (j = 1; j <= (2*i-1); j++)
		{
			//Prints the asterisks in the triangle
			if (i == rows || j == 1 || j == (2*i-1))
			{
				printf ("*");
			}
			//Prints the spaces in the triangle
			else {
				printf (" ");
			}
		}
		printf ("\n");
	}
	}
	else {
		;
	}
	
	return 0;
}
