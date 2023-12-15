#include "functions.h"

#include "functions.h"

double rads(double degrees) {
    return degrees * M_PI / 180;
}

bool isNorthernHemisphere(float lat) {
    return lat > 0;
}

bool isSouthernHemisphere(float lat) {
    return lat < 0;
}

double localDistanceKm(double lhsLat, double lhsLon, double rhsLat, double rhsLon) {
    double deltaY = 111.3 * fabs(lhsLat - rhsLat);
    double deltaX = 111.3 * cos(rads((lhsLat + rhsLat) / 2.0)) * fabs(lhsLon - rhsLon);

    return sqrt(deltaY * deltaY + deltaX * deltaX);
}

double distanceKm(double lhsLat, double lhsLon, double rhsLat, double rhsLon) {
    return 6378.388 * acos(sin(rads(lhsLat)) * sin(rads(rhsLat)) + cos(rads(lhsLat))
                                                                   * cos(rads(rhsLat)) * cos(rads(rhsLon - lhsLon)));
}
