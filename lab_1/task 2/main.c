#include <math.h>
#include <stdio.h>



typedef enum {
    NOptE = 0,
    NOptPi,
    NOptLn2,
    NOptSqrt2,
}NOpts;

typedef enum {
    COptLim = 0,
    COptSeries,
    COptEquation,
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


long long Factorial(int N) {
    long long Result = 1;


    if (N == 0 || N == 1) {
        return 1;
    }

    for(int i = 1; i <= N; ++i) {
        Result *= i;
    }

    return Result;

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
            *option = COptEquation;
        break;
        default:
            printf("Key not recognised\n");
        return 0;
    }
     return 1;
}


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


long double HandlerESeries(long double Precision) {
    long double Calculation = 0.0;
    long double Sum = 0.0;
    long double SumPrevios = 0.0;
    unsigned int n = 0;


    do {
        SumPrevios = Sum;
        Calculation = (1.0/Factorial(n));
        Sum += Calculation;
        ++n;
    } while ((Calculation > Precision) && (n <= 20));

    return Sum;
}

int main(const int argc, const char* argv[]) {
    long double eps = 1e-10;
    printf("%Lf\n", HandlerESeries(eps));

    return 0;
}





