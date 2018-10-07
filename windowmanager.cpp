#include "windowmanager.h"
#include "player.h"
#include <SDL2/SDL.h>
#include <fstream>
#include <iostream>

WindowManager::WindowManager()
    : pWindow(nullptr), win_surf(nullptr), plancheSprites(nullptr),
      srcBg({0, 128, 96, 128}), srcVaiss({128, 0, 128, 32}), m_width(600),
      m_height(600), m_level(0), m_nbLines(0), m_nbColumns(0) {
  init();
}

WindowManager::WindowManager(int width, int height)
    : pWindow(nullptr), win_surf(nullptr), plancheSprites(nullptr),
      srcBg({0, 128, 96, 128}), srcVaiss({128, 0, 128, 32}), m_width(width),
      m_height(height), m_level(0), m_nbLines(0), m_nbColumns(0) {
  init();
}

// initialise la fenêtre
void WindowManager::init() {
  // vérifie si SDL s'est bien initialisé
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cerr << "Echec de l'initialisation de la SDL " << SDL_GetError()
              << std::endl;
    exit(1);
  }

  pWindow = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED, m_width, m_height,
                             SDL_WINDOW_SHOWN);
  win_surf = SDL_GetWindowSurface(pWindow);

  plancheSprites = SDL_LoadBMP("./sprites.bmp");
  SDL_SetColorKey(plancheSprites, true, 0); // 0: 00/00/00 noir -> transparent

  readLevelFile(1);
}

void WindowManager::readLevelFile(int level) {
  // no need to read file if we already read it just before
  if (level == m_level)
    return;

  m_bricks.clear(); // clear bricks

  std::ifstream f;
  f.open("./levels/" + std::to_string(level) + ".txt");

  // if we can't open the file don't go further
  if (!f.is_open())
    return;

  f >> m_nbLines;
  f >> m_nbColumns;

  int x;
  int nbBricks(0);

  while (f >> x) {
    if (x > 0) {
      Brick b(x, nbBricks / m_nbColumns, nbBricks % m_nbColumns);
      m_bricks.push_back(b);
    }
    nbBricks++;
  }

  m_level = level; // save level information
}

// dessine ce qui est nécessaire dans la surface de la fenêtre
void WindowManager::draw(Board &board) {
  Player &player = board.getPlayer();
  Ball &ball = board.getBall();
  SDL_Rect ballRect = ball.getRect();
  SDL_Rect srcBall = ball.getSrc();

  // remplit le fond
  SDL_Rect dest = {0, 0, 0, 0};

  for (int j = 0; j < win_surf->h; j += 128) {
    for (int i = 0; i < win_surf->w; i += 96) {
      dest.x = i;
      dest.y = j;
      SDL_BlitSurface(plancheSprites, &srcBg, win_surf, &dest);
    }
  }

  // display ball
  SDL_BlitSurface(plancheSprites, &srcBall, win_surf, &ballRect);

  // effectue le déplacement de la balle
  ball.move(player);

  // vaisseau
  dest.x = player.get_x();
  dest.y = win_surf->h - 32;
  SDL_BlitSurface(plancheSprites, &srcVaiss, win_surf, &dest);

  // display bricks
  for (auto &b : m_bricks) {
    SDL_Rect bRect = b.getRect();
    SDL_BlitSurface(plancheSprites, &b.getSrc(), win_surf, &bRect);
  }

  // lives
  for (int i = 0; i < player.get_lives(); i++) {
    dest.x = 30;
    dest.y = 30 + i * 30;
    SDL_BlitSurface(plancheSprites, &srcVaiss, win_surf, &dest);
  }
}

// met à jour l'affichage de la surface de la fenêtre
void WindowManager::update() {
  SDL_UpdateWindowSurface(pWindow);
  SDL_Delay(20); // 50 fps
}

// retourne la largeur de la surface de la fenêtre
int WindowManager::getWindowWidth() const { return win_surf->w; }

// retourne la hauteur de la surface de la fenêtre
int WindowManager::getWindowHeight() const { return win_surf->h; }
