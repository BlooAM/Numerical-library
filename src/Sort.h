#ifndef _Sort
#define _Sort
#include <cstddef>
template<size_t n,typename T> void BubbleSort(T *tab)
{
    size_t sup = n,s;
    T temp;
    while(sup>0)
    {
        s = 0;
        for(size_t i=1; i<sup; i++)
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
template<typename T> void QuickSort(T *tab, int l, int r)
{
    T x = tab[(l+r)/2],temp;
    int i,j;
    i = l;
    j = r;
    do
    {
        while(tab[i]<x) i++;
        while(tab[j]>x) j--;
        if(i<=j)
        {
            temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
            i++;
            j--;
        }
    }while(i<=j);
    if(j>l) QuickSort<T>(tab,l,j);
    if(i<r) QuickSort<T>(tab,i,r);
}
template<size_t n,typename T> void SelectionSort(T *tab)
{
    T m,temp;
    size_t ind;
    for(size_t i=0; i<n; i++)
    {
        ind = i;
        m = tab[i];
        for(size_t j=i+1; j<n; j++)
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
#endif // _Sort

