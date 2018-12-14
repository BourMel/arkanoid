#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <SDL2/SDL.h>
#include <vector>

#include "bonus.h"
#include "brick.h"
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
  SDL_Window *m_window;
  SDL_Surface *m_windowSurface;
  SDL_Surface *m_sprites;
  SDL_Surface *m_spritesAscii;
  SDL_Rect m_srcBg;
  SDL_Rect m_srcLive;
  int m_width;
  int m_height;
  int m_height_start;

  int m_nbLines;
  int m_nbColumns;
  std::vector<Brick> m_bricks;
  std::vector<Brick> m_undestructibleBricks;
  std::vector<Bonus *> m_bonus;
  std::vector<Laser *> m_lasers;

  Uint64 m_prev;
  Uint64 m_now;
  double m_deltaTime;

  Game *m_game;
};

#endif // WINDOWMANAGER_H
