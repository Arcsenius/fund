#include "handlers.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int GetOpts(int argc, char** argv, kOpts* option, int* number) {
    if (argc != 3) {
        printf("Error: Not enough arguments\n");
        return EXIT_FAILURE;
    }
    char* flag = argv[1];
    if (flag[0] != '-' && flag[0] != '/') {
        printf("Error: Invalid flag\n");
        return EXIT_FAILURE;
    }
    switch (flag[1]) {
        case 'h':
            *option = OPT_H;
            break;
        case 'p':
            *option = OPT_P;
            break;
        case 's':
            *option = OPT_S;
            break;
        case 'e':
            *option = OPT_E;
            break;
        case 'a':
            *option = OPT_A;
            break;
        case 'f':
            *option = OPT_F;
            break;
        default:
            printf("Error: Flag undefined\n");
            return EXIT_FAILURE;
    }
    *number = atoi(argv[2]);
    if (*number < 0) {
        printf("Error: Number doesn`t positive\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}




int HandlerOptH(int X){
    int exist = 0;
    for(int i = 1; i <= 100; ++i) {
        if (i % X == 0) {
            printf("%d ", i);
            exist = 1;
        }
    }
    if (!exist) {
        printf("Such number don`t exists.\n");
    }
    return exist;
}


int HandlerOptP(int X) {
    int Divider = 2;
    while(Divider * Divider <= X) {
        if (X % Divider == 0) {
            printf("The number is composite\n");
            return EXIT_SUCCESS;
        }
        ++Divider;
    }
    printf("The number is prime\n");
    return EXIT_FAILURE;
}


int HandlerOptS(int X) {
    char hexDigits[64];
    int i = 0;

    while (X > 0) {
        int remainder = X % 16;
        if (remainder < 10) {
            hexDigits[i++] = '0' + remainder;
        } else {
            hexDigits[i++] = 'A' + (remainder - 10);
        }
        X /= 16;
    }

    if (i == 0) {
        printf("0\n");
        return EXIT_FAILURE;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexDigits[j]);
        if (j > 0) {
            printf(" ");
        }
    }
    printf("\n");

    return EXIT_SUCCESS;
}


int HandlerOptE(int X) {
    if (X <= 10) {
        for (int i = 1; i < 10; ++i) {
            printf("%d ", i);
            for (int j = 2; j <= X; ++j) {
                long long calc = pow(i, j);
                printf("%lld", calc);
                PrintSpace(11 - LenNumber(calc));
            }
            printf("\n");
        }
        return EXIT_SUCCESS;
    }
    printf("The number %d >= 10\n", X);

    return EXIT_FAILURE;
}


int HandlerOptA(int X) {
    int Sum = (X + 1) * (X) / 2;
    printf("The sum from 1 to %d is %d\n", X, Sum);

    return EXIT_SUCCESS;
}


int HandlerOptF(int X) {
    if (X < 0) {
        printf("The number is negative\n");
        return EXIT_FAILURE;
    }
    if (X > 20) {
        printf("The number is so big\n");
        return EXIT_FAILURE;
    }
    if (X == 1 || X == 0) {
        printf("Factorial is 1\n");
        return EXIT_SUCCESS;
    }
    long long Calc = 1;
    for (int i = 1; i <= X ; ++i) {
        Calc *= i;
    }
    printf("Factorial of %d is %lld\n", X, Calc);

    return EXIT_SUCCESS;
}


int LenNumber(long long n) {
    long long d = 10;
    int pow = 1;
    while (d < n) {
        d *= 10;
        ++pow;
    }
    return pow;
}


void PrintSpace(int ch) {

    for (int i = 0; i < ch; ++i) {
        printf(" ");
    }
}