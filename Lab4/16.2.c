#define _CRT_NO_SECURE_DEPRECATE
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#define SIZE 7
#define EarthRadius 6378.388

double degreesToRadians(double degrees);
double distanceKm(double lat1, double lat2, double lon1, double lon2);
double getMaximumDistance(const double coords[][2], int n, int* indexA, int* indexB);

int main(void)
{
	char *names[] = {"HAW Hamburg", "Eiffel Tower", "Palma de Mallorca", "Las Vegas", "Copacabana", "Waikiki Beach", "Surfer’s Paradise"};
	double latlon[][2] = { {53.557078,10.023109}, {48.858363,2.294481}, {39.562553,2.661947}, {36.156214,-115.148736}, {-22.971177,-43.182543}, {21.281004,-157.837456}, {-28.002695,153.431781} };
	int indexA = 0;
	int indexB = 0;

	double maxD = getMaximumDistance(latlon, SIZE, &indexA, &indexB);

	printf("%s and %s have the largest distance (%lf km).\nYou'd better not walk. Take a flight, instead:)\n", names[indexA], names[indexB], maxD );

	return 0;
}

double degreesToRadians(double degrees)
{
	return degrees * M_PI / 180.0;
}

double distanceKm(double lat1, double lat2, double lon1, double lon2)
{
	double radLat1 = degreesToRadians(lat1);
	double radLat2 = degreesToRadians(lat2);
	double radLon1 = degreesToRadians(lon1);
	double radLon2 = degreesToRadians(lon2);

	return EarthRadius * (acos((sin(radLat1) * sin(radLat2)) + (cos(radLat1) * cos(radLat2) * cos(fabs(radLon2 - radLon1)))));
}

double getMaximumDistance(const double coords[][2], int n, int* indexA, int* indexB)
{
	double maxD = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			double distance = distanceKm(coords[i][0], coords[j][0], coords[i][1], coords[j][1]);
			if (distance > maxD)
			{
				maxD = distance;
				*indexA = i;
				*indexB = j;
			}
		}
	}
	return maxD;
}