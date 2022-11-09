#include <iostream>
#include "Frame.h"
#include "Player.h"
#include <string>
#include <iomanip>

using namespace std;

int main(){
const int nameWidth = 6;

int numPlayers;
cout << "-------------------------------- Welcome to Shabad's Bowling Alley --------------------------------" << endl;
// Input number of players
cout << "How many players would like to play: ";
cin >> numPlayers;

// Declaring/Initializing an array of Players
Player players[numPlayers];
for(int i=0; i<numPlayers; i++){
	players[i] = Player();
}

// Setting Player names
for(int i=0; i<numPlayers; i++){
	string playerName;
	cout << "Name of player " << i+1 << ": ";
	cin >> playerName;
	players[i].name = playerName;
}


// Taking the input for the ball throws on each turn for each player
// We put the input on the frames for each player

int numPins1;
int numPins2;
int fillBall1;
int fillBall2;
for (int i=0; i<10; i++){
	for (int player = 0; player < numPlayers; player++){
		cout << "How many pins did player " << players[player].name << " get in " << "frame " << i+1 << " on turn 1 " << ": "  ;
		cin >> numPins1;
		players[player].frames[i].scoreThrow1 = numPins1;
		if(numPins1 == 10){
			cout << "STRIKE!!!" << endl;
			players[player].frames[i].isStrike = true;

			if(i == 9){
				cout << "How many pins did player " << players[player].name << " get in " << "frame " << i+1 << " on fill Ball 1 " << ": "  ;
				cin >> fillBall1;
				players[player].frames[10].scoreThrow1 = fillBall1;
				cout << "How many pins did player " << players[player].name << " get in " << "frame " << i+1 << " on fill Ball 2 " << ": "  ;
			 	cin >> fillBall2;
				players[player].frames[10].scoreThrow2 = fillBall2;
			}
		}



		if(numPins1 != 10){
		cout << "How many pins did player " << players[player].name << " get in " << "frame " << i+1 << " on turn 2 " << ": "  ;
		cin >> numPins2;
		if(numPins1+numPins2>10){
			cout << "Error: Total Pins knocked cannot be greater than 10" << endl;
			exit(1);
		}
		players[player].frames[i].scoreThrow2 = numPins2;
		if(numPins1 + numPins2 == 10 && numPins1!=10){
			cout << "SPARE!!" << endl;
			players[player].frames[i].isSpare = true;
			players[player].frames[i].isStrike = false;

			if(i==9){
				cout << "How many pins did player " << players[player].name << " get in " << "frame " << i+1 << " on fill Ball 1 " << ": "  ;
				cin >> fillBall1;
				players[player].frames[10].scoreThrow1 = fillBall1;

			}
		}
		}
		else{
			players[player].frames[i].scoreThrow2 = 0;	
		}
	}
}

cout << "" << endl;

//////////////// PRINTTNG THE SCORE BOARD HERE //////////////

cout << "Players   | Frame 1 | Frame 2 | Frame 3  |  Frame 4  | Frame 5  |  Frame 6 |  Frame 7  | Frame 8  | Frame 9  | Frame 10 |" << endl;
cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;



for (int player = 0; player < numPlayers; player++){
	cout << left << setw(nameWidth)<< players[player].name << "      ";
	for (int i=0; i<10; i++){
		if(players[player].frames[i].isStrike == true){
			if(i==9){
				cout << "  X  " << " "<< players[player].frames[10].scoreThrow1 <<" "<< players[player].frames[10].scoreThrow2;

			}
			else{cout << "  X  " << "      ";}
		}
		else if(players[player].frames[i].isSpare == true){
			if(i==9){
				cout << players[player].frames[i].scoreThrow1 << " - " << "/" << "  " << players[player].frames[10].scoreThrow1;
			}
			else{
			cout << players[player].frames[i].scoreThrow1 << " - " << "/" << "      ";
			}
		}
		else{
		cout << players[player].frames[i].scoreThrow1 << " - " << players[player].frames[i].scoreThrow2 << "      ";
		
	}
	}
	cout << "" << endl;

}

/////////////// PRINT SOCRE BAORD ENDS HERE /////////////////

cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;

///////////// CALCULATE SCORE STARTS HERE //////////////////
cout << "Scoreboard:" << endl;

int highestScore = 0;
string winner;
for(int player = 0; player < numPlayers; player++){
	cout << players[player].name  << ": " << players[player].calculateScore() << endl;

	if(players[player].calculateScore() > highestScore){
		highestScore = players[player].calculateScore();
		winner = players[player].name;
	}

}

cout << "The winner is " << winner << "!!!" << endl;

//////////// CALCULATE SOCRE ENDS HERE /////////////////////

	return 0;


}