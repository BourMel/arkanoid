#ifndef LASER_H
#define LASER_H

#include "drawable.h"
#include "graphicmanager.h"

class Game;

class Laser : public Drawable {
public:
  Laser(Box position);
  Laser(Box position, Game *game);

  void drawCallback();
  static void setState(bool value);
  static bool getState();
  static bool m_state;

protected:
  Game *m_game;
};

#endif // LASER_H
