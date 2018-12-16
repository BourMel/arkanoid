#ifndef GAME_H
#define GAME_H

#include <memory>
#include <vector>

#include "ball.h"
#include "eventmanager.h"
#include "player.h"
#include "windowmanager.h"

#define GAME_TITLE "Arkanoid"

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

  void run();

  WindowManager *getWindowManager() const;
  EventManager *getEventManager() const;
  Player *getPlayer() const;
  std::vector<std::shared_ptr<Ball>> getBalls() const;

  bool getCylinderMode() const;
  void toggleCylinderMode();
  void addPointsToGame(int points);
  int getGamePoints() const;
  void setCurrentScreen(screen s);
  screen getCurrentScreen() const;
  int getLevel() const;
  void nextLevel();
  void reset();
  void resetBonus();
  void resetAllBonus();
  void threeBalls();
  void removeBall(Ball *b);

private:
  screen m_currentScreen;

  int m_level;
  int m_points;

  // instances
  WindowManager *m_wm;
  EventManager *m_em;
  Player *m_player;
  std::vector<std::shared_ptr<Ball>> m_balls;

  // options
  bool m_cylinderMode;
};

#endif // GAME_H
