#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

// Constructor
Player::Player(){
	for (int i =0; i<11; i++){
		frames[i] = Frame();
	}
}

// Calculate the score for the player
int Player::calculateScore(){
	int score = 0;

	for (int i=0; i<10; i++){

		if(i<9 && frames[i].isStrike && frames[i+1].isStrike){
			score += 10 + 10 + frames[i+2].scoreThrow1;
		}

		else if(frames[i].isStrike){
			score += 10 + frames[i+1].totalFrameScore();
		}

		else if(frames[i].isSpare){
			score += 10 + frames[i+1].scoreThrow1;
		}
		else{
			score += frames[i].totalFrameScore();
		}
	}

	return score;


}