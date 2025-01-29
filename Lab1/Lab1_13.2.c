#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>	
// Lab1A 13.2, author: Heshini Jayaweera

int main(void) {
	int first; // first operand for basic calculations
	int second;
	int addition;
	int substraction;
	int multiplication;
	int division;
	int remainder;

	printf("Enter the first operand: ");
	scanf("%d", &first);
	printf("Enter the second operand: ");
	scanf("%d", &second);

	addition = first + second;
	substraction = first - second;
	multiplication = first * second;
	division = first / second;
	remainder = first % second;

	printf("Simple Calculator:\n______________\n1st operand : %d \n2nd operand : %d \n", first, second);
	
	printf("%d + %d = %d \n", first, second, addition);
	printf("%d - %d = %d \n", first, second, substraction);
	printf("%d * %d = %d \n", first, second, multiplication);
	printf("%d / %d = %d \n", first, second, division);
	printf("%d %% %d = %d \n", first, second, remainder);

	getchar();
	return 0;
}
