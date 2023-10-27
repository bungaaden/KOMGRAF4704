/* Nama     : Bunga Dinda Endri NOvita
   Nim      : A11.2021.13786
   Kelompok : A11.4704
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <GL/glut.h>

float xAwal, yAwal, xAkhir, yAkhir;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-30,30,-30,30);
}

void plotPixel(GLint xCoordinate, GLint yCoordinate)
{
    glBegin(GL_POINTS);
    glVertex2i(xCoordinate, yCoordinate);
    glEnd();
    glFlush();
}

void translasi (GLint x0, GLint y0, GLint x1, GLint y1)
{
    plotPixel(x0, y0);
    GLint xAkhir = x0 + x1;
    GLint yAkhir = y0 + y1;
    GLint xtemp= x0;
    GLint ytemp= y0;
    while (xtemp < xAkhir || ytemp < yAkhir) {
        if (xtemp < xAkhir)
        {
            xtemp++;
        }else if (ytemp < yAkhir) {
            ytemp++;
        }
        plotPixel(xtemp, ytemp);
    }
    plotPixel(xAkhir, yAkhir);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glPointSize(2.0);
    translasi(xAwal, yAwal, xAkhir, yAkhir);
}

int main(int argc, char** argv)
{
    xAwal= 6;
    yAwal= 8;
    xAkhir= 7;
    yAkhir =3;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Transformasi 2d Translasi");
    init();
    glutDisplayFunc(display);
    glutMainLoop();


    return 0;
}
