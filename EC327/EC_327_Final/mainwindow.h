#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

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
    void on_Play_Button_clicked();

    void on_High_Score_Button_clicked();

    void on_Rules_Button_clicked();

    void on_Rule_Back_Button_clicked();

    void on_Back_Score_Button_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
