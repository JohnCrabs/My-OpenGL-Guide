#include "glwidget.h"
#include <GL/glu.h>

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent)
{
    //Update Window every 30ms
    connect(&GLtimer, SIGNAL(timeout()), this, SLOT(updateGL()));
    GLtimer.start(30);
}

/* Same as init(void) */
void GLWidget::initializeGL(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0); //Set Clear Color State

}

/* Same as display(void) */
void GLWidget::paintGL(void) {
    glClear(GL_COLOR_BUFFER_BIT); //Clear Window Background

    glColor3f(1.0, 1.0, 1.0); //Set Draw Color to WHITE

    //Draw rectangle
    glBegin(GL_POLYGON);
        glVertex3f(0.25, 0.25, 0.0);
        glVertex3f(0.75, 0.25, 0.0);
        glVertex3f(0.75, 0.75, 0.0);
        glVertex3f(0.25, 0.75, 0.0);
    glEnd();
}

/* Same as reshape(int w, int h) */
void GLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
