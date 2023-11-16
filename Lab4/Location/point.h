#ifndef LAB2_POINT_H
#define LAB2_POINT_H

#include <stdbool.h>

// latitude щирота [-90; 90] parallel to the equator - y coordinate
// longitude долгота [-180;180] - x coordinate
// in Euclid geom: latitude is  x
// in Euclid geom: longitude is y

struct Point {
    double lat;
    double lon;
};

double degreesToRadians(double degrees);

bool isNorthernHemisphere(struct Point* point);
bool isSouthernHemisphere(struct Point* point);
bool isEasternHemisphere(struct Point* point);
bool isWesternHemisphere(struct Point* point);

double localDistanceKm(struct Point* pointA, struct Point* pointB);
double distanceKm1(struct Point* pointA, struct Point* pointB);
double distanceKm(double lat1_, double lon1_, double lat2_, double lon2_);

#endif

