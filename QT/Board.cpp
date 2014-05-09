//
//  Board.cpp
//  Set
//
//  Created by Christine Duong
//  Copyright (c) 2014 Christine Duong. All rights reserved.
//
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Board.h"
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "Card.h"


Board::Board() {
    for(int i=0; i<3;i++) { //Makes the deck
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++){
                for (int l=1; l<=3; l++) {
                    deck.push_back(Card(i, j, k, l));
                }
            }
        }
    }
    
    std::srand(time(0)); //this seeds srand so we get different rand results
    random_shuffle(deck.begin(), deck.end()); // shuffles the deck
    
    width=3;
    length=4;
    for (int i=0;i<3; i++) {
        for (int j=0; j<4; j++) {
            board[i][j] = deck.back();
            deck.pop_back();
        }
    }
}

/*void Board::draw(int x, int y) { // draws a card into position x,y on the board
    if (deck.size()!=0) {
        board[x][y] = deck.back();
        deck.pop_back();
    }
}*/

void Board::draw(Card *position){
    if(deck.size()!=0) {
        *position=deck.back();
        deck.pop_back();;
    }
    else {
        *position=Card();
    }
}

bool Board::check_set(Card one, Card two, Card three) { //checks to see if three cards make a set
    
    if(one.get_color() == -1 || two.get_color() == -1 || three.get_color() == -1)
        return false;
    bool sameColor = one.get_color()==two.get_color() && two.get_color()==three.get_color();
    bool diffColor = one.get_color()!=two.get_color() && two.get_color()!=three.get_color() && one.get_color()!=three.get_color();
    bool sameNumber = one.get_number()==two.get_number() && two.get_number()==three.get_number();
    bool diffNumber = one.get_number()!=two.get_number() && one.get_number()!=three.get_number() && two.get_number()!=three.get_number();
    bool sameShape = one.get_shape()==two.get_shape() && two.get_shape()==three.get_shape();
    bool diffShape = one.get_shape()!=two.get_shape() && two.get_shape()!=three.get_shape() && one.get_shape() !=three.get_shape();
    bool sameShade = one.get_shading()==two.get_shading() && two.get_shading()==three.get_shading();
    bool diffShade = one.get_shading()!=two.get_shading() && two.get_shading()!=three.get_shading() && one.get_shading()!=three.get_shading();
    
    return (sameColor || diffColor) && (sameNumber || diffNumber) && (sameShade || diffShade) && (sameShape || diffShape);
    
}

bool Board::isThereASet() { //iterates through the board
    for (int i=0; i<length; i++) {
        for (int j=0; j<width; j++) { //first card
            
            for(int k=0; k<length; k++) {
                for (int l=0; l<width; l++) {//second card
                    
                    for (int m=0; m<length; m++) {
                        for (int n=0; n<width; n++) {//third card
                            
                            if (board[i][j]!=board[k][l] && board[k][l]!=board[m][n] && board[i][j]!=board[m][n]) {
                                //if the cards picked are not the same
                                if (check_set(board[i][j], board[k][l], board[m][n])) {
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
bool Board::pop_back_check()
{
    for (int i = 0; i < 3 ; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            deck.push_back(board[i][j]);
        }
    }
    return (check_deck());
}
void Board::replot_board()
{
    std::srand(time(0)); //this seeds srand so we get different rand results
    random_shuffle(deck.begin(), deck.end()); // shuffles the deck

    for (int i=0;i<3; i++) {
        for (int j=0; j<4; j++) {
            board[i][j] = deck.back();
            deck.pop_back();
        }
    }
}

bool Board::check_deck()
{
    for(unsigned int i=0; i < deck.size(); i++){
        for(unsigned int j=0; j < deck.size(); j++){
            for(unsigned int k=0; k < deck.size(); k++){
               if((i != j) && (j != k))
               {
                   if (check_set(deck[i], deck[j], deck[k]))
                   {
                       return true;
                   }
               }
            }
        }
    }
    return false;
}

int Board::deckSize() {
    return deck.size();
}




