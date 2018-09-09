#include <string.h>
#include <stdint.h>

#include "bdd-for-c.h"

#include "floating-point-comparison.h"

spec("Floating point number comparisons") {
    describe("compareDoubleWithAbsoluteEpsilon") {
        it("should return 0 for identical floating point numbers") {
            double d1 = 0.0;
            double d2 = 0.0;
            double absEps = 0.1;

            result_t comparisonResult = compareDoubleWithAbsoluteEpsilon(d1, d2, absEps);
            check(comparisonResult == 0);
        }

        it("should ignore sign of absolute epsilon") {
            double d1 = 0.0;
            double d2 = 0.0;
            double negativeAbsEps = -0.1;

            result_t comparisonResult = compareDoubleWithAbsoluteEpsilon(d1, d2, negativeAbsEps);
            check(comparisonResult == 0);
        }

        it("should return 0 for approximately equal floating point numbers where one number is only slightly larger") {
            double d1 = 0.0;
            double d2 = 0.05;
            double absEps = 0.2;

            result_t comparisonResult = compareDoubleWithAbsoluteEpsilon(d1, d2, absEps);
            check(comparisonResult == 0);
        }

        it("should return 0 for approximately equal floating point numbers where one number is only slightly smaller") {
            double d1 = 0.0;
            double d2 = -0.05;
            double absEps = 0.2;

            result_t comparisonResult = compareDoubleWithAbsoluteEpsilon(d1, d2, absEps);
            check(comparisonResult == 0);
        }

        it("should return 0 for approximately equal floating point numbers where one number is bigger at the upper "
           "bound") {
            double d1 = 0.0;
            double d2 = 0.1;
            double absEps = 0.2;

            result_t comparisonResult = compareDoubleWithAbsoluteEpsilon(d1, d2, absEps);
            check(comparisonResult == 0);
        }

        it("should return 0 for approximately equal floating point numbers where one number is smaller at the lower "
           "bound") {
            double d1 = 0.0;
            double d2 = -0.1;
            double absEps = 0.2;

            result_t comparisonResult = compareDoubleWithAbsoluteEpsilon(d1, d2, absEps);
            check(comparisonResult == 0);
        }

        it("should return 1 when one number is sufficiently greater than another") {
            double d1 = 0.10000001;
            double d2 = 0.0;
            double absEps1 = 0.2;

            result_t comparisonResult1 = compareDoubleWithAbsoluteEpsilon(d1, d2, absEps1);
            check(comparisonResult1 == 1);

            double d3 = 200000000.1;
            double d4 = 100000000.0;
            double absEps2 = 200000000.0;
            result_t comparisonResult2 = compareDoubleWithAbsoluteEpsilon(d3, d4, absEps2);
            check(comparisonResult2 == 1);
        }

        it("should return -1 when one number is sufficiently smaller than another") {
            double d1 = -0.10000001;
            double d2 = 0.0;
            double absEps1 = 0.2;

            result_t comparisonResult1 = compareDoubleWithAbsoluteEpsilon(d1, d2, absEps1);
            check(comparisonResult1 == -1);

            double d3 = -200000000.1;
            double d4 = -100000000.0;
            double absEps2 = 200000000.0;
            result_t comparisonResult2 = compareDoubleWithAbsoluteEpsilon(d3, d4, absEps2);
            check(comparisonResult2 == -1);
        }
    }
}