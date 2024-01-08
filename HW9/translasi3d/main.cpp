#include <GL/glut.h>
#include <iostream>

float x = 0.0f;
float y = 0.0f;
float z = 0.0f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // matriks translasi
    glTranslatef(x, y, z);

    // dmenggambar objek 3D
    glColor3f(1.0f, 0.0f, 0.0f);
    glutSolidCube(1.0f);

    glutSwapBuffers();
}

void specialKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_RIGHT)
        x += 0.1f;
    else if (key == GLUT_KEY_LEFT)
        x -= 0.1f;
    else if (key == GLUT_KEY_UP)
        y += 0.1f;
    else if (key == GLUT_KEY_DOWN)
        y -= 0.1f;

    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("3D Translasi");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);

    glutMainLoop();

    return 1;
}
