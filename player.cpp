#include "player.h"

Player::Player() : m_x((600 - 128) / 2) {}

void Player::set_x(int value) {
  if (value < 0)
    value = 0;
  else if (value > 600 - 128)
    value = 600 - 128;
  m_x = value;
}

int Player::get_x() { return m_x; }
