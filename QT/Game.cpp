//
//  Game.cpp
//  Set
//
//  Created by Christine Duong
//  Copyright (c) 2014 Christine Duong. All rights reserved.
//

#include "Game.h"
#include <vector>
#include <fstream>
#include <QTimer>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <fstream>
#include <string>
#define IO_ReadOnly QIODevice::ReadOnly

Game::Game() {
    Board board;
    Player player;
    Player ai;
    num_active=0;
}
void Game::restart_game()
{
    board = Board();
    ai = Player();
    player = Player();
    num_active=0;

}

/*bool Game::gameOver() {
    if (board.deckSize()==0 && !board.isThereASet()) {
        return true;
    }
    else {
        return false;
    }
}*/

bool Game::highScore() {
    ifstream datafile;
    datafile.open("/Users/christineduong/Desktop/Set/high_scores.txt");

    bool onTheList=false;
    vector<string> players;
    vector<int> scores;
    string ignore;
    string readString;
    int readInt;
    for(int i=0;i<5;i++) {
        getline(datafile, readString);
        players.push_back(readString);
       datafile >> readInt;
       scores.push_back(readInt);
        getline(datafile,ignore);
    }
    
    int i=0;
    while(i<5 && !onTheList){
        if (player.get_amount()>=scores[i]) {
            onTheList=true;
            scores.insert(scores.begin()+i,player.get_amount());
            players.insert(players.begin()+i,player.get_name());
        }
        i++;
    }

    ofstream output;
    output.open("/Users/christineduong/Desktop/Set/high_scores.txt");
    for (int j=0;j<5;j++) {
        output << players[j] << endl;
        output << scores[j] << endl;
    }
    
    output.close();
    
    return onTheList;
}

void Game::setActive(int x, int y) {
    if(num_active<3) {
        active[num_active]=&board.board[x][y];
        num_active++;
    }
}

Game::~Game() {
    std::cout<<"Game terminated.";
}

bool Game::findSet(bool test) {
    for (int i=0; i<3; i++) {
        for (int j=0; j<4; j++) { //first card

            for(int k=0; k<3; k++) {
                for (int l=0; l<4; l++) {//second card

                    for (int m=0; m<3; m++) {
                        for (int n=0; n<4; n++) {//third card

                            if (board.board[i][j]!=board.board[k][l] && board.board[k][l]!=board.board[m][n] && board.board[i][j]!=board.board[m][n]) {
                                //if the cards picked are not the same

                                if (board.check_set(board.board[i][j], board.board[k][l], board.board[m][n])) {
                                    if(!test){
                                    ai.increase_amount();

                                    board.draw(&board.board[i][j]);
                                    board.draw(&board.board[k][l]);
                                    board.draw(&board.board[m][n]);
                                    }
                                    return true;
                                }

                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}
