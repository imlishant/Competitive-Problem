#include "player.h"
#include "round.h"

#include <bits/stdc++.h>
using namespace std;
/*
Player::Player() {
    string name = "";
    Round round[14];
}
*/
// Constructor
Player::Player(){
	for (int i =0; i<6; i++){
		round[i] = Round();
	}
}

int Player::calcScore() {

	int score = 0;

	for (int i=0; i<5; i++){

		if(i<4 && round[i].isStrike && round[i+1].isStrike){
			score += 10 + 10 + round[i+2].throw1;
		} 
        // last round: 
        else if(round[i].isStrike){
			score += 10 + 10 + round[i+1].totalScore();
		} else if(round[i].isSpare){
			score += 10 + 5 + round[i+1].throw2;
		} else{
			score += round[i].totalScore();
		}
	}

	return score;
}
