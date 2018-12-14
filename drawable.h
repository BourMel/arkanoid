#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SDL2/SDL.h>

class Drawable {
public:
  Drawable();
  Drawable(SDL_Rect rect, SDL_Rect src);

  // get object position
  const SDL_Rect &getRect() const;

  // get sprite position
  const SDL_Rect &getSrc() const;

  // callback when object is draw
  virtual void drawCallback();

protected:
  SDL_Rect m_rect; // object position
  SDL_Rect m_src;  // sprite position
};

#endif // DRAWABLE_H
