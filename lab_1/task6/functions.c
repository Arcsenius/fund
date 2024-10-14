#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>


int GetPrecision(const int argc, const char **argv,  double* precision) {
    if (argc != 2) {
        printf("Error: Not enough arguments\n");
        return EXIT_FAILURE;
    }
    *precision = atof(argv[1]);
    if (*precision <= 0.0) {
        printf("Error: Invalid precision value\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}


double TypeA(double x) {
    return log(x + 1) / x;
}


double TypeB(double x) {
    return exp(-pow(x, 2) / 2);
}


double TypeC(double x) {
    return log(1/(1-x));
}


double TypeD(double x) {
    return pow(x, x);
}


double Trapezoidal(double (*f)(double), double left, double right, int lambda) {
    double step = (right - left) / lambda;
    double sum = 0.5 * (f(left) + f(right));

    for (int i = 1; i < lambda; ++i) {
        double x = left + i * step;
        sum += f(x);
    }

    return sum * step;
}


double IntegrateWithPrecision(double (*f)(double), double left, double right, double precision) {
    int lambda = 10;
    double prevRes, currentRes;


    do {
        prevRes = Trapezoidal(f, left, right, lambda);
        lambda += 10;
        currentRes = Trapezoidal(f, left, right, lambda);
    } while (fabs(currentRes - prevRes) > precision);

    return currentRes;
}


