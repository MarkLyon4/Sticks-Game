/*
 * Sticks.h
 *
 *  Created on: Jan 12, 2018
 *      Author: Mark 4
 */

#ifndef STICKS_H_INCLUDED_
#define STICKS_H_INCLUDED_

class Sticks {
public:
	Sticks();
	virtual ~Sticks();
	int getUserChoice();
	int getComputerChoice(int number_sticks);
	int user, computer, number_sticks;
};

#endif /* STICKS_H_INCLUDED_ */
