#include "graphicmanager.h"
#include "drawable.h"
#include "sprite.h"
#include <iostream>

#define GAME_TITLE "Arkanoid"

Window *GraphicManager::m_window = nullptr;
Surface *GraphicManager::m_windowSurface = nullptr;
Surface *GraphicManager::m_sprites = nullptr;
GraphicManager *GraphicManager::m_instance = nullptr;

/**
 * Default constructor
 */
GraphicManager::GraphicManager() {}

GraphicManager::~GraphicManager() { delete m_instance; }

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

  // initialize sprites
  m_sprites = SDL_LoadBMP("./sprites.bmp");
  SDL_SetColorKey(m_sprites, true, 0); // 0: 00/00/00 black -> transparent
}

Window *GraphicManager::createWindow(const int width, const int height) {
  m_window =
      SDL_CreateWindow(GAME_TITLE, SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
  return m_window;
}

Surface *GraphicManager::getWindowSurface(Window *w) {
  m_windowSurface = SDL_GetWindowSurface(w);
  return m_windowSurface;
}

Uint64 GraphicManager::getPerformanceCounter() {
  return SDL_GetPerformanceCounter();
}

double GraphicManager::getPerformanceFrequency() {
  return SDL_GetPerformanceFrequency();
}

void GraphicManager::setBackgroud(const Uint32 color) {
  SDL_FillRect(m_windowSurface, NULL, color);
}

void GraphicManager::setBlackBackground() { setBackgroud(0); }

void GraphicManager::draw(Drawable d) {
  Box rect = d.getRect();
  Box src = d.getSrc();

  SDL_BlitSurface(m_sprites, &src, m_windowSurface, &rect);
}

void GraphicManager::draw(Drawable *d) {
  Box rect = d->getRect();
  Box src = d->getSrc();

  SDL_BlitSurface(m_sprites, &src, m_windowSurface, &rect);

  d->drawCallback();
}

void GraphicManager::draw(std::shared_ptr<Drawable> d) { draw(d.get()); }

bool GraphicManager::hasIntersection(const Box *a, const Box *b) {
  return SDL_HasIntersection(a, b);
}

void GraphicManager::updateWindowSurface(Window *w) {
  SDL_UpdateWindowSurface(w);
}

void GraphicManager::quit() { SDL_Quit(); }

void GraphicManager::delay(Uint32 ms) { SDL_Delay(ms); }

/**
 * Create a text zone on the screen at (`x`, `y`) and print the text `str`
 */
void GraphicManager::printText(const int x, const int y,
                               const std::string str) {
  Box rect = {x, y, ASCII_SIZE, ASCII_SIZE};
  for (const char &c : str) {
    Box box = Sprite::get(Sprite::getTypeFromChar(c));
    draw(Drawable(rect, box));
    rect.x += ASCII_SIZE * 0.6;
  }
}
