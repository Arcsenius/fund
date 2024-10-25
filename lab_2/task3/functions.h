#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Vector.h"

kState SearchSubstringsInFile(char* substring,char* path, Vector* lines, Vector* chars, Vector* fileIds, int fileId);
kState FindEnterancesInFiles(Vector* lines, Vector* chars, Vector* fileIds, char* substring, int count, ...);
void logErrors(kState code);



#endif //FUNCTIONS_H
