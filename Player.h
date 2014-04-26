#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
	string name; 
	int amount_sets;

public:
	Player();
	Player(string name);

	int get_amount();
	void increase_amount(int amount = 1);
};
#endif