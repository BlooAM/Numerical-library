#include "ElementaryAlgorithms.h"
#include <iostream>
double Leader(double *t,int n)
{
    double lead = t[0];
    int c = 1;
    for(int i=1; i<n; i++)
    {
        if(t[i]==lead) c++;
        else c--;
        if(c==0)
        {
            lead = t[i];
            c=1;
        }
    }
    if(c==0)
    {
        std::cout<<"There is no leader in the given set ... \n";
        return -666;
    }
    else
    {
        c=0;
        for(int i=0; i<n; i++)
        {
            if(t[i]==lead) c++;
        }
        if(2*c>n) return lead;
        else
        {
        std::cout<<"There is no leader in the given set ... \n";
        return -666;
        }
    }
}
//***********************************
double Max(double *t,int n)
{
    double x;
    if(n<=0)
    {
        std::cout<<"Number of elements in given array is not positive integer\n";
        return -666;
    }
    else
    {
        x=t[0];
        for(int i=1;i<n;i++)
        {
            if(t[i]>x) x=t[i];
        }
    }
    return x;
}
//***********************************
double *MaxMin(double *t,int n)
{
    static double tab [2];
    if(n<=0)
    {
        std::cout<<"Number of elements in given array is not positive integer\n";
        return 0;
    }
    else
    {
        double temp,m,M;
        for(int i=1;i<n;i+=2)
        {
            if(t[i-1]>t[i])
            {
                temp=t[i];
                t[i]=t[i-1];
                t[i-1]=temp;
            }
        }
        m=t[0];
        M=t[1];
        for(int i=3;i<n;i+=2)
        {
            if(t[i-1]<m) m=t[i-1];
            if(t[i]>M) M=t[i];
        }
        tab[1]=m;
        tab[0]=M;
        return tab;
    }
}
//***********************************
double Min(double *t,int n)
{
    double x;
    if(n<=0)
    {
        std::cout<<"Number of elements in given array is not positive integer\n";
        return -666;
    }
    else
    {
        x=t[0];
        for(int i=1;i<n;i++)
        {
            if(t[i]<x) x=t[i];
        }
    }
    return x;
}
