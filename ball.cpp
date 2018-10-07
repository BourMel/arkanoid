#include "ball.h"
#include "board.h"
#include <iostream>

#define BALL_SIZE 24

Ball::Ball()
    : m_ball({0, 0, BALL_SIZE, BALL_SIZE}), m_speedX(5), m_speedY(7),
      m_windowX(0), m_windowY(0), m_src({0, 64, BALL_SIZE, BALL_SIZE}),
      m_is_moving(false) {}
Ball::Ball(int x, int y)
    : m_ball({x / 2, y - 55, BALL_SIZE, BALL_SIZE}), m_speedX(5), m_speedY(7),
      m_windowX(x), m_windowY(y), m_src({0, 64, BALL_SIZE, BALL_SIZE}),
      m_is_moving(false) {}

SDL_Rect Ball::getRect() const { return m_ball; }
SDL_Rect Ball::getSrc() const { return m_src; }

/**
 * When function is called, the ball stays on the player
 * Stop the action of the "move" function
 */
void Ball::set_magnet() { m_is_moving = true; }

/**
 * When function is called, the ball starts to move
 */
void Ball::set_moving() { m_is_moving = true; }

void Ball::move(Player &player) {
  if (m_is_moving) {
    // deplacement
    m_ball.x += m_speedX;
    m_ball.y += m_speedY;

    // collision bord
    if ((m_ball.x < 1) || (m_ball.x > m_windowX - 25)) {
      m_speedX *= -1;
    }
    if ((m_ball.y < 1) || (m_ball.y > m_windowY - 25)) {
      m_speedY *= -1;
    }

    // touche bas -> rouge
    if (m_ball.y > (m_windowY - 25)) {
      m_src.y = 64;
      player.loose_life();
    }

    // collision vaisseau
    if ((m_ball.x > player.get_x()) && (m_ball.x < player.get_x() + 128) &&
        (m_ball.y > m_windowY - 32 - 20)) {
      m_speedY *= -1;
      m_src.y = 96; // -> vert
    }

  } else { // the ball sticks on the player
    m_ball.x = player.get_x();
  }
}

void Ball::collisionLeftRight() { m_speedX *= -1; }

void Ball::collisionTopBottom() { m_speedY *= -1; }
