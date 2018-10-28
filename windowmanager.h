#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "brick.h"
#include <SDL2/SDL.h>
#include <vector>

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

  // get window height
  int getWindowHeight() const;

private:
  SDL_Window *m_window;
  SDL_Surface *m_windowSurface;
  SDL_Surface *m_sprites;
  SDL_Surface *m_spritesAscii;
  SDL_Rect m_srcBg;
  SDL_Rect m_srcLive;
  int m_width;
  int m_height;

  int m_level;
  int m_nbLines;
  int m_nbColumns;
  std::vector<Brick> m_bricks;

  Game *m_game;

  void readLevelFile(int level);
};

#endif // WINDOWMANAGER_H
