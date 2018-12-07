#ifndef BRICK_H
#define BRICK_H

#include "ball.h"
#include "bonus.h"
#include "drawable.h"
#include <string>

class Brick : public Drawable {
public:
  Brick();
  Brick(int lives, int line, int col);

  bool checkCollision(Ball &ball);
  Bonus spawnBonus();
  int getId() const;
  int getPoints() const;

protected:
  int m_lives;
  int m_id;
  int m_points;
};

#endif // BRICK_H
