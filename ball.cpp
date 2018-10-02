#include "ball.h"
#include <iostream>

Ball::Ball()
    : m_ball({0, 0, 0, 0}), m_speedX(5), m_speedY(7), m_windowX(0),
      m_windowY(0) {}
Ball::Ball(int x, int y)
    : m_ball({x / 2, y / 2, 0, 0}), m_speedX(5), m_speedY(7), m_windowX(x),
      m_windowY(y) {}

SDL_Rect Ball::getRect() { return m_ball; }

void Ball::move() {
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
}

void Ball::debug() {
  std::cout << "x=" << m_ball.x << ", y=" << m_ball.y << std::endl;
}
