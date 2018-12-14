#ifndef LASER_H
#define LASER_H

#include "drawable.h"

class Game;

class Laser : public Drawable {
public:
  Laser(SDL_Rect position);
  Laser(SDL_Rect position, Game *game);

  void drawCallback();
  static void setState(bool value);
  static bool getState();
  static bool m_state;

protected:
  Game *m_game;
};

#endif // LASER_H
