#include "board.h"

Board::Board(Player &player, Ball &ball) : m_player(player), m_ball(ball) {}

Player &Board::getPlayer() { return m_player; }

Ball &Board::getBall() { return m_ball; }
