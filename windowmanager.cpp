#include "windowmanager.h"
#include <SDL2/SDL.h>

WindowManager::WindowManager()
    : pWindow(nullptr), win_surf(nullptr), plancheSprites(nullptr),
      srcBg({0, 128, 96, 128}), srcBall({0, 64, 24, 24}),
      scrVaiss({128, 0, 128, 32}) {

  // vérifie si SDL s'est bien initialisé
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cerr << "Echec de l'initialisation de la SDL " << SDL_GetError()
              << std::endl;
    exit(1);
  }

  pWindow =
      SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_SHOWN);
  win_surf = SDL_GetWindowSurface(pWindow);

  plancheSprites = SDL_LoadBMP("./sprites.bmp");
  SDL_SetColorKey(plancheSprites, true, 0); // 0: 00/00/00 noir -> transparent
}

// dessine ce qui est nécessaire dans la surface de la fenêtre
void WindowManager::draw() {

  // remplit le fond
  SDL_Rect dest = {0, 0, 0, 0};

  for (int j = 0; j < win_surf->h; j += 128) {
    for (int i = 0; i < win_surf->w; i += 96) {
      dest.x = i;
      dest.y = j;
      SDL_BlitSurface(plancheSprites, &srcBg, win_surf, &dest);
    }
  }

  //  // affiche balle
  //  SDL_BlitSurface(plancheSprites, &srcBall, win_surf, &ball);

  //  // deplacement
  //  ball.x += speed.x;
  //  ball.y += speed.y;

  //  // collision bord
  //  if ((ball.x < 1) || (ball.x > (win_surf->w - 25)))
  //    speed.x *= -1;
  //  if ((ball.y < 1) || (ball.y > (win_surf->h - 25)))
  //    speed.y *= -1;

  //  // touche bas -> rouge
  //  if (ball.y > (win_surf->h - 25))
  //    srcBall.y = 64;

  //  // collision vaisseau
  //  if ((ball.x > x_vault) && (ball.x < x_vault + 128) &&
  //      (ball.y > win_surf->h - 32 - 20)) {
  //    speed.y *= -1;
  //    srcBall.y = 96; // -> vert
  //  }

  //  // vaisseau
  //  dest.x = x_vault;
  //  dest.y = win_surf->h - 32;
  //  SDL_BlitSurface(plancheSprites, &scrVaiss, win_surf, &dest);
}

// met à jour l'affichage de la surface de la fenêtre
void WindowManager::update() {
  SDL_UpdateWindowSurface(pWindow);
  SDL_Delay(20); // 50 fps
}

// retourne la largeur de la surface de la fenêtre
int WindowManager::getWindowWidth() { return win_surf->w; }

// retourne la hauteur de la surface de la fenêtre
int WindowManager::getWindowHeight() { return win_surf->h; }
