#include "brick.h"

Brick::Brick() : Drawable({0, 0, 0, 0}, {140, 0, 67, 32}), m_lives(1) {}
Brick::Brick(int lives)
    : Drawable({0, 0, 0, 0}, {140, 0, 67, 32}), m_lives(lives) {}
Brick::Brick(int lives, int line, int col)
    : Drawable({col * 67, line * 32, 0, 0}, {140, 0, 67, 32}), m_lives(lives) {}
