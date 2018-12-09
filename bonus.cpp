#include <SDL2/SDL.h>
#include <cmath>
#include <iostream>

#include "bonus.h"
#include "graphicmanager.h"

Bonus::Bonus() : Drawable() {}

// @TODO
/**
 * Make the bonus fall until it comes out of the screen or hits the player
 */
void Bonus::fall() {}

/** BONUS TYPES **/

BonusS::BonusS(SDL_Rect position) : Bonus() {
  Drawable::m_src = GraphicManager::getSprite(GraphicManager::BONUS_S);
  Drawable::m_rect = position;
}
