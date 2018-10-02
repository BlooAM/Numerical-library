#include <iostream>
#include <time.h>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include "Array.h"
using namespace std;


void Array::GenMat(int r, int c)
{
    m=r;
    n=c;
    M = new double* [m];
    for(int i=0; i<m; i++)  M[i] = new double [n];
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++) M[i][j]=0;
    }
}
//****************************************************************************************
void Array::DispMat()
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<setprecision(5)<<M[i][j]<<"\t";
            if((j+1)%n==0) cout<<endl;
        }
    }
    cout<<endl;
}
//****************************************************************************************
void Array::ChangeRows(int i, int j)
{
    if((i>0)&&(j>0)&&(i<=m)&&(j<=m))
    {
        double *temp = new double [n];
        for(int k=0;k<n;k++)
        {
            temp[k]=M[i-1][k];
            M[i-1][k]=M[j-1][k];
            M[j-1][k]=temp[k];
        }
        delete [] temp;
    }
    else
    {
        cout<<"Zle indeksy"<<endl;
        exit(-1);
    }
}
//****************************************************************************************
void Array::ChangeColumns(int i, int j)
{
    if((i>0)&&(j>0)&&(i<=n)&&(j<=n))
    {
        double *temp = new double [m];
        for(int k=0;k<m;k++)
        {
            temp[k]=M[k][i-1];
            M[k][i-1]=M[k][j-1];
            M[k][j-1]=temp[k];
        }
        delete [] temp;
    }
    else
    {
        cout<<"Zle indeksy"<<endl;
        exit(-1);
    }
}
//****************************************************************************************
void Array::ModRow(int i, int j, double lambda)
{
    if((i!=j)&&(i>0)&&(j>0)&&(i<=m)&&(j<=m))
    {
        for(int k=0; k<n; k++)
        {
            M[i-1][k]=M[i-1][k]+lambda*M[j-1][k];
        }
    }
    else
    {
        cout<<"Zly wybor wierzy"<<endl;
        exit(-1);
    }
}
//****************************************************************************************
void Array::ModColumn(int i, int j, double lambda)
{
    if((i!=j)&&(i>0)&&(j>0)&&(i<=n)&&(j<=n))
    {
        for(int k=0; k<n; k++)
        {
            M[k][i-1]=M[k][i-1]+lambda*M[k][j-1];
        }
    }
    else
    {
        cout<<"Zly wybor wierzy"<<endl;
        exit(-1);
    }
}
//****************************************************************************************
Array Gauss(const Array &A, const Array &B)
{
    int indx,indy,temp;
    int *tablica;
    double lambda,dif;
    Array L(A),P(B),KopiaA(A),KopiaB(B);
    double maks;
    tablica = new int [A.n];
    for(int i=0; i<A.n; i++) tablica[i]=i+1;
    if ((A.m==B.m)&&(A.m==A.n)&&(B.n==1))
    {
        for(int wiersz=0; wiersz<A.m-1; wiersz++)
        {
            maks=0;
            indx=0;
            indy=0;
            for(int i=wiersz;i<A.m;i++)
            {
                for(int j=wiersz;j<A.n;j++)
                {
                    if(fabs(A.M[i][j])>maks)
                    maks=fabs(A.M[i][j]);
                    indx=i;
                    indy=j;
                }
            }
            L.ChangeRows(indx+1,wiersz+1);
            L.ChangeColumns(indy+1,wiersz+1);
            temp=tablica[indy];
            tablica[indy]=tablica[wiersz];
            tablica[wiersz]=temp;
            P.ChangeRows(indx+1,wiersz+1);
            for(int i=wiersz+1;i<A.m;i++)
            {
                lambda = (-1)*L.M[i][wiersz]/L.M[wiersz][wiersz];
                L.ModRow(i+1,wiersz+1,lambda);
                P.ModRow(i+1,wiersz+1,lambda);
            }
            cout<<endl;
        }
        P.M[A.m-1][0] = P.M[A.m-1][0]/L.M[A.m-1][A.m-1];
        for(int i=A.m-2;i>=0;i--)
        {
            dif=0;
            for(int k=0; k<A.m-1-i;k++) dif=dif+P.M[A.m-1-k][0]*L.M[i][A.m-1-k];
            P.M[i][0]=(P.M[i][0]-dif)/L.M[i][i];
        }
    Array KopiaP(P);
    for(int i=0; i<A.n; i++)    P.M[tablica[i]-1][0]=KopiaP.M[i][0];
    cout<<endl;
    /*cout<<"Rozwiazanie: "<<endl;
    P.DispMat();
    cout<<"Sprawdzenie: "<<endl;
    (KopiaA*P-KopiaB).DispMat();*/
    }
    else
    {
        cout<<"Zle dobrane macierze! "<<endl;
        exit(-1);
    }
    delete [] tablica;
    return P;
}
//****************************************************************************************
Array JacobiGauss(const Array &A, const Array &B)
{
    int indx,indy,temp;
    int *tablica;
    double lambda,dif;
    Array L(A),P(B),KopiaA(A),KopiaB(B);
    double maks;
    tablica = new int [A.n];
    for(int i=0; i<A.n; i++) tablica[i]=i+1;
    if ((A.m==B.m)&&(A.m==A.n)&&(B.n==1))
    {
        for(int wiersz=0; wiersz<A.m-1; wiersz++)
        {
            maks=0;
            indx=0;
            indy=0;
            for(int i=wiersz;i<A.m;i++)
            {
                for(int j=wiersz;j<A.n;j++)
                {
                    if(fabs(A.M[i][j])>maks)
                    maks=fabs(A.M[i][j]);
                    indx=i;
                    indy=j;
                }
            }
            L.ChangeRows(indx+1,wiersz+1);
            L.ChangeColumns(indy+1,wiersz+1);
            temp=tablica[indy];
            tablica[indy]=tablica[wiersz];
            tablica[wiersz]=temp;
            P.ChangeRows(indx+1,wiersz+1);
            for(int i=wiersz+1;i<A.m;i++)
            {
                lambda = (-1)*L.M[i][wiersz]/L.M[wiersz][wiersz];
                L.ModRow(i+1,wiersz+1,lambda);
                P.ModRow(i+1,wiersz+1,lambda);
            }
            cout<<endl;
        }
        for(int i=A.m-1;i>0;i--)
        {
            for(int j=i-1;j>=0;j--)
            {
                lambda = (-1)*L.M[j][i]/L.M[i][i];
                L.ModRow(j+1,i+1,lambda);
                P.ModRow(j+1,i+1,lambda);
            }
            P.M[i][0]=P.M[i][0]/L.M[i][i];
        }
        P.M[0][0]=P.M[0][0]/L.M[0][0];
    Array KopiaP(P);
    for(int i=0; i<A.n; i++)    P.M[tablica[i]-1][0]=KopiaP.M[i][0];
    /*cout<<endl;
    cout<<"Rozwiazanie: "<<endl;
    P.DispMat();
    cout<<"Sprawdzenie: "<<endl;
    (KopiaA*P-KopiaB).DispMat();*/
    }
    else
    {
        cout<<"Zle dobrane macierze! "<<endl;
        exit(-1);
    }
    delete [] tablica;
    return P;
}
//****************************************************************************************
Array Jacobi(const Array &A, const Array &B)
{
    double suma,epsilon=100;
    int max_iter=1000,iter=0;
    Array L(A),P(B);
    Array X,KopiaX,Res;
    X.GenMat(B.m,1);
    while((epsilon>0.0001)&&(iter<=max_iter))
    {
        iter++;
        KopiaX=X;
        for(int i=0; i<B.m; i++)
        {
            suma=0;
            for(int j=0;j<i;j++) suma=suma+L.M[i][j]*KopiaX.M[j][0];
            for(int j=i+1;j<A.n;j++) suma=suma+L.M[i][j]*KopiaX.M[j][0];
            X.M[i][0]=(P.M[i][0]-suma)/L.M[i][i];
        }
        epsilon=0;
        Res=(L*X-P);
        for(int i=1;i<B.m;i++) epsilon=epsilon+Res.M[i][0]*Res.M[i][0];
        epsilon=sqrt(epsilon);
    }
    cout<<"Jacobi, liczba iteracji: "<<iter<<endl;
    cout<<"Residuum: "<<endl;
    Res.DispMat();
    return X;

}
//****************************************************************************************
Array GaussSeidl(const Array &A, const Array &B)
{
    double suma,epsilon=100;
    int max_iter=1000,iter=0;
    Array L(A),P(B);
    Array X,KopiaX,Res;
    X.GenMat(B.m,1);
    while((epsilon>0.0001)&&(iter<=max_iter))
    {
        iter++;
        KopiaX=X;
        for(int i=0; i<B.m; i++)
        {
            suma=0;
            for(int j=0;j<i;j++) suma=suma+L.M[i][j]*X.M[j][0];
            for(int j=i+1;j<A.n;j++) suma=suma+L.M[i][j]*KopiaX.M[j][0];
            X.M[i][0]=(P.M[i][0]-suma)/L.M[i][i];
        }
        epsilon=0;
        Res=(L*X-P);
        for(int i=1;i<B.m;i++) epsilon=epsilon+Res.M[i][0]*Res.M[i][0];
        epsilon=sqrt(epsilon);
    }
    cout<<"Gauss_Siedl, liczba iteracji: "<<iter<<endl;
    cout<<"Residuum: "<<endl;
    Res.DispMat();
    return X;

}
//****************************************************************************************
Array Array::operator +(const Array &A)
{
    Array C;
    if((m==A.m)&&(n==A.n))
    {
        C.GenMat(m,n);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                C.M[i][j]=M[i][j]+A.M[i][j];
            }
        }
    }
    else
    {
        cout<<"Macierze nie sa jednakowych wymiarow !!!";
        exit(-1);
    }
    return C;
}
//****************************************************************************************
Array Array::operator -(const Array &A)
{
    Array C;
    if((m==A.m)&&(n==A.n))
    {
        C.GenMat(m,n);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                C.M[i][j]=M[i][j]-A.M[i][j];
            }
        }
    }
    else
    {
        cout<<"Macierze nie sa jednakowych wymiarow !!!";
        exit(-1);
    }
    return C;
}
//****************************************************************************************
Array& Array::operator =(Array A)
{
    for(int i=0; i<m; i++) delete [] M[i]; delete [] M;
    this->GenMat(A.m,A.n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
             M[i][j]=A.M[i][j];
        }
    }
    return (*this);
}
//****************************************************************************************
Array Array::operator *(const Array &A)
{
    Array C;
    double sum;
    if(n==A.m)
    {
        C.GenMat(m,A.n);
        for(int i=0; i<C.m; i++)
        {
            for(int j=0; j<C.n; j++)
                {
                    sum=0;
                    for(int k=0;k<n;k++) sum+=M[i][k]*A.M[k][j];
                    C.M[i][j]=sum;
                }
        }
    }
    else
    {
        cout<<"Macierze nie maja odpowiednich wymiarow !!!";
        exit(-1);
    }
    return C;
}
