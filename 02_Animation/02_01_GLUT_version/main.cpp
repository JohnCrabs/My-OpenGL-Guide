/************/
/* main.cpp */
/************/

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

#define MY_WIN_WIDTH 250
#define MY_WIN_HEIGHT 250
#define MY_WIN_POS_X 100
#define MY_WIN_POS_Y 100
#define MY_WIN_TITLE "Motion"

static GLfloat spin =0.0;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(spin, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glRectf(-25.0, -25.0, 25.0, 25.0);
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void spinDisplay(void) {
    spin += 2.0;
    if(spin > 360)
        spin -= 360;
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    switch(button) {
    case GLUT_LEFT_BUTTON: {
        if(state == GLUT_DOWN)
            glutIdleFunc(spinDisplay);
        break;
    } case GLUT_MIDDLE_BUTTON: {
        if(state == GLUT_DOWN)
            glutIdleFunc(NULL);
        break;
    } default:
        break;
    }
}

void initializeGL(void) {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(MY_WIN_WIDTH, MY_WIN_HEIGHT);
    glutInitWindowPosition(MY_WIN_POS_X, MY_WIN_POS_Y);
    glutCreateWindow(MY_WIN_TITLE);
}

/*
 * Request double buffer display mode.
 * Register mouse input callback functions.
 */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    initializeGL();

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMainLoop();

    return 0;
}
