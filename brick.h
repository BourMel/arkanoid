#ifndef BRICK_H
#define BRICK_H

#include "ball.h"
#include "drawable.h"
#include <string>

class Brick : public Drawable {
public:
  Brick();
  Brick(int lives);
  Brick(int lives, int line, int col);

  bool checkCollision(Ball &ball);
  int getId() const;
  std::string getColor() const;

protected:
  int m_lives = 1;
  int m_id = 1;
  int m_points = 50;
  std::string m_color = "white";
};

#endif // BRICK_H
