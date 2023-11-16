#include <stdio.h>
#include <stdlib.h>
#include "Location/point.h"

// task2

void theLongestLength(double locations[][2], int M, double* maxDist, int* maxPoint1, int* maxPoint2);

int main() {
    int N = 9;
    double **points = (double **) malloc(N * sizeof(double *));
    for (int i = 0; i < N; ++i) {
        points[i] = (double *) malloc(2 * sizeof(double));
    }

    // reading data from .txt
    FILE *file = fopen("/Users/evgenijsmirnov/HAW_HAMBURG/SOL1/Lab4/Geo.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Can't open file.\n");
        return 1;
    }
    while (!feof(file)) {
        for (int j = 0; j < N; j++) {
            fscanf(file, "%lf,%lf\n", &points[j][0], &points[j][1]);
        }
    }

    double distance = 0.0;
    for (int j = 0; j < N - 1; j++) {
        distance += distanceKm(points[j][0], points[j][1], points[j + 1][0], points[j + 1][1]);
    }

    distance += distanceKm(points[N - 1][0], points[N - 1][1], points[0][0], points[0][1]);

    printf("Distance is: %.3f km\n", distance);

    // Task2
    char *names[] = {"HAW Hamburg",
                     "Eiffel Tower",
                     "Palma de Mallorca",
                     "Las Vegas",
                     "Copacabana",
                     "Waikiki Beach",
                     "Surfer’s Paradise"};

    int M = 7;
    double locations[7][2] = {
            {53.557078,  10.023109},
            {48.858363,  2.294481},
            {39.562553,  2.661947},
            {36.156214,  -115.148736},
            {-22.971177, -43.182543},
            {21.281004,  -157.837456},
            {-28.002695, 153.431781}
    };
    double maxDist = 0;
    int point1 = 0;
    int point2 = 0;

    theLongestLength(locations, M, &maxDist, &point1, &point2);

    printf("%s and %s have the largest distance (%.2f km).\n"
           "You’d better not walk. Take a flight , instead.\n", names[point1], names[point2], maxDist);

    return 0;
}

void theLongestLength(double locations[][2], int M, double* maxDist, int* maxPoint1, int* maxPoint2) {
    *maxDist = 0.0;
    *maxPoint1 = 0;
    *maxPoint2 = 0;

    for (int i = 0; i < M; i++) {
        double cur_lat1 = locations[i][0];
        double cur_lon1 = locations[i][1];
        for (int j = 0; j < M; j++) {
            if (i == j) continue;
            double lat1 = locations[j][0];
            double lon1 = locations[j][1];

            double current_distance = distanceKm(cur_lat1, cur_lon1, lat1, lon1);
            if (*maxDist < current_distance) {
                *maxDist = current_distance;
                *maxPoint1 = i;
                *maxPoint2 = j;
            }
        }
    }
}