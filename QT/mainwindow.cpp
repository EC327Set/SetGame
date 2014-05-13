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
#include <QInputDialog>
#define IO_ReadOnly QIODevice::ReadOnly
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //makes a new game object
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

    showCards();
    resetDisable();

}
void MainWindow::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timer_player.timerId()) //if player has run out of time to pick a set
    {
        timer_player.stop();
        resetClicked();
        resetDisable();
        game->player.wrongSets++;
        game->num_active=0;
    }
    if (event->timerId() == timer_computer.timerId())//Computer makes a move
    {
        if(!(timer_player.isActive()))
        {
        game->findSet(false);
        game->player.wrongSets=0;
        check_board_shuffle();
        showCards();
        ui->aiScore->setNum(game->ai.get_amount());
        ui->deckSize->setNum(game->board.deckSize());

        }

    }

}
void MainWindow::check_board_shuffle() //makes sure a set is on the board
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
                QMessageBox::information(this,tr("Message"),tr("No Sets Found \nBoard Reshuffled"));
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
    QString text = QInputDialog::getText(this, tr(""),
                                              tr("Enter Name:"), QLineEdit::Normal);
         if (!text.isEmpty())
         {
             ui->playerName->setText(text);
             game->player.set_name(text.toStdString());
         }
    timer_computer.start(time_c, this);


}

void MainWindow::on_High_Score_Button_clicked()
{
     //High Scores
    QFile file("/Users/christineduong/Desktop/Set/high_scores.txt"); // Create a file handle for the file named
    QString line;

    file.open(IO_ReadOnly);
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
    QPixmap shape("/Users/christineduong/Desktop/Set/pictures_for_rules/shapes.png");
    ui->shapeEx->setPixmap(shape);
    QPixmap shading("/Users/christineduong/Desktop/Set/pictures_for_rules/shading.png");
    ui->shadingEx->setPixmap(shading);
    QPixmap colors("/Users/christineduong/Desktop/Set/pictures_for_rules/colors.png");
    ui->colorEx->setPixmap(colors);
    QPixmap numbers("/Users/christineduong/Desktop/Set/pictures_for_rules/numbers.png");
    ui->numberEx->setPixmap(numbers);
    QPixmap ex1("/Users/christineduong/Desktop/Set/pictures_for_rules/example1.png");
    ui->set->setPixmap(ex1);
    QPixmap ex2("/Users/christineduong/Desktop/Set/pictures_for_rules/example2.png");
    ui->set1->setPixmap(ex2);
    QPixmap ex3("/Users/christineduong/Desktop/Set/pictures_for_rules/example3.png");
    ui->set2->setPixmap(ex3);
    QPixmap boardPic("/Users/christineduong/Desktop/Set/pictures_for_rules/board.png");
    ui->boardEx->setPixmap(boardPic);
    ui->Set_Stack->setCurrentIndex(2); //Rules
}

void MainWindow::on_Rule_Back_Button_clicked()
{
    ui->Set_Stack->setCurrentIndex(1);
    //Back To main screen
}

void MainWindow::on_Back_Score_Button_clicked()
{
    ui->Set_Stack->setCurrentIndex(1); //Back to main screen
}


void MainWindow::on_setButton_clicked()
{
    if(game->player.wrongSets<3) {
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
        ui->setButton->setEnabled(false);
        timer_player.start(time_p,this );
    }
    else {
         QMessageBox::information(this,tr("Message"),tr("Don't blindly guess! \nYou're restricted from picking \nsets until the computer goes."));
    }
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
        game->player.wrongSets=0;
    }
    else {
        timer_computer.stop();
        QMessageBox::information(this,tr("Message"),tr("This is not a set."));
        timer_computer.start(time_c, this);
        resetClicked();
        game->player.wrongSets++;
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
    ui->setButton->setEnabled(true);
}


void MainWindow::showCards() {
    QString address="/Users/christineduong/Desktop/Set/40percent/card";

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
QMessageBox::information(this,tr("Message"),tr("Game Over \nYou Win!"));
else if(game->player.get_amount() < game->ai.get_amount())
QMessageBox::information(this,tr("Message"),tr("Game Over \nComputer Wins!"));
else
QMessageBox::information(this,tr("Message"),tr("Tie"));
if(game->highScore())
QMessageBox::information(this,tr("Message"),tr("High Score!!"));
end_game();
}

void MainWindow::on_Back_Button_Main_clicked()
{
    ui->Set_Stack->setCurrentIndex(4);
    timer_computer.stop();
}

void MainWindow::on_unpausebutton_clicked()
{
    ui->Set_Stack->setCurrentIndex(0);
    timer_computer.start(time_c,this );
}

void MainWindow::on_Quit_Button_clicked()
{
    end_game();
}
void MainWindow::end_game()
{
    game->restart_game();
    ui->aiScore->setNum(0);
    ui->deckSize->setNum(game->board.deckSize());
    ui->playerScore->setNum(0);
    timer_computer.stop();
    timer_player.stop();
    ui->playerName->setText("Player 1");
    resetDisable();
    ui->Set_Stack->setCurrentIndex(1);
}


