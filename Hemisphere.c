#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include <math.h>

int isNorthernHemisphere(double latitude); // Check if a coordinate is in the Northern Hemisphere
int isSouthernHemisphere(double latitude); // Check if a coordinate is in the Southern Hemisphere

int main(void) 
{
    printf("This is to find whether a particular location is in the southern Hemisphere, Northern Hemisphere or on the equator. \n\n");
    double latitude;

    printf("Enter the latitude: ");
    scanf("%lf", &latitude);

    if (isNorthernHemisphere(latitude)) {
        printf("The location is in the Northern Hemisphere\n");
    }
    else if (isSouthernHemisphere(latitude)) {
        printf("The location is in the Southern Hemisphere\n");
    }
    else {
        printf("The location is on the Equator\n");
    }
}

// Check if a coordinate is in the Northern Hemisphere
int isNorthernHemisphere(double latitude) 
{ 
    return latitude > 0;
}

// Check if a coordinate is in the Southern Hemisphere
int isSouthernHemisphere(double latitude)
{ 
    return latitude < 0;
}