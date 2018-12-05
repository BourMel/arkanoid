#include "player.h"
#include "game.h"
#include <SDL2/SDL.h>

Player::Player() { init(); }
Player::Player(Game *game) : m_game(game) { init(); }

void Player::init() {
  m_windowWidth = m_game->getWindowManager()->getWindowWidth();
  m_lives = 3;
  m_src = GraphicManager::getSprite(GraphicManager::SpriteType::PLAYER_1);
  m_rect.x = (m_windowWidth - m_src.w) / 2;
  m_rect.y = m_game->getWindowManager()->getWindowHeight() - 32;
  m_rect.w = m_src.w;
  m_rect.h = m_src.h;
}

void Player::setX(int value) {
  if (value < 0)
    value = 0;
  else if (value > m_windowWidth - m_src.w)
    value = m_windowWidth - m_src.w;
  m_rect.x = value;
}

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
 * Returns true if the player is still alive
 */
// bool Player::isAlive() const { return m_lives > 0; }

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

void Player::reset() {
  m_lives = 3;
  m_src = GraphicManager::getSprite(GraphicManager::SpriteType::PLAYER_1);
  m_rect.x = (m_windowWidth - m_src.w) / 2;
  m_rect.y = m_game->getWindowManager()->getWindowHeight() - 32;
  m_rect.w = m_src.w;
  m_rect.h = m_src.h;
}
