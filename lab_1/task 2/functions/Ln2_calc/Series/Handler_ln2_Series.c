#include "Handler_ln2_Series.h"
#include <tgmath.h>


long double HandlerLn2Series(long double Precision) {
    unsigned int n = 1;
    long double Sum = 0, Calculation = 0;


    do {
        Calculation = pow(-1, n - 1)/n;
        Sum += Calculation;
    } while (Calculation > Precision);


    return Sum;
}
