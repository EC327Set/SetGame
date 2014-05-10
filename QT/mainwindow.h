#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "Game.h"
#include <QBasicTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    QBasicTimer timer_player;
    QBasicTimer timer_computer;
    const int time_p = 6000;
    const int time_c = 200;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Play_Button_clicked();

    void on_High_Score_Button_clicked();

    void on_Rules_Button_clicked();

    void on_Rule_Back_Button_clicked();

    void on_Back_Score_Button_clicked();

    void on_setButton_clicked();

    void on_card1_clicked(bool checked);

    void on_card2_clicked(bool checked);

    void on_card3_clicked(bool checked);

    void on_card4_clicked(bool checked);

    void on_card5_clicked(bool checked);

    void on_card6_clicked(bool checked);

    void on_card7_clicked(bool checked);

    void on_card8_clicked(bool checked);

    void on_card9_clicked(bool checked);

    void on_card10_clicked(bool checked);

    void on_card11_clicked(bool checked);

    void on_card12_clicked(bool checked);

    void on_Back_Button_Main_clicked();

private:
    Ui::MainWindow *ui;
    Game* game;
    void checkSet();
    void resetClicked();
    void resetDisable();
    void testCards();
    void endgame();
    void check_board_shuffle();
protected:
    void timerEvent(QTimerEvent *event);
};

#endif // MAINWINDOW_H
