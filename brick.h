#ifndef BRICK_H
#define BRICK_H

#include "drawable.h"

class Brick : public Drawable {
public:
  Brick();
  Brick(int lives);
  Brick(int lives, int line, int col);

protected:
  int m_lives;
};

#endif // BRICK_H
