#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>	
// Lab2 14.1, author: Heshini Jayaweera

int main(void) {
	printf("+----+----+----+----+----+----+----+----+\n");

	for (int row = 8; row >= 1; row--) {
		for (char column = 'a'; column <= 'h'; column++)
		{
			printf("| %c%d ", column, row);
		}
		printf("|\n+----+----+----+----+----+----+----+----+\n");
	}
	
	getchar();
	return 0;
}