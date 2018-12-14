#include <SDL2/SDL.h>
#include <cmath>
#include <iostream>

#include "bonus.h"
#include "brick.h"
#include "graphicmanager.h"

Brick::Brick()
    : Drawable({0, 0, BRICK_WIDTH, BRICK_HEIGHT},
               {0, 0, BRICK_WIDTH, BRICK_HEIGHT}),
      m_lives(1), m_points(50), m_id(0) {
  m_src = GraphicManager::getSprite(GraphicManager::BRICK_WHITE);
}

Brick::Brick(int lives, int line, int col)
    : Drawable({col * BRICK_WIDTH, 100 + (line * BRICK_HEIGHT), BRICK_WIDTH,
                BRICK_HEIGHT},
               {0, 0, BRICK_WIDTH, BRICK_HEIGHT}),
      m_lives(lives), m_points(50), m_id(0) {
  m_src = GraphicManager::getSprite(GraphicManager::BRICK_WHITE);
}

/**
 * Check if the ball passed as argument has a collision with this brick
 * if yes, it will make the ball bounce in the right direction
 * and will return true if the brick need to be destructed or false otherwise
 */
bool Brick::checkCollision(Ball &ball) {
  SDL_Rect ballRect = ball.getRect();

  // if there is a collision between the ball and the brick
  if (SDL_HasIntersection(&ballRect, &m_rect)) {

    // get last position of the ball
    int oldPosX = ballRect.x - ball.getSpeedX();
    int oldPosY = ballRect.y - ball.getSpeedY();

    // brick ratio
    double ratio = m_rect.w / m_rect.h;

    // compute delta X and fix the value to consider the center of the ball
    double deltaX = oldPosX - m_rect.x - (m_rect.w / 2);
    if (deltaX < 0)
      deltaX -= ballRect.w / 2;
    else
      deltaX += ballRect.w / 2;

    // compute delta Y and fix the value to consider the center of the ball
    double deltaY = oldPosY - m_rect.y - (m_rect.h / 2);
    if (deltaY < 0)
      deltaY -= ballRect.h / 2;
    else
      deltaY += ballRect.h / 2;

    // some values to simplify following calculations
    double absDeltaX = std::abs(deltaX);
    double limitY = ratio * std::abs(deltaY);

    // left collision
    if (deltaX < -limitY) {
      ball.setX(m_rect.x - ballRect.w);
      ball.bounceX();
    }

    // right collision
    else if (deltaX > limitY) {
      ball.setX(m_rect.x + m_rect.w);
      ball.bounceX();
    }

    // top collision
    else if (deltaY < 0 && absDeltaX < limitY) {
      ball.setY(m_rect.y - ballRect.h);
      ball.bounceY();
    }

    // bottom collision
    else if (deltaY >= 0 && absDeltaX < limitY) {
      ball.setY(m_rect.y + m_rect.h);
      ball.bounceY();
    }

    // x and y collisions
    else if (absDeltaX = limitY) {
      ball.bounceX();
      ball.bounceY();
    }

    // the brick need to be destructed
    if (m_lives != -1 && --m_lives < 1)
      return true;
  }

  // we need to keep this brick
  return false;
}

/**
 * Returns the id of a brick (its type)
 */
int Brick::getId() const { return m_id; }

/**
 * Returns the number of points the brick gives to the player if broken
 */
int Brick::getPoints() const { return m_points; }
