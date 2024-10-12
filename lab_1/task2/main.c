#include <math.h>
#include <stdio.h>

#include "functions/Ln2_calc/Lim/Handler_Ln2_Lim.h"
#include "functions/Ln2_calc/Quation/Handler_ln2_Quation.h"
#include "functions/Pi_calc/Handler_Pi_Lim.h"


typedef enum {
    NOptE = 0,
    NOptPi,
    NOptLn2,
    NOptSqrt2,
}NOpts;

typedef enum {
    COptLim = 0,
    COptSeries,
    COptEQuation,
}COpts;



int SelectNumber(NOpts* option) {
        printf(
            "press:"
            "'0' for 'e'\n"
            "'1' for 'pi'\n"
            "'2' for ln2\n"
            "'3' for sqrt(2)\n"
               );

        char Key = getchar();
        switch(Key) {
            case '0':
                *option = NOptE;
                break;
            case '1':
                *option = NOptPi;
                break;
            case '2':
                *option = NOptLn2;
                break;
            case '3':
                *option = NOptSqrt2;
            default:
                printf("Key not recognised\n");
                return 0;
    }
    return 1;
}




int SelectCalculation(COpts* option) {
    printf(
        "press:"
        "'1' for limited"
        "'2' for series"
        "'3' for equation"
        );
    char Key = getchar();
    switch(Key) {
        case '1':
            *option = COptLim;
        break;
        case '2':
            *option = COptSeries;
        break;
        case '3':
            *option = COptEQuation;
        break;
        default:
            printf("Key not recognised\n");
        return 0;
    }
     return 1;
}









int main(const int argc, const char* argv[]) {
    long double eps = 1e-10;
    printf("%Lf\n", HandlerPiLim(1e-10));

    return 0;
}





