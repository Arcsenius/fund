
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    Vector v1 = { (double[]){1.0, 2.0, 3.0} };
    Vector v2 = { (double[]){4.0, 5.0, 1.0} };
    Vector v3 = { (double[]){1.0, 4.0, 2.0} };
    Vector v4 = { (double[]){1.0, 6.0, 2.0} };

    kState code  = FindLongestVectors(3, 4, &v1, &v2, &v2, &v3, NormInf, NormPowerP, NormMatrix );

    if (code != kS_OK) {
        logErrors(code);
    }
}

//1 0 1 0 1 0 0 0 1
