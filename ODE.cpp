#include <iostream>
#include <math.h>
#include "ODE.h"

using namespace std;

double *EulerExplicit(double(*f)(double,double),double x0,double a,double b, int N)
{
    double h=(b-a)/(N-1);
    double *tab=new double [N];
    tab[0]=x0;
    for(int i=1; i<N; i++)
    {
        tab[i]=tab[i-1]+h*f(a+i*h,tab[i-1]);
    }
    return tab;
}
double *EulerImplicit(double(*f)(double,double),double x0,double a,double b, int N)
{
    double h=(b-a)/(N-1),temp,eps=0.01;
    double *tab=new double [N];
    tab[0]=x0;
    for(int i=1; i<N; i++)
    {
        temp = tab[i-1]+h*f(a+i*h,tab[i-1]);
        tab[i] = tab[i-1]+h*f(a+(i+1)*h,temp);
    }
    return tab;
}
