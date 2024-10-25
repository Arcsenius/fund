#include "functions.h"

#include <float.h>
#include <math.h>
#include <stdarg.h>


//1

double GeometricAverage(int count, ...) {
    va_list ap;
    double prod = 1.0;
    va_start(ap, count);
    for (int i = 0; i < count; ++i) {
        prod *= va_arg(ap, double);
    }
    va_end(ap);

    return pow(prod, 1.0 / count);
}


double Overflow(double a) {
    return a > DBL_MAX || a < DBL_MIN;
}

//2

double FastPower(double a, int n) {
    if (n == 0)
        return 1;
    if (n % 2 == 0) {
        double tmp = FastPower(a, n / 2);
        return tmp * tmp;
    }
    return  a * FastPower(a, n - 1);
}


