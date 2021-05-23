/*
 * population.hpp
 *
 *  Created on: Apr 25, 2021
 *      Author: albus
 */

#ifndef POPULATION_HPP_
#define POPULATION_HPP_





#endif /* POPULATION_HPP_ */
#include "board.hpp"
#include <vector>
#include <cstdint>
#include <algorithm>
#include <iostream>
class population
{
private:
    std::vector<board> individuals;
    uint_fast32_t size;
    uint_fast8_t elites;
    int_fast32_t score;
public:
    population(uint_fast32_t size);
    void score_calc();
    void sort();
    void mutate();
    void reset_scores();
    int_fast32_t get_score();
    void print_best_ind(int i);
    ~population();
};
