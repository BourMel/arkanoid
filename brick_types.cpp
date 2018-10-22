#include "brick.h"
#include "brick_types.h"
#include <SDL2/SDL.h>

#include <cmath>
#include <iostream>

#define BRICK_HEIGHT 16
#define BRICK_WIDTH 32

Brick1::Brick1() : Brick() {}

Brick1::Brick1(int lives, int line, int col)
    : Brick(lives, line, col) {
  m_rect.x = col * BRICK_WIDTH;
  m_rect.y = line * BRICK_HEIGHT;
}
