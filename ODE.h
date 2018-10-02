#include <iostream>

double *EulerExplicit(double(*f)(double,double),double,double,double,int);
double *EulerImplicit(double(*f)(double,double),double,double,double,int);
