#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include <math.h>
#include <stdint.h>
// Lab2 14.2, author: Heshini Jayaweera

int main(void) {
	    unsigned long long onField = 1;    // Grains on the current field
		unsigned long long sum = 0;  // Cumulative sum of grains
		unsigned long long totalGrains = 0;
		double weightPerGrainTons = 55.0e-9;
		double worldWheatProductionTons = 735.8e6;
		double weightChessMg;
		double weightChessTons = 0;
		double p = 0;

		printf("|Field | On Field                | Sum                                  |\n");
		printf("+------+-------------------------+--------------------------------------+\n");

		for (int field = 1; field <= 64; field++) {
			sum += onField;
			
			printf("|%5d |     %19llu | %25llu (= %.1e)|\n", field, onField, sum, (double)sum);
			if (field % 8 == 0)
				printf("+------+-------------------------+--------------------------------------+\n");

            onField *= 2; // Double the grains for the next field
		}

		totalGrains = sum;
		weightChessTons = (double)totalGrains * weightPerGrainTons;
		p = weightChessTons / worldWheatProductionTons;

		printf("Total weight of wheat on chessboard: %2.3e tons\n" , weightChessTons);
		printf("Ratio to worldwide production,in 2015: p = %.10lf\n", p);
		getchar();
		return 0;
	}


	