#ifndef BDD_FOR_C_TEST_FLOATING_POINT_COMPARISON_H
#define BDD_FOR_C_TEST_FLOATING_POINT_COMPARISON_H

#include <stdint.h>

typedef int8_t result_t;

result_t compareDoubleWithAbsoluteEpsilon(double d1, double d2, double absoluteEpsilon);
result_t compareDoubleWithRelativeEpsilon(double d1, double d2, double relativeEpsilon);
result_t compareDoubleWithAbsoluteAndRelativeEpsilon(double d1,
                                                     double d2,
                                                     double absoluteEpsilon,
                                                     double relativeEpsilon);

//const result_t INVALID_PARAMETER_EXCEPTION = -2;

#endif //BDD_FOR_C_TEST_FLOATING_POINT_COMPARISON_H
