#include "functions.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>


kState FindLongestVectors(int size, unsigned int numVectors, ...) {
    va_list ap;
    va_start(ap, numVectors);
    Vector** vectors = (Vector*)malloc(numVectors * sizeof(Vector));

    if (vectors == NULL) {
        va_end(ap);
        free(vectors);
        return kE_ERROR_MEMORY_ALLOCATION;
    }

    for (int i = 0; i < numVectors; i++) {
        vectors[i] = va_arg(ap, Vector*);
    }
    NormFunc* normArr = (NormFunc*)malloc(FUNC_NUM * sizeof(NormFunc));

    if (normArr == NULL) {
        va_end(ap);
        free(vectors);
        free(normArr);
        return kE_ERROR_MEMORY_ALLOCATION;
    }


    double p;
    printf("Enter the number p for norm number 2\n");
    scanf("%lf",&p);
    printf("P is %f\n", p);


    double** matrix = (double**)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        matrix[i] = (double*)malloc(size * sizeof(double));
    }

    printf("Enter the matrix A %dx%d for norm number 3 \n", size, size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (scanf("%lf", &matrix[i][j]) != 1) {
                va_end(ap);
                free(matrix);
                free(vectors);
                free(normArr);
                return kE_INVALID_MATRIX;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        normArr[i] = va_arg(ap, NormFunc);
        int maxCount = 0;
        double maxValue = -1;
        int* longestIndex = (int*)malloc(size * sizeof(int));
        if (longestIndex == NULL) {
            va_end(ap);
            free(longestIndex);
            free(vectors);
            free(normArr);
            return kE_ERROR_MEMORY_ALLOCATION;
        }
        double tmp = -1.0;
        for (int j = 0; j < numVectors; ++j) {
            tmp = normArr[i](vectors[j], size, p, matrix);
            if (tmp > maxValue) {
                maxValue = tmp;
                longestIndex[0] = j;
                maxCount = 1;
            } else if (tmp == maxValue) {
                longestIndex[maxCount++] = j;
            }

        }
        printf("the maximum values %f for the norm %d are achieved in the vector(s):\n", maxValue,i + 1);
        for (int k = 0; k < maxCount; ++k) {
            PrintVector(vectors[longestIndex[k]], size);
        }
        free(longestIndex);

    }
    free(vectors);
    free(normArr);
    va_end(ap);
    return kS_OK;
}

void PrintVector(Vector *v, int size) {
    for(int i = 0; i < size; i++) {
        printf("%f ", v->coords[i]);
    }
    printf("\n");
}


double NormPowerP(const Vector *v, int n, int p, double** matrix) {

    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += pow(v->coords[i], p);
    }
    return pow(sum, 1.0 / p);
}

double NormInf(const Vector *v, int n, int p, double** matrix) {
    double max_val = 0;
    for (int i = 0; i < n; ++i) {
        double abs_val = fabs(v->coords[i]);
        if (abs_val > max_val) {
            max_val = abs_val;
        }
    }
    return max_val;
}

double NormMatrix(Vector *v, int n, int p, double** matrix) {
    double mult[n];
    for (int i = 0; i < n; ++i) {
        double calc = 0.0;
        for (int k = 0; k < n; ++k) {
            calc += matrix[i][k] * v->coords[k];
        }
        mult[i] = calc;
    }


    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += mult[i] * v->coords[i];
    }
    return sqrt(sum);
}


void logErrors(kState state) {
    switch (state) {
    case kE_ERROR_MEMORY_ALLOCATION:
        printf("Memory allocation error\n");
        break;
        default:
            printf("Unknown error\n");
        break;
    }
}