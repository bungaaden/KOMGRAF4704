/* Nama     : Bunga Dinda Endri Novita
   Nim      : A11.2021.13786
   Kelompok : A11.4704
*/  
#include <iostream>
using namespace std;

int main()
{

    int a[10][10],b[10][10];
    int hasil[10][10];
    int m,n,s;
    cout << "Input baris matriks : ";
    cin >> m;
    cout << "Input kolom matriks : ";
    cin >> n;
    cout << "=================================" << endl;

    cout << "Input Matriks A :" << endl;
    for (int x=1; x<=m; x++){ 
        for (int y=1; y<=n; y++){ 
                cin >> a[x][y];
            }
      }
    cout << "Matriks A : " << endl;
    for (int x=1; x<=m; x++){ 
     for (int y=1; y<=n; y++){   
             cout << a[x][y] << " ";
         }
         cout<<endl;
   }
    cout << endl;
    cout << "Input Matriks B :" << endl;
    for (int x=1; x<=m; x++){ 
        for (int y=1; y<=n; y++){ 
                cin >> b[x][y];
            }
    }
    cout << "Matriks B :" << endl;
    for (int x=1; x<=m; x++){ 
            for (int y=1; y<=n; y++){ 
                    cout << b[x][y] << " ";
                }
            cout<<endl;
    }
    cout << "=================================" << endl;

    cout << "Hasil Matriks A + Matriks B : "<< endl;
    for (int x=1; x<=m; x++){ 
        for (int y=1; y<=n; y++){ 
            hasil[x][y] = a[x][y] + b[x][y];
        cout << hasil[x][y] << " ";
        }
    cout << endl;
    }
    cout << "=================================" << endl;

    cout << "Hasil Matriks A - Matriks B : "<< endl;
        for (int x=1; x<=m; x++){ 
            for (int y=1; y<=n; y++){ 
                hasil[x][y] = a[x][y] - b[x][y];
                cout << hasil[x][y] << " ";
            }
        cout << endl;
    }
    cout << "=================================" << endl;

    //proses perhitungan perkalian matriks
    for (int x=1; x<=m; x++){ 
        for (int y=1; y<=n; y++){ 
            hasil[x][y]=0;
            for (int z=1; z<=m; z++){
                hasil[x][y] = hasil[x][y] + (a[x][z] * b[z][y]);
            }
        }
    }
    cout << "Hasil Matriks A * Matriks B : "<< endl;
      for (int x=1; x<=m; x++){ 
            for (int y=1; y<=n; y++){ 
            cout << hasil[x][y] << " ";
            }
        cout << endl;
    }
     
    cout << "=================================" << endl;

    cout << "Hasil Matriks Perkalian Skalar : "<< endl;
    cout << "Input nilai skalar : ";
    cin >> s;
    for (int x=1; x<=m; x++){ 
            for (int y=1; y<=n; y++){ 
                hasil[x][y] = a[x][y] * s;
                cout << hasil[x][y] << " ";
            }
        cout << endl;
    }

    return 0;
}
