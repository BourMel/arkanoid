#include <SDL2/SDL.h>
#include <cmath>
#include <iostream>

#include "bonus.h"
#include "brick.h"
#include "graphicmanager.h"

#define ANIM_FPS 5

Bonus::Bonus() : Drawable(), m_countAnim(0) {}

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

/** BONUS TYPES **/
BonusS::BonusS(SDL_Rect pos) : Bonus() {
  m_rect = pos;
  m_src = GraphicManager::getSprite(GraphicManager::BONUS_S);
}

/**
 * Callback each time the object is drawn
 */
void BonusS::drawCallback() { Bonus::drawCallback(); }

BonusC::BonusC(SDL_Rect pos) : Bonus() {
  m_rect = pos;
  m_src = GraphicManager::getSprite(GraphicManager::BONUS_C);
}

/**
 * Callback each time the object is drawn
 */
void BonusC::drawCallback() { Bonus::drawCallback(); }

BonusL::BonusL(SDL_Rect pos) : Bonus() {
  m_rect = pos;
  m_src = GraphicManager::getSprite(GraphicManager::BONUS_L);
}

/**
 * Callback each time the object is drawn
 */
void BonusL::drawCallback() { Bonus::drawCallback(); }

BonusE::BonusE(SDL_Rect pos) : Bonus() {
  m_rect = pos;
  m_src = GraphicManager::getSprite(GraphicManager::BONUS_E);
}

/**
 * Callback each time the object is drawn
 */
void BonusE::drawCallback() { Bonus::drawCallback(); }

BonusD::BonusD(SDL_Rect pos) : Bonus() {
  m_rect = pos;
  m_src = GraphicManager::getSprite(GraphicManager::BONUS_D);
}

/**
 * Callback each time the object is drawn
 */
void BonusD::drawCallback() { Bonus::drawCallback(); }

BonusB::BonusB(SDL_Rect pos) : Bonus() {
  m_rect = pos;
  m_src = GraphicManager::getSprite(GraphicManager::BONUS_B);
}

/**
 * Callback each time the object is drawn
 */
void BonusB::drawCallback() { Bonus::drawCallback(); }

BonusP::BonusP(SDL_Rect pos) : Bonus() {
  m_rect = pos;
  m_src = GraphicManager::getSprite(GraphicManager::BONUS_P);
}

/**
 * Callback each time the object is drawn
 */
void BonusP::drawCallback() { Bonus::drawCallback(); }
