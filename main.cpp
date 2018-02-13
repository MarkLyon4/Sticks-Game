/*
 * main.cpp
 *
 *  Created on: Jan 18, 2018
 *      Author: Mark 4
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sstream>
#include "Sticks.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv) {

	Sticks game;
	string filler;
    srand (time(NULL)); /* for reproducible results, you can call srand(1); */

    cout << "Welcome to the game of sticks! A fun game to play when you're bored of cat videos."  << endl;
    cout << "To play, you start with a certain number of sticks on the table." << endl;
    cout << "You and the computer take turns picking up 1-3 sticks, causing the total number of sticks available for picking to dwindle." << endl;
    cout << "Whoever winds up with zero sticks left to pick on their turn loses." << endl;
    cout << "How many sticks are there on the table initially? Pick a number between 10 and 100." << endl;
    getline(cin,filler);
    stringstream(filler) >> game.number_sticks;

	if (game.number_sticks < 10 or game.number_sticks > 100){ /*Checks whether the number is in boundaries.*/
		cout << "Error: Number of sticks is out of bounds. Think very carefully about what your possible choices are." << endl;
	    exit(1);
	}

	while (game.number_sticks > 0){
		cout << "There are " << game.number_sticks << " sticks on the board." << endl;

	    game.user = game.getUserChoice();
		game.number_sticks = game.number_sticks - game.user;
		if (game.number_sticks < 1){
			cout << "Computer loses. You have beaten the machine. You are now ready to take on Skynet." << endl;

		    break; /*No reason to continue if there's already a winner.*/
		}

		cout << "There are now " << game.number_sticks << " sticks on the board. This is getting intense!" << endl;

		game.computer = game.getComputerChoice(game.number_sticks);
		cout << "Hold onto your socks, the computer selects " << game.computer << " sticks!" << endl;
		game.number_sticks = game.number_sticks - game.computer;
		if (game.number_sticks < 1){
			cout << "Computer wins. Bummer dude. Go outside and clear your head." << endl;
		}
	}
    return 0;
}

