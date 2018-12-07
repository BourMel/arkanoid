#include <SDL2/SDL.h>
#include <cmath>
#include <iostream>

#include "bonus.h"
#include "graphicmanager.h"

Bonus::Bonus() : Drawable() {}

/** BONUS TYPES **/
BonusS::BonusS(SDL_Rect position) : Bonus() {
  Drawable::m_src = GraphicManager::getSprite(GraphicManager::BONUS_S);
  Drawable::m_rect = position;
}
