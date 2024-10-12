#include "Handler_Pi_Lim.h"
#include <math.h>
#include "../E_calc/Series/etc/Factorial.h"

long double HandlerPiLim(long double Precision) {
    unsigned long long int n = 1;
    long double Pi_Current = 0.0, Pi_Previos;


    do {
        Pi_Previos = Pi_Current;
        int c = Factorial(2 * n);
        Pi_Current = powl(powl(2.0, n) * Factorial(n), 4.0) / (n * powl(Factorial(2 * n), 2.0));
        ++n;
    } while (fabsl(Pi_Current - Pi_Previos) > Precision);

    return Pi_Current;
}
