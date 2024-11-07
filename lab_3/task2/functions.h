
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct  {
    double* coords;
} Vector;


typedef double (* NormFunc)(Vector*, int, int, double**);

typedef struct {
    int num;
    double result;
} CalcNormsObject;


typedef enum  {
    kS_OK,
    kE_ERROR_MEMORY_ALLOCATION,
    kE_INVALID_MATRIX
} kState;
#define FUNC_NUM 3
void PrintVector(Vector *v, int size);
double NormPowerP(const Vector *v, int n, int p, double **);
kState FindLongestVectors(int size, unsigned int numVectors, ...);
double NormInf(const Vector *v, int n, int p, double**);
double NormMatrix(Vector *v, int n, int, double**);
void logErrors(kState state);
#endif //FUNCTIONS_H
