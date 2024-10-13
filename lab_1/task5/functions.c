#include "functions.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int GetArgs(const int argc, const char ** argv, ld* precision,  ld* x) {
    if (argc != 3) {
        printf("Error: Not enough arguments\n");
        return EXIT_FAILURE;
    }
    *precision = atof(argv[1]);
    *x = atof(argv[2]);
    if (*precision <= 0.0) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


int SeriesA(ld precision, ld x) {
    ld sum = 1.0, calculation;
    unsigned int n = 2;
    long long fact = 1;
    do {
        x *= x;
        fact *= n;
        calculation = x / n;
        sum += calculation;
        ++n;

    } while ((calculation > precision) && (n < 21));

    return sum;
}


\