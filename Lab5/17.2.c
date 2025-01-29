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
	struct geoCoord{
		double latitude;
		double longitude;
	};

	struct geoCoord* waypoints = NULL;
	int rows = 7;
	int columns = 2;
	int numWaypoints = 0;

	waypoints = (struct geoCoord*)malloc(numWaypoints * sizeof(struct geoCoord));

	while (1)
	{
		printf("Enter the number of waypoints: ");
		if (scanf("%d", &numWaypoints) == 1 && numWaypoints > 0)
		{
			break;
		}
		else
		{
			printf("Try again (expected number >= 0):\n");
			while (getchar() != '\n'); // Clear input buffer
		}
	}

	for (int i = 0; i < numWaypoints; i++) {
		while (1) {
			printf("Waypoint %d as <latitude> <longitude>: ", i + 1);
			if (scanf("%lf %lf", &waypoints[i].latitude, &waypoints[i].longitude) != 2) {
				printf("Invalid input (expected <latitude> <longitude>): Try again.\n");
				while (getchar() != '\n'); // Clear input buffer
			}
			else 
			{
				break;
			}
		}
	}

	// Calculate the overall route length
	double total_distance = 0.0;
	for (int i = 0; i < numWaypoints - 1; i++) {
		total_distance += distanceKm(waypoints[i].latitude,waypoints[i + 1].latitude, waypoints[i].longitude, waypoints[i + 1].longitude);
	}

	// Output: Total travel distance
	printf("By taking this route you will travel %.2f km.\n", total_distance);

	free(waypoints);

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

/*
double distanceKm(struct geoCoord* coord1, struct geoCoord* coord2) {
	double radLat1 = degreesToRadians(coord1->latitude);
	double radLat2 = degreesToRadians(coord2->latitude);
	double radLon1 = degreesToRadians(lon1);
	double radLon2 = degreesToRadians(lon2);

	return EarthRadius * acos((sin(radLat1) * sin(radLat2)) + (cos(radLat1) * cos(radLat2) * cos(fabs(radLon2 - radLon1))));
}
*/

void countdown(int i) {

	//for (int n = i; n >= 0; n--) {
	for (; i >= 0; i--) {
		printf("%d ", i);
	}
}
