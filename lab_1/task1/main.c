#include <stdio.h>
#include <math.h>
#include "kOpts.h"



int HandlerOptH(int);
int HandlerOptP(int);
int HandlerOptS(int);
int HandlerOptE(int);
int HandlerOptA(int);
int HandlerOptF(int);
int GetOpts(int argc, char** argv, kOpts*, int*);

int main(const int argc, const char* argv[]) {
    kOpts opt = 0;
    int procceed_number = 0;
    void (*Handlers[6])(int) = {
    HandlerOptH,
    HandlerOptP,
    HandlerOptS,
    HandlerOptE,
    HandlerOptA,
    HandlerOptF
    };

    if (GetOpts(argc, argv, &opt, &procceed_number)) {
        printf("Incorrect input\n");
            return 1;
    }
    Handlers[opt](procceed_number);
return 0;
}

int GetOpts(int argc, char** argv, kOpts *option, int *number) {
    if (argc != 3) {
        return 1;
    }

    for (int i = 1; i <= 2; ++i) {
        char *procceding_option = argv[i];
        if (procceding_option[0] == '-' || procceding_option[0] == '/') {
            switch (procceding_option[1]) {
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
                    return 1;
            }
        } else {
            for (int j = 0; procceding_option[j]; ++j) {
                if (procceding_option[j] >= '0' && procceding_option[j] <= '9') {
                    *number *= 10;
                    *number += procceding_option[j] - '0';
                } else {
                    return 1;
                }
            }
        }
    }
        return 0;
        }


int HandlerOptH(int X){
    int Exist = 0;
    for(int i = 1; i <= 100; ++i) {
        if (i % X == 0) {
            printf("%d ", i);
            Exist = 1;
        }
    }
        if (!Exist) {
            printf("NaturalNumbers: No such number exists.\n");
        }
    return Exist;
}


int HandlerOptP(int X) {
    int Divider = 2;
    while(Divider * Divider <= X) {
        if (X % Divider == 0) {
            printf("The number is composite!\n");
            return 1;
        }
        ++Divider;
    }
    printf("The number is prime\n");
    return 0;
}


int HandlerOptS(int X) {
    char hexDigits[8];
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
        return 1;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexDigits[j]);
        if (j > 0) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}


int HandlerOptE(int X) {
    if (X <= 10) {
        for (int i = 1; i < 10; ++i) {
            printf("%d ", i);
            for (int j = 2; j <= X; ++j) {
                printf("%d ", (int)pow(i, j));
            }
            printf("\n");
        }
        return 1;
    }
    printf("The number %d >= 10!\n", X);
    return 0;
}


int HandlerOptA(int X) {
    int Sum = 0;
    for (int i = 1; i <= X; ++i) {
        Sum += i;
    }
    if (Sum) {
        printf("The sum of %d is %d\n", X, Sum);
        return 1;
    }
    printf("Sum undefined");
    return 0;
}


int HandlerOptF(int X) {
    int Calc = 1;
    for (int i = 1; i <= X; ++i) {
        Calc *= i;
    }
    printf("factorial of %d is %d\n", X, Calc);
    return 0;
}
