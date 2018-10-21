#include "brick.h"
#include <SDL2/SDL.h>

#include <cmath>
#include <iostream>

#define BRICK_HEIGHT 16
#define BRICK_WIDTH 32

Brick::Brick()
    : Drawable({0, 0, BRICK_WIDTH, BRICK_HEIGHT},
               {0, 0, BRICK_WIDTH, BRICK_HEIGHT}),
      m_lives(1) {}
Brick::Brick(int lives)
    : Drawable({0, 0, BRICK_WIDTH, BRICK_HEIGHT},
               {0, 0, BRICK_WIDTH, BRICK_HEIGHT}),
      m_lives(lives) {}
Brick::Brick(int lives, int line, int col)
    : Drawable(
          {col * BRICK_WIDTH, line * BRICK_HEIGHT, BRICK_WIDTH, BRICK_HEIGHT},
          {0, 0, BRICK_WIDTH, BRICK_HEIGHT}),
      m_lives(lives) {}

bool Brick::checkCollision(Ball &ball) {
  SDL_Rect bRect = ball.getRect();

  if (SDL_HasIntersection(&bRect, &m_rect)) {
    int deltaLeft = std::abs(bRect.x - m_rect.x);
    int deltaRight = std::abs(bRect.x + bRect.w - m_rect.x - m_rect.w);
    int deltaTop = std::abs(bRect.y - m_rect.y);
    int deltaBottom = std::abs(bRect.y + bRect.h - m_rect.y - m_rect.h);

    if ((deltaLeft < deltaTop && deltaLeft < deltaBottom) ||
        (deltaRight < deltaTop && deltaRight < deltaBottom))
      ball.collisionLeftRight();
    else if ((deltaTop < deltaLeft && deltaTop < deltaRight) ||
             (deltaBottom < deltaLeft && deltaBottom < deltaRight))
      ball.collisionTopBottom();

    if (--m_lives < 1)
      return true;
  }

  return false;
}
