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

  enum screen {
    SCREEN_MENU,
    SCREEN_WIN,
    SCREEN_LOSE,
    SCREEN_LEVEL,
  };

  WindowManager *getWindowManager() const;
  EventManager *getEventManager() const;
  Player *getPlayer() const;
  Ball *getBall() const;

  bool getCylinderMode() const;
  void toggleCylinderMode();
  void addPointsToGame(int points);
  int getGamePoints() const;
  void setCurrentScreen(screen s);

private:
  screen m_currentScreen;

  int m_level;
  int m_lives;
  int m_points;

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
