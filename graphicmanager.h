#ifndef GRAPHICMANAGER_H
#define GRAPHICMANAGER_H

#include <SDL2/SDL.h>
#include <memory>
#include <string>
#include <vector>

#define BRICK_HEIGHT 16
#define BRICK_WIDTH 32
#define ASCII_SIZE 32

using Box = SDL_Rect;
using Surface = SDL_Surface;
using Window = SDL_Window;

class Drawable;

class GraphicManager {
public:
  ~GraphicManager();
  static GraphicManager *getInstance();
  static Window *createWindow(const int width, const int height);
  static Surface *getWindowSurface(Window *w);
  static Uint64 getPerformanceCounter();
  static double getPerformanceFrequency();
  static void setBackgroud(const Uint32 color);
  static void setBlackBackground();
  static void draw(Drawable d);
  static void draw(Drawable *d);
  static void draw(std::shared_ptr<Drawable> d);
  static bool hasIntersection(const Box *a, const Box *b);
  static void updateWindowSurface(Window *s);
  static void quit();
  static void delay(Uint32 ms);
  static void printText(const int x, const int y, const std::string str);
  void init();

private:
  GraphicManager();
  static Window *m_window;
  static Surface *m_windowSurface;
  static Surface *m_sprites;
  static GraphicManager *m_instance;
};

#endif // GRAPHICMANAGER_H
