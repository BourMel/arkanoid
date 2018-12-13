#include <SDL2/SDL.h>
#include <cmath>
#include <iostream>

#include "bonus.h"
#include "brick.h"
#include "game.h"
#include "graphicmanager.h"

#define ANIM_FPS 5

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
void BonusS::action() {
  m_game->getBall()->slow();
}

/**
 * @TODO
 */
BonusC::BonusC(Game *game, SDL_Rect pos) : Bonus(game) {
  m_rect = pos;
  m_src = GraphicManager::getSprite(GraphicManager::BONUS_C);
}
void BonusC::action() { std::cout << "action for bonus C" << std::endl; }

/**
 * @TODO
 */
BonusL::BonusL(Game *game, SDL_Rect pos) : Bonus(game) {
  m_rect = pos;
  m_src = GraphicManager::getSprite(GraphicManager::BONUS_L);
}
void BonusL::action() { std::cout << "action for bonus L" << std::endl; }

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
 * @TODO
 */
BonusB::BonusB(Game *game, SDL_Rect pos) : Bonus(game) {
  m_rect = pos;
  m_src = GraphicManager::getSprite(GraphicManager::BONUS_B);
}
void BonusB::action() { std::cout << "action for bonus B" << std::endl; }

/**
 * Add a life to player
 */
BonusP::BonusP(Game *game, SDL_Rect pos) : Bonus(game) {
  m_rect = pos;
  m_src = GraphicManager::getSprite(GraphicManager::BONUS_P);
}
void BonusP::action() { m_game->getPlayer()->winLife(); }
