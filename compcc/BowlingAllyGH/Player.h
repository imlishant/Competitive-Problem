#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include "Frame.h"

using namespace std;

// Class Player
class Player {
public:
	Player();
	string name;
	Frame frames[11];
	int calculateScore();
};


#endif