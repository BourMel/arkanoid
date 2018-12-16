#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <memory>
#include <vector>

#include "bonus.h"
#include "brick.h"
#include "graphicmanager.h"
#include "laser.h"

class Game;

class WindowManager {
public:
  WindowManager();
  WindowManager(Game *game);

  // init window
  void init();

  // draw what needed in the window
  void drawMenu();
  void drawWin();
  void drawLose();
  void drawLevel();

  // update window surface
  void update();

  // get window width
  int getWindowWidth() const;

  // get window height & start value
  int getWindowHeight() const;
  int getWindowHeightStart() const;

  void readLevelFile(int level);

  void addLasers();

private:
  Window *m_window;
  Surface *m_windowSurface;
  Box m_srcBg;
  Box m_srcLive;
  int m_width;
  int m_height;
  int m_height_start;

  int m_nbLines;
  int m_nbColumns;
  std::vector<std::shared_ptr<Brick>> m_bricks;
  std::vector<std::shared_ptr<Brick>> m_undestructibleBricks;
  std::vector<std::shared_ptr<Bonus>> m_bonus;
  std::vector<std::shared_ptr<Laser>> m_lasers;

  Uint64 m_prev;
  Uint64 m_now;
  double m_deltaTime;

  Game *m_game;
};

#endif // WINDOWMANAGER_H
