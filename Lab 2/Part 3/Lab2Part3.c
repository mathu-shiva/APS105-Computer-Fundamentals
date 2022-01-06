#include <stdio.h>
#include <math.h>

/*
 * File: Lab2Part3.c
 * Author: Mathura Shivakaran
 * Date: Jan 28, 2021
 * --------------------------
 * Description:
 * Calculating the future value after a number of years of an investement
 */
 
int main(int argc, char **argv)
{
	//Initialization of variables
	double initialDeposit = 0;
	double interestRate = 0;
	double compoundedTimes = 0;
	double yearsInvested = 0;
	double futureValue = 0;
	
	//Gaining input from the user
	printf ("The amount deposited P: ");
	scanf ("%lf", &initialDeposit);
	printf ("The interest rate r: ");
	scanf ("%lf", &interestRate);
	printf ("The number of times the interest is compounded n: ");
	scanf ("%lf", &compoundedTimes);
	printf ("The period of time t the money is invested (in years): ");
	scanf ("%lf", &yearsInvested);
	
	//Calculation of the future value of investement
	futureValue = (initialDeposit * pow((1 + interestRate/compoundedTimes), compoundedTimes * yearsInvested));
	
	//Output of the future value of investement
	printf ("The future value of the investment A: %.2lf\n", futureValue);
	
	return 0;
}