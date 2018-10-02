#ifndef BALL_H
#define BALL_H

#include <SDL2/SDL.h>

class Ball {
public:
  Ball();
  Ball(int x, int y);
  SDL_Rect getRect();
  void move();
  void debug();

private:
  SDL_Rect m_ball;
  int m_speedX;
  int m_speedY;
  int m_windowX;
  int m_windowY;
};

#endif // BALL_H
