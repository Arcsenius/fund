#include "functions.h"
#include <stdio.h>
#include <tgmath.h>
#include "errors.h"


int SolveQuadratic(double precision, double a, double b, double c, double* root1, double* root2) {
    double discriminant = b * b - 4 * a * c;
    if (fabs(discriminant) < precision) {
        discriminant = 0;
    }

    if (discriminant < 0) {
        return 0;
    }

    if (discriminant == 0) {
        *root1 = (-b + sqrt(discriminant)) / (2 * a);
        return 1;
    }
    *root1 = (-b + sqrt(discriminant)) / (2 * a);
    *root2 = (-b - sqrt(discriminant)) / (2 * a);
    return 2;

}


void PrintRootsQuadratic(int numRoots, double* root1, double* root2) {
    if (!numRoots) {
        printf("The quadratic equation doesn`t has roots\n");
        return;
    } if (numRoots == 1) {
        printf("The root of the quadratic equation is %lf \n", *root1);
        return;
    }
    printf("The roots of the quadratic equation are:%lf, %lf\n", *root1, *root2);

    return;
}


int MultiplicityNums(int a, int b) {
    if (!(a * b)) {
        return -1;
    }
    return a % b;
}


int IsSquareTriangle(const double precision, const double a, const double b, const double c) {
    const double hypotenuse = fmax(fmax(a, b), c);
    const double sumSquaresLegs = a * a + b * b + c * c - hypotenuse * hypotenuse;


    return fabs(hypotenuse * hypotenuse - sumSquaresLegs) < precision;
}

