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
    double** points = (double**)calloc(num, sizeof(double*));
    for (int i = 0; i < num; i++) {
        points[i] = (double*)calloc(2, sizeof(double));
    }

    // read lat and lon from std input
    printf("Enter way points as \"<latitude> <longitude>\"\n");
    for (int i = 0; i < num; i++){
        printf("Way point %d: ", i+1);
        while (scanf("%lf %lf", &points[i][0], &points[i][1]) != 2) {
            printf("Invalid input (expected \"<latitude> <longitude>\")\n");
            printf("Way point %d: ", i+1);
            while (getchar() != '\n');
        }
    }

    // count overall length of the route
    double length = 0.0;
    for (int j = 0; j < num - 1; j++) {
        length += distanceKm(points[j][0], points[j][1], points[j + 1][0], points[j + 1][1]);
    }
    printf("By taking this route you will travel: %.1f ", length);

    for (int i = 0; i < num; i++) {
        free(points[i]);
    }
    free(points);

    return 0;
}
