#include <SDL2/SDL.h>

#include "player.h"
#include "game.h"

Player::Player() { init(); }
Player::Player(Game *game) : m_game(game) { init(); }

/**
 * Initialize the player for the first time
 */
void Player::init() {
  m_windowWidth = m_game->getWindowManager()->getWindowWidth();
  reset();
}

/**
 * Set player position on the x-axis
 */
void Player::setX(int value) {
  if (value < 0)
    value = 0;
  else if (value > m_windowWidth - m_src.w)
    value = m_windowWidth - m_src.w;
  m_rect.x = value;
}

/**
 * Get the player position on the x-axis
 */
int Player::getX() const { return m_rect.x; }

/**
 * The player looses a life
 */
void Player::looseLife() {
  if (--m_lives <= 0) {
    m_game->setCurrentScreen(Game::SCREEN_LOSE);
  }
}

/**
 * Returns number of remaining lives
 */
int Player::getLives() const { return m_lives; }

/**
 * Change the sprite used to represent the player
 */
void Player::setSprite(GraphicManager::SpriteType type) {
  m_src = GraphicManager::getSprite(type);
  if (m_rect.x + m_rect.w > m_windowWidth) {
    m_rect.x = m_windowWidth - m_src.w;
  }
  m_rect.w = m_src.w;
  m_rect.h = m_src.h;
}

/**
 * Reset player informations
 */
void Player::reset() {
  m_lives = 3;
  m_src = GraphicManager::getSprite(GraphicManager::SpriteType::PLAYER_1);
  m_rect.x = (m_windowWidth - m_src.w) / 2;
  m_rect.y = m_game->getWindowManager()->getWindowHeight() - 50;
  m_rect.w = m_src.w;
  m_rect.h = m_src.h;
}
