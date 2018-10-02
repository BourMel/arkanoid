#ifndef BALL_H
#define BALL_H

#include "player.h"
#include <SDL2/SDL.h>

class Ball {
public:
  Ball();
  Ball(int x, int y);
  SDL_Rect getRect() const;
  SDL_Rect getSrc() const;
  void move(Player &player);

private:
  SDL_Rect m_ball;
  SDL_Rect m_src;
  int m_speedX;
  int m_speedY;
  int m_windowX;
  int m_windowY;
};

#endif // BALL_H
