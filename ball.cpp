#include "ball.h"
#include <iostream>

Ball::Ball()
    : m_ball({0, 0, 0, 0}), m_speedX(5), m_speedY(7), m_windowX(0),
      m_windowY(0), m_src({0, 64, 24, 24}) {}
Ball::Ball(int x, int y)
    : m_ball({x / 2, y / 2, 0, 0}), m_speedX(5), m_speedY(7), m_windowX(x),
      m_windowY(y), m_src({0, 64, 24, 24}) {}

SDL_Rect Ball::getRect() const { return m_ball; }
SDL_Rect Ball::getSrc() const { return m_src; }

void Ball::move(Player &player) {
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
  if (m_ball.y > (m_windowY - 25))
    m_src.y = 64;

  // collision vaisseau
  if ((m_ball.x > player.get_x()) && (m_ball.x < player.get_x() + 128) &&
      (m_ball.y > m_windowY - 32 - 20)) {
    m_speedY *= -1;
    m_src.y = 96; // -> vert
  }
}
