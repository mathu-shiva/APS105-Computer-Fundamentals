#include <stdio.h>
#include <math.h>

/*
 * File: Lab2Part2.c
 * Author: Mathura Shivakaran
 * Date: Jan 28, 2021
 * --------------------------
 * Description:
 * Rounding prices to the nearest nickel
 */
 
int main(int argc, char **argv)
{
	//Initialization of variables
	double enteredPrice = 0;
	double roundedPrice = 0;
	const int NICKELS_IN_DOLLAR = 20;
	
	//Gaining input from the user
	printf ("Enter the price as a float with two decimals: ");
	scanf ("%lf", &enteredPrice);
	
	//Rounding and outputting the total charge
	roundedPrice = (round(enteredPrice*NICKELS_IN_DOLLAR)/NICKELS_IN_DOLLAR);
	printf ("The total charge is : %.2lf\n", roundedPrice);
	
	return 0;
}
