#ifndef FRAME_H
#define FRAME_H

#include <iostream>

using namespace std;

class Frame {
public:
	Frame();
		int scoreThrow1;
		int scoreThrow2;
		bool isStrike;
		bool isSpare;
		int totalFrameScore();
};


#endif