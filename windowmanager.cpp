#include <SDL2/SDL.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

#include "bonus.h"
#include "brick.h"
#include "brick_types.h"
#include "game.h"
#include "graphicmanager.h"
#include "player.h"
#include "windowmanager.h"

WindowManager::WindowManager()
    : m_window(nullptr), m_windowSurface(nullptr), m_sprites(nullptr),
      m_srcBg({0, 128, 48, 64}), m_width(600), m_height(600),
      m_height_start(50), m_nbLines(0), m_nbColumns(0) {
  init();
}

WindowManager::WindowManager(Game *game)
    : m_game(game), m_window(nullptr), m_windowSurface(nullptr),
      m_sprites(nullptr), m_srcBg({0, 128, 48, 64}), m_width(600),
      m_height_start(50), m_height(600), m_nbLines(0), m_nbColumns(0) {
  init();
}

/**
 * Init SDL window
 */
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

  m_now = SDL_GetPerformanceCounter();

  m_sprites = SDL_LoadBMP("./sprites.bmp");
  m_spritesAscii = SDL_LoadBMP("./ascii.bmp");
  SDL_SetColorKey(m_sprites, true, 0); // 0: 00/00/00 black -> transparent
  SDL_SetColorKey(m_spritesAscii, true, 0);

  m_srcLive =
      GraphicManager::getSprite(GraphicManager::SpriteType::PLAYER_LIFE);

  readLevelFile(1);
}

/**
 * Read file representing a level and use it to build it
 */
void WindowManager::readLevelFile(int level) {
  m_bricks.clear(); // clear bricks
  m_bonus.clear();

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

/**
 * Draw screen menu
 */
void WindowManager::drawMenu() {
  // fill the screen with black
  SDL_FillRect(SDL_GetWindowSurface(m_window), NULL, 0);

  GraphicManager::printText(200, 200, m_spritesAscii, m_windowSurface,
                            "Arkanoid");

  GraphicManager::printText(m_width / 2 - 190, 400, m_spritesAscii,
                            m_windowSurface, "Press ENTER to begin");
}

/**
 * Draw "congratulations" screen
 */
void WindowManager::drawWin() {
  // fill the screen with black
  SDL_FillRect(SDL_GetWindowSurface(m_window), NULL, 0);

  GraphicManager::printText(m_width / 2 - 150, 200, m_spritesAscii,
                            m_windowSurface, "Congratulations");

  GraphicManager::printText(m_width / 2 - 230, 400, m_spritesAscii,
                            m_windowSurface, "Return to menu with ENTER");
}

/**
 * Draw "game over" screen
 */
void WindowManager::drawLose() {
  // fill the screen with black
  SDL_FillRect(SDL_GetWindowSurface(m_window), NULL, 0);

  GraphicManager::printText(m_width / 2 - 90, 200, m_spritesAscii,
                            m_windowSurface, "Game Over");

  GraphicManager::printText(m_width / 2 - 230, 400, m_spritesAscii,
                            m_windowSurface, "Return to menu with ENTER");
}

/**
 * Draw level (actual game)
 */
void WindowManager::drawLevel() {
  Player *player = m_game->getPlayer();
  SDL_Rect pRect = player->getRect();
  Ball *ball = m_game->getBall();
  SDL_Rect ballRect = ball->getRect();
  SDL_Rect srcBall = ball->getSrc();
  std::string level = std::to_string(m_game->getLevel());

  SDL_Rect dest = {0, 0, 0, 0};

  SDL_FillRect(m_windowSurface, NULL, 0x302C2C);

  // background
  for (int j = m_height_start; j < m_windowSurface->h; j += m_srcBg.h) {
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

  std::random_device rd;
  std::mt19937 e{rd()};
  std::uniform_int_distribution<int> dist3{0, 3};
  std::uniform_int_distribution<int> dist7{0, 7};

  // display bricks
  for (int i = 0; i < m_bricks.size(); i++) {
    Brick currentbrick = m_bricks.at(i);
    SDL_Rect bRect = currentbrick.getRect();
    SDL_BlitSurface(m_sprites, &currentbrick.getSrc(), m_windowSurface, &bRect);

    // handle the brick-ball collision
    if (currentbrick.checkCollision(*ball)) {

      // adds a bonus to the level
      if (!dist3(e)) {
        Bonus *bonus;

        // spawn a random bonus type
        switch (dist7(e)) {
        case 0:
          bonus = new BonusS(m_game, bRect);
          break;
        case 1:
          bonus = new BonusC(m_game, bRect);
          break;
        case 2:
          bonus = new BonusL(m_game, bRect);
          break;
        case 3:
          bonus = new BonusE(m_game, bRect);
          break;
        case 4:
          bonus = new BonusD(m_game, bRect);
          break;
        case 5:
          bonus = new BonusB(m_game, bRect);
          break;
        case 6:
          bonus = new BonusP(m_game, bRect);
          break;
        default:
          goto nobonus;
        }

        m_bonus.push_back(bonus);
      }

    nobonus:
      m_game->addPointsToGame(currentbrick.getPoints());
      m_bricks.erase(m_bricks.begin() + i--);
    }

    // check collision with lasers
    for(int j=0; j<m_lasers.size(); j++){
      Laser* currentLaser = m_lasers.at(j);

      // check laser-brick collision
      if (SDL_HasIntersection(&currentLaser->getRect(),
                              &currentbrick.getRect())) {

        // delete both if they collide
        delete currentLaser;

        if (m_lasers.size()) {
          m_lasers.erase(m_lasers.begin() + j--);
        }
        if (m_bricks.size()) {
          m_bricks.erase(m_bricks.begin() + i--);
        }
      }

    }
  }

  // bonus timer
  if (Bonus::isTimeUp()) {
    // stop non cumulative bonus
    m_game->resetBonus();
  }

  // display bonus & make them fall
  for (int i = 0; i < m_bonus.size(); i++) {
    Bonus *current = m_bonus.at(i);
    SDL_Rect current_rect = current->getRect();
    current->drawCallback();

    SDL_BlitSurface(m_sprites, &current->getSrc(), m_windowSurface,
                    &current_rect);

    // check bonus-player collision
    if (SDL_HasIntersection(&current->getRect(),
                            &m_game->getPlayer()->getRect())) {
      m_game->resetBonus();
      current->action();
      m_game->addPointsToGame(1000);
      delete current;

      if (m_bonus.size()) {
        m_bonus.erase(m_bonus.begin() + i--);
      }

      // start timer
      Bonus::active_bonus = true;
      Bonus::initTimer();
    }

    // remove bonus if it goes outside the window
    if (current->getRect().y >= m_windowSurface->h) {
      delete current;
      m_bonus.erase(m_bonus.begin() + i--);
    }
  }

  // display lasers
  for (int i = 0; i < m_lasers.size(); i++) {
    Laser *current = m_lasers.at(i);
    SDL_Rect lRect = current->getRect();
    SDL_BlitSurface(m_sprites, &current->getSrc(), m_windowSurface, &lRect);
    current->drawCallback();

    // remove laser if it goes outside the window
    if (current->getRect().y <= 0) {
      delete current;
      m_lasers.erase(m_lasers.begin() + i--);
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
  GraphicManager::printText(m_width - 100, 10, m_spritesAscii, m_windowSurface,
                            level);

  GraphicManager::printText(40, 10, m_spritesAscii, m_windowSurface,
                            std::to_string(m_game->getGamePoints()) +
                                " points");
}

// update window surface
void WindowManager::update() {
  SDL_UpdateWindowSurface(m_window);

  m_prev = m_now;
  m_now = SDL_GetPerformanceCounter();
  m_deltaTime =
      (double)((m_now - m_prev) * 1000 / (double)SDL_GetPerformanceFrequency());

  if (m_deltaTime < 20) {
    SDL_Delay(20 - m_deltaTime);
    m_now = SDL_GetPerformanceCounter();
    m_deltaTime = (double)((m_now - m_prev) * 1000 /
                           (double)SDL_GetPerformanceFrequency());
  }
}

// get window width
int WindowManager::getWindowWidth() const { return m_windowSurface->w; }

// get window height
int WindowManager::getWindowHeight() const { return m_windowSurface->h; }

// get window height start
int WindowManager::getWindowHeightStart() const { return m_height_start; }

void WindowManager::addLasers() {
  Player *player = m_game->getPlayer();
  SDL_Rect position = player->getRect();

  // check there is no lasers left in the game
  if(m_lasers.size() > 0) return;

  Laser *l1 = new Laser(position);
  Laser *l2 =
      new Laser({position.x + position.w, position.y, position.w, position.h});
  m_lasers.push_back(l1);
  m_lasers.push_back(l2);
}
