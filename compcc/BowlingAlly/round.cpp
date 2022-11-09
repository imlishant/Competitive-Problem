#include "round.h"

#include <bits/stdc++.h>
using namespace std;

Round::Round() {
    int throw1 = 0;
    int throw2 = 0;
    bool isStrike = false;
    bool isSpare = false;
}

int Round::totalScore() {
    return throw1+throw2;
}