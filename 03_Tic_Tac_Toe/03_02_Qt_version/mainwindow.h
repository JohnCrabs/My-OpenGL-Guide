#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStatusBar>
#include <QTimer>
#include <QLCDNumber>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void checkWinDrawConditions();

    void on_resetBoard_clicked();

private:
    Ui::MainWindow *ui;

    QTimer timer;
    int WinCounter_O;
    int WinCounter_X;
    bool isOn;
};

#endif // MAINWINDOW_H
