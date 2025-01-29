#define _CRT_NO_SECURE_DEPRECATE
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#define SIZE 9
#define EarthRadius 6378.388

double degreesToRadians(double degrees); // Convert degrees to radians
double distanceKm(double lat1, double lon1, double lat2, double lon2);// To calculate the distance between two points
double getRouteLengthKm(double* lon, double* lat, int n);//to get the distance of the route in km

int main(void)
{
    double lat[SIZE] = { 53.557029 ,53.557166 ,53.557274 ,53.560288 ,53.561306 ,53.562015 ,53.558241 ,53.557900 ,53.557203};
    double lon[SIZE] = { 10.022918 ,10.021343 ,10.020297 ,10.014906 ,10.015426 ,10.016568 ,10.023244 ,10.022142 ,10.022632};

    double totalDistance = getRouteLengthKm(lon, lat, SIZE);

    printf("The total route length: %2f km\n", totalDistance);
	//getchar();
	return 0;
}

// Convert degrees to radians
double degreesToRadians(double degrees) 
{  
    return degrees * M_PI / 180.0;
}

// To calculate the distance between two points
double distanceKm(double lat1, double lat2, double lon1, double lon2)
{
    double radLat1 = degreesToRadians(lat1);
    double radLat2 = degreesToRadians(lat2);
    double radLon1 = degreesToRadians(lon1);
    double radLon2 = degreesToRadians(lon2);

    return EarthRadius * (acos((sin(radLat1) * sin(radLat2)) + (cos(radLat1) * cos(radLat2) * cos(fabs(radLon2 - radLon1)))));
}

//to get the distance of the route in km
double getRouteLengthKm(double *lon, double *lat, int n)
{
    double totalDistance = 0.0;

    for (int i = 0; i < n - 1; i++)
    {
        totalDistance += distanceKm(*lat, *(lat + 1), *lon, *(lon + 1));
        lat++;
        lon++;
    }

    //adding the final distance back to the original position
    totalDistance += distanceKm(*lat, *(lat - n + 1), *lon, *(lon - n + 1));
    return totalDistance;
}