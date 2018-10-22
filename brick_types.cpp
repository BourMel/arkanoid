#include "brick.h"
#include <SDL2/SDL.h>

#include <cmath>
#include <iostream>

#define BRICK_HEIGHT 16
#define BRICK_WIDTH 32

Brick1::Brick1(int line, int col)
    : Drawable(
          {col * BRICK_WIDTH, line * BRICK_HEIGHT, BRICK_WIDTH, BRICK_HEIGHT},
          {0, 0, BRICK_WIDTH, BRICK_HEIGHT}) {}
