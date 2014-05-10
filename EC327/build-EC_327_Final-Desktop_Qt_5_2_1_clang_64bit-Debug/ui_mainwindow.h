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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *Set_Stack;
    QWidget *Game_Screen;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *card1;
    QPushButton *card4;
    QPushButton *card6;
    QPushButton *card3;
    QPushButton *card11;
    QPushButton *card12;
    QPushButton *card10;
    QPushButton *card8;
    QPushButton *card2;
    QPushButton *card5;
    QPushButton *card7;
    QPushButton *card9;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *playerName;
    QLabel *playerScore;
    QLabel *aiName;
    QLabel *aiScore;
    QLabel *deck;
    QLabel *deckSize;
    QPushButton *setButton;
    QPushButton *Back_Button_Main;
    QWidget *Main_Screen;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Play_Button;
    QPushButton *Rules_Button;
    QPushButton *High_Score_Button;
    QWidget *Rules_Screen;
    QPushButton *Rule_Back_Button;
    QWidget *Score_Screen;
    QPushButton *Back_Score_Button;
    QLabel *Name5;
    QLabel *Name1;
    QLabel *Score4;
    QLabel *Name4;
    QLabel *label_6;
    QLabel *Name2;
    QLabel *label_3;
    QLabel *Score5;
    QLabel *label_4;
    QLabel *Name3;
    QLabel *label_7;
    QLabel *Score2;
    QLabel *Score3;
    QLabel *Score1;
    QLabel *label_2;
    QLabel *label_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(718, 531);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Set_Stack = new QStackedWidget(centralWidget);
        Set_Stack->setObjectName(QStringLiteral("Set_Stack"));
        Set_Stack->setGeometry(QRect(10, 0, 711, 471));
        Set_Stack->setAutoFillBackground(true);
        Game_Screen = new QWidget();
        Game_Screen->setObjectName(QStringLiteral("Game_Screen"));
        gridLayoutWidget = new QWidget(Game_Screen);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(200, 50, 462, 311));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        card1 = new QPushButton(gridLayoutWidget);
        card1->setObjectName(QStringLiteral("card1"));

        gridLayout->addWidget(card1, 0, 0, 1, 1);

        card4 = new QPushButton(gridLayoutWidget);
        card4->setObjectName(QStringLiteral("card4"));

        gridLayout->addWidget(card4, 0, 3, 1, 1);

        card6 = new QPushButton(gridLayoutWidget);
        card6->setObjectName(QStringLiteral("card6"));

        gridLayout->addWidget(card6, 1, 1, 1, 1);

        card3 = new QPushButton(gridLayoutWidget);
        card3->setObjectName(QStringLiteral("card3"));

        gridLayout->addWidget(card3, 0, 2, 1, 1);

        card11 = new QPushButton(gridLayoutWidget);
        card11->setObjectName(QStringLiteral("card11"));

        gridLayout->addWidget(card11, 2, 2, 1, 1);

        card12 = new QPushButton(gridLayoutWidget);
        card12->setObjectName(QStringLiteral("card12"));

        gridLayout->addWidget(card12, 2, 3, 1, 1);

        card10 = new QPushButton(gridLayoutWidget);
        card10->setObjectName(QStringLiteral("card10"));

        gridLayout->addWidget(card10, 2, 1, 1, 1);

        card8 = new QPushButton(gridLayoutWidget);
        card8->setObjectName(QStringLiteral("card8"));

        gridLayout->addWidget(card8, 1, 3, 1, 1);

        card2 = new QPushButton(gridLayoutWidget);
        card2->setObjectName(QStringLiteral("card2"));

        gridLayout->addWidget(card2, 0, 1, 1, 1);

        card5 = new QPushButton(gridLayoutWidget);
        card5->setObjectName(QStringLiteral("card5"));

        gridLayout->addWidget(card5, 1, 0, 1, 1);

        card7 = new QPushButton(gridLayoutWidget);
        card7->setObjectName(QStringLiteral("card7"));

        gridLayout->addWidget(card7, 1, 2, 1, 1);

        card9 = new QPushButton(gridLayoutWidget);
        card9->setObjectName(QStringLiteral("card9"));

        gridLayout->addWidget(card9, 2, 0, 1, 1);

        verticalLayoutWidget_2 = new QWidget(Game_Screen);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 60, 184, 201));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        playerName = new QLabel(verticalLayoutWidget_2);
        playerName->setObjectName(QStringLiteral("playerName"));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        playerName->setFont(font);

        verticalLayout_2->addWidget(playerName);

        playerScore = new QLabel(verticalLayoutWidget_2);
        playerScore->setObjectName(QStringLiteral("playerScore"));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        playerScore->setFont(font1);
        playerScore->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(playerScore);

        aiName = new QLabel(verticalLayoutWidget_2);
        aiName->setObjectName(QStringLiteral("aiName"));
        aiName->setFont(font);

        verticalLayout_2->addWidget(aiName);

        aiScore = new QLabel(verticalLayoutWidget_2);
        aiScore->setObjectName(QStringLiteral("aiScore"));
        aiScore->setFont(font1);
        aiScore->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(aiScore);

        deck = new QLabel(verticalLayoutWidget_2);
        deck->setObjectName(QStringLiteral("deck"));
        deck->setFont(font);

        verticalLayout_2->addWidget(deck);

        deckSize = new QLabel(verticalLayoutWidget_2);
        deckSize->setObjectName(QStringLiteral("deckSize"));
        deckSize->setFont(font1);
        deckSize->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(deckSize);

        setButton = new QPushButton(Game_Screen);
        setButton->setObjectName(QStringLiteral("setButton"));
        setButton->setGeometry(QRect(380, 390, 114, 32));
        Back_Button_Main = new QPushButton(Game_Screen);
        Back_Button_Main->setObjectName(QStringLiteral("Back_Button_Main"));
        Back_Button_Main->setGeometry(QRect(590, 420, 101, 41));
        Set_Stack->addWidget(Game_Screen);
        Main_Screen = new QWidget();
        Main_Screen->setObjectName(QStringLiteral("Main_Screen"));
        label = new QLabel(Main_Screen);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 30, 381, 181));
        label->setStyleSheet(QStringLiteral("font: 48pt \"Swis721 BlkEx BT\";"));
        label->setPixmap(QPixmap(QString::fromUtf8("setLogo.png")));
        verticalLayoutWidget = new QWidget(Main_Screen);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(220, 220, 291, 191));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Play_Button = new QPushButton(verticalLayoutWidget);
        Play_Button->setObjectName(QStringLiteral("Play_Button"));
        Play_Button->setStyleSheet(QStringLiteral("font: 18pt \"Swis721 BlkEx BT\";"));

        verticalLayout->addWidget(Play_Button);

        Rules_Button = new QPushButton(verticalLayoutWidget);
        Rules_Button->setObjectName(QStringLiteral("Rules_Button"));
        Rules_Button->setStyleSheet(QStringLiteral("font: 18pt \"Swis721 BlkEx BT\";"));

        verticalLayout->addWidget(Rules_Button);

        High_Score_Button = new QPushButton(verticalLayoutWidget);
        High_Score_Button->setObjectName(QStringLiteral("High_Score_Button"));
        High_Score_Button->setStyleSheet(QStringLiteral("font: 14pt \"Swis721 BlkEx BT\";"));

        verticalLayout->addWidget(High_Score_Button);

        Set_Stack->addWidget(Main_Screen);
        Rules_Screen = new QWidget();
        Rules_Screen->setObjectName(QStringLiteral("Rules_Screen"));
        Rule_Back_Button = new QPushButton(Rules_Screen);
        Rule_Back_Button->setObjectName(QStringLiteral("Rule_Back_Button"));
        Rule_Back_Button->setGeometry(QRect(610, 410, 75, 23));
        Set_Stack->addWidget(Rules_Screen);
        Score_Screen = new QWidget();
        Score_Screen->setObjectName(QStringLiteral("Score_Screen"));
        Score_Screen->setEnabled(true);
        Back_Score_Button = new QPushButton(Score_Screen);
        Back_Score_Button->setObjectName(QStringLiteral("Back_Score_Button"));
        Back_Score_Button->setGeometry(QRect(610, 410, 75, 23));
        Name5 = new QLabel(Score_Screen);
        Name5->setObjectName(QStringLiteral("Name5"));
        Name5->setGeometry(QRect(270, 300, 151, 31));
        Name5->setStyleSheet(QStringLiteral("font: 16pt \"Swis721 BlkEx BT\";"));
        Name1 = new QLabel(Score_Screen);
        Name1->setObjectName(QStringLiteral("Name1"));
        Name1->setGeometry(QRect(270, 140, 151, 31));
        Name1->setStyleSheet(QStringLiteral("font: 16pt \"Swis721 BlkEx BT\";"));
        Score4 = new QLabel(Score_Screen);
        Score4->setObjectName(QStringLiteral("Score4"));
        Score4->setGeometry(QRect(470, 260, 81, 31));
        Score4->setStyleSheet(QStringLiteral("font: 16pt \"Swis721 BlkEx BT\";"));
        Name4 = new QLabel(Score_Screen);
        Name4->setObjectName(QStringLiteral("Name4"));
        Name4->setGeometry(QRect(270, 260, 151, 31));
        Name4->setStyleSheet(QStringLiteral("font: 16pt \"Swis721 BlkEx BT\";"));
        label_6 = new QLabel(Score_Screen);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(150, 260, 61, 31));
        label_6->setStyleSheet(QStringLiteral("font: 16pt \"Swis721 BlkEx BT\";"));
        Name2 = new QLabel(Score_Screen);
        Name2->setObjectName(QStringLiteral("Name2"));
        Name2->setGeometry(QRect(270, 180, 151, 31));
        Name2->setStyleSheet(QStringLiteral("font: 16pt \"Swis721 BlkEx BT\";"));
        label_3 = new QLabel(Score_Screen);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(150, 140, 61, 31));
        label_3->setStyleSheet(QStringLiteral("font: 16pt \"Swis721 BlkEx BT\";"));
        Score5 = new QLabel(Score_Screen);
        Score5->setObjectName(QStringLiteral("Score5"));
        Score5->setGeometry(QRect(470, 300, 81, 31));
        Score5->setStyleSheet(QStringLiteral("font: 16pt \"Swis721 BlkEx BT\";"));
        label_4 = new QLabel(Score_Screen);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(150, 180, 61, 31));
        label_4->setStyleSheet(QStringLiteral("font: 16pt \"Swis721 BlkEx BT\";"));
        Name3 = new QLabel(Score_Screen);
        Name3->setObjectName(QStringLiteral("Name3"));
        Name3->setGeometry(QRect(270, 220, 151, 31));
        Name3->setStyleSheet(QStringLiteral("font: 16pt \"Swis721 BlkEx BT\";"));
        label_7 = new QLabel(Score_Screen);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(150, 300, 61, 31));
        label_7->setStyleSheet(QStringLiteral("font: 16pt \"Swis721 BlkEx BT\";"));
        Score2 = new QLabel(Score_Screen);
        Score2->setObjectName(QStringLiteral("Score2"));
        Score2->setGeometry(QRect(470, 180, 81, 31));
        Score2->setStyleSheet(QStringLiteral("font: 16pt \"Swis721 BlkEx BT\";"));
        Score3 = new QLabel(Score_Screen);
        Score3->setObjectName(QStringLiteral("Score3"));
        Score3->setGeometry(QRect(470, 220, 81, 31));
        Score3->setStyleSheet(QStringLiteral("font: 16pt \"Swis721 BlkEx BT\";"));
        Score1 = new QLabel(Score_Screen);
        Score1->setObjectName(QStringLiteral("Score1"));
        Score1->setGeometry(QRect(470, 140, 81, 31));
        Score1->setStyleSheet(QStringLiteral("font: 16pt \"Swis721 BlkEx BT\";"));
        label_2 = new QLabel(Score_Screen);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 20, 411, 41));
        label_2->setStyleSheet(QStringLiteral("font: 30pt \"Swis721 BlkEx BT\";"));
        label_5 = new QLabel(Score_Screen);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(150, 220, 61, 31));
        label_5->setStyleSheet(QStringLiteral("font: 16pt \"Swis721 BlkEx BT\";"));
        Set_Stack->addWidget(Score_Screen);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 718, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        Set_Stack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        card1->setText(QString());
        card4->setText(QString());
        card6->setText(QString());
        card3->setText(QString());
        card11->setText(QString());
        card12->setText(QString());
        card10->setText(QString());
        card8->setText(QString());
        card2->setText(QString());
        card5->setText(QString());
        card7->setText(QString());
        card9->setText(QString());
        playerName->setText(QApplication::translate("MainWindow", "Player 1", 0));
        playerScore->setText(QApplication::translate("MainWindow", "0", 0));
        aiName->setText(QApplication::translate("MainWindow", "Computer", 0));
        aiScore->setText(QApplication::translate("MainWindow", "0", 0));
        deck->setText(QApplication::translate("MainWindow", "Cards left in Deck", 0));
        deckSize->setText(QApplication::translate("MainWindow", "81", 0));
        setButton->setText(QApplication::translate("MainWindow", "Set!", 0));
        Back_Button_Main->setText(QApplication::translate("MainWindow", "Back", 0));
        label->setText(QString());
        Play_Button->setText(QApplication::translate("MainWindow", "Play", 0));
        Rules_Button->setText(QApplication::translate("MainWindow", "Rules", 0));
        High_Score_Button->setText(QApplication::translate("MainWindow", "High Scores", 0));
        Rule_Back_Button->setText(QApplication::translate("MainWindow", "Back", 0));
        Back_Score_Button->setText(QApplication::translate("MainWindow", "Back", 0));
        Name5->setText(QApplication::translate("MainWindow", "John Doe", 0));
        Name1->setText(QApplication::translate("MainWindow", "John Doe", 0));
        Score4->setText(QApplication::translate("MainWindow", "1", 0));
        Name4->setText(QApplication::translate("MainWindow", "John Doe", 0));
        label_6->setText(QApplication::translate("MainWindow", "4.", 0));
        Name2->setText(QApplication::translate("MainWindow", "John Doe", 0));
        label_3->setText(QApplication::translate("MainWindow", "1.", 0));
        Score5->setText(QApplication::translate("MainWindow", "1", 0));
        label_4->setText(QApplication::translate("MainWindow", "2.", 0));
        Name3->setText(QApplication::translate("MainWindow", "John Doe", 0));
        label_7->setText(QApplication::translate("MainWindow", "5.", 0));
        Score2->setText(QApplication::translate("MainWindow", "1", 0));
        Score3->setText(QApplication::translate("MainWindow", "1", 0));
        Score1->setText(QApplication::translate("MainWindow", "1", 0));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p>HIGH SCORES</p><p><br/></p></body></html>", 0));
        label_5->setText(QApplication::translate("MainWindow", "3.", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
