/*
every round:
throw1 
throw2
socore = throw1 + throw2 + bounus;

attempts:
10
9+2 =11 max?
5+2 = 7 min 
12 score point array 
for 5 rounds.
*/

#include <bits/stdc++.h>
#include "player.h"
#include "round.h"

using namespace std;


int main() {

    int numPlayers;
    cin >> numPlayers;
    Player player[numPlayers];

Player players[numPlayers];
for(int i=0; i<numPlayers; i++){
	players[i] = Player();
}

for(int i=0; i<numPlayers; i++){
	string playerName;
	cin >> playerName;
	players[i].name = playerName;
}


int numPins1;
int numPins2;
int fillBall1;
int fillBall2;

// 5 rounds palyed
// +2 balls he will get when string or spare?
// howw?

for (int i=0; i < 5; i++){
	for (int player = 0; player < numPlayers; player++){
		cin >> numPins1;
		players[player].round[i].throw1 = numPins1;
		if(numPins1 == 10){
			players[player].round[i].isStrike = true;

		}


		// last round, extra ball for every one but value is non-zero for strike/spare.
			if(i == 4){
				cin >> fillBall1;
				players[player].round[5].throw1 = fillBall1;
			 	cin >> fillBall2;
				players[player].round[5].throw2 = fillBall2;
			}

		if(numPins1 != 10){
		cin >> numPins2;
		if(numPins1+numPins2>10){
			exit(1);
		}
		players[player].round[i].throw2 = numPins2;
		if(numPins1 + numPins2 == 10 && numPins1!=10){
			players[player].round[i].isSpare = true;
			players[player].round[i].isStrike = false;

		}
		}
		else{
			players[player].round[i].throw2 = 0;	
		}
	}
}

// winner kaise?
// each player ka socre?
// then we sort? according indivi score?
// map use kr?


int highestScore = 0;
string winner;
for(int player = 0; player < numPlayers; player++){
	cout << players[player].name  << ": " << players[player].calcScore() << endl;

	if(players[player].calcScore() > highestScore){
		highestScore = players[player].calcScore();
		winner = players[player].name;
	}

}

    return 0;
}


/*
with traces. output... debug.

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
// We put the input on the round for each player

int numPins1;
int numPins2;
int fillBall1;
int fillBall2;
for (int i=0; i<10; i++){
	for (int player = 0; player < numPlayers; player++){
		cout << "How many pins did player " << players[player].name << " get in " << "frame " << i+1 << " on turn 1 " << ": "  ;
		cin >> numPins1;
		players[player].round[i].throw1 = numPins1;
		if(numPins1 == 10){
			cout << "STRIKE!!!" << endl;
			players[player].round[i].isStrike = true;

			if(i == 9){
				cout << "How many pins did player " << players[player].name << " get in " << "frame " << i+1 << " on fill Ball 1 " << ": "  ;
				cin >> fillBall1;
				players[player].round[10].throw1 = fillBall1;
				cout << "How many pins did player " << players[player].name << " get in " << "frame " << i+1 << " on fill Ball 2 " << ": "  ;
			 	cin >> fillBall2;
				players[player].round[10].throw2 = fillBall2;
			}
		}



		if(numPins1 != 10){
		cout << "How many pins did player " << players[player].name << " get in " << "frame " << i+1 << " on turn 2 " << ": "  ;
		cin >> numPins2;
		if(numPins1+numPins2>10){
			cout << "Error: Total Pins knocked cannot be greater than 10" << endl;
			exit(1);
		}
		players[player].round[i].throw2 = numPins2;
		if(numPins1 + numPins2 == 10 && numPins1!=10){
			cout << "SPARE!!" << endl;
			players[player].round[i].isSpare = true;
			players[player].round[i].isStrike = false;

			if(i==9){
				cout << "How many pins did player " << players[player].name << " get in " << "frame " << i+1 << " on fill Ball 1 " << ": "  ;
				cin >> fillBall1;
				players[player].round[10].throw1 = fillBall1;

			}
		}
		}
		else{
			players[player].round[i].throw2 = 0;	
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
		if(players[player].round[i].isStrike == true){
			if(i==9){
				cout << "  X  " << " "<< players[player].round[10].throw1 <<" "<< players[player].round[10].throw2;

			}
			else{cout << "  X  " << "      ";}
		}
		else if(players[player].round[i].isSpare == true){
			if(i==9){
				cout << players[player].round[i].throw1 << " - " << "/" << "  " << players[player].round[10].throw1;
			}
			else{
			cout << players[player].round[i].throw1 << " - " << "/" << "      ";
			}
		}
		else{
		cout << players[player].round[i].throw1 << " - " << players[player].round[i].throw2 << "      ";
		
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
	cout << players[player].name  << ": " << players[player].calcScore() << endl;

	if(players[player].calcScore() > highestScore){
		highestScore = players[player].calcScore();
		winner = players[player].name;
	}

}

cout << "The winner is " << winner << "!!!" << endl;

//////////// CALCULATE SOCRE ENDS HERE /////////////////////

	return 0;


}

*/