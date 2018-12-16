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
  GraphicManager *getInstance();
  static void printText(int x, int y, Surface *src, Surface *dst,
                        std::string str);

private:
  GraphicManager();
  static GraphicManager *m_instance;
};

#endif // GRAPHICMANAGER_H
