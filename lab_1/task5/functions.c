#include "functions.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int GetArgs(const int argc, const char ** argv, long double* precision,  long double* x) {
    if (argc != 3) {
        printf("Error: Not enough arguments\n");
        return EXIT_FAILURE;
    }
    *precision = atof(argv[1]);
    *x = atof(argv[2]);
    if (*precision <= 0.0) {
        printf("Error: precision cannot not positive\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


void SeriesA(long double precision, long double x) {
    long double sum = 1.0, calculation;
    unsigned int n = 1;
    unsigned long long fact = 1;
    long double chx = x;
    do {
        chx *= x;
        fact *= n;
        calculation = x / fact;
        sum += calculation;
        ++n;
        if (n == 20) {
            printf("The series A does not converge");
            return;
        }
    } while (calculation > precision);

    printf("The sum of series A is %Lf\n", sum);
}


void SeriesB(long double precision, long double x) {
    unsigned int n = 2;
    unsigned long long fact = 2;
    long double xPowTwo = x * x;
    long double chX = xPowTwo;
    int chOne = -1;
    int sum1 = -1.0 * xPowTwo / 2.0;
    long double sum = 1.0 + sum1, calculation;
// n = 2
    do {
        chOne *= -1;
        chX *= xPowTwo;
        fact *= ((2 * n - 1) * (2 * n));
        calculation = chOne * chX / fact;
        sum += calculation;
        n += 1;
        if (n == 10) {
            printf("The series B does not converge");
            return;
        }
    } while (calculation > precision);

    printf("The sum of series B is %Lf\n", sum);
}


void SeriesC(long double precision, long double x) {
    long double sum = 1.0, calculation;
    unsigned long long threePowThree = 27, chThreePowThreeN = 1, chFact = 1, chFactPowThree = 1;
    unsigned int n = 1, factZnThree = 1;
    long double xPowTwo = x * x;
    long double chX = 1.0;



    do {
        chThreePowThreeN *= threePowThree;
        chFact *= n;
        chFactPowThree *= (chFact * chFact);
        chX *= xPowTwo;
        factZnThree *= ((3 * n - 1) * (3 * n - 2) * (3 * n));
        calculation = chThreePowThreeN *  factZnThree * chX / factZnThree;
        sum += calculation;
        ++n;
        if (n == 7) {
            printf("The series C does not converge\n");
            return;
        }
    } while (calculation > precision);


    printf("The sum of series B is %Lf\n", sum);

}


void SeriesD(long double precision, long double x) {
    long double chX = 1.0;
    long double xPowTwo = x * x;
    unsigned int n = 1;
    int chOne = 1;
    unsigned long long factTwoNMinusOne = 1, factTwoN = 2;
    long double sum = 0.0, calculation;

    do {
        chX *= xPowTwo;
        chOne += -1;
        factTwoNMinusOne *= (2 * n - 1);
        factTwoN *= (2 * n);
        calculation = chX * factTwoNMinusOne * chX / factTwoN;
        sum += calculation;
        ++n;
        if (n == 15) {
            printf("The series D does not converge\n");
            return;
        }
    } while (calculation > precision);

    printf("The sum of series D is %Lf\n", sum);
}
