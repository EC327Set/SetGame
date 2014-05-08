//
//  Game.h
//  Set
//
//  Created by Christine Duong
//  Copyright (c) 2014 Christine Duong. All rights reserved.
//

#ifndef __Set__Game__
#define __Set__Game__

#include <iostream>
#include "Board.h"
#include "Player.h"

class Game{
private:
    Player ai;
public:
    Game();
    ~Game();
    Player player;
    Card* active[3];
    Board board;
    bool gameOver();
    bool highScore();
    void setActive(int x, int y);
    int num_active;
    void findSet();
    
};
#endif /* defined(__Set__Game__) */
