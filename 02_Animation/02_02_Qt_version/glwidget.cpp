#include "glwidget.h"

GLWidget::GLWidget(QWidget* parent) :
    QGLWidget(parent)
{
    connect(&glTimer, SIGNAL(timeout()), this, SLOT(updateGL()));
    glTimer.start(30);

    spin = 0.0;
    spinState = false;
}

/* Same as
 *  void init(void){...}
 * function.
 */
void GLWidget::initializeGL(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

/* Same as
 *  void reshape(int w, int h){...}
 * function. There isn't any need to call
 *  glutReshapeFunc(...)
 * to run this function.
 */
void GLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/* Same as
 *  void display(void){...}
 * function. There isn't any need to call
 *  glutDisplayFunc(...)
 * to run this function.
 */
void GLWidget::paintGL(void) {
    if(spinState)
        spinDisplay();
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(spin, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glRectf(-25.0, -25.0, 25.0, 25.0);
    glPopMatrix();
}

//Mouse Event Handling on QT
void GLWidget::mousePressEvent(QMouseEvent* event) {
    if(event->button() == Qt::LeftButton) {
        spinState = true;
    } else if (event->button() == Qt::MiddleButton) {
        spinState = false;
    } else {
        ;
    }
}





void GLWidget::spinDisplay(void) {
    spin += 2.0;
    if(spin >360)
        spin -= 360;
}

void GLWidget::changeSpinState() {
    spinState = (spinState == true) ? false : true;
}
