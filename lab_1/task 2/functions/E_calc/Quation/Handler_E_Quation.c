#include <tgmath.h>
#include "Handler_E_Quation.h"


long double HandlerEQuation(long double Precision) {
    long double Argument;
    long double Left = 1;
    long double Right = 15.0;


    while ((Right - Left) / 2.0 > Precision) {
        Argument = (Left + Right) / 2.0;
        if (log(Argument) - 1 == 0.0) {
            break;
        } else if ((log(Argument) - 1) * (log(Left) - 1) < 0.0) {
            Right = Argument;
        } else {
            Left = Argument;
        }
    }


    return (Left + Right) / 2.0;
}
