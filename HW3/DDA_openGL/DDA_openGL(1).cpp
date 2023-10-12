/* Nama     : Bunga Dinda Endri NOvita
   Nim      : A11.2021.13786
   Kelompok : A11.4704
*/

#include<stdlib.h>
#include<iostream>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;
float x1, x2, y1, y2;

void display(void)
{
    float dy, dx, step, x, y, k, Xin, Yin;
    dx = x2 - x1;
    dy = y2 - y1;
    if (abs(dx) > abs(dy))
    {
        step = abs(dx);
    }
    else
        step = abs(dy);
    Xin = dx / step;
    Yin = dy / step;
    x = x1;
    y = y1;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    for (k = 1; k <= step; k++)
    {
        x = x + Xin;
        y = y + Yin;
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
    }
    glFlush();
}

void myInit (void)
{
    glClearColor(0.7,0.7,0.7,0.7);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-30,30,-30,30);
}

int main(int argc, char ** argv)
{
    x1=4;
    y1=10;
    x2=15;
    y2=4;
    cout << "Nilai x1 : " << x1 << endl;
    cout << "Nilai x1 : " << y1 << endl;
    cout << "Nilai x1 : " << x2 << endl;
    cout << "Nilai x1 : " << y2 << endl;

    glutInit( & argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(100,100);
    glutCreateWindow("DDA Line");
    myInit ();
    glutDisplayFunc(display);
    glutMainLoop();
}
