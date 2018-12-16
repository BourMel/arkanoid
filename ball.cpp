#include <cstdlib>
#include <iostream>

#include "ball.h"
#include "game.h"

#define BALL_SIZE 12
#define PLAYER_HEIGHT 50
#define DEFAULT_X_SPEED 2
#define DEFAULT_Y_SPEED 4

Ball::Ball()
    : Drawable({0, 0, BALL_SIZE, BALL_SIZE}, {50, 68, BALL_SIZE, BALL_SIZE}),
      m_speedX(DEFAULT_X_SPEED), m_speedY(DEFAULT_Y_SPEED), m_windowX(0),
      m_windowY(0), m_isMoving(false), m_slowed(false) {}

Ball::Ball(Game *game)
    : Drawable(), m_game(game), m_speedX(DEFAULT_X_SPEED),
      m_speedY(DEFAULT_Y_SPEED), m_isMoving(false), m_slowed(false) {

  m_windowX = game->getWindowManager()->getWindowWidth();
  m_windowY = game->getWindowManager()->getWindowHeight();

  m_rect = {m_windowX / 2, m_windowY - PLAYER_HEIGHT - BALL_SIZE, BALL_SIZE,
            BALL_SIZE};
  m_src = {50, 68, BALL_SIZE, BALL_SIZE};
}

Ball::Ball(Game *game, Ball *b)
    : Drawable(), m_game(game), m_speedX(rand() % 8 - 5),
      m_speedY(-rand() % 8 - 1), m_isMoving(true), m_slowed(false) {

  m_windowX = game->getWindowManager()->getWindowWidth();
  m_windowY = game->getWindowManager()->getWindowHeight();

  m_rect = b->getRect();
  m_src = {50, 68, BALL_SIZE, BALL_SIZE};
}

/**
 * If moving = true, the ball will be moving on the screen
 */
void Ball::setMoving(bool moving) { m_isMoving = moving; }

/**
 * Animate the move of the ball for the next frame
 */
void Ball::move(Player *player) {
  int playerPosition = player->getX();
  int playerWidth = player->getRect().w;
  int topY = m_game->getWindowManager()->getWindowHeightStart();
  int oldPosX = m_rect.x;
  int oldPosY = m_rect.y;

  bool cylinderModeEnabled = m_game->getCylinderMode();

  if (m_isMoving) {
    // move the ball

    // bonus "slow" is active
    if (m_slowed) {
      m_rect.x += m_speedX * 0.5;
      m_rect.y += m_speedY * 0.5;

    } else {
      m_rect.x += m_speedX;
      m_rect.y += m_speedY;
    }

    if (m_rect.x < 1) { // left collision
      if (cylinderModeEnabled) {
        m_rect.x = m_windowX - BALL_SIZE;
      } else {
        bounceX();
        if (m_rect.x < 0)
          m_rect.x = 0;
      }

    } else if (m_rect.y < topY + 1) { // top collision
      bounceY();
      if (m_rect.y < topY)
        m_rect.y = topY;

    } else if (m_rect.x > m_windowX - BALL_SIZE) { // right collision
      if (cylinderModeEnabled) {
        m_rect.x = 0;
      } else {
        m_rect.x = -m_rect.x + (2 * (m_windowX - BALL_SIZE));
        bounceX();
      }

    } else if (m_rect.y > m_windowY - BALL_SIZE) { // bottom collision
      m_rect.y = -m_rect.y + (2 * (m_windowY - BALL_SIZE));
      bounceY();

      if (m_game->getBalls().size() == 1) {
        player->looseLife();
      } else {
        m_game->removeBall(this);
      }

      m_isMoving = false;
    }

    // player collision
    if (SDL_HasIntersection(&m_rect, &player->getRect())) {
      if (player->getCatchBall()) {
        m_rect.x = playerPosition + (playerWidth / 2) - (BALL_SIZE / 2);
        m_rect.y = player->getRect().y - player->getRect().h;
      } else {
        // the next direction of the ball depends on where it hits the player :
        // allows the player to choose the direction of the ball
        double positionOnPlayer =
            (double)((double)(m_rect.x - playerPosition) / (double)playerWidth);
        // speed between -10 et 10 (range of 20), using the ball position
        m_speedX = positionOnPlayer * 20 - 10;

        m_speedY *= -1;
      }
    }

  } else { // ball not moving : it sticks on the player
    m_rect.x = playerPosition + (playerWidth / 2) - (BALL_SIZE / 2);
    m_rect.y = m_windowY - PLAYER_HEIGHT - BALL_SIZE;
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

/**
 * Slow the ball
 */
void Ball::slow() { m_slowed = true; }

/**
 * Reset speed to its default values
 */
void Ball::resetSpeed() { m_slowed = false; }

/**
 * Set x coord for the ball
 */
void Ball::setX(int x) { m_rect.x = x; }

/**
 * Set y coord for the ball
 */
void Ball::setY(int y) { m_rect.y = y; }
