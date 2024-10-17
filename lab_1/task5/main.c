#include <stdio.h>
#include "functions.h"

int main(const int argc, const char** argv) {
    long double precision, x;
    if(GetArgs(argc, argv, &precision, &x)){
        return 1;
    }
    double result = 0;
    double startValues[4] = {1.0, 1.0, 1.0, -x * x / 2.0};
    int startsN[4] = {0, 0, 0, 1};
    double (*func[4])(long double, int) = {FuncA, FuncB, FuncC, FuncD};


    for (int i = 0; i < 4; ++i) {
        printf("Series %c : ", i + 1 + 'A');
        int code = CalcuiationSeries(precision, x, func[i], startsN[i], startValues[i], &result);
        if (code) {
            printf("Value is too large\n");
            continue;
        }
        printf("The result is %lf\n", result);
    }

    return 0;
}
