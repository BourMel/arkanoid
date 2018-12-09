#include "drawable.h"

Drawable::Drawable() : m_rect({0, 0, 0, 0}), m_src({0, 0, 0, 0}) {}
Drawable::Drawable(SDL_Rect rect, SDL_Rect src) : m_rect(rect), m_src(src) {}

/**
 * Returns the drawable object
 */
const SDL_Rect &Drawable::getRect() const { return m_rect; }

/**
 * Returns the sprite position
 */
const SDL_Rect &Drawable::getSrc() const { return m_src; }
