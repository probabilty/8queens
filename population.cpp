/*
 * population.cpp
 *
 *  Created on: Apr 25, 2021
 *      Author: albus
 */

#include "population.hpp"
population::population(uint_fast32_t size) {
	this->size = size;
	this->elites = 5;
	this->score = 0;
	while (this->individuals.size() != this->size) {
		board board = *(new class board());
		if (board.validate())
			this->individuals.push_back(board);
	}
}
void population::score_calc() {
	this->reset_scores();
	for (auto it = this->individuals.begin(); it != this->individuals.end();
			++it) {
		it->calc_score();
	}
}
void population::sort() {
	std::sort(this->individuals.begin(), this->individuals.end(),
			[](board &a, board &b) {
				return a.get_score() > b.get_score();
			});
}
void population::reset_scores() {
	for (auto it = this->individuals.begin(); it != this->individuals.end();
			++it) {
		it->set_score(0);
	}
}

void population::mutate() {
	for (int i = 0; i < this->elites; i++) {
		this->individuals.push_back(this->individuals[i]);
	}
	for (auto it = this->individuals.begin() + this->elites;
			it != this->individuals.end(); ++it) {

		it->mutate();
	}
}
void population::print_best_ind(int i) {
//    if (this->individuals[0].get_score()>512)
	{
		std::cout << this->individuals[0].get_score() << " generation:" << i
				<< std::endl;
		for (uint8_t i = 0; i < 8; i++) {
			std::cout << unsigned((this->individuals[0].get_queens()[i]))
					<< ",";
		}
		std::cout << std::endl;
	}
	this->score = this->individuals[0].get_score();
}

int_fast32_t population::get_score() {
	return this->score;
}
population::~population() {
}
