#include "player.h"
#include "game.h"
#include <SDL2/SDL.h>

Player::Player() : m_lives(3) { init(); }
Player::Player(Game *game) : m_game(game), m_lives(3) { init(); }

void Player::init() {
  m_windowWidth = m_game->getWindowManager()->getWindowWidth();
  m_src = GraphicManager::getSprite(GraphicManager::SpriteType::PLAYER_8);
  m_rect.x = (m_windowWidth - m_src.w) / 2;
  m_rect.y = m_game->getWindowManager()->getWindowHeight() - 32;
  m_rect.w = m_src.w;
  m_rect.h = m_src.h;
}

void Player::set_x(int value) {
  if (value < 0)
    value = 0;
  else if (value > m_windowWidth - m_src.w)
    value = m_windowWidth - m_src.w;
  m_rect.x = value;
}

int Player::get_x() const { return m_rect.x; }

/**
 * The player looses a life
 */
void Player::loose_life() {
  if (--m_lives <= 0) {
    m_game->setCurrentScreen(Game::SCREEN_LOSE);
  }
}

/**
 * Returns true if the player is still alive
 */
// bool Player::is_alive() const { return m_lives > 0; }

/**
 * Returns number of remaining lives
 */
int Player::get_lives() const { return m_lives; }

void Player::setSprite(GraphicManager::SpriteType type) {
  m_src = GraphicManager::getSprite(type);
  if (m_rect.x + m_rect.w > m_windowWidth) {
    m_rect.x = m_windowWidth - m_src.w;
  }
  m_rect.w = m_src.w;
  m_rect.h = m_src.h;
}
