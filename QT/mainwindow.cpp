#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QString>
#include <QTimer>
#include "Game.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    game = new Game();
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(5000);

    ui->deckSize->setNum(game->board.deckSize());

    ui->Set_Stack->setCurrentIndex(1); //makes sure the game starts on main screen
    QPixmap pic("/Users/christineduong/Desktop/Set/setLogo.png");
    ui->label->setPixmap(pic);

    QPixmap pixmap("/Users/christineduong/Desktop/Set/cards/card2003.png");
    QIcon ButtonIcon(pixmap);

    //this will allow users to unclick a card if they want to
    ui->card1->setCheckable(true);
    ui->card2->setCheckable(true);
    ui->card3->setCheckable(true);
    ui->card4->setCheckable(true);
    ui->card5->setCheckable(true);
    ui->card6->setCheckable(true);
    ui->card7->setCheckable(true);
    ui->card8->setCheckable(true);
    ui->card9->setCheckable(true);
    ui->card10->setCheckable(true);
    ui->card11->setCheckable(true);
    ui->card12->setCheckable(true);
    ui->setButton->setCheckable(true);

    game = new Game();
    //makes a new game object

    /*ui->card1->setIcon(ButtonIcon);
    ui->card2->setIcon(ButtonIcon);
    ui->card3->setIcon(ButtonIcon);
    ui->card4->setIcon(ButtonIcon);
    ui->card5->setIcon(ButtonIcon);
    ui->card6->setIcon(ButtonIcon);
    ui->card7->setIcon(ButtonIcon);
    ui->card8->setIcon(ButtonIcon);
    ui->card9->setIcon(ButtonIcon);
    ui->card10->setIcon(ButtonIcon);
    ui->card11->setIcon(ButtonIcon);
    ui->card12->setIcon(ButtonIcon);

    ui->card1->setIconSize(pixmap.rect().size());
    ui->card2->setIconSize(pixmap.rect().size());
    ui->card3->setIconSize(pixmap.rect().size());
    ui->card4->setIconSize(pixmap.rect().size());
    ui->card5->setIconSize(pixmap.rect().size());
    ui->card6->setIconSize(pixmap.rect().size());
    ui->card7->setIconSize(pixmap.rect().size());
    ui->card8->setIconSize(pixmap.rect().size());
    ui->card9->setIconSize(pixmap.rect().size());
    ui->card10->setIconSize(pixmap.rect().size());
    ui->card11->setIconSize(pixmap.rect().size());
    ui->card12->setIconSize(pixmap.rect().size());
*/
    resetDisable();
    testCards();
    std::cout<<game->board.isThereASet();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Play_Button_clicked()
{
    ui->Set_Stack->setCurrentIndex(0); //Game Screen

}

void MainWindow::on_High_Score_Button_clicked()
{
    ui->Set_Stack->setCurrentIndex(3); //High Scores
}

void MainWindow::on_Rules_Button_clicked()
{
    ui->Set_Stack->setCurrentIndex(2); //Rules
}

void MainWindow::on_Rule_Back_Button_clicked()
{
    ui->Set_Stack->setCurrentIndex(1); //Back To main screen
}

void MainWindow::on_Back_Score_Button_clicked()
{
    ui->Set_Stack->setCurrentIndex(1); //Back to main screen
}


void MainWindow::on_setButton_clicked()
{
    ui->card1->setEnabled(true);
    ui->card2->setEnabled(true);
    ui->card3->setEnabled(true);
    ui->card4->setEnabled(true);
    ui->card5->setEnabled(true);
    ui->card6->setEnabled(true);
    ui->card7->setEnabled(true);
    ui->card8->setEnabled(true);
    ui->card9->setEnabled(true);
    ui->card10->setEnabled(true);
    ui->card11->setEnabled(true);
    ui->card12->setEnabled(true);
    game->player.turn=true;
}

void MainWindow::on_card1_clicked(bool checked)
{

    if(game->num_active<3 && checked){
        game->setActive(0,0);
    }
    else if(!checked && game->num_active<3) {
        game->num_active--;
    }

    //if three cards are picked, check if it's a set
    if(game->num_active==3) {
        checkSet();
    }

}

void MainWindow::on_card2_clicked(bool checked)
{

    if(game->num_active<3 && checked){
        game->setActive(0,1);
    }
    else if(!checked && game->num_active<3) {
        game->num_active--;
    }
    //if three cards are picked, check if it's a set
    if(game->num_active==3) {
        checkSet();
    }
}

void MainWindow::on_card3_clicked(bool checked)
{

    if(game->num_active<3 && checked){
        game->setActive(0,2);
    }
    else if(!checked && game->num_active<3) {
        game->num_active--;
    }
    //if three cards are picked, check if it's a set
    if(game->num_active==3) {
        checkSet();
    }
}

void MainWindow::on_card4_clicked(bool checked)
{
    if(game->num_active<3 && checked){
        game->setActive(0,3);
    }
    else if(!checked && game->num_active<3) {
        game->num_active--;
    }
    //if three cards are picked, check if it's a set
    if(game->num_active==3) {
        checkSet();
    }
}

void MainWindow::on_card5_clicked(bool checked)
{
    if(game->num_active<3 && checked){
        game->setActive(1,0);
    }
    else if(!checked && game->num_active<3) {
        game->num_active--;
    }
    //if three cards are picked, check if it's a set
    if(game->num_active==3) {
        checkSet();
    }
}

void MainWindow::on_card6_clicked(bool checked)
{
    if(game->num_active<3 && checked){
        game->setActive(1,1);
    }
    else if(!checked && game->num_active<3) {
        game->num_active--;
    }
    //if three cards are picked, check if it's a set
    if(game->num_active==3) {
        checkSet();
    }

}

void MainWindow::on_card7_clicked(bool checked)
{
    if(game->num_active<3 && checked){
        game->setActive(1,2);
    }
    else if(!checked && game->num_active<3) {
        game->num_active--;
    }
    //if three cards are picked, check if it's a set
    if(game->num_active==3) {
        checkSet();
    }

}

void MainWindow::on_card8_clicked(bool checked)
{
    if(game->num_active<3 && checked){
        game->setActive(1,3);
    }
    else if(!checked && game->num_active<3) {
        game->num_active--;
    }
    //if three cards are picked, check if it's a set
    if(game->num_active==3) {
        checkSet();
    }
}

void MainWindow::on_card9_clicked(bool checked)
{
    if(game->num_active<3 && checked){
        game->setActive(2,0);
    }
    else if(!checked && game->num_active<3) {
        game->num_active--;
    }
    //if three cards are picked, check if it's a set
    if(game->num_active==3) {
        checkSet();
    }

}

void MainWindow::on_card10_clicked(bool checked)
{
    if(game->num_active<3 && checked){
        game->setActive(2,1);
    }
    else if(!checked && game->num_active<3) {
        game->num_active--;
    }
    //if three cards are picked, check if it's a set
    if(game->num_active==3) {
        checkSet();
    }

}

void MainWindow::on_card11_clicked(bool checked)
{
    if(game->num_active<3 && checked){
        game->setActive(2,2);
    }
    else if(!checked && game->num_active<3) {
        game->num_active--;
    }
    //if three cards are picked, check if it's a set
    if(game->num_active==3) {
        checkSet();
    }

}

void MainWindow::on_card12_clicked(bool checked)
{
    if(game->num_active<3 && checked){
        game->setActive(2,3);
    }
    else if(!checked && game->num_active<3) {
        game->num_active--;
    }
    //if three cards are picked, check if it's a set
    if(game->num_active==3) {
        checkSet();
    }

}

void MainWindow::checkSet() {
    bool set=game->board.check_set(*(game->active[0]), *(game->active[1]),*(game->active[2]));
    if (set) {
        game->player.increase_amount();
        ui->playerScore->setNum(game->player.get_amount());
        game->board.draw(game->active[0]);
        game->board.draw(game->active[1]);
        game->board.draw(game->active[2]);
        ui->deckSize->setNum(game->board.deckSize());
        resetClicked();
    }
    else {
        QMessageBox::information(this,tr("Message"),tr("This is not a set."));
        resetClicked();
    }
    game->num_active=0;
    testCards();
    resetDisable();
}

void MainWindow::resetClicked() {
    ui->card1->setChecked(false);
    ui->card2->setChecked(false);
    ui->card3->setChecked(false);
    ui->card4->setChecked(false);
    ui->card5->setChecked(false);
    ui->card6->setChecked(false);
    ui->card7->setChecked(false);
    ui->card8->setChecked(false);
    ui->card9->setChecked(false);
    ui->card10->setChecked(false);
    ui->card11->setChecked(false);
    ui->card12->setChecked(false);
}

void MainWindow::resetDisable() {
    ui->card1->setEnabled(false);
    ui->card2->setEnabled(false);
    ui->card3->setEnabled(false);
    ui->card4->setEnabled(false);
    ui->card5->setEnabled(false);
    ui->card6->setEnabled(false);
    ui->card7->setEnabled(false);
    ui->card8->setEnabled(false);
    ui->card9->setEnabled(false);
    ui->card10->setEnabled(false);
    ui->card11->setEnabled(false);
    ui->card12->setEnabled(false);
}

void MainWindow::testCards() {//for testing before images
    QString message=QString::number(game->board.board[0][0].get_shading())+QString::number(game->board.board[0][0].get_color())+QString::number(game->board.board[0][0].get_shape())+QString::number(game->board.board[0][0].get_number());
    ui->card1->setText(message);

    QString message2=QString::number(game->board.board[0][1].get_shading())+QString::number(game->board.board[0][1].get_color())+QString::number(game->board.board[0][1].get_shape())+QString::number(game->board.board[0][1].get_number());
    ui->card2->setText(message2);

    QString message3=QString::number(game->board.board[0][2].get_shading())+QString::number(game->board.board[0][2].get_color())+QString::number(game->board.board[0][2].get_shape())+QString::number(game->board.board[0][2].get_number());
    ui->card3->setText(message3);

    QString message4=QString::number(game->board.board[0][3].get_shading())+QString::number(game->board.board[0][3].get_color())+QString::number(game->board.board[0][3].get_shape())+QString::number(game->board.board[0][3].get_number());
    ui->card4->setText(message4);

    QString message5=QString::number(game->board.board[1][0].get_shading())+QString::number(game->board.board[1][0].get_color())+QString::number(game->board.board[1][0].get_shape())+QString::number(game->board.board[1][0].get_number());
    ui->card5->setText(message5);

    QString message6=QString::number(game->board.board[1][1].get_shading())+QString::number(game->board.board[1][1].get_color())+QString::number(game->board.board[1][1].get_shape())+QString::number(game->board.board[1][1].get_number());
    ui->card6->setText(message6);

    QString message7=QString::number(game->board.board[1][2].get_shading())+QString::number(game->board.board[1][2].get_color())+QString::number(game->board.board[1][2].get_shape())+QString::number(game->board.board[1][2].get_number());
    ui->card7->setText(message7);

    QString message8=QString::number(game->board.board[1][3].get_shading())+QString::number(game->board.board[1][3].get_color())+QString::number(game->board.board[1][3].get_shape())+QString::number(game->board.board[1][3].get_number());
    ui->card8->setText(message8);

    QString message9=QString::number(game->board.board[2][0].get_shading())+QString::number(game->board.board[2][0].get_color())+QString::number(game->board.board[2][0].get_shape())+QString::number(game->board.board[2][0].get_number());
    ui->card9->setText(message9);

    QString message10=QString::number(game->board.board[2][1].get_shading())+QString::number(game->board.board[2][1].get_color())+QString::number(game->board.board[2][1].get_shape())+QString::number(game->board.board[2][1].get_number());
    ui->card10->setText(message10);

    QString message11=QString::number(game->board.board[2][2].get_shading())+QString::number(game->board.board[2][2].get_color())+QString::number(game->board.board[2][2].get_shape())+QString::number(game->board.board[2][2].get_number());
    ui->card11->setText(message11);

    QString message12=QString::number(game->board.board[2][3].get_shading())+QString::number(game->board.board[2][3].get_color())+QString::number(game->board.board[2][3].get_shape())+QString::number(game->board.board[2][3].get_number());
    ui->card12->setText(message12);
}
