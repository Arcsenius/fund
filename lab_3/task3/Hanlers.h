
#ifndef HANLERS_H
#define HANLERS_H
#include <stdio.h>

#include "states.h"

kState HandlerOptA( char* file1,  char* file2);
int CompareEmployeesA(const void *a, const void *b);
int CountLines(FILE *file);
kState HandlerOptD( char* file1,  char* file2);
void LogErrors(kState);
#endif //HANLERS_H
