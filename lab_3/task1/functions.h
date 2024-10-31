#ifndef FUNCTIONS_H
#define FUNCTIONS_H


typedef enum {
    kS_OK,
    kE_BAD_ALLOCATION_MEMORY,
    kE_INVALID_ARGUMENT
} kState;

unsigned int Increment(unsigned int number);
unsigned int Decrement(unsigned int number);
char* DecimalToBaseR(int number, int r, kState* code);
void LogErrors(kState code);

#endif
