#include "brick.h"
#include "graphicmanager.h"
#include <SDL2/SDL.h>

#include <cmath>
#include <iostream>

Brick::Brick()
    : Drawable({0, 0, BRICK_WIDTH, BRICK_HEIGHT},
               {0, 0, BRICK_WIDTH, BRICK_HEIGHT}),
      m_lives(1), m_points(50), m_id(0), m_color("white") {
  m_src = GraphicManager::getSprite(GraphicManager::BRICK_WHITE);
}

Brick::Brick(int lives, int line, int col)
    : Drawable(
          {col * BRICK_WIDTH, line * BRICK_HEIGHT, BRICK_WIDTH, BRICK_HEIGHT},
          {0, 0, BRICK_WIDTH, BRICK_HEIGHT}),
      m_lives(lives), m_points(50), m_id(0), m_color("white") {
  m_src = GraphicManager::getSprite(GraphicManager::BRICK_WHITE);
}

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

/**
 * Returns the id of a brick
 */
int Brick::getId() const { return m_id; }

/**
 * Returns the number of points the brick represents
 */
int Brick::getPoints() const { return m_points; }

/**
 * Returns the color of a brick
 */
std::string Brick::getColor() const { return m_color; }
