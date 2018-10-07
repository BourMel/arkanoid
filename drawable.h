#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SDL2/SDL.h>

class Drawable {
public:
  Drawable();

  const SDL_Rect &getRect() const;
  const SDL_Rect &getSrc() const;

private:
  int m_posX; // position d'affichage sur l'axe des x
  int m_posY; // position d'affichage sur l'axe des y
  SDL_Rect m_rect;
  SDL_Rect m_src;
};

#endif // DRAWABLE_H