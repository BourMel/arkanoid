#ifndef BRICK_H
#define BRICK_H

#include "ball.h"
#include "drawable.h"

class Brick : public Drawable {
public:
  Brick();
  Brick(int lives, int line, int col);

  bool checkCollision(Ball &ball);

protected:
  int m_lives;
};

#endif // BRICK_H
