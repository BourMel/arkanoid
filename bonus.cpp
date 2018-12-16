#include <SDL2/SDL.h>
#include <cmath>
#include <iostream>

#include "bonus.h"
#include "brick.h"
#include "game.h"
#include "graphicmanager.h"
#include "laser.h"

#define ANIM_FPS 5

int Bonus::bonusTimer = 0;
bool Bonus::activeBonus = false;

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
void Bonus::initTimer() { bonusTimer = 0; }

/**
 * Increments timer and, if over, returns true
 */
bool Bonus::isTimeUp() {
  if (activeBonus) {
    // bonus last 1000 frames
    if (bonusTimer < 1000) {
      bonusTimer++;
    } else {
      activeBonus = false;
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
BonusS::BonusS(Game *game, Box pos) : Bonus(game) {
  m_rect = pos;
  m_src = Sprite::get(Sprite::BONUS_S);
}
void BonusS::action() {
  for (auto ball : m_game->getBalls()) {
    ball->slow();
  }
}

/**
 * Catch the ball
 */
BonusC::BonusC(Game *game, Box pos) : Bonus(game) {
  m_rect = pos;
  m_src = Sprite::get(Sprite::BONUS_C);
}
void BonusC::action() { m_game->getPlayer()->setCatchBall(true); }

/**
 * Creates 2 lasers that the player can use
 */
BonusL::BonusL(Game *game, Box pos) : Bonus(game) {
  m_rect = pos;
  m_src = Sprite::get(Sprite::BONUS_L);
}
void BonusL::action() { Laser::setState(true); }

/**
 * Expends the player
 */
BonusE::BonusE(Game *game, Box pos) : Bonus(game) {
  m_rect = pos;
  m_src = Sprite::get(Sprite::BONUS_E);
}
void BonusE::action() { m_game->getPlayer()->grow(); }

/**
 * 3 balls
 */
BonusD::BonusD(Game *game, Box pos) : Bonus(game) {
  m_rect = pos;
  m_src = Sprite::get(Sprite::BONUS_D);
}
void BonusD::action() { m_game->threeBalls(); }

/**
 * Next round
 */
BonusB::BonusB(Game *game, Box pos) : Bonus(game) {
  m_rect = pos;
  m_src = Sprite::get(Sprite::BONUS_B);
}
void BonusB::action() {
  m_game->addPointsToGame(10000);
  m_game->nextLevel();
}

/**
 * Add a life to player
 */
BonusP::BonusP(Game *game, Box pos) : Bonus(game) {
  m_rect = pos;
  m_src = Sprite::get(Sprite::BONUS_P);
}
void BonusP::action() { m_game->getPlayer()->winLife(); }
