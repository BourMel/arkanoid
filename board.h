#ifndef BOARD_H
#define BOARD_H

#include "ball.h"
#include "player.h"

class Board {
public:
  Board(Player &player, Ball &ball);
  Player &getPlayer();
  Ball &getBall();

private:
  Player &m_player;
  Ball &m_ball;
};

#endif // BOARD_H
