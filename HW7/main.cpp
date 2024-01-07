#include <iostream>
#include <cmath>

using namespace std;

struct Point
{
    double x, y;
};

Point reflectPoint(Point p, char axis)
{
    if (axis == 'x' || axis == 'X') //sumbu X
    {
        p.y = -p.y;
    }
    else if (axis == 'y' || axis == 'Y') //sumbu Y
    {
        p.x = -p.x;
    }
    else if (axis == 'l' || axis == 'L') //sumbu Y=X
    {
        double temp = p.x;
        p.x = p.y;
        p.y = temp;
    }
    else if (axis == 'r' || axis == 'R') //sumbu Y=-X
    {
        double temp = p.x;
        p.x = -p.y;
        p.y = -temp;
    }
    else
    {
        cout << "ERROR" << endl;
        return p;
    }
    return p;
}

int main() {
    Point p = {1, 3};
    char axis;

    cout << "Titik (" << p.x << ", " << p.y << ")" << endl;
    cout << "Masukkan Refleksi Terhadap Sumbu : ";
    cin >> axis;

    Point reflectedPoint = reflectPoint(p, axis);

    cout << "Titik Refleksi (" << reflectedPoint.x << ", " << reflectedPoint.y << ")" << endl;

    return 0;
}
