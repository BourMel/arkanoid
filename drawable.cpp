#include "drawable.h"

Drawable::Drawable() : m_rect({0, 0, 0, 0}), m_src({0, 0, 0, 0}) {}
Drawable::Drawable(SDL_Rect rect, SDL_Rect src) : m_rect(rect), m_src(src) {}

/**
 * Callback each time the object is drawn
 */
void Drawable::drawCallback() {}

/**
 * Returns the drawable object
 */
const SDL_Rect &Drawable::getRect() const { return m_rect; }

/**
 * Returns the sprite position
 */
const SDL_Rect &Drawable::getSrc() const { return m_src; }

/**
 * X and Y setters and getters
 */
const int &Drawable::getX() const { return m_rect.x; }
const int &Drawable::getY() const { return m_rect.y; }
void Drawable::setX(int value) { m_rect.x = value; }
void Drawable::setY(int value) { m_rect.y = value; }
