#include "functions.h"

double degreesToRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

bool isNorthernHemisphere(double lat) {
    return lat > 0.0;
}

bool isSouthernHemisphere(double lat) {
    return lat < 0.0;
}

double localDistanceKm(double lat1_, double lon1_, double lat2_, double lon2_) {
    double delY = 111.3 * fabs(lat1_ - lat2_);
    double delX = 111.3 * cos((degreesToRadians(lat1_)+degreesToRadians(lat2_))/2.0) * fabs(lon1_-lon2_);
    double d = sqrt(pow(delX,2) + pow(delY,2));
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
