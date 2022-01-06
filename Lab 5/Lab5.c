#include <stdio.h>

//Factorial Function
int factorial (int n)
{
	int calculatedFactorial = (1);
	//For Loop to calculate the factorial of the variable
	for (int i = 1; i <= n; i++)//the i++ helps multiply all the numbers till the n
	{
		calculatedFactorial = (calculatedFactorial * i);
	}
	return (calculatedFactorial);//returns the value back to the calling function
}

//Choose Function
int choose (int n, int r)
{
	//Calculating n! in the nCr Formula
	int nFactorial = 0;
	nFactorial = factorial(n);//Calling the factorial function to calculate
	
	//Calculating the r! in the nCr Formula
	int rFactorial = 0;
	rFactorial = factorial(r);//Calling the factorial function to calculate
	
	//Calculating the (n-r)! in the nCr Formula
	int bracketFactorial = 0;
	bracketFactorial = factorial(n-r);//Calling the factorial function to calculate
	
	//Calculation of nCr  using the Formula
	int nCr = factorial(n)/(factorial(r)*factorial(n-r));
	return (nCr);//returns the value back to the calling function
}

//Spaces Function
int spaces (int s)
{
	for (int i = 0; i <= s; i++)
	{
		printf (" ");//Prints the spaces prior to the printed values in each row
	}
	return (0);
}
//Triangle Function
void triangle (int n)//void indicates that there is no return value
{
	for (int i = 0; i < n; i++)//i acts as the n in the nCr formula
	{
		int numberOfSpaces = (0);
		numberOfSpaces = spaces(3*n - (3*i) - 4);//Calling the spaces function
		
		for (int j = 0; j <= i; j++)//j acts as the r in the nCr formula
		{
			int answer = (0);
			answer = choose (i, j);//calling the choose function (which calls the factorial function)
			printf ("%d", answer);//prints the final answer in the triangle
			if (answer < 10)
			{
				printf ("     ");//adjusts spacing for single-digit numbers
			}
			else if (answer >= 10 && answer <100)
			{
				printf ("    ");//adjusts spacing for double-digit numbers
			}
			else
			{
				printf ("   ");//adjusts spacing for triple-digit numbers
			}
		}
		printf ("\n");//Allows triangle to form the next line when the last row is done printing. 
	}
}

//Main Function
int main(int argc, char **argv)
{
	for (;;)//Infinite loop
	{
		int n = 0;
		//Seeking and scanning user input
		printf ("Enter the number of rows: ");
		scanf ("%d", &n);
		
		if (n >= 0 && n <= 13)
		{
			;//allows code to run normally if n is between 1 and 13 inclusive
		}
		else 
		{
			break;//terminates the loop if the input is invalid
		}
		//Calling the triangle function (which calls the choose function which calls the factorial function)
		triangle (n);
	}
	
	return 0;
}
