#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

// Lab1A 13.3, Author : Heshini Jayaweera

int main(void) {
	int year;
	int y1;
	int y2;
	int y3;
	int y4; //Here y1, y2, y3 and y4 represents each number of the birth year from the right side respectively

	printf("Enter your year of birth: \n");// the user inputs his/her birth year
	scanf("%d", &year);

	y1 = year % 10;
	y2 = (year / 10) % 10;
	y3 = (year / 100) % 10;
	y4 = (year / 1000) % 10; // arithmetic operations for getting each number of the year

	printf("The digit sum of %d is: %d \n", year, y1 + y2 + y3 + y4);

	getchar();
	return 0;
}
