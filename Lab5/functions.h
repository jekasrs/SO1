#ifndef LAB5_FUNCTIONS_H
#define LAB5_FUNCTIONS_H

#define _USE_MATH_DEFINES
#include "math.h"
#include <stdbool.h>

bool isNorthernHemisphere(float);
bool isSouthernHemisphere(float);
double localDistanceKm(double, double, double, double);
double distanceKm(double, double, double, double);

#endif
