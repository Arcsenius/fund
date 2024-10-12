#include "Handler_ln2_Series.h"
#include <tgmath.h>


long double HandlerLn2Series(long double Precision) {
    unsigned int n = 1;
    long double Sum = 0.0, Calculation = 0.0;


    do {
        Calculation = powl(-1.0, n - 1.0)/n;
        Sum += Calculation;
    } while (Calculation > Precision);


    return Sum;
}
