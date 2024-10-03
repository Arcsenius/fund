#include <math.h>
#include "Handler_E_Lim.h"


int HandlerELim(long double Precision) {
    long double ECurrent = 0.0;
    long double EPrevious = 0.0;
    long double n = 1.0;


    do {
        EPrevious = ECurrent;
        ECurrent = (long double)powl((1.0 + 1/n), n);
        ++n;
    } while (fabsl(ECurrent-EPrevious) > Precision);


    return ECurrent;
}
