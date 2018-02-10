/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QLabel *winsX_label;
    QLabel *winsO_label;
    QPushButton *resetBoard;
    QLCDNumber *XWins_LCD;
    GLWidget *TicTacToeWidget;
    QLCDNumber *OWins_LCD;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *StatusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(710, 556);
        MainWindow->setMinimumSize(QSize(710, 550));
        MainWindow->setMaximumSize(QSize(710, 556));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        winsX_label = new QLabel(centralWidget);
        winsX_label->setObjectName(QStringLiteral("winsX_label"));
        winsX_label->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(winsX_label, 0, 6, 1, 1);

        winsO_label = new QLabel(centralWidget);
        winsO_label->setObjectName(QStringLiteral("winsO_label"));
        winsO_label->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(winsO_label, 0, 0, 1, 1);

        resetBoard = new QPushButton(centralWidget);
        resetBoard->setObjectName(QStringLiteral("resetBoard"));

        gridLayout->addWidget(resetBoard, 1, 3, 1, 1);

        XWins_LCD = new QLCDNumber(centralWidget);
        XWins_LCD->setObjectName(QStringLiteral("XWins_LCD"));
        XWins_LCD->setAutoFillBackground(false);
        XWins_LCD->setStyleSheet(QStringLiteral(""));
        XWins_LCD->setFrameShape(QFrame::StyledPanel);
        XWins_LCD->setFrameShadow(QFrame::Raised);
        XWins_LCD->setLineWidth(1);
        XWins_LCD->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(XWins_LCD, 1, 6, 1, 1);

        TicTacToeWidget = new GLWidget(centralWidget);
        TicTacToeWidget->setObjectName(QStringLiteral("TicTacToeWidget"));
        TicTacToeWidget->setMinimumSize(QSize(450, 450));
        TicTacToeWidget->setMaximumSize(QSize(450, 450));

        gridLayout->addWidget(TicTacToeWidget, 0, 3, 1, 1);

        OWins_LCD = new QLCDNumber(centralWidget);
        OWins_LCD->setObjectName(QStringLiteral("OWins_LCD"));
        OWins_LCD->setLayoutDirection(Qt::LeftToRight);
        OWins_LCD->setAutoFillBackground(false);
        OWins_LCD->setStyleSheet(QStringLiteral(""));
        OWins_LCD->setFrameShape(QFrame::StyledPanel);
        OWins_LCD->setDigitCount(5);
        OWins_LCD->setMode(QLCDNumber::Dec);
        OWins_LCD->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(OWins_LCD, 1, 0, 1, 1, Qt::AlignHCenter);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 710, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        StatusBar = new QStatusBar(MainWindow);
        StatusBar->setObjectName(QStringLiteral("StatusBar"));
        MainWindow->setStatusBar(StatusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Tic-Tac-Toe", nullptr));
        winsX_label->setText(QApplication::translate("MainWindow", "<b>X Wins <b>", nullptr));
        winsO_label->setText(QApplication::translate("MainWindow", "<b>O Wins<b>", nullptr));
        resetBoard->setText(QApplication::translate("MainWindow", "Reset Board", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
