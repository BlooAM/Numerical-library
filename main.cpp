#include <iostream>
#include <time.h>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include "Array.h"
#include "ComplexNumbers.h"
#include "ElementaryAlgorithms.h"
#include "ElementaryFunctions.h"
#include "Interpolation.h"
#include "ODE.h"
#include "Sort.h"


double f(double,double);

using namespace std;


int main()
{
    double tab[] {5,2,-1,50,12,3.13};
    BubbleSort<6,double>(tab);
    //BubbleSortT<double>(tab,6);
    for(int i=0; i<6; i++)  cout<<tab[i]<<"\t";
    cout<<endl;

}

double f(double t,double x)
{
    return x;
}
