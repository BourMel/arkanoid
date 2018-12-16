#include "graphicmanager.h"
#include "sprite.h"

/**
 * Default constructor
 */
GraphicManager *GraphicManager::m_instance = nullptr;

GraphicManager::GraphicManager() {}

GraphicManager *GraphicManager::getInstance() {
  if (m_instance != nullptr)
    return m_instance;
  m_instance = new GraphicManager();
  return m_instance;
}

/**
 * Create a text zone on the screen at (`x`, `y`) and print the text `str`
 */
void GraphicManager::printText(int x, int y, Surface *src, Surface *dst,
                               std::string str) {
  Box rect = {x, y, ASCII_SIZE, ASCII_SIZE};
  for (char &c : str) {
    Box box = Sprite::get(Sprite::getTypeFromChar(c));
    SDL_BlitSurface(src, &box, dst, &rect);
    rect.x += ASCII_SIZE * 0.6;
  }
}
