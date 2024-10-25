#ifndef VECTOR_H
#define VECTOR_H

#include "states.h"

typedef struct {
    int len;
    int capacity;
    int* buffer;
}Vector;

typedef struct {
    int index;
    Vector* v;
}Iterator;


Vector* CreateVector(int, kState* );
void DestroyVector(Vector*);
kState PushVector(Vector*, int);
int PopVector(Vector* v, Iterator* iter);
void PrintVector(Vector* v);




#endif //VECTOR_H
