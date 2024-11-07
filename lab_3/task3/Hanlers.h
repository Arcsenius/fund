
#ifndef HANLERS_H
#define HANLERS_H
#include <stdio.h>
#include "employee.h"
#include "states.h"

void HandlerOptA(Employee*, int);
int CompareEmployeesA(const void *a, const void *b);
int CountLines(FILE *file);
void HandlerOptD(Employee*, int);
void LogErrors(kState);
#endif //HANLERS_H
