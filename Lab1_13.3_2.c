#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
// Lab1A 13.3 2nd method, Author : Heshini

int main(void) {
	int year;
	int sum; 
	int y1, y2, y3, y4; 
	
    printf("enter your dob one digit at a time:  \n "); 
	scanf("%d%d%d%d", &y1, &y2, &y3, &y4);

	sum = y1 + y2 + y3 + y4; 

	printf("The digit sum is: %d \n", sum);
	getchar();
	return 0;
}