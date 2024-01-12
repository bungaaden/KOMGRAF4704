#include <GL/glut.h>
#include <cmath>

// variabel global untuk transformasi 3D
float translateX = 0.0;
float translateY = 0.0;
float translateZ = -5.0;

float scaleX = 1.0;
float scaleY = 1.0;
float scaleZ = 1.0;

float rotateX = 0.0;
float rotateY = 0.0;
float rotateZ = 0.0;

// fungsi untuk mengatur model dan view pada pembangunan struktur OpenGL
void displayModel(void) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 30.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glPushMatrix();
    glTranslatef(translateX, translateY, translateZ);
    glScalef(scaleX, scaleY, scaleZ);
    glRotatef(rotateX, 1.0, 0.0, 0.0);
    glRotatef(rotateY, 0.0, 1.0, 0.0);
    glRotatef(rotateZ, 0.0, 0.0, 1.0);

    glutSolidSphere(1.0, 50, 50);

    glPopMatrix();

    glFlush();
}

// fungsi untuk menampilkan gambar pada layar
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    displayModel();
    glutSwapBuffers();
}

// fungsi untuk menangani event reshape
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
}

// fungsi untuk menangani event keyboard
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':
            translateX -= 0.1;
            break;
        case 'd':
            translateX += 0.1;
            break;
        case 'w':
            translateY += 0.1;
            break;
        case 's':
            translateY -= 0.1;
            break;
        case 'q':
            translateZ -= 0.1;
            break;
        case 'e':
            translateZ += 0.1;
            break;
        case 'r':
            scaleX += 0.1;
            scaleY += 0.1;
            scaleZ += 0.1;
            break;
        case 'f':
            scaleX -= 0.1;
            scaleY -= 0.1;
            scaleZ -= 0.1;
            break;
        case 'x':
            rotateX += 5.0;
            break;
        case 'y':
            rotateY += 5.0;
            break;
        case 'z':
            rotateZ += 5.0;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

// fungsi main untuk menjalankan program
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL 3D Transformasi");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
