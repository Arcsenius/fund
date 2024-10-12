#include <stdio.h>
#include "handlers.h"

#include <stdlib.h>

#include "functions.h"

int HandlerOptQ(const double* args) {
    const double precision = args[0];
    const double a = args[1], b = args[2], c = args[3];
    double root1, root2;


    printf("equation with coeff %lf, %lf, %lf \n", a, b, c);
    const int result1 = SolveQuadratic(precision, a, b, c, &root1, &root2);
    PrintRootsQuadratic(result1, &root1, &root2);


    printf("equation with coeff %lf, %lf, %lf \n", a, c, b);
    const int result2 = SolveQuadratic(precision, a, c, b, &root1, &root2);
    PrintRootsQuadratic(result2, &root1, &root2);


    printf("equation with coeff %lf, %lf, %lf \n", b, a, c);
    const int result3 = SolveQuadratic(precision, b, a, c, &root1, &root2);
    PrintRootsQuadratic(result3, &root1, &root2);


    printf("equation with coeff %lf, %lf, %lf \n", b, c, a);
    const int result4 = SolveQuadratic(precision, b, c, a, &root1, &root2);
    PrintRootsQuadratic(result4, &root1, &root2);


    printf("equation with coeff %lf, %lf, %lf \n", c, a, b);
    const int result5 = SolveQuadratic(precision, c, a, b, &root1, &root2);
    PrintRootsQuadratic(result5, &root1, &root2);


    printf("equation with coeff %lf, %lf, %lf \n", c, b, a);
    const int result6 = SolveQuadratic(precision, a, b, c, &root1, &root2);
    PrintRootsQuadratic(result6, &root1, &root2);


    return EXIT_SUCCESS;
}


int HandlerOptM(const double* args) {
    const int a = (int)args[0], b = (int)args[1];

    const int result = MultiplicityNums(a, b);
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
    if (IsSquareTriangle(precision, a, b, c)) {
        printf("This triangle is rectangular");
        return EXIT_SUCCESS;
    }
    printf("This triangle is not rectangular");
    return EXIT_FAILURE;
}





