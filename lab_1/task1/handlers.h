
#ifndef HANDLERS_H
#define HANDLERS_H
typedef enum {
    OPT_H,
    OPT_P,
    OPT_S,
    OPT_E,
    OPT_A,
    OPT_F
} kOpts;

int HandlerOptH(int);
int HandlerOptP(int);
int HandlerOptS(int);
int HandlerOptE(int);
int HandlerOptA(int);
int HandlerOptF(int);
int GetOpts(int argc, char** argv, kOpts*, int*);
int LenNumber(long long);
void PrintSpace(int);



#endif //HANDLERS_H
