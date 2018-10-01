#include "board.h"

Board::Board(Player *player) : m_player(player) {}

Player Board::getPlayer() { return *m_player; }
