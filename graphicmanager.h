#ifndef GRAPHICMANAGER_H
#define GRAPHICMANAGER_H

#include <SDL2/SDL.h>
#include <string>

#define BRICK_HEIGHT 16
#define BRICK_WIDTH 32
#define ASCII_SIZE 32

using Box = SDL_Rect;
using Surface = SDL_Surface;
using Window = SDL_Window;

class GraphicManager {
public:
  static GraphicManager *getInstance();
  static Window *createWindow(int width, int height);
  static Surface *getWindowSurface(Window *w);
  static Uint64 getPerformanceCounter();
  static void setBackgroud(Uint32 color);
  static void setBlackBackground();
  static void printText(int x, int y, Surface *src, Surface *dst,
                        std::string str);
  void init();
  void draw(Box);

private:
  GraphicManager();
  static Window *m_window;
  static Surface *m_windowSurface;
  static GraphicManager *m_instance;
};

#endif // GRAPHICMANAGER_H
