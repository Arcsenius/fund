#include <stdio.h>
#include "handlers.h"

#include <math.h>
#include <stdlib.h>

#include "functions.h"

int HandlerOptQ(const double* args) {
    const double precision = args[0];
    double a = args[1], b = args[2], c = args[3];
    double root1, root2;


    if (precision <= 0.0) {
        printf("precision don`t positive\n");
        return EXIT_FAILURE;
    }

    double permutation[6][3] = {{a, b, c}, {a, c, b}, {b, a, c}, {b, c, a}, {c, a, b}, {c, b, a}};
    double uniqPermutation[6][3];
    uniqPermutation[0][0] = a;
    uniqPermutation[0][1] = b;
    uniqPermutation[0][2] = c;
    int k = 0;


    for (int i = 0; i < 6; i++) {
        if(IsUnique(uniqPermutation, k, permutation[i])) {
            uniqPermutation[k][0] = permutation[i][0];
            uniqPermutation[k][1] = permutation[i][1];
            uniqPermutation[k][2] = permutation[i][2];
            ++k;
        }
    }

    for (int i = 0; i < k; ++i) {
        printf("coefficients: %lf, %lf, %lf\n", uniqPermutation[i][0], uniqPermutation[i][1], uniqPermutation[i][2]);
        int result = SolveQuadratic(precision, uniqPermutation[i][0], uniqPermutation[i][1], uniqPermutation[i][2], &root1, &root2);
        PrintRootsQuadratic(result, &root1, &root2);
    }


    return EXIT_SUCCESS;
}


int HandlerOptM(const double* args) {
    const int a = (int)args[0], b = (int)args[1];
    const int aabs = fabs((int)args[0]), babs = fabs((int)args[1]);
    const int result = MultiplicityNums(aabs, babs);
    if (result == -1) {
        printf("Multipliers have zero");
         return EXIT_FAILURE;
    } if (result) {
        printf("number %d is not a multiple of number %d\n", b, a);
        return EXIT_FAILURE;
    }
    printf("number %d is a multiple of number %d\n", b, a);
    return EXIT_SUCCESS;
}


int HandlerOptT(const double* args) {
    const double precision = args[0];
    const double a = args[1], b = args[2], c = args[3];

    if (precision <= 0.0) {
        printf("precision don`t positive\n");
        return EXIT_FAILURE;
    }
    if (a <= precision || b <= precision || c <= precision) {
        printf("It`s not triangle\n");
        return EXIT_FAILURE;
    }
    if (IsSquareTriangle(precision, a, b, c)) {
        printf("This triangle is rectangular");
        return EXIT_SUCCESS;
    }
    printf("This triangle is not rectangular");
    return EXIT_FAILURE;
}





