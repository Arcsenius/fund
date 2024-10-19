#include "functions.h"
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int GetArgs(const int argc, const char ** argv, long double* precision,  long double* x) {
    if (argc != 3) {
        printf("Error: Not enough arguments\n");
        return EXIT_FAILURE;
    }
    *precision = atof(argv[1]);
    if (*precision <= 1e-6 ) {
        printf("Error: precision cannot not positive or too small\n");
        return EXIT_FAILURE;
    }
    int comma = 0;
    int minus = 0;
    if (argv[2][0] == '-') {
        minus = 1;
    }
    for (int i = minus; argv[2][i] != '\0'; ++i) {
        if (!(argv[2][i] >= '0' && argv[2][i] <= '9')) {
            if (argv[2][i] == '.') {
                ++comma;
                if (comma > 1) {
                    printf("Error: number undefined\n");
                    return EXIT_FAILURE;
                }
                continue;
            }
            printf("Error: number undefined\n");
            return EXIT_FAILURE;
        }
    }
        *x = atof(argv[2]);
        return EXIT_SUCCESS;
    }


int CalcuiationSeries(long double precision, long double x, double (*f)(long double, int), int startN, double startValue, double* result) {


    int n = startN + 1;
    double currentSum = startValue;
    double prevSum = currentSum;
    double currentElem = startValue;
    double prevElem;


    do {
        prevElem = currentElem;
        currentElem *= f(x, n);
        prevSum = currentSum;
        currentSum += currentElem;
        if (n > 1000 || currentSum > DBL_MAX || currentSum < -DBL_MAX) {
            return EXIT_FAILURE;
        }
        ++n;
    } while (fabsl(currentSum - prevSum) > precision);

    *result = currentSum;

    return EXIT_SUCCESS;
}


double Sqr(long double x) {
    return x * x;
}


double FuncA(long double x, int n) {
    return x / (double)n;
}


double FuncB(long double x, int n) {
    return x * x / (4.0 * (double)n * (double)n - 2.0 * (double)n) * (-1);
}


double FuncC(long double x, int n) {
    return 9.0 * (double)n * (double)n * x * x / (9.0 * (double)n * (double)n - 9.0 * (double)n + 2.0);
}


double FuncD(long double x, int n) {
    return (-1.0) * (x * x) * (2.0 * (double)n - 1) / (2.0 * (double)n);
}
