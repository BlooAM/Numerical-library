#ifndef _ODE
#define _ODE
#include <iostream>

double *EulerExplicit(double(*f)(double,double),double,double,double,int);
double *EulerImplicit(double(*f)(double,double),double,double,double,int);
#endif // _ODE
