#include "ball.h"
#include "game.h"
#include <iostream>

#define BALL_SIZE 12
#define PLAYER_HEIGHT 50

Ball::Ball()
    : m_ball({0, 0, BALL_SIZE, BALL_SIZE}), m_speedX(5), m_speedY(7),
      m_windowX(0), m_windowY(0), m_src({50, 68, BALL_SIZE, BALL_SIZE}),
      m_isMoving(false) {}
Ball::Ball(Game *game)
    : m_game(game), m_speedX(5), m_speedY(7),
      m_src({50, 68, BALL_SIZE, BALL_SIZE}), m_isMoving(false) {
  m_windowX = game->getWindowManager()->getWindowWidth();
  m_windowY = game->getWindowManager()->getWindowHeight();
  m_ball = {m_windowX / 2, m_windowY - PLAYER_HEIGHT - BALL_SIZE, BALL_SIZE,
            BALL_SIZE};
}

SDL_Rect Ball::getRect() const { return m_ball; }
SDL_Rect Ball::getSrc() const { return m_src; }

/**
 * If true, the ball will be moving on the screen
 */
void Ball::setMoving(bool moving) { m_isMoving = moving; }

/**
 * Animate the move of the ball for the next frame
 */
void Ball::move(Player *player) {
  int playerPosition = player->getX();
  int playerWidth = player->getRect().w;

  bool cylinderModeEnabled = m_game->getCylinderMode();

  if (m_isMoving) {
    // move the ball
    m_ball.x += m_speedX;
    m_ball.y += m_speedY;

    if (m_ball.x < 1) { // left collision
      if (cylinderModeEnabled) {
        m_ball.x = m_windowX - BALL_SIZE;
      } else {
        bounceX();
        if (m_ball.x < 0)
          m_ball.x = 0;
      }
    } else if (m_ball.y < 101) { // top collision
      bounceY();
      if (m_ball.y < 100)
        m_ball.y = 100;
    } else if (m_ball.x > m_windowX - BALL_SIZE) { // right collision
      if (cylinderModeEnabled) {
        m_ball.x = 0;
      } else {
        m_ball.x = -m_ball.x + (2 * (m_windowX - BALL_SIZE));
        bounceX();
      }
    } else if (m_ball.y > m_windowY - BALL_SIZE) { // bottom collision
      m_ball.y = -m_ball.y + (2 * (m_windowY - BALL_SIZE));
      bounceY();

      player->looseLife();
      m_isMoving = false;
    }

    // player collision
    if ((m_ball.x > playerPosition) &&
        (m_ball.x < playerPosition + playerWidth) &&
        (m_ball.y > m_windowY - PLAYER_HEIGHT - BALL_SIZE)) {

      // allows the player to choose the direction of the ball
      double positionOnPlayer =
          (double)((double)(m_ball.x - playerPosition) / (double)playerWidth);
      // speed between -10 et 10 (range of 20), using the ball position
      m_speedX = positionOnPlayer * 20 - 10;

      m_speedY *= -1;
    }

  } else { // the ball sticks on the player
    m_ball.x = playerPosition + (playerWidth / 2) - (BALL_SIZE / 2);
    m_ball.y = m_windowY - PLAYER_HEIGHT - BALL_SIZE;
  }
}

/**
 * Collision with the ball on the left or right side
 */
void Ball::bounceX() { m_speedX *= -1; }

/**
 * Collision with the ball on the top or bottom side
 */
void Ball::bounceY() { m_speedY *= -1; }

/**
 * Return current ball speed for the x-axis
 */
int Ball::getSpeedX() const { return m_speedX; }

/**
 * Return current ball speed for the y-axis
 */
int Ball::getSpeedY() const { return m_speedY; }
