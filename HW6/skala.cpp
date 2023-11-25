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

void matriksSkala ()
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
     cout << "Matrix Skala :" << endl;

    for (j = 0; j < 3 ; j++)
    {
        cout << z[j] << " " << endl;
    }
}



int main ()
{
    cout << " Masukkan nilai matriks :"<<endl;
    for (j = 0; j < 3 ; j++)
    {
        cout << "Baris Matriks " << j+1 << " :" << endl;
        for (i = 0; i < 3 ; i++)
        {
            cin >> x[i][j];
        }
    }
    cout << "Matriks" << endl;
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
    cout << "Matrix Koordinat :" << endl;
    for (j = 0; j < 3 ; j++)
    {
        cout << y[j] << " " << endl;
    }
    cout << endl;
    matriksSkala();

    return 0;
}
