#include <iostream>
#include "ElementaryFunctions.h"
#include <math.h>

using namespace std;

double Abs(double x)
{
    if(x>=0) return x;
    else return (-x);
}
double Exp(double x)
{
    const double E=2.718281828459;
    double factor=1,val=1,epsilon=1e-100,e=1;
    int k=1,ent;
    ent=x;
    if(x>=0)
    {
        x=x-ent;
        for(int i=0;i<ent;i++)
        {
            e*=E;
        }
    }
    if(x!=0)
    {
        while(Abs(factor)>epsilon)
        {
            factor*=x/k;
            val+=factor;
            k++;
        }
        e=e*val;
    }
    else
    {
        val=1;
        e=e*val;
    }
    return e;
}
