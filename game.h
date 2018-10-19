#ifndef GAME_H
#define GAME_H

#include "ball.h"
#include "eventmanager.h"
#include "player.h"
#include "windowmanager.h"

class Game {
public:
  Game();
  ~Game();

  WindowManager *getWindowManager() const;
  EventManager *getEventManager() const;
  Player *getPlayer() const;
  Ball *getBall() const;

private:
  int m_level;
  int m_lives;

  // instances
  WindowManager *m_wm;
  EventManager *m_em;
  Player *m_player;
  Ball *m_ball;

  // options
  bool m_cylinderMode;

  void init();
};

#endif // GAME_H
