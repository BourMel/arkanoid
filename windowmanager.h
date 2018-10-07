#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "board.h"
#include "brick.h"
#include <SDL2/SDL.h>
#include <vector>

class WindowManager {
public:
  WindowManager();
  WindowManager(int width, int height);

  // initialise la fenêtre
  void init();

  // dessine ce qui est nécessaire dans la surface de la fenêtre
  void draw(Board &board);

  // met à jour l'affichage de la surface de la fenêtre
  void update();

  // retourne la largeur de la surface de la fenêtre
  int getWindowWidth() const;

  // retourne la hauteur de la surface de la fenêtre
  int getWindowHeight() const;

private:
  SDL_Window *pWindow;
  SDL_Surface *win_surf;
  SDL_Surface *plancheSprites;
  SDL_Rect srcBg;
  SDL_Rect srcVaiss;
  int m_width;
  int m_height;

  int m_level;
  int m_nbLines;
  int m_nbColumns;
  std::vector<Brick> m_bricks;

  void readLevelFile(int level);
};

#endif // WINDOWMANAGER_H
