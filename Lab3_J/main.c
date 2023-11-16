#include <stdio.h>
#include "Location/point.h"


int main() {
    struct Point points[] = {
            {53.557078, 10.023109, "Haw"},
            {48.858363, 2.294481, "Eiffel Tower"},
            {39.562553, 2.661947, "Mallorca"},
            {36.156214, -115.148736, "Las Vegas"},
            {-22.971177, -43.182543, "Copacabana"},
            {21.281004, -157.837456, "Waikiki"},
            {-28.002695, 153.431781, "Surfer's Paradise"}
    };

    printf("%-20s | %-20s | %-25s\n", "Location", "Distance to HAW (km)", "Local distance to HAW (km)");
    printf("------------------------------------------------------------------------\n");

    for (int i = 0; i < sizeof(points) / sizeof(points[0]); i++ ){
        printf("%-20s | %-20.1f | %-25.1f\n", points[i].name, distanceKm(&points[0], &points[i]), localDistanceKm(&points[0], &points[i]));
    }

    return 0;
}
