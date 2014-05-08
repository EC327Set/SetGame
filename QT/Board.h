//
//  Board.h
//  Set
//
//  Created by Christine Duong
//  Copyright (c) 2014 Christine Duong. All rights reserved.
//

#ifndef __Set__Board__
#define __Set__Board__

#include <iostream>
#include <vector>
#include "Card.h"

using namespace std;

class Board{
private:
    vector<Card> deck;
    int width;
    int length;
public:
    Board();
    Card board[3][4];
    bool check_set(Card one, Card two, Card three);
    bool check_board();
    //void draw(int x, int y);
    void draw(Card * position);
    bool isThereASet();
    int deckSize();
};


#endif /* defined(__Set__Board__) */
