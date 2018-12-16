#include "graphicmanager.h"
#include "sprite.h"
#include <iostream>

#define GAME_TITLE "Arkanoid"

Window * GraphicManager::m_window = nullptr;
Surface * GraphicManager::m_windowSurface = nullptr;

/**
 * Default constructor
 */
GraphicManager *GraphicManager::m_instance = nullptr;

GraphicManager::GraphicManager() {}

GraphicManager *GraphicManager::getInstance() {
  if (m_instance != nullptr)
    return m_instance;
  m_instance = new GraphicManager();
  m_instance->init();
  return m_instance;
}

void GraphicManager::init() {
  // check if SDL is successfuly loaded
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cerr << "Error during SDL initialization: " << SDL_GetError()
              << std::endl;
    exit(1);
  }
}

Window * GraphicManager::createWindow(int width, int height) {
  m_window = SDL_CreateWindow(GAME_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
  return m_window;
}

Surface * GraphicManager::getWindowSurface(Window * w) {
  m_windowSurface = SDL_GetWindowSurface(w);
  return m_windowSurface;
}

Uint64 GraphicManager::getPerformanceCounter() {
  return SDL_GetPerformanceCounter();
}

void GraphicManager::setBackgroud(Uint32 color) {
  SDL_FillRect(m_windowSurface, NULL, color);
}

void GraphicManager::setBlackBackground() {
  setBackgroud(0);
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
