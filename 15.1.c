#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
#include<stdio.h>
#include <math.h>
#define EarthRadius 6378.388

// Lab3 15.1.2, author: Heshini Jayaweera
double degreesToRadians(double degrees);
double deltaYCalculation(double lat1, double lat2);
double deltaXCalculation(double lat1, double lat2, double lon1, double lon2);
double localDistanceCalculation(double deltaX, double deltaY);
double globalDistanceCalculation(double lat1, double lon1, double lat2, double lon2);

int main(void) {
    double lat1;
    double lat2;
    double lon1;
    double lon2;
    double deltaY;
    double deltaX;
    double localDistance;
    double globalDistance;

    printf("Enter the latitude at 1st location: ");
    scanf("%lf", &lat1);
    printf("Enter the longitude at 1st location: ");
    scanf("%lf", &lon1);
    printf("Enter the latitude at 2nd location: ");
    scanf("%lf", &lat2);
    printf("Enter the longitude at 2nd location: ");
    scanf("%lf", &lon2);

    if ((-90 < lat1) && (lat1 < 90) && (-90 < lat2) && (lat2 < 90) && (-180 < lon1) && (lon1 < 180) && (-180 < lon2) && (lon2 < 180)) {
        deltaY = deltaYCalculation(lat1, lat2);
        deltaX = deltaXCalculation(lat1, lat2, lon1, lon2);
        localDistance = localDistanceCalculation(deltaX, deltaY);
        globalDistance = globalDistanceCalculation(lat1, lon1, lat2, lon2);
        printf("\ndelta y: %.2lf km\n", deltaY);
        printf("delta x: %.2lf km\n", deltaX);
        printf("Local distance between the two locations: %.2lf km\n", localDistance);
        printf("More accurate local distance between the two locations: %.2lf km\n", globalDistance);
    }
    else
    {
        printf("\nCheck the valid ranges for the latitudes and longitudes!\n");
    }

    getchar();
    return 0;
}

double degreesToRadians(double degrees) {  // Convert degrees to radians
    return degrees * M_PI / 180.0;
}

double deltaYCalculation(double lat1, double lat2) {
    return 111.3 * fabs(lat1 - lat2);
}

double deltaXCalculation(double lat1, double lat2, double lon1, double lon2) {
    double averageLat = degreesToRadians(lat1 + lat2) / 2.0;
    return 111.3 * cos(averageLat) * fabs(lon1 - lon2); // degrees to radians
}

double localDistanceCalculation(double deltaX, double deltaY) {
    return sqrt(deltaX * deltaX + deltaY * deltaY);
}

double globalDistanceCalculation(double lat1, double lon1, double lat2, double lon2) {
    double radLat1 = degreesToRadians(lat1);
    double radLat2 = degreesToRadians(lat2);
    double radLon1 = degreesToRadians(lon1);
    double radLon2 = degreesToRadians(lon2);

    return EarthRadius * acos(
        sin(radLat1) * sin(radLat2) +
        cos(radLat1) * cos(radLat2) * cos(radLon2 - radLon1)
    );
}





