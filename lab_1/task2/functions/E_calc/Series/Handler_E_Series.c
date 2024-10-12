#include "etc/Factorial.c"

long double HandlerESeries(long double Precision) {
    long double Calculation = 0.0;
    long double Sum = 0.0;
    unsigned int n = 0;


    do {
        Calculation = (1.0/Factorial(n));
        Sum += Calculation;
        ++n;
    } while ((Calculation > Precision) && (n <= 20));

    return Sum;
}