#ifndef BRICK_H
#define BRICK_H

#include "ball.h"
#include "drawable.h"
#include <string>

class Brick : public Drawable {
public:
  Brick();
  Brick(int lives, int line, int col);

  bool checkCollision(Ball &ball);
  int getId() const;
  std::string getColor() const;
  int getPoints() const;

protected:
  int m_lives;
  int m_id;
  int m_points;
  std::string m_color;
};

#endif // BRICK_H
