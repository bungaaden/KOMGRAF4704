/* Nama     : Bunga Dinda Endri Novita
   Nim      : A11.2021.13786
   Kelompok : A11.4704
*/

#include <iostream>
using namespace std;

int outsideRegion(int x, int y, int xmin, int xmax, int ymin, int ymax) {
    int regionCode = 0;
    if (x < xmin) regionCode |= 1; // region code bit 01: 0001
    if (x > xmax) regionCode |= 2; // region code bit 10: 0010
    if (y < ymin) regionCode |= 4; // region code bit 11: 0100
    if (y > ymax) regionCode |= 8; // region code bit 111: 1000
    return regionCode;
}

bool cohenSutherlandClip(int x0, int y0, int x1, int y1, int xmin, int xmax, int ymin, int ymax)
{
    int outcode0 = outsideRegion(x0, y0, xmin, xmax, ymin, ymax);
    int outcode1 = outsideRegion(x1, y1, xmin, xmax, ymin, ymax);
    bool accept = false;
    while (true) {
        if (!(outcode0 | outcode1)) { // Kedua titik di dalam klip
            accept = true;
            break;
        } else if (outcode0 & outcode1) { // Kedua titik di luar klip yang sama
            break;
        } else {
            int x, y;
            int outcodeOut = outcode0 ? outcode0 : outcode1;
            if (outcodeOut & 1) { // Titik keluar dari region pada sumbu X
                x = xmin;
                y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
            } else if (outcodeOut & 2) { // Titik keluar dari region pada sumbu X
                x = xmax;
                y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
            } else if (outcodeOut & 4) { // Titik keluar dari region pada sumbu Y
                y = ymin;
                x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
            } else { // Titik keluar dari region pada sumbu Y
                y = ymax;
                x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
            }
            if (outcodeOut == outcode0) {
                x0 = x;
                y0 = y;
                outcode0 = outsideRegion(x0, y0, xmin, xmax, ymin, ymax);
            } else {
                x1 = x;
                y1 = y;
                outcode1 = outsideRegion(x1, y1, xmin, xmax, ymin, ymax);
            }
        }
    }
    cout << endl;
    if (accept) {
        cout << "Titik akhir berada di dalam persegi." << endl;
        cout << "Koordinat titik potong : (" << x0 << ", " << y0 << ")" << endl;
    } else {
        cout << "Titik akhir berada di luar persegi." << endl;
    }
    return accept;
}

int main() {
    int x0, y0, x1, y1, xmin, xmax, ymin, ymax;
    cout << "Masukkan koordinat x0,y0 : ";
    cin >> x0 >> y0;
    cout << "Masukkan koordinat x1,y1 : ";
    cin >> x1 >> y1;
    cout << "Masukkan koordinat xmin,ymin : ";
    cin >> xmin >> ymin;
    cout << "Masukkan koordinat xmax,ymax : ";
    cin >> xmax >> ymax;

    cohenSutherlandClip(x0, y0, x1, y1, xmin, xmax, ymin, ymax);
    return 0;
}
