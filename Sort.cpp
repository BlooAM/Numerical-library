#include "Sort.h"

void BubbleSort(double *tab,int n)
{
    int sup = n,s;
    double temp;
    while(sup>0)
    {
        s = 0;
        for(int i=1; i<sup; i++)
        {

            if(tab[i-1]>tab[i])
            {
                temp = tab[i-1];
                tab[i-1] = tab[i];
                tab[i] = temp;
                s = i;
            }
        }
        sup = s;
    }
}

void SelectionSort(double *tab,int n)
{
    double m,temp;
    int ind;
    for(int i=0; i<n; i++)
    {
        ind = i;
        m = tab[i];
        for(int j=i+1; j<n; j++)
        {
            if(tab[j]<m)
            {
                m = tab[j];
                ind = j;
            }
        }
        temp = tab[i];
        tab[i] = tab[ind];
        tab[ind] = temp;
    }
}
