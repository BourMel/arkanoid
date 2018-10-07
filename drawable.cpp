#include "drawable.h"

Drawable::Drawable() : m_rect({0, 0, 0, 0}), m_src({0, 0, 0, 0}) {}

const SDL_Rect &Drawable::getRect() const { return m_rect; }
const SDL_Rect &Drawable::getSrc() const { return m_src; }