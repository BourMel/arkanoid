#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "board.h"
#include <SDL2/SDL.h>

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
};

#endif // WINDOWMANAGER_H
