#ifndef _Array
#define _Array
#include <iostream>
#include <time.h>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
using namespace std;

class Array
{
    int m,n;
    friend Array Gauss(const Array &A, const Array &B);
    friend Array JacobiGauss(const Array &A, const Array &B);
    friend Array Jacobi(const Array &A, const Array &B);
    friend Array GaussSeidl(const Array &A, const Array &B);
public:
    double **M;
    void GenMat(int r=0, int c=0);
    void DispMat();
    void ChangeRows(int i, int j);
    void ChangeColumns(int i, int j);
    void ModRow(int i, int j, double lambda);
    void ModColumn(int i, int j, double lambda);
    Array operator +(const Array &A);
    Array operator -(const Array &A);
    Array& operator =(Array A);
    Array operator *(const Array &A);
    Array():m(0),n(0),M(0){}
    Array(const Array &A){m=A.m;n=A.n; this->GenMat(m,n); for(int i=0;i<m;i++) for(int j=0;j<n;j++) M[i][j]=A.M[i][j];}
    ~Array(){for(int i=0; i<m; i++) delete [] M[i]; delete [] M;}
};
#endif // _Array
