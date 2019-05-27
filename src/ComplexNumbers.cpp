#include <iostream>
#include <time.h>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include "ComplexNumbers.h"
using namespace std;

void Cmplx::GetVal(double x,double y)
{
    Re=x;
    Im=y;
}
void Cmplx::Disp()
{
    cout<<"(Re, Im) = ("<<Re<<", "<<Im<<")"<<endl;
}
double Cmplx::Abs()
{
    return (sqrt(Re*Re+Im*Im));
}
Cmplx Cmplx::operator +(Cmplx z1)
{
    Cmplx z;
    z.Re=Re+z1.Re;
    z.Im=Im+z1.Im;
    return z;
}
Cmplx Cmplx::operator -(Cmplx z1)
{
    Cmplx z;
    z.Re=Re-z1.Re;
    z.Im=Im-z1.Im;
    return z;
}
Cmplx Cmplx::operator *(Cmplx z1)
{
    Cmplx z;
    z.Re=Re*z1.Re-Im*z1.Im;
    z.Im=Re*z1.Im+Im*z1.Re;
    return z;
}
Cmplx Cmplx::operator /(Cmplx z1)
{
    Cmplx z;
    if(z1.Abs()==0)
    {
        cout<<"Serio, chcesz dzielic przez 0 ? "<<endl;
        exit(-1);
    }
    else
    {
        z.Re=(Re*z1.Re+Im*z1.Im)/(z1.Abs()*z1.Abs());
        z.Im=(Im*z1.Re-Re*z1.Im)/(z1.Abs()*z1.Abs());
    }
    return z;
}
