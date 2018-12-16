#include <SDL2/SDL.h>

#include "game.h"
#include "player.h"

Player::Player() : m_game(nullptr), m_size(1), m_catchBall(false) { init(); }
Player::Player(Game *game) : m_game(game), m_size(1), m_catchBall(false) {
  init();
}

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
 * The player looses a life
 */
void Player::looseLife() {
  m_game->resetAllBonus();

  if (--m_lives <= 0) {
    m_game->setCurrentScreen(Game::SCREEN_LOSE);
  }
}

/**
 * The player win a life (max: 8)
 */
void Player::winLife() {
  if (m_lives >= 8)
    return;
  m_lives++;
}

/**
 * Grow player's size
 */
void Player::grow() {
  if (m_size >= 8)
    return;
  switch (m_size) {
  case 1:
    setSprite(GraphicManager::PLAYER_2);
    break;
  case 2:
    setSprite(GraphicManager::PLAYER_3);
    break;
  case 3:
    setSprite(GraphicManager::PLAYER_4);
    break;
  case 4:
    setSprite(GraphicManager::PLAYER_5);
    break;
  case 5:
    setSprite(GraphicManager::PLAYER_6);
    break;
  case 6:
    setSprite(GraphicManager::PLAYER_7);
    break;
  case 7:
    setSprite(GraphicManager::PLAYER_8);
    break;
  default:
    // do nothing
    break;
  }
  m_size++;
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
 * Define if the player will catch the ball or not
 */
void Player::setCatchBall(bool b) { m_catchBall = b; }

/**
 * Get if user has to cath the ball or not
 */
bool Player::getCatchBall() const { return m_catchBall; }

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
  setCatchBall(false);
}
