#ifndef PLAYER_H
#define PLAYER_H

#include "round.h"
#include <bits/stdc++.h>
using namespace std;
/*
0 1 2 .. 9 10 x /
14 size
*/

class Player {

public:
    Player();
    string name;
    Round round[6]; // or 11
    int calcScore();
};

#endif