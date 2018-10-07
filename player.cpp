#include "player.h"

Player::Player() : m_x((600 - 128) / 2), m_lives(2) {}

void Player::set_x(int value) {
  if (value < 0)
    value = 0;
  else if (value > 600 - 128)
    value = 600 - 128;
  m_x = value;
}

int Player::get_x() const { return m_x; }

/**
  * The player looses a life
  */
void Player::loose_life() { m_lives--; }

/**
  * Returns true if the player is still alive
  */
bool Player::is_alive() const { return m_lives >= 0; }

/**
  * Returns number of remaining lives
  */
int Player::get_lives() const { return m_lives; }
