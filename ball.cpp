#include "ball.h"
#include "board.h"
#include <iostream>

#define BALL_SIZE 24
#define PLAYER_HEIGHT 32
#define PLAYER_WIDTH 128

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
  int playerPosition = player.get_x();

  if (m_is_moving) {
    // deplacement
    m_ball.x += m_speedX;
    m_ball.y += m_speedY;

    if (m_ball.x < 1) { // collision bord gauche
      m_speedX *= -1;
      if (m_ball.x < 0)
        m_ball.x = 1;
    } else if (m_ball.y < 1) { // collision bord haut
      m_speedY *= -1;
      if (m_ball.y < 0)
        m_ball.y = 1;
    } else if (m_ball.x > m_windowX - BALL_SIZE) { // collision bord droit
      m_ball.x = -m_ball.x + (2 * (m_windowX - BALL_SIZE));
      m_speedX *= -1;
    } else if (m_ball.y > m_windowY - BALL_SIZE) { // collsion bord bas
      m_ball.y = -m_ball.y + (2 * (m_windowY - BALL_SIZE));
      m_speedY *= -1;

      // touche bas -> rouge
      m_src.y = 64;
      player.loose_life();
    }

    // collision vaisseau
    if ((m_ball.x > playerPosition) &&
        (m_ball.x < playerPosition + PLAYER_WIDTH) &&
        (m_ball.y > m_windowY - PLAYER_HEIGHT - 20)) {
      m_speedY *= -1;
      m_src.y = 96; // -> vert
    }

  } else { // the ball sticks on the player
    m_ball.x = playerPosition;
  }
}

void Ball::collisionLeftRight() { m_speedX *= -1; }

void Ball::collisionTopBottom() { m_speedY *= -1; }
