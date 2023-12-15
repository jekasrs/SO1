#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "geoCoord.h"
#include "functions.h"

int main() {
    // read number of points from std input
    printf("Enter number of way points: ");
    int num = 0;
    while (scanf("%d", &num) != 1 || num <= 0) {
        printf("Try again (expected number > 0): ");
        while (getchar() != '\n');
    }

    // allocate dynamical array for points
    struct geoCoord* points = (struct geoCoord *) malloc(num* sizeof(struct geoCoord));

    // read lat and lon from std input
    printf("Enter way points as \"<latitude> <longitude>\"\n");
    for (int i = 0; i < num; i++){
        printf("Way point %d: ", i+1);
        while (scanf("%lf %lf", &points[i].lat, &points[i].lon) != 2) {
            printf("Invalid input (expected\"<latitude> <longitude>\")\n");
            printf("Way point %d: ", i+1);
            while (getchar() != '\n');
        }
    }

    // count overall length of the route
    double length = 0.0;

    for (int j = 0; j < num - 1; j++) {
        length += distanceKm(points[j].lat, points[j].lon, points[j + 1].lat, points[j + 1].lon);
    }
    printf("By taking this route you will travel: %.1f ", length);

    free(points);

    return 0;
}
