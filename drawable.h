#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SDL2/SDL.h>

class Drawable {
public:
  Drawable();
  Drawable(SDL_Rect rect, SDL_Rect src);

  // retourne la surface de l'objet
  const SDL_Rect &getRect() const;

  // retourne la position du sprite de l'objet
  const SDL_Rect &getSrc() const;

protected:
  SDL_Rect m_rect; // emplacement de l'élément dans la fenêtre
  SDL_Rect m_src;  // emplacement du sprite
};

#endif // DRAWABLE_H
