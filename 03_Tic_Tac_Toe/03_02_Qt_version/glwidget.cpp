/****************/
/* glwidget.cpp */
/****************/

#include "glwidget.h"

GLWidget::GLWidget(QWidget* parent) :
    QGLWidget(parent)
{
    connect(&glTimer, SIGNAL(timeout()), this, SLOT(updateGL()));
    glTimer.start(30);

    resetGame();
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
    glOrtho(0.0, game.boardWidth(), 0.0, game.boardHeight(), -1.0, 1.0);
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
    glClear(GL_COLOR_BUFFER_BIT);
    game.drawGrid();
    game.drawTiles();

}

//Mouse Event Handling on QT
void GLWidget::mousePressEvent(QMouseEvent* event) {
    switch (event->button()) {
    case Qt::LeftButton:
        if(!game.IsWin() && !game.IsDraw())
            game.checkTileToDraw((float)event->x()/width(), (float)(height() - event->y())/height());
        break;
    default:
        break;
    }
}
