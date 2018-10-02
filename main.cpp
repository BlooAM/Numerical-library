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
    srand(time(NULL));
    int N=25;
    double tab1[] = {1,2,3,-5,-8,0,100,-100};
    BubbleSort(tab1,8);
    for(int i=0;i<8;i++)
    {
        cout<<tab1[i]<<"\t";
    }
    cout<<endl<<endl;

}

double f(double t,double x)
{
    return x;
}
