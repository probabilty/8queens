/*
 * board.hpp
 *
 *  Created on: Apr 25, 2021
 *      Author: albus
 */

#ifndef BOARD_HPP_
#define BOARD_HPP_





#endif /* BOARD_HPP_ */
#include <cstdint>
class board
{
private:
	uint8_t queens[8];
   int score;
public:
    board(unsigned char queens[8]);
    board();
    ~board();
    void calc_score();
    void mutate();
    bool validate();
    int get_score();
    void set_score(int score);
    uint8_t*  get_queens();
};
