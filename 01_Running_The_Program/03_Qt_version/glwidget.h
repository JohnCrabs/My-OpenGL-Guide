/**************/
/* glwidget.h */
/**************/

#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QTimer>

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = nullptr);

    void initializeGL(void);

    void paintGL(void);

    void resizeGL(int w, int h);

private:
    QTimer GLtimer;
};

#endif // GLWIDGET_H
