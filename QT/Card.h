//
//  Card.h
//  Set
//
//  Created by Christine Duong
//  Copyright (c) 2014 Christine Duong. All rights reserved.
//

#ifndef __Set__Card__
#define __Set__Card__

#include <iostream>

class Card {
private:
    int shading;
    int color;
    int shape;
    int number;
public:
    Card();
    Card(int shading, int color, int shape, int number);
    int get_shading();
    int get_color();
    int get_shape();
    int get_number();


};

bool operator!=(Card & c1, Card & c2);

#endif /* defined(__Set__Card__) */
