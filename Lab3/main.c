#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "functions.h"

int main() {
    time_t t;
    srand(time(&t));

    float arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = (float) rand() / (float) (RAND_MAX / 180) - 90;
        printf("Latitude = %f; ", arr[i]);
        printf("isNothernHemishere() = %d; ", isNorthernHemisphere(arr[i]));
        printf("isSouthernHemishpere() = %d;\n", isSouthernHemisphere(arr[i]));
    }

    char* names[7] = {"HAW Hamburg", "Eiffel Tower", "Palma de Mallorca",
        "Las Vegas", "Copacabana", "Waikiki Beach", "Surfer's Paradise"};
    float data[7][2] = {{53.557078, 10.023109}, {48.858363, 2.294481}, {39.562553, 2.661947},
        {36.156214, -115.148736}, {-22.971177, -43.182543}, {21.281004, -157.837456}, {-28.002695, 153.431781}};

    printf("-----Location-----|--Latitude--|--Longitude--|-Distance to HAW (15.3)-|-Distance to HAW (15.4)-|\n");
    for (int i = 0; i < 7; i++) {
        printf("%17s | %10f | %11f | %22f | %22f |\n", names[i], data[i][0], data[i][1],
            localDistanceKm(data[i][0], data[i][1], data[0][0], data[0][1]),
            distanceKm(data[i][0], data[i][1], data[0][0], data[0][1]));
    }

    return 0;
}
