#include <SDL2/SDL.h>
#include <cmath>
#include <iostream>

#include "laser.h"
#include "game.h"
#include "graphicmanager.h"

bool Laser::m_state = false;

Laser::Laser(SDL_Rect position) : Drawable(position, {0, 0, 0, 0}), m_game(nullptr) {
  m_src = GraphicManager::getSprite(GraphicManager::BRICK_WHITE);
}
Laser::Laser(SDL_Rect position, Game* game) : Drawable(position, {0, 0, 0, 0}), m_game(game) {
  m_src = GraphicManager::getSprite(GraphicManager::BRICK_WHITE);
}

/**
 * Callback each time the object is drawn
 */
void Laser::drawCallback() {
  // @TODO : no action
  m_rect.y -= 4;
}

/**
 * Choose if lasers are active or not
 */
void Laser::setState(bool state) {
  m_state = state; }

/**
 * Know if lasers are active or not
 */
bool Laser::getState() { return m_state; }
