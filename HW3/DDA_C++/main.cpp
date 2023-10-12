/* Nama     : Bunga Dinda Endri NOvita
   Nim      : A11.2021.13786
   Kelompok : A11.4704
*/

#include <iostream>
#include <cmath>

using namespace std;

void titikDDA(int x1, int y1, int x2, int y2) {
    // Menghitung selisih X dan Y
    int dx = x2 - x1;
    int dy = y2 - y1;

    // Menghitung step yang dibutuhkan
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = static_cast<float>(dx) / static_cast<float>(steps);
    float yIncrement = static_cast<float>(dy) / static_cast<float>(steps);

    float x = x1;
    float y = y1;

    cout << "Titik-titik pada garis algoritma DDA :" << endl;
    for (int i = 0; i <= steps; ++i) {
        cout << "(" << round(x) << "," << round(y) << ")";
        x += xIncrement;
        y += yIncrement;
    }
}

int main()
{
    int x1, y1, x2, y2;

    x1=4, y1=10, x2=15, y2=4;
    cout << "1. A(4,10) B(15,4)"<<endl;
    titikDDA(x1, y1, x2, y2);
    cout<<endl;

    x1=14, y1=10, x2=2, y2=8;
    cout << "2. A(14,10) B(2,8) "<<endl;;
    titikDDA(x1, y1, x2, y2);
    cout<<endl;

    x1=14, y1=2, x2=2, y2=10;
    cout << "3. A(14,2) B(2,10) "<<endl;
    titikDDA(x1, y1, x2, y2);

    return 0;
}
