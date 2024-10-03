#include <tgmath.h>
#include "Handler_ln2_Quation.h"


long double HandlerLn2Quation(long double Precision) {
    long double Argument;
    long double Left = -10.0;
    long double Right = 15.0;

    while ((Right - Left) / 2.0 > Precision) {
        Argument = (Left + Right) / 2.0;
        long double f = expl(Argument) - 2;
        if ( f == 0.0) {
            break;
        } else if (f * (expl(Left) - 2) < 0.0) {
            Right = Argument;
        } else {
            Left = Argument;
        }
    }


    return (Left + Right) / 2.0;

}
