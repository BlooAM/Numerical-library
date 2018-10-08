#ifndef _ComplexNumbers
#define _ComplexNumbers
#include <iostream>
#include <time.h>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;

class Cmplx
{
    double Re, Im;
public:
    Cmplx():Re(0),Im(0){}
    Cmplx(const double &x, const double &y):Re(x),Im(y){}
    void GetVal(double,double);
    void Disp();
    double Abs();
    Cmplx operator +(Cmplx);
    Cmplx operator -(Cmplx);
    Cmplx operator *(Cmplx);
    Cmplx operator /(Cmplx);
};
#endif // _ComplexNumbers
