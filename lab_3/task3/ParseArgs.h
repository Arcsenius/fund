#ifndef PARSEARGS_H
#define PARSEARGS_H
#include "states.h"

typedef enum {
    kOPT_A,
    kOPT_D
} kOption;

kState ParseArgs(int argc,  char **argv,  char** file1, kOption* opt, char** file2);
#endif //PARSEARGS_H
