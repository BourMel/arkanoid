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

  // initialise la fenêtre
  void init();

  // dessine ce qui est nécessaire dans la surface de la fenêtre
  void draw();

  // met à jour l'affichage de la surface de la fenêtre
  void update();

  // retourne la largeur de la surface de la fenêtre
  int getWindowWidth() const;

  // retourne la hauteur de la surface de la fenêtre
  int getWindowHeight() const;

  // handle points when destroying bricks
  // void addPointsToGame();

private:
  SDL_Window *pWindow;
  SDL_Surface *win_surf;
  SDL_Surface *plancheSprites;
  SDL_Surface *m_sprites_ascii;
  SDL_Rect srcBg;
  SDL_Rect srcVaiss;
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
