/*
 * board.cpp
 *
 *  Created on: Apr 25, 2021
 *      Author: albus
 */

#include "board.hpp"
#include <stdlib.h>

board::board(unsigned char queens[8]) {
	for (unsigned int i = 0; i < 8; i++) {
		this->queens[i] = queens[i];
		this->score = 0;
	}
}
board::board() {
	for (unsigned int i = 0; i < 8; i++) {
		int val = 0;
		val = rand() % 8;
		this->queens[i] = val;
	}
	this->score = 0;
}
board::~board() {
}
void board::calc_score() {
	//for each queen in the board
	this->score = 0;
	for (unsigned int i = 0; i < 8; i++) {
		int x = i, y = this->queens[i];
		//get all intersecting cells in the forward diagonal
		while (x < 8 && x >= 0 && y < 8 && y >= 0) {
			if (y == int(this->queens[x]))
				this->score--;
			else
				this->score++;
			x++;
			y--;
		}
		x = i, y = this->queens[i];
		while (x < 8 && x >= 0 && y < 8 && y >= 0) {
			if (y == int(this->queens[x]))
				this->score--;
			else
				this->score++;
			x--;
			y++;
		}

		x = i, y = this->queens[i];
		//get all intersecting cells in the backward diagonal
		while (x < 8 && x >= 0 && y < 8 && y >= 0) {
			if (y == int(this->queens[x]))
				this->score--;
			else
				this->score++;
			x++;
			y++;
		}
		x = i, y = this->queens[i];
		while (x < 8 && x >= 0 && y < 8 && y >= 0) {
			if (y == int(this->queens[x]))
				this->score--;
			else
				this->score++;
			x--;
			y--;
		}
	}
}

int board::get_score() {
	return this->score;
}

void board::mutate() {
	int pos_a = 0, pos_b = 0, holder = 0;
	pos_a = rand() % 8;
	pos_b = rand() % 8;
	holder = this->queens[pos_a];
	this->queens[pos_a] = this->queens[pos_b];
	this->queens[pos_b] = holder;
	this->score = 0;
}

bool board::validate() {
	for (int i = 0; i < 8; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (this->queens[i] == this->queens[j])
				return false;
		}
	}
	return true;
}

void board::set_score(int score) {
	this->score = score;
}
uint8_t* board::get_queens() {
	return this->queens;
}
