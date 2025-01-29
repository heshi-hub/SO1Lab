#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EarthRadius 6378.388

double degreesToRadians(double degrees); // Convert degrees to radians
double distanceKm(double lat1, double lat2, double lon1, double lon2);// To calculate the distance between two points

int main(void)
{
	double** latlon;
	int rows = 7;
	int columns = 2;
	int waypoints = 0;
	double totalDistance = 0.0;

	if ((latlon = (double**)malloc(rows * sizeof(double*))) == NULL) //Dynamic memory allocation for the row pointers
		exit(EXIT_FAILURE);

	for (int i = 0; i < rows; i++) //Dynamic memory allocation for each row of longitude and latitude independently
	{
		if ((latlon[i] = (double*)malloc(columns * sizeof(double))) == NULL)
			exit(EXIT_FAILURE);
	}

	while (1)
	{
		printf("Enter the number of waypoints: ");
		if (scanf(" %d", &waypoints) == 1 && waypoints > 0)
		{
			break;
		}
		else
		{
			printf("Try again (expected number >= 0):\n");
			while (getchar() != '\n'); // Clear input buffer
		}
	}

	// Ensure waypoints do not exceed rows
	if (waypoints > rows)
	{
		printf("Number of waypoints exceeds maximum supported (%d).\n", rows);
		exit(EXIT_FAILURE);
	}

	// Input: Geographic coordinates of all waypoints
	for (int i = 0; i < waypoints; i++)
	{
		while (1)
		{
			printf("Waypoint %d as <latitude> <longitude>: ", i + 1);
			if (scanf(" %lf %lf", &latlon[i][0], &latlon[i][1]) != 2)
			{
				printf("Invalid input (expected <latitude> <longitude>): Try again.\n");
				while (getchar() != '\n'); // Clear input buffer
			}
			else
			{
				break;
			}
		}
	}

	for (int i = 0; i < waypoints - 1; i++)
	{
		totalDistance += distanceKm(latlon[i][0], latlon[i + 1][0], latlon[i][1], latlon[i + 1][1]);
	}

	// Output: Total travel distance
	printf("By taking this route you will travel %.2f km.\n", totalDistance);

	for (int i = 0; i < rows; i++)
	{
		free(latlon[i]);
	}
	free(latlon);

	while (getchar() != '\n');
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
