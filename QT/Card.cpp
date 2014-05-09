//
//  Card.cpp
//  Set
//
//  Created by Christine Duong
//  Copyright (c) 2014 Christine Duong. All rights reserved.
//

#include "Card.h"
using namespace std;

Card::Card() {
    shading=-1;
    color=-1;
    shape=-1;
    number=-1;
}

Card::Card(int in_shading, int in_color, int in_shape, int in_number) {
    /*
     Shading: 0 is empty, 1 is shaded, 2 is filled in
     Color: 0 is red, 1 is green, 2 is purple
     Shape: 0 is diamond, 1 is oval, 2 is squiggly
     */
    shading = in_shading;
    color = in_color;
    shape = in_shape;
    number = in_number;
}

int Card::get_color() {
    return color;
}

int Card::get_shading() {
    return shading;
}

int Card::get_shape() {
    return shape;
}

int Card::get_number() {
    return number;
}

bool operator!=(Card & c1, Card & c2){
    if((c1.get_color() == -1) ||( c2.get_color() == -1))
        return false;
    bool sameColor = (c1.get_color()==c2.get_color());
    bool sameShading = (c1.get_shading() == c2.get_shading());
    bool sameShape = (c1.get_shape() == c2.get_shape());
    bool sameNumber = (c1.get_number() == c2.get_number());
    
    return !(sameColor && sameShading && sameShape && sameNumber);
    
}


