#include <stdio.h>

/*
 * File: Lab1.c
 * Author: Mathura Shivakaran
 * Date: Jan 28, 2021
 * --------------------------
 * Description:
 * obtaining half the sum of the numbers
 * obtaining twice the product of the numbers
 * obtaining the average of the numbers
 */
 
int main(int argc, char **argv)
{
	
	double inputNumber1 = 0;
	double inputNumber2 = 0;
	double inputNumber3 = 0;
	double sumHalf = 0;
	double twiceProduct = 0;
	double average = 0;
	
	//Obtaining User Input
	printf("Enter First Number: ");
	scanf ("%lf", &inputNumber1);
	printf("Enter Second Number: ");
	scanf ("%lf", &inputNumber2);
	printf("Enter Third Number: ");
	scanf ("%lf", &inputNumber3);
	
	//Calculating and Outputting Half the Sum
	sumHalf = (inputNumber1 + inputNumber2 + inputNumber3)/2;
	printf("Half the Sum: %.2lf\n", sumHalf);
	
	//Calculating and Outputting Twice the Product
	twiceProduct = (inputNumber1*inputNumber2*inputNumber3)*2;
	printf("Twice the Product: %.2lf\n", twiceProduct);
	
	//Calculating and Outputting the Average
	average = (inputNumber1 + inputNumber2 + inputNumber3)/3;
	printf("Average: %.2lf\n", average);
	return 0;
}
