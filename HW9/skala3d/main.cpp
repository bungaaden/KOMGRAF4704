#include <GL/glut.h>
#include <cmath>

// variabel rotasi
float rotationY = 0;
float rotationX = 0;

// fungsi untuk menggambar sebuah skala
void drawScale(float size, float divisions, float subdivisions)
{
    float subdivisionSize = size / divisions / subdivisions;
    for (int i = 0; i <= divisions; i++)
    {
        float pos = (i - divisions / 2) * size / divisions;
        glPushMatrix();
        glTranslatef(pos, 0, 0);
        glColor3f(1, 1, 1);
        glutSolidCube(size / divisions / 10);
        glPopMatrix();
        for (int j = 1; j < subdivisions; j++)
        {
            float subPos = (j - subdivisions / 2) * subdivisionSize;
            glPushMatrix();
            glTranslatef(pos + subPos, 0, 0);
            glColor3f(0.5, 0.5, 0.5);
            glutSolidCube(size / divisions / 10);
            glPopMatrix();
        }
    }
}

// fungsi untuk menggambar skala 3D
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

    glRotatef(rotationX, 1, 0, 0);
    glRotatef(rotationY, 0, 1, 0);

    glColor3f(0, 1, 0);
    drawScale(5, 5, 10);

    glutSwapBuffers();
}

// fungsi untuk menangani gerakan mouse
void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        rotationX += x - glutGet(GLUT_WINDOW_WIDTH) / 2;
        rotationY += y - glutGet(GLUT_WINDOW_HEIGHT) / 2;
        glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH) / 2, glutGet(GLUT_WINDOW_HEIGHT) / 2);
    }
}

// fungsi untuk merubah ukuran window
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (float) w / h, 1, 100);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Skala 3D");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
}
