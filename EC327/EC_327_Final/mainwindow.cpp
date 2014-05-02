#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Play_Button_clicked()
{
    ui->Set_Stack->setCurrentIndex(0);
}

void MainWindow::on_High_Score_Button_clicked()
{
    ui->Set_Stack->setCurrentIndex(3);
}

void MainWindow::on_Rules_Button_clicked()
{
    ui->Set_Stack->setCurrentIndex(2);
}

void MainWindow::on_Rule_Back_Button_clicked()
{
    ui->Set_Stack->setCurrentIndex(1);
}

void MainWindow::on_Back_Score_Button_clicked()
{
    ui->Set_Stack->setCurrentIndex(1);
}
