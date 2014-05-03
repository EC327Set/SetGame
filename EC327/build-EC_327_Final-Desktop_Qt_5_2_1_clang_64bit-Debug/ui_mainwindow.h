/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
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
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *Set_Stack;
    QWidget *Game_Screen;
    QLCDNumber *lcdNumber;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *Main_Screen;
    QPushButton *Play_Button;
    QPushButton *Rules_Button;
    QPushButton *High_Score_Button;
    QLabel *label;
    QWidget *Rules_Screen;
    QPushButton *Rule_Back_Button;
    QWidget *Score_Screen;
    QPushButton *Back_Score_Button;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(381, 309);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Set_Stack = new QStackedWidget(centralWidget);
        Set_Stack->setObjectName(QStringLiteral("Set_Stack"));
        Set_Stack->setGeometry(QRect(-50, 0, 441, 271));
        Game_Screen = new QWidget();
        Game_Screen->setObjectName(QStringLiteral("Game_Screen"));
        lcdNumber = new QLCDNumber(Game_Screen);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(350, 30, 64, 23));
        gridLayoutWidget = new QWidget(Game_Screen);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(60, 20, 281, 231));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Set_Stack->addWidget(Game_Screen);
        Main_Screen = new QWidget();
        Main_Screen->setObjectName(QStringLiteral("Main_Screen"));
        Play_Button = new QPushButton(Main_Screen);
        Play_Button->setObjectName(QStringLiteral("Play_Button"));
        Play_Button->setGeometry(QRect(140, 110, 181, 31));
        Play_Button->setStyleSheet(QStringLiteral("font: 18pt \"Swis721 BlkEx BT\";"));
        Rules_Button = new QPushButton(Main_Screen);
        Rules_Button->setObjectName(QStringLiteral("Rules_Button"));
        Rules_Button->setGeometry(QRect(140, 160, 181, 31));
        Rules_Button->setStyleSheet(QStringLiteral("font: 18pt \"Swis721 BlkEx BT\";"));
        High_Score_Button = new QPushButton(Main_Screen);
        High_Score_Button->setObjectName(QStringLiteral("High_Score_Button"));
        High_Score_Button->setGeometry(QRect(140, 210, 181, 31));
        High_Score_Button->setStyleSheet(QStringLiteral("font: 14pt \"Swis721 BlkEx BT\";"));
        label = new QLabel(Main_Screen);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 30, 191, 61));
        label->setStyleSheet(QStringLiteral("font: 48pt \"Swis721 BlkEx BT\";"));
        Set_Stack->addWidget(Main_Screen);
        Rules_Screen = new QWidget();
        Rules_Screen->setObjectName(QStringLiteral("Rules_Screen"));
        Rule_Back_Button = new QPushButton(Rules_Screen);
        Rule_Back_Button->setObjectName(QStringLiteral("Rule_Back_Button"));
        Rule_Back_Button->setGeometry(QRect(310, 220, 75, 23));
        Set_Stack->addWidget(Rules_Screen);
        Score_Screen = new QWidget();
        Score_Screen->setObjectName(QStringLiteral("Score_Screen"));
        Score_Screen->setEnabled(true);
        Back_Score_Button = new QPushButton(Score_Screen);
        Back_Score_Button->setObjectName(QStringLiteral("Back_Score_Button"));
        Back_Score_Button->setGeometry(QRect(310, 220, 75, 23));
        Set_Stack->addWidget(Score_Screen);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 381, 18));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        Set_Stack->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        Play_Button->setText(QApplication::translate("MainWindow", "Play", 0));
        Rules_Button->setText(QApplication::translate("MainWindow", "Rules", 0));
        High_Score_Button->setText(QApplication::translate("MainWindow", "High Scores", 0));
        label->setText(QApplication::translate("MainWindow", "SET ", 0));
        Rule_Back_Button->setText(QApplication::translate("MainWindow", "Back", 0));
        Back_Score_Button->setText(QApplication::translate("MainWindow", "Back", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
