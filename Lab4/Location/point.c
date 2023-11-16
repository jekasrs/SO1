#include "point.h"
#include "math.h"

double degreesToRadians(double degrees) {
    return degrees * (M_PI / 180.0);
}

bool isNorthernHemisphere(struct Point* point){
    return point->lat > 0.0;
}

bool isSouthernHemisphere(struct Point* point){
    return point->lat < 0.0;
}

bool isEasternHemisphere(struct Point* point){
    return point->lon > 0.0;
}

bool isWesternHemisphere(struct Point* point){
    return point->lon < 0.0;
}

double localDistanceKm(struct Point* pointA, struct Point* pointB){
    double delY = 111.3 * fabs(pointA->lat - pointB->lat);
    double delX = 111.3 * cos((degreesToRadians(pointA->lat)+degreesToRadians(pointB->lat))/2.0) * fabs(pointA->lon-pointB->lon);
    double d = sqrt(pow(delX,2) + pow(delY,2));
    return d;
}

double distanceKm1(struct Point* pointA, struct Point* pointB){
    double lat1 = degreesToRadians(pointA->lat);
    double lat2 = degreesToRadians(pointB->lat);
    double lon1 = degreesToRadians(pointA->lon);
    double lon2 = degreesToRadians(pointB->lon);
    double d = 6378.388 * acos(sin(lat1)*sin(lat2) + cos(lat1)*cos(lat2)*cos(lon2 - lon1));
    return d;
}

double distanceKm(double lat1_, double lon1_, double lat2_, double lon2_){
    double lat1 = degreesToRadians(lat1_);
    double lat2 = degreesToRadians(lat2_);
    double lon1 = degreesToRadians(lon1_);
    double lon2 = degreesToRadians(lon2_);
    double d = 6378.388 * acos(sin(lat1)*sin(lat2) + cos(lat1)*cos(lat2)*cos(lon2 - lon1));
    return d;
}