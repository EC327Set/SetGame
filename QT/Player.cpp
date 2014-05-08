#include <iostream>
#include <cmath>
#include "Player.h"
#include <string>
using namespace std;

Player::Player()
{
	name = "Player";
	amount_sets = 0;
}

Player::Player(string name)
{
	name = "Player";
	amount_sets = 0;
    turn=false;
}
int Player::get_amount()
{
	return amount_sets;
}
void Player::increase_amount(int amount)
{
	amount_sets += amount;
}
string Player::get_name() {
    return name;
}