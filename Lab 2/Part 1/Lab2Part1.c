#include <stdio.h>
#include <math.h>

/*
 * File: Lab2Part1.c
 * Author: Mathura Shivakaran
 * Date: Jan 28, 2021
 * --------------------------
 * Description:
 * Calculating the money saved
 * For every 3 dollars spent, you get 10 cents back 
 */
 
int main(int argc, char **argv)
{
	//Initialization of variables
	double poundPrice = 0;
	double totalWeight = 0;
	double totalCharge = 0;
	double savedAmount = 0;
	
	//Receiving input from the user
	printf ("Enter the price per pound: ");
	scanf ("%lf", &poundPrice);
	printf ("Enter the total weight: ");
	scanf ("%lf", &totalWeight);
	
	//Calculating saved amount and the total charge
	totalCharge = (poundPrice*totalWeight);
	savedAmount = (floor(totalCharge/3)*0.1);
	totalCharge = (totalCharge - savedAmount);
	
	//Outputting the saved amount and the total charge
	printf ("The total charge is: %.2lf\n", totalCharge);
	printf ("You saved: %.2lf\n", savedAmount);
	
	return 0;
}
