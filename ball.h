#ifndef BALL_H
#define BALL_H

#include "player.h"
#include <SDL2/SDL.h>

class Game;

class Ball {
public:
  Ball();
  Ball(Game *game);

  void setMoving(bool moving);

  SDL_Rect getRect() const;
  SDL_Rect getSrc() const;
  void move(Player *player);
  void bounceX();
  void bounceY();
  int getSpeedX() const;
  int getSpeedY() const;
  void slow();

private:
  SDL_Rect m_ball;
  SDL_Rect m_src;

  bool m_isMoving;

  int m_speedX;
  int m_speedY;
  int m_windowX;
  int m_windowY;

  Game *m_game;
};

#endif // BALL_H
