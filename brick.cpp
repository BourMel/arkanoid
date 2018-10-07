#include "brick.h"
#include <SDL2/SDL.h>

#include <iostream>

#define BRICK_HEIGHT 32
#define BRICK_WIDTH 67

Brick::Brick()
    : Drawable({0, 0, BRICK_WIDTH, BRICK_HEIGHT},
               {140, 0, BRICK_WIDTH, BRICK_HEIGHT}),
      m_lives(1) {}
Brick::Brick(int lives)
    : Drawable({0, 0, BRICK_WIDTH, BRICK_HEIGHT},
               {140, 0, BRICK_WIDTH, BRICK_HEIGHT}),
      m_lives(lives) {}
Brick::Brick(int lives, int line, int col)
    : Drawable({col * BRICK_WIDTH, line * BRICK_HEIGHT, 0, 0},
               {140, 0, BRICK_WIDTH, BRICK_HEIGHT}),
      m_lives(lives) {}

bool Brick::checkCollision(const Ball &ball) {
  SDL_Rect bRect = ball.getRect();

  if (!(bRect.x > (m_rect.x + m_rect.w) || (bRect.x + bRect.w) < m_rect.x ||
        bRect.y > (m_rect.y + m_rect.h) || (bRect.y + bRect.h) < m_rect.y)) {
    if (m_lives-- < 1)
      return true;
  }

  return false;
}
