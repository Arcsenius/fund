#ifndef PARSEARGS_H
#define PARSEARGS_H

#include "states.h"


typedef enum {
    kOPT_L,
    kOPT_R,
    kOPT_U,
    kOPT_N,
    kOPT_C,
} kOption;


typedef struct {
    kState code;
    kOption opt;
    char** strings;
    int stringsLen;
    int seed;
} Input;



kState parseInt(char* input, int* output);
Input* CreateInput(kState code, kOption opt, char** strings, int strLen, int seed);
void FreeInput(Input* input);
Input* ParseArgs(int argc, char** argv);
void LogErrors(kState code);


#endif //PARSEARGS_H
