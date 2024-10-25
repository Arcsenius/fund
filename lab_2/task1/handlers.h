#ifndef HANDLERS_H
#define HANDLERS_H
#include "parseArgs.h"
#include "states.h"

kState HandlerOptL(Input*, char**);
kState HandlerOptR(Input*, char**);
kState HandlerOptU(Input*, char**);
kState HandlerOptN(Input*, char**);
kState HandlerOptC(Input*, char**);
int StrLen(char* input);
void shuffleStrings(char** array, int n);


#endif //HANDLERS_H
