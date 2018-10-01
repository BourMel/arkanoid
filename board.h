#ifndef BOARD_H
#define BOARD_H

#include "player.h"

class Board
{
public:
    Board(Player *player);
    Player getPlayer();
private:
    Player * m_player;
};

#endif // BOARD_H
