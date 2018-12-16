#ifndef BALL_H
#define BALL_H

#include "player.h"

class Game;

class Ball : public Drawable {
public:
  Ball();
  Ball(Game *game);
  Ball(Game *game, Ball *b);

  void setMoving(bool moving);

  void move(Player *player);
  void bounceX();
  void bounceY();
  int getSpeedX() const;
  int getSpeedY() const;
  void slow();
  void resetSpeed();

private:
  bool m_isMoving;

  int m_speedX;
  int m_speedY;
  bool m_slowed;
  int m_windowX;
  int m_windowY;

  Game *m_game;
};

#endif // BALL_H
