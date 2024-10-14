#include <stdio.h>
#include "functions.h"

int main(const int argc, const  char** argv) {
    double precision;
    if (!GetPrecision(argc, argv, &precision)) {
        double left = 1e-6, right = 0.9999999999;

        double resultA = IntegrateWithPrecision(TypeA, left, right, precision);
        printf("integral value for function A: %f\n", resultA);

        double resultB = IntegrateWithPrecision(TypeB, left, right, precision);
        printf("integral value for function B: %f\n", resultB);

        double resultC = IntegrateWithPrecision(TypeC, left, right, precision);
        printf("integral value for function C: %f\n", resultC);

        double resultD = IntegrateWithPrecision(TypeD, left, right, precision);
        printf("integral value for function D: %f\n", resultD);

        return 0;
    }
return 1;
}