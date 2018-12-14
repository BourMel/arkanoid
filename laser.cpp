#include <SDL2/SDL.h>
#include <cmath>
#include <iostream>

#include "game.h"
#include "graphicmanager.h"
#include "laser.h"

bool Laser::m_state = false;

Laser::Laser(SDL_Rect position)
    : Drawable({position.x, position.y, 10, 36}, {0, 0, 0, 0}),
      m_game(nullptr) {
  m_src = GraphicManager::getSprite(GraphicManager::LASER);
}
Laser::Laser(SDL_Rect position, Game *game)
    : Drawable({position.x, position.y, 10, 36}, {0, 0, 0, 0}), m_game(game) {
  m_src = GraphicManager::getSprite(GraphicManager::LASER);
}

/**
 * Callback each time the object is drawn
 */
void Laser::drawCallback() { m_rect.y -= 4; }

/**
 * Choose if lasers are active or not
 */
void Laser::setState(bool state) { m_state = state; }

/**
 * Know if lasers are active or not
 */
bool Laser::getState() { return m_state; }
