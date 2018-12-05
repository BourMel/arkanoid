#include "windowmanager.h"
#include "game.h"
#include "graphicmanager.h"
#include "player.h"
#include <SDL2/SDL.h>
#include <fstream>
#include <iostream>
#include <string>

#include "brick_types.h"

WindowManager::WindowManager()
    : m_window(nullptr), m_windowSurface(nullptr), m_sprites(nullptr),
      m_srcBg({0, 128, 48, 64}), m_width(600), m_height(600), m_nbLines(0),
      m_nbColumns(0) {
  init();
}

WindowManager::WindowManager(Game *game)
    : m_game(game), m_window(nullptr), m_windowSurface(nullptr),
      m_sprites(nullptr), m_srcBg({0, 128, 48, 64}), m_width(600),
      m_height(600), m_nbLines(0), m_nbColumns(0) {
  init();
}

// init the window
void WindowManager::init() {
  // check if SDL is successfuly loaded
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cerr << "Error during SDL initialization: " << SDL_GetError()
              << std::endl;
    exit(1);
  }

  m_window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, m_width, m_height,
                              SDL_WINDOW_SHOWN);
  m_windowSurface = SDL_GetWindowSurface(m_window);

  m_sprites = SDL_LoadBMP("./sprites.bmp");
  m_spritesAscii = SDL_LoadBMP("./ascii.bmp");
  SDL_SetColorKey(m_sprites, true, 0); // 0: 00/00/00 black -> transparent
  SDL_SetColorKey(m_spritesAscii, true, 0);

  m_srcLive =
      GraphicManager::getSprite(GraphicManager::SpriteType::PLAYER_LIFE);

  readLevelFile(1);
}

void WindowManager::readLevelFile(int level) {
  m_bricks.clear(); // clear bricks

  std::ifstream f;
  f.open("./levels/" + std::to_string(level) + ".txt");

  // if we can't open the file don't go further
  if (!f.is_open())
    return;

  if (level == 1) {
    if (m_game->getPlayer() != nullptr) {
      m_game->reset();
    }
  }

  f >> m_nbLines;
  f >> m_nbColumns;

  int x;
  int nbBricks(0);

  while (f >> x) {
    if (x > 0) {
      Brick b;
      int line = nbBricks / m_nbColumns;
      int col = nbBricks % m_nbColumns;

      switch (x) {
      case 1:
        b = Brick1(line, col);
        break;
      case 2:
        b = Brick2(line, col);
        break;
      case 3:
        b = Brick3(line, col);
        break;
      case 4:
        b = Brick4(line, col);
        break;
      case 5:
        b = Brick5(line, col);
        break;
      case 6:
        b = Brick6(line, col);
        break;
      case 7:
        b = Brick7(line, col);
        break;
      case 8:
        b = Brick8(line, col);
        break;
      case 9:
        b = Brick9(line, col);
        break;
      case 10:
        b = Brick10(line, col);
        break;
      case 11:
        b = Brick11(line, col);
        break;
      case 12:
        b = Brick12(line, col);
        break;
      case 13:
        b = Brick13(m_game, line, col);
        break;
      case 14:
        b = Brick14(line, col);
        break;
      default:
        b = Brick(x, line, col);
        break;
      }

      m_bricks.push_back(b);
    }
    nbBricks++;
  }
}

void WindowManager::drawMenu() {
  // fill the screen with black
  SDL_FillRect(SDL_GetWindowSurface(m_window), NULL, 0);

  GraphicManager::printText(200, 200, m_spritesAscii, m_windowSurface,
                            "Arkanoid");

  GraphicManager::printText(m_width / 2 - 190, 400, m_spritesAscii,
                            m_windowSurface, "Press ENTER to begin");
}

void WindowManager::drawWin() {
  // fill the screen with black
  SDL_FillRect(SDL_GetWindowSurface(m_window), NULL, 0);

  GraphicManager::printText(m_width / 2 - 150, 200, m_spritesAscii,
                            m_windowSurface, "Congratulations");

  GraphicManager::printText(m_width / 2 - 230, 400, m_spritesAscii,
                            m_windowSurface, "Return to menu with ENTER");
}

void WindowManager::drawLose() {
  // fill the screen with black
  SDL_FillRect(SDL_GetWindowSurface(m_window), NULL, 0);

  GraphicManager::printText(m_width / 2 - 90, 200, m_spritesAscii,
                            m_windowSurface, "Game Over");

  GraphicManager::printText(m_width / 2 - 230, 400, m_spritesAscii,
                            m_windowSurface, "Return to menu with ENTER");
}

void WindowManager::drawLevel() {
  Player *player = m_game->getPlayer();
  SDL_Rect pRect = player->getRect();
  Ball *ball = m_game->getBall();
  SDL_Rect ballRect = ball->getRect();
  SDL_Rect srcBall = ball->getSrc();
  std::string level = std::to_string(m_game->getLevel());

  SDL_Rect dest = {0, 0, 0, 0};

  // background
  for (int j = 0; j < m_windowSurface->h; j += m_srcBg.h) {
    for (int i = 0; i < m_windowSurface->w; i += m_srcBg.w) {
      dest.x = i;
      dest.y = j;
      SDL_BlitSurface(m_sprites, &m_srcBg, m_windowSurface, &dest);
    }
  }

  // display ball
  SDL_BlitSurface(m_sprites, &srcBall, m_windowSurface, &ballRect);

  // move the ball
  ball->move(player);

  // player
  SDL_BlitSurface(m_sprites, &player->getSrc(), m_windowSurface, &pRect);

  // display bricks
  for (int i = 0; i < m_bricks.size(); i++) {
    SDL_Rect bRect = m_bricks.at(i).getRect();
    SDL_BlitSurface(m_sprites, &m_bricks.at(i).getSrc(), m_windowSurface,
                    &bRect);

    if (m_bricks.at(i).checkCollision(*ball)) {
      m_game->addPointsToGame(m_bricks.at(i).getPoints());
      m_bricks.erase(m_bricks.begin() + i--);
    }
  }

  if (m_bricks.size() <= 0) {
    m_game->nextLevel();
  }

  // display lives
  for (int i = 1; i < player->getLives(); i++) {
    dest.x = 30 + (i - 1) * 30;
    dest.y = m_windowSurface->h - 20;
    SDL_BlitSurface(m_sprites, &m_srcLive, m_windowSurface, &dest);
  }

  // display informations on game (points, level)
  GraphicManager::printText(m_width - 100, 20, m_spritesAscii, m_windowSurface,
                            level);

  GraphicManager::printText(m_width - 250, 70, m_spritesAscii, m_windowSurface,
                            std::to_string(m_game->getGamePoints()) +
                                " points");
}

// update window surface
void WindowManager::update() {
  SDL_UpdateWindowSurface(m_window);
  SDL_Delay(20); // 50 fps
}

// get window width
int WindowManager::getWindowWidth() const { return m_windowSurface->w; }

// get window height
int WindowManager::getWindowHeight() const { return m_windowSurface->h; }
