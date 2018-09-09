#include <stdint.h>
#include <stdbool.h>

#include "floating-point-comparison.h"

const result_t GREATER = 1;
const result_t EQUAL = 0;
const result_t SMALLER = -1;

int64_t intabs(int64_t i);
double doubleabs(double d);

bool isAbsolutelyApproximatelyEqual(double d1, double d2, double halfAbsEps);

result_t compareDoubleWithAbsoluteEpsilon(double d1, double d2, double absoluteEpsilon) {
    double difference = d1 - d2;

    double absEps = doubleabs(absoluteEpsilon);

    if (isAbsolutelyApproximatelyEqual(d1, d2, absEps)) {
        return EQUAL;
    } else {
        if (d1 > d2) {
            return GREATER;
        } else {
            return SMALLER;
        }
    }
}

bool isAbsolutelyApproximatelyEqual(double d1, double d2, double absEps) {
    double halfEps = absEps / 2.0;
    return doubleabs(d1 - d2) <= halfEps;
}

int64_t intabs(int64_t i) {
    if (i <= 0) {
        return -i;
    }
    return i;
}

double doubleabs(double d) {
    if (d <= 0.0) {
        return -d;
    }
    return d;
}