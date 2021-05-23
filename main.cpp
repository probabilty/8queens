/*
 * main.cpp
 *
 *  Created on: Apr 25, 2021
 *      Author: albus
 */

#include <time.h>
#include <stdlib.h>
#include "population.hpp"
int main(int argc, char const *argv[]) {
	/* code */
	srand(time(NULL));
	int pop_size = 20;
	population population = *(new class population(pop_size));
	int i = 1;
	while (population.mutate(), population.get_score() < 38) {
		population.score_calc();
		population.sort();
		population.print_best_ind(++i);
	}
	return 0;
}
