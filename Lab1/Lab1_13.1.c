#include<stdio.h>	
// Lab1A 13.1, author: Heshini Jayaweera
int main(void) {
	int first = 7; // first operand for basic calculations
	int second = 3;
	int addition;
	int substraction;
	int multiplication;
	int division;
	int remainder;

	addition = first + second;            //arithmetic operations
	substraction = first - second;
	multiplication = first * second;
	division = first / second;
	remainder = first % second;

	printf("Simple Calculator:\n______________\n1st operand : %d \n2nd operand : %d \n", first, second);
	
	printf("7 + 3 = %d \n", addition);
	printf("7 - 3 = %d \n", substraction);
	printf("7 * 3 = %d \n", multiplication);
	printf("7 / 3 = %d \n", division);
	printf("7 %% 3 = %d \n", remainder);

	getchar();
	return 0;
}
