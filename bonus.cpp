#include <SDL2/SDL.h>
#include <cmath>
#include <iostream>

#include "bonus.h"
#include "brick.h"
#include "game.h"
#include "graphicmanager.h"
#include "laser.h"

#define ANIM_FPS 5

int Bonus::bonus_timer = 0;
bool Bonus::active_bonus = false;

Bonus::Bonus() : Drawable(), m_countAnim(0), m_game(nullptr) {}
Bonus::Bonus(Game *game) : Drawable(), m_countAnim(0), m_game(game) {}
void Bonus::action() {}

/**
 * Callback each time the object is drawn
 */
void Bonus::drawCallback() {
  if (++m_countAnim % ANIM_FPS == 0) {
    m_countAnim = 0;

    m_src.x += m_src.w;
    if (m_src.x >= 16 * BRICK_WIDTH) {
      m_src.x = 8 * BRICK_WIDTH;
    }
  }
  m_rect.y += 4;
}

/**
 * Initialization of timer variable
 */
void Bonus::initTimer() { bonus_timer = 0; }

/**
 * Increments timer and, if over, returns true
 */
bool Bonus::isTimeUp() {
  if (active_bonus) {
    // bonus last 200 frames
    if (bonus_timer < 200) {
      bonus_timer++;
    } else {
      active_bonus = false;
      initTimer();
      return true;
    }
  }

  return false;
}

/*****************/
/** BONUS TYPES **/
/*****************/

/**
 * Slow the ball
 */
BonusS::BonusS(Game *game, SDL_Rect pos) : Bonus(game) {
  m_rect = pos;
  m_src = GraphicManager::getSprite(GraphicManager::BONUS_S);
}
void BonusS::action() { m_game->getBall()->slow(); }

/**
 * Catch the ball
 */
BonusC::BonusC(Game *game, SDL_Rect pos) : Bonus(game) {
  m_rect = pos;
  m_src = GraphicManager::getSprite(GraphicManager::BONUS_C);
}
void BonusC::action() { m_game->getPlayer()->setCatchBall(true); }

/**
 * Creates 2 lasers that the player can use
 */
BonusL::BonusL(Game *game, SDL_Rect pos) : Bonus(game) {
  m_rect = pos;
  m_src = GraphicManager::getSprite(GraphicManager::BONUS_L);
}
void BonusL::action() {
  //@TODO : always true ?
  Laser::setState(true);
}

/**
 * Expends the player
 */
BonusE::BonusE(Game *game, SDL_Rect pos) : Bonus(game) {
  m_rect = pos;
  m_src = GraphicManager::getSprite(GraphicManager::BONUS_E);
}
void BonusE::action() { m_game->getPlayer()->grow(); }

/**
 * @TODO
 */
BonusD::BonusD(Game *game, SDL_Rect pos) : Bonus(game) {
  m_rect = pos;
  m_src = GraphicManager::getSprite(GraphicManager::BONUS_D);
}
void BonusD::action() { std::cout << "action for bonus D" << std::endl; }

/**
 * Next round
 */
BonusB::BonusB(Game *game, SDL_Rect pos) : Bonus(game) {
  m_rect = pos;
  m_src = GraphicManager::getSprite(GraphicManager::BONUS_B);
}
void BonusB::action() {
  m_game->addPointsToGame(10000);
  m_game->nextLevel();
}

/**
 * Add a life to player
 */
BonusP::BonusP(Game *game, SDL_Rect pos) : Bonus(game) {
  m_rect = pos;
  m_src = GraphicManager::getSprite(GraphicManager::BONUS_P);
}
void BonusP::action() { m_game->getPlayer()->winLife(); }
