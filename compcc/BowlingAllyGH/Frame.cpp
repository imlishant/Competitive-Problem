#include "Frame.h"

// Constructor for Frame
Frame::Frame(){
	scoreThrow1 = 0;
	scoreThrow2 = 0;
	isStrike = false;
	isSpare = false;
}

// Calculates the Frame score, ie. (scoreThrow1 + scoreThrow2)
int Frame::totalFrameScore(){
	return scoreThrow1 + scoreThrow2;
}