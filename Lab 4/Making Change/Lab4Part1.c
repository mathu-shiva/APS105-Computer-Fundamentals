#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
	//Initialization of variables
	int totalValue = 0;
	int quarterTotalValue = 0;
	int dimeTotalValue = 0;
	int nickelTotalValue = 0;
	int centTotalValue = 0;
	int numberOfQuarters = 0;
	int quarterValue = 0;
	int numberOfDimes = 0;
	int dimeValue = 0;
	int numberOfNickels = 0;
	int nickelValue = 0;
	int numberOfCents = 0;
	
	for (; ;)// this is an infinite loop
	{
		//Seeking and scanning user input
		printf ("Please give an amount in cents less than 100: ");
		scanf ("%d", &totalValue);
	
		if (totalValue > 0 && totalValue < 100) {
			printf ("%d cents: ", totalValue); }
		else {
			break; } //breaks the infinite loop if the user input is invalid
	
		//Quarter Calculation
		numberOfQuarters = (floor(totalValue/25));
		quarterValue = (numberOfQuarters*25);
		quarterTotalValue = (totalValue - quarterValue);
	
		//Dime Calculation
		numberOfDimes = (floor(quarterTotalValue/10));
		dimeValue = (numberOfDimes*10);
		dimeTotalValue = (quarterTotalValue - dimeValue);
	
		//Nickel Calculation
		numberOfNickels = (floor(dimeTotalValue/5));
		nickelValue = (numberOfNickels*5);
		nickelTotalValue = (dimeTotalValue - nickelValue);
	
		//Cent Calculation
		numberOfCents = (nickelTotalValue);
		centTotalValue = (nickelTotalValue - numberOfCents);
	
		//Output for quarters
		if (numberOfQuarters == 1) {
			printf ("%d quarter", numberOfQuarters); }
		else if (numberOfQuarters > 1) {
			printf ("%d quarters", numberOfQuarters); }
		else {
			; }
		
		//Printing a period if the total value is 0
		if (quarterTotalValue > 0 && numberOfQuarters > 0) {
			printf (", "); }
		else if (quarterTotalValue > 0 && numberOfQuarters == 0) {
			printf (""); }
	
		
		//Output for dimes
		if (numberOfDimes == 1) {
			printf ("%d dime", numberOfDimes); }
		else if (numberOfDimes > 1) {
			printf ("%d dimes", numberOfDimes); }
		else {
			; }
	
		//Printing a period if the total value is 0
		if (dimeTotalValue > 0 && numberOfDimes > 0) {
			printf (", "); }
		else if (dimeTotalValue > 0 && numberOfDimes == 0) {
			printf (""); }

	
	
		//Output for nickels
		if (numberOfNickels == 1) {
			printf ("%d nickel", numberOfNickels); }
		else if (numberOfNickels > 1) {
			printf ("%d nickels", numberOfNickels); }
		else {
			; }
	
		//Printing a period if the total value is 0
		if (nickelTotalValue > 0 && numberOfNickels > 0) {
			printf (", "); }
		else if (nickelTotalValue > 0 && numberOfNickels == 0) {
			printf (""); }

	
	
		//Output for cents
		if (numberOfCents == 1) {
			printf ("%d cent", numberOfCents); }
		else if (numberOfCents > 1) {
			printf ("%d cents", numberOfCents); }
		else {
			; }
	
		printf (".\n");
	}
	
	
	printf ("Goodbye\n");
	
	return (0);
}
