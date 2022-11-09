#ifndef ROUND_H
#define ROUND_H

#include <bits/stdc++.h>
using namespace std;

class Round {


public:
    Round();
    int throw1;
    int throw2;
    bool isStrike;
    bool isSpare;
    int totalScore();
};

#endif