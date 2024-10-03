#include <math.h>
#include "Handler_Ln2_Lim.h"


long double HandlerLn2Lim(long double Precision) {
    long double Ln2Current = 0.0;
    long double Ln2Previous;
    unsigned long long n = 1;


    do {
        Ln2Previous = Ln2Current;
        Ln2Current = n * (powl(2, 1.0 / n) - 1);
        ++n;
    } while (fabsl(Ln2Current - Ln2Previous) > Precision);


    return Ln2Current;
}
