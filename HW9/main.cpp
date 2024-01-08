#include <iostream>
#include <cmath>

using namespace std;

void translate(double &x, double &y, double &z, double tx, double ty, double tz) {
    x += tx;
    y += ty;
    z += tz;
}

void scale(double &x, double &y, double &z, double sx, double sy, double sz) {
    x *= sx;
    y *= sy;
    z *= sz;
}

void rotateX(double &x, double &y, double &z, double angle) {
    double rad = angle * M_PI / 180;
    double newY = y * cos(rad) - z * sin(rad);
    double newZ = y * sin(rad) + z * cos(rad);
    y = newY;
    z = newZ;
}

void rotateY(double &x, double &y, double &z, double angle) {
    double rad = angle * M_PI / 180;
    double newX = x * cos(rad) - z * sin(rad);
    double newZ = x * sin(rad) + z * cos(rad);
    x = newX;
    z = newZ;
}

void rotateZ(double &x, double &y, double &z, double angle) {
    double rad = angle * M_PI / 180;
    double newX = x * cos(rad) - y * sin(rad);
    double newY = x * sin(rad) + y * cos(rad);
    x = newX;
    y = newY;
}

int main() {
    double x,y,z;
    cout << "Titik Koordinat (x,y,z) : ";
    cin >> x >> y >> z;

    translate(x, y, z, 2, 3, 4);
    cout << "Titik Translasi: (" << x << ", " << y << ", " << z << ")\n";

    scale(x, y, z, 2, 3, 4);
    cout << "Titik Skala: (" << x << ", " << y << ", " << z << ")\n";

    rotateX(x, y, z, 30);
    cout << "Titik Rotasi Sumbu-X: (" << x << ", " << y << ", " << z << ")\n";

    rotateY(x, y, z, 60);
    cout << "Titik Rotasi Sumbu-Y: (" << x << ", " << y << ", " << z << ")\n";

    rotateZ(x, y, z, 45);
    cout << "Titik Rotasi Sumbu-Z: (" << x << ", " << y << ", " << z << ")\n";


    return 0;
}
