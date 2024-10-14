
#ifndef FUNCTIONS_H
#define FUNCTIONS_H


int GetPrecision(const int , const char** , double*);
double TypeA(double);
double TypeB(double);
double TypeC(double);
double TypeD(double);
double Trapezoidal(double (*)(double), double, double, int);
double IntegrateWithPrecision(double (*)(double), double, double, double);



#endif //FUNCTIONS_H
