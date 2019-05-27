#include "ElementaryFunctions.h"
#include "Interpolation.h"

double AitkenLagrange(double x,double *X,double *Y,int n)
{
    double *XX=new double [n],*YY=new double [n],*W=new double [n],D,B;
    int i0;
    B=0;
    for(int i=0; i<n; i++)
    {
        XX[i]=X[i];
        YY[i]=Y[i];
        W[i]=Abs(x-X[i]);
        D=W[i];
        if(D>B) B=D;
    }
    B++;
    for(int j=0; j<n; j++)
    {
        D=B;
        for(int i=0; i<n; i++)
        {
            if(W[i]<D)
            {
                D=W[i];
                i0=i;
            }
        }
        X[j]=XX[i0];
        Y[j]=YY[i0];
        W[i0]=B;
    }
    delete [] XX,YY;

    return 1;

}
//***************************************************
double Lagrange(double x,double *X,double *Y,int n)
{
    double s=0,w1=1,w2;
    for(int i=0; i<n; i++)
    {
        if(x==X[i]) return Y[i];
        w1*=(x-X[i]);
        w2=1;
        for(int j=0; j<n; j++)
        {
            if(j!=i) w2*=(X[i]-X[j]);
        }
        s+=Y[i]/(w2*(x-X[i]));
    }
    return w1*s;
}
