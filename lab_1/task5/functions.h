
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
int GetArgs(const int , const char** , long double*, long double*);
int CalcuiationSeries(long double , long double , double (*f)(long double, int), int , double , double* );
double Sqr(long double x);
double FuncA(long double x, int n);
double FuncB(long double x, int n);
double FuncC(long double x, int n);
double FuncD(long double x, int n);
#endif
