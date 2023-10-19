/* Nama     : Bunga Dinda Endri NOvita
   Nim      : A11.2021.13786
   Kelompok : A11.4704
*/

#include <GL/glut.h>
#include<iostream>

using namespace std;
int x1, y1, x2, y2;

void plotPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void bresenhamLine()
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int p = 2 * dy - dx;

    int x = x1;
    int y = y1;

    plotPixel(x, y);

    for (int i = x1; i <= x2; i++) {
        if (p < 0) {
            p = p + 2 * dy;
        } else {
            p = p + 2 * dy - 2 * dx;
            y++;
        }
        x++;
        plotPixel(x, y);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set color to white
    bresenhamLine();
    glFlush();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set clear color to black
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-30, 30, -30, 30);
}

int main(int argc, char** argv)
{
    //x1 = 8, y1 = 6, x2 = 3, y2 = 7;
    cout << "Nilai x1 : ";
    cin >>x1;
    cout << "Nilai y1 : ";
    cin >>y1;
    cout << "Nilai x2 : ";
    cin >>x2;
    cout << "Nilai y2 : ";
    cin >>y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham's Line Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
