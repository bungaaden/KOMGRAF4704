/*  Nama : Bunga Dinda Endri Novita
    Nim : A11.2021.13786
    Kelompok : A11.4704
*/

#include <iostream>
#include <cmath>

using namespace std;

double x [100][100];
double y [100];
double z [100];
double temp = 0 ;
double hasil;
int i, j;
double derajat;
double nilaiSin,nilaiCos,radian,epsilon;

void matriksRotasi ()
{
    for (j = 0; j < 3 ; j++)
    {
        y[i]=y[j];
        for (i = 0; i < 3 ; i++)
        {
            temp = x[i][j] * y[i] ;
            hasil +=temp;
        }
        z[j] = hasil;

        temp = 0;
        hasil = 0;
    }
     cout << "Matriks Rotasi :" << endl;

    for (j = 0; j < 3 ; j++)
    {
        cout << z[j] << " " << endl;
    }
}



int main ()
{
    cout << "Masukkan nilai derajat : ";
    cin >> derajat;

    radian = derajat * M_PI / 180;
    nilaiSin = sin(radian);
    nilaiCos = cos(radian);
    epsilon = numeric_limits<double>::epsilon();
    if (fabs(nilaiCos) < epsilon)
    {
        nilaiCos = 0.0;
    }
    else if (fabs(nilaiSin) < epsilon)
    {
        nilaiSin = 0.0;
    }
    for (j = 0 ; j  < 3;j++)
    {
        for (i = 0 ; i <3 ; i++)
        {
            if ((i == 0 && j == 0)||(i == 1 && j == 1))
            {
                x[i][j] = nilaiCos;
            }
            else if (i == 1 && j == 0)
            {
                x[i][j]=-nilaiSin;
            }
            else if (i == 0 && j == 1)
            {
                x[i][j]= nilaiSin;
            }
            else if ((i == 2 && j == 0)||(i == 2 && j == 1)||(i == 0 && j == 2)||(i == 1 && j == 2))
            {
                x[i][j]=0;
            }
            else
            {
                x[i][j]=1;
            }
        }
    }
    cout << "Matriks :" << endl;
    for (j = 0; j < 3 ; j++)
    {
        for (i = 0; i < 3 ; i++)
        {
            cout << x[i][j] << " " ;
        }
        cout << endl;
    }
    cout << endl;

    cout << "Masukkkan  titik kordinat " << endl;
    for (j = 0; j < 3 ; j++)
    {
        cin >> y[j];
    }
    cout << "Matriks Koordinat :" << endl;
    for (j = 0; j < 3 ; j++)
    {
        cout << y[j] << " ";
        cout << endl;
    }
    cout << endl;
    matriksRotasi();

    return 0;
}
