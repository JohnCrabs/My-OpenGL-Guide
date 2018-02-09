#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QMouseEvent>
#include <QTimer>

class GLWidget : public QGLWidget
{
public:
    GLWidget(QWidget *parent);

    void initializeGL(void); //init(void)

    void resizeGL(int w, int h); //reshape(int h, int w)

    void paintGL(void); //display(void)

    void mousePressEvent(QMouseEvent* event); //Check Mouse Events

    void changeSpinState();

private:
    QTimer glTimer;
    GLdouble spin;
    bool spinState;

    void spinDisplay(void);
};

#endif // GLWIDGET_H
