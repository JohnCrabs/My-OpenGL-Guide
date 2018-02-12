/******************/
/* mainwindow.cpp */
/******************/

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "tictactoe.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->StatusBar->showMessage("Player O plays First", 2000);

    connect(&timer, SIGNAL(timeout()), this, SLOT(checkWinDrawConditions()));
    timer.start(500);

    WinCounter_O = 0;
    WinCounter_X = 0;

    ui->OWins_LCD->display(WinCounter_O);
    ui->OWins_LCD->setPalette(Qt::blue);

    ui->XWins_LCD->display(WinCounter_X);
    ui->XWins_LCD->setPalette(Qt::red);

    isOn = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::checkWinDrawConditions() {
    if(ui->TicTacToeWidget->isWin()) {
        if(ui->TicTacToeWidget->WinPlayer() == PLAYER_O && isOn) {
            WinCounter_O++;
            ui->StatusBar->showMessage("Player O win!", 2000);
            ui->OWins_LCD->display(WinCounter_O);
            isOn = false;
        } else if(ui->TicTacToeWidget->WinPlayer() == PLAYER_X && isOn) {
            WinCounter_X++;
            ui->StatusBar->showMessage("Player X win!", 2000);
            ui->XWins_LCD->display(WinCounter_X);
            isOn = false;
        }
    } else if(ui->TicTacToeWidget->isDraw() && isOn) {
        ui->StatusBar->showMessage("Congratulations both of you! The game is DRAWN!", 2000);
        isOn = false;
    }

}

void MainWindow::on_resetBoard_clicked()
{
    ui->TicTacToeWidget->resetGame();
    ui->StatusBar->showMessage("Player O plays First", 2000);
    isOn = true;
}
