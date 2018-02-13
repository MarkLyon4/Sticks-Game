/*
 * Sticks.cpp
 *
 *  Created on: Jan 12, 2018
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

Sticks::Sticks() {
	// TODO Auto-generated constructor stub
	this->user = 0;
	this->computer = 0;
	this->number_sticks = 0;
}

Sticks::~Sticks() {
	// TODO Auto-generated destructor stub
}

int Sticks::getUserChoice() {

	int sticks_chosen;
	string filler;

	cout << "Player 1: How many sticks do you take (1-3)?" << endl;
	getline(cin,filler);
	stringstream(filler) >> sticks_chosen;
	while (sticks_chosen > 3 or sticks_chosen < 1){
		cout << "Error: Not within 1-3. Think very carefully about what your possible choices are." << endl;
	    cout << "Player 1: How many sticks do you take (1-3)? Choose anything else, and you've got to be trolling the computer at that point." << endl;
	    getline(cin,filler);
	    stringstream(filler) >> sticks_chosen;
	}
	return sticks_chosen;
}

int Sticks::getComputerChoice(int current_sticks) {

    /* get a pseudo-random integer between 1 and 3 (inclusive) */
    int rand_choice = rand() % 3 + 1;

    if (rand_choice > current_sticks){
		return current_sticks;
    }

    return rand_choice;
}

