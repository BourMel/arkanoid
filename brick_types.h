#ifndef BRICK_TYPES_H
#define BRICK_TYPES_H

#include "brick.h"
// #include <string>

class Brick1 : public Brick {
public:
  Brick1();
  Brick1(int lives, int line, int col);

protected:
  int m_lives = 1;
  int m_id = 1;
  int m_points = 50;
  std::string m_color = "white";
};

#endif // BRICK_TYPES_H
