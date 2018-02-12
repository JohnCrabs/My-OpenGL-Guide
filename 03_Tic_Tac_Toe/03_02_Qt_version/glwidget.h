/**************/
/* glwidget.h */
/**************/

#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QMouseEvent>
#include <QTimer>

#include "tictactoe.h"

class GLWidget : public QGLWidget
{
public:
    GLWidget(QWidget *parent);

    void initializeGL(void); //init(void)

    void resizeGL(int w, int h); //reshape(int h, int w)

    void paintGL(void); //display(void)

    void mousePressEvent(QMouseEvent* event); //Check Mouse Events

    void resetGame(void) {game.resetBoard();}

    bool isWin(void) {return game.IsWin();}

    bool isDraw(void) {return game.IsDraw();}

    char WinPlayer(void) {return game.WinPlayer();}

private:
    QTimer glTimer;
    TicTacToe game;

};

#endif // GLWIDGET_H
