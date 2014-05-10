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
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <fstream>
#define IO_ReadOnly QIODevice::ReadOnly
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    game = new Game();

    ui->deckSize->setNum(game->board.deckSize());

    ui->Set_Stack->setCurrentIndex(1); //makes sure the game starts on main screen
    QPixmap pic("/Users/christineduong/Desktop/Set/setLogo.png");
    ui->label->setPixmap(pic);



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
    showCards();

<<<<<<< HEAD
    ui->card1->setIcon(ButtonIcon);
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

=======
>>>>>>> FETCH_HEAD
    resetDisable();

}
void MainWindow::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timer_player.timerId())
    {
        timer_player.stop();
        resetClicked();
        resetDisable();
    }
    if (event->timerId() == timer_computer.timerId())
    {
        if(!(timer_player.isActive()))
        {
        game->findSet(false);
        check_board_shuffle();
        showCards();
        ui->aiScore->setNum(game->ai.get_amount());
        ui->deckSize->setNum(game->board.deckSize());
        }

    }

}
void MainWindow::check_board_shuffle()
{
    int counter = 0;
    while(true)
    {
        if(counter > 6)
            return;
        if((game->findSet(true)))
        {
            if(counter!= 0){
                timer_computer.stop();
                QMessageBox::information(this,tr("Message"),tr("No Sets Found \n Board Reshuffled"));
                timer_computer.start(time_c, this);
            }
            return;
        }
        else
        {
            counter++;
            if(game->board.pop_back_check()){
                game->board.replot_board();
            }
            else
            {
                game->board.replot_board();
                ui->deckSize->setNum(game->board.deckSize());
                timer_computer.stop();
                endgame();
                return;
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Play_Button_clicked()
{
    ui->Set_Stack->setCurrentIndex(0); //Game Screen
    timer_computer.start(time_c, this);

}

void MainWindow::on_High_Score_Button_clicked()
{
     //High Scores
    QFile file("C:\\Users\\Anish\\Documents\\GitHub\\SetGame\\QT\\high_scores.txt"); // Create a file handle for the file named
    QString line;
    if (!file.open(IO_ReadOnly)) // Open the file
    {
       //ui->textEdit->append("High Score File Not Found.\nError 401");
       //ui->textEdit->append("Please contact: asthana@bu.edu");
    }
    QTextStream stream( &file ); // Set the stream to read from myFile

    while(!stream.atEnd()){

    line = stream.readLine(); // this reads a line (QString) from the file
    ui->Name1->setText(line);
    line = stream.readLine();
    ui->Score1->setText(line);
    line = stream.readLine();
    ui->Name2->setText(line);
    line = stream.readLine();
    ui->Score2->setText(line);
    line = stream.readLine();
    ui->Name3->setText(line);
    line = stream.readLine();
    ui->Score3->setText(line);
    line = stream.readLine();
    ui->Name4->setText(line);
    line = stream.readLine();
    ui->Score4->setText(line);
    line = stream.readLine();
    ui->Name5->setText(line);
    line = stream.readLine();
    ui->Score5->setText(line);
    }
    file.close();
    ui->Set_Stack->setCurrentIndex(3);
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
    timer_player.start(time_p, this);
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
        timer_computer.stop();
        QMessageBox::information(this,tr("Message"),tr("This is not a set."));
        timer_computer.start(time_c, this);
        resetClicked();
    }
    game->num_active=0;
    showCards();
    resetDisable();
    check_board_shuffle();
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

void MainWindow::showCards() {
    QString address="C:\\Users\\Anish\\Documents\\GitHub\\SetGame\\Base\\assets\\40percent\\card";

    QString message=address+QString::number(game->board.board[0][0].get_shading())+QString::number(game->board.board[0][0].get_color())+QString::number(game->board.board[0][0].get_shape())+QString::number(game->board.board[0][0].get_number());
    QPixmap pixmap(message);
    QIcon cardOne(pixmap);
    ui->card1->setIcon(cardOne);

    QString message2=address+QString::number(game->board.board[0][1].get_shading())+QString::number(game->board.board[0][1].get_color())+QString::number(game->board.board[0][1].get_shape())+QString::number(game->board.board[0][1].get_number());
    QPixmap pixmap2(message2);
    QIcon cardTwo(pixmap2);
    ui->card2->setIcon(cardTwo);

    QString message3=address+QString::number(game->board.board[0][2].get_shading())+QString::number(game->board.board[0][2].get_color())+QString::number(game->board.board[0][2].get_shape())+QString::number(game->board.board[0][2].get_number());
    QPixmap pixmap3(message3);
    QIcon cardThree(pixmap3);
    ui->card3->setIcon(cardThree);

    QString message4=address+QString::number(game->board.board[0][3].get_shading())+QString::number(game->board.board[0][3].get_color())+QString::number(game->board.board[0][3].get_shape())+QString::number(game->board.board[0][3].get_number());
    QPixmap pixmap4(message4);
    QIcon cardFour(pixmap4);
    ui->card4->setIcon(cardFour);

    QString message5=address+QString::number(game->board.board[1][0].get_shading())+QString::number(game->board.board[1][0].get_color())+QString::number(game->board.board[1][0].get_shape())+QString::number(game->board.board[1][0].get_number());
    QPixmap pixmap5(message5);
    QIcon cardFive(pixmap5);
    ui->card5->setIcon(cardFive);

    QString message6=address+QString::number(game->board.board[1][1].get_shading())+QString::number(game->board.board[1][1].get_color())+QString::number(game->board.board[1][1].get_shape())+QString::number(game->board.board[1][1].get_number());
    QPixmap pixmap6(message6);
    QIcon cardSix(pixmap6);
    ui->card6->setIcon(cardSix);

    QString message7=address+QString::number(game->board.board[1][2].get_shading())+QString::number(game->board.board[1][2].get_color())+QString::number(game->board.board[1][2].get_shape())+QString::number(game->board.board[1][2].get_number());
    QPixmap pixmap7(message7);
    QIcon cardSeven(pixmap7);
    ui->card7->setIcon(cardSeven);

    QString message8=address+QString::number(game->board.board[1][3].get_shading())+QString::number(game->board.board[1][3].get_color())+QString::number(game->board.board[1][3].get_shape())+QString::number(game->board.board[1][3].get_number());
    QPixmap pixmap8(message8);
    QIcon cardEight(pixmap8);
    ui->card8->setIcon(cardEight);

    QString message9=address+QString::number(game->board.board[2][0].get_shading())+QString::number(game->board.board[2][0].get_color())+QString::number(game->board.board[2][0].get_shape())+QString::number(game->board.board[2][0].get_number());
    QPixmap pixmap9(message9);
    QIcon cardNine(pixmap9);
    ui->card9->setIcon(cardNine);

    QString message10=address+QString::number(game->board.board[2][1].get_shading())+QString::number(game->board.board[2][1].get_color())+QString::number(game->board.board[2][1].get_shape())+QString::number(game->board.board[2][1].get_number());
    QPixmap pixmap10(message10);
    QIcon cardTen(pixmap10);
    ui->card10->setIcon(cardTen);

    QString message11=address+QString::number(game->board.board[2][2].get_shading())+QString::number(game->board.board[2][2].get_color())+QString::number(game->board.board[2][2].get_shape())+QString::number(game->board.board[2][2].get_number());
    QPixmap pixmap11(message11);
    QIcon cardEleven(pixmap11);
    ui->card11->setIcon(cardEleven);

    QString message12=address+QString::number(game->board.board[2][3].get_shading())+QString::number(game->board.board[2][3].get_color())+QString::number(game->board.board[2][3].get_shape())+QString::number(game->board.board[2][3].get_number());
    QPixmap pixmap12(message12);
    QIcon cardTwelve(pixmap12);
    ui->card12->setIcon(cardTwelve);


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

}

void MainWindow::endgame()
{
timer_computer.stop();
timer_player.stop();
if(game->player.get_amount() > game->ai.get_amount())
QMessageBox::information(this,tr("Message"),tr("Player Wins!"));
else if(game->player.get_amount() < game->ai.get_amount())
QMessageBox::information(this,tr("Message"),tr("Computer Wins!"));
else
QMessageBox::information(this,tr("Message"),tr("Tie"));
if(game->highScore())
QMessageBox::information(this,tr("Message"),tr("High Score!!"));
}

void MainWindow::on_Back_Button_Main_clicked()
{
    ui->Set_Stack->setCurrentIndex(1);
    timer_computer.stop();
}
