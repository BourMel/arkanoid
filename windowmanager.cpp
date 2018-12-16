#include <cstdlib>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

#include "ball.h"
#include "bonus.h"
#include "brick.h"
#include "brick_types.h"
#include "game.h"
#include "graphicmanager.h"
#include "player.h"
#include "sprite.h"
#include "windowmanager.h"

WindowManager::WindowManager()
    : m_window(nullptr), m_windowSurface(nullptr), m_sprites(nullptr),
      m_srcBg(Sprite::get(Sprite::Type::BG1)), m_width(416), m_height(550),
      m_height_start(70), m_nbLines(0), m_nbColumns(0) {
  init();
}

WindowManager::WindowManager(Game *game)
    : m_game(game), m_window(nullptr), m_windowSurface(nullptr),
      m_sprites(nullptr), m_srcBg(Sprite::get(Sprite::Type::BG1)), m_width(416),
      m_height_start(70), m_height(550), m_nbLines(0), m_nbColumns(0) {
  init();
}

/**
 * Init SDL window
 */
void WindowManager::init() {
  m_window = GraphicManager::createWindow(m_width, m_height);
  m_windowSurface = GraphicManager::getWindowSurface(m_window);
  m_now = GraphicManager::getPerformanceCounter();

  m_sprites = SDL_LoadBMP("./sprites.bmp");
  SDL_SetColorKey(m_sprites, true, 0); // 0: 00/00/00 black -> transparent

  m_srcLive = Sprite::get(Sprite::Type::PLAYER_LIFE);

  readLevelFile(1);
}

/**
 * Read file representing a level and use it to build it
 */
void WindowManager::readLevelFile(int level) {
  int background;

  // clear all content
  m_bricks.clear();
  m_undestructibleBricks.clear();
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
  f >> background;

  // choose right sprite for background
  switch (background) {
  case 2:
    m_srcBg = Sprite::get(Sprite::Type::BG2);
    break;
  case 3:
    m_srcBg = Sprite::get(Sprite::Type::BG3);
    break;
  case 4:
    m_srcBg = Sprite::get(Sprite::Type::BG4);
    break;
  case 5:
    m_srcBg = Sprite::get(Sprite::Type::BG5);
    break;
  case 6:
    m_srcBg = Sprite::get(Sprite::Type::BG6);
    break;
  case 1:
  default:
    m_srcBg = Sprite::get(Sprite::Type::BG1);
    break;
  }

  int x;
  int nbBricks(0);

  // number of bricks required to center the level in the window
  // since all levels can have a different width
  // 13 = max number of bricks
  int completeBricks = (int)((13 - m_nbColumns) / 2);

  while (f >> x) {
    if (x > 0) {
      int line = nbBricks / m_nbColumns;
      // completeBricks adds enough space to center the level
      int col = completeBricks + nbBricks % m_nbColumns;

      switch (x) {
      case 1:
        m_bricks.push_back(std::shared_ptr<Brick>(new Brick1(line, col)));
        break;
      case 2:
        m_bricks.push_back(std::shared_ptr<Brick>(new Brick2(line, col)));
        break;
      case 3:
        m_bricks.push_back(std::shared_ptr<Brick>(new Brick3(line, col)));
        break;
      case 4:
        m_bricks.push_back(std::shared_ptr<Brick>(new Brick4(line, col)));
        break;
      case 5:
        m_bricks.push_back(std::shared_ptr<Brick>(new Brick5(line, col)));
        break;
      case 6:
        m_bricks.push_back(std::shared_ptr<Brick>(new Brick6(line, col)));
        break;
      case 7:
        m_bricks.push_back(std::shared_ptr<Brick>(new Brick7(line, col)));
        break;
      case 8:
        m_bricks.push_back(std::shared_ptr<Brick>(new Brick8(line, col)));
        break;
      case 9:
        m_bricks.push_back(std::shared_ptr<Brick>(new Brick9(line, col)));
        break;
      case 10:
        m_bricks.push_back(std::shared_ptr<Brick>(new Brick10(line, col)));
        break;
      case 11:
        m_bricks.push_back(std::shared_ptr<Brick>(new Brick11(line, col)));
        break;
      case 12:
        m_bricks.push_back(std::shared_ptr<Brick>(new Brick12(line, col)));
        break;
      case 13:
        m_bricks.push_back(
            std::shared_ptr<Brick>(new Brick13(m_game, line, col)));
        break;
      case 14:
        m_undestructibleBricks.push_back(
            std::shared_ptr<Brick>(new Brick14(line, col)));
        break;
      default:
        // do nothing
        break;
      }
    }
    nbBricks++;
  }
}

/**
 * Draw screen menu
 */
void WindowManager::drawMenu() {
  Box logoSrc = Sprite::get(Sprite::LOGO);
  Box logoRect = {70, 150, logoSrc.w, logoSrc.h};

  GraphicManager::setBlackBackground();
  SDL_BlitSurface(m_sprites, &logoSrc, m_windowSurface, &logoRect);
  GraphicManager::printText(m_width / 2 - 190, 400, m_sprites, m_windowSurface,
                            "Press ENTER to begin");
}

/**
 * Draw "congratulations" screen
 */
void WindowManager::drawWin() {
  GraphicManager::setBlackBackground();
  GraphicManager::printText(m_width / 2 - 150, 200, m_sprites, m_windowSurface,
                            "Congratulations");
  GraphicManager::printText(m_width / 2 - 170, 400, m_sprites, m_windowSurface,
                            "Restart with ENTER");
}

/**
 * Draw "game over" screen
 */
void WindowManager::drawLose() {
  GraphicManager::setBlackBackground();
  GraphicManager::printText(m_width / 2 - 90, 200, m_sprites, m_windowSurface,
                            "Game Over");
  GraphicManager::printText(m_width / 2 - 170, 400, m_sprites, m_windowSurface,
                            "Restart with ENTER");
}

/**
 * Draw level (actual game)
 */
void WindowManager::drawLevel() {
  Player *player = m_game->getPlayer();
  Box pRect = player->getRect();
  std::string level = std::to_string(m_game->getLevel());

  GraphicManager::setBackgroud(0x302C2C);

  // background
  Box dest = {0, 0, 0, 0};

  for (int j = m_height_start; j < m_windowSurface->h; j += m_srcBg.h) {
    for (int i = 0; i < m_windowSurface->w; i += m_srcBg.w) {
      dest.x = i;
      dest.y = j;
      SDL_BlitSurface(m_sprites, &m_srcBg, m_windowSurface, &dest);
    }
  }

  // shadow in background
  Box shadow = {m_srcBg.x, m_srcBg.y + m_srcBg.h, m_srcBg.w, 10};
  dest = {0, m_height_start, 0, 0};

  for (int i = 0; i < m_windowSurface->w; i += shadow.w) {
    dest.x = i;
    SDL_BlitSurface(m_sprites, &shadow, m_windowSurface, &dest);
  }

  // top of the screen
  Box topSprite = Sprite::get(Sprite::Type::TOP);
  dest = {0, m_height_start - topSprite.h, 0, 0};

  for (int i = 0; i < m_windowSurface->w; i += topSprite.w) {
    dest.x = i;
    SDL_BlitSurface(m_sprites, &topSprite, m_windowSurface, &dest);
  }

  // display and move all balls
  for (auto ball : m_game->getBalls()) {
    Box ballRect = ball->getRect();
    Box srcBall = ball->getSrc();

    // display ball
    SDL_BlitSurface(m_sprites, &srcBall, m_windowSurface, &ballRect);

    // move the ball
    ball->move(player);
  }

  // player
  SDL_BlitSurface(m_sprites, &player->getSrc(), m_windowSurface, &pRect);

  // a better random engine
  std::random_device rd;
  std::mt19937 e{rd()};
  std::uniform_int_distribution<int> dist3{0, 3};
  std::uniform_int_distribution<int> dist7{0, 7};

  // display undestructable bricks
  for (int i = 0; i < m_undestructibleBricks.size(); i++) {
    std::shared_ptr<Brick> currentBrick = m_undestructibleBricks.at(i);
    Box bRect = currentBrick->getRect();
    SDL_BlitSurface(m_sprites, &currentBrick->getSrc(), m_windowSurface,
                    &bRect);
    currentBrick->drawCallback();

    // handle the brick-ball collision
    for (auto ball : m_game->getBalls()) {
      currentBrick->checkCollision(*ball);
    }
  }

  // display bricks
  for (int i = 0; i < m_bricks.size(); i++) {
    std::shared_ptr<Brick> currentBrick = m_bricks.at(i);
    Box bRect = currentBrick->getRect();
    SDL_BlitSurface(m_sprites, &currentBrick->getSrc(), m_windowSurface,
                    &bRect);
    currentBrick->drawCallback();

    // handle the brick-balls collision
    for (auto ball : m_game->getBalls()) {
      if (currentBrick->checkCollision(*ball)) {

        // adds a bonus to the level
        if (!dist3(e)) {
          // spawn a random bonus type
          switch (dist7(e)) {
          case 0:
            m_bonus.push_back(
                std::shared_ptr<Bonus>(new BonusS(m_game, bRect)));
            break;
          case 1:
            m_bonus.push_back(
                std::shared_ptr<Bonus>(new BonusC(m_game, bRect)));
            break;
          case 2:
            m_bonus.push_back(
                std::shared_ptr<Bonus>(new BonusL(m_game, bRect)));
            break;
          case 3:
            m_bonus.push_back(
                std::shared_ptr<Bonus>(new BonusE(m_game, bRect)));
            break;
          case 4:
            m_bonus.push_back(
                std::shared_ptr<Bonus>(new BonusD(m_game, bRect)));
            break;
          case 5:
            m_bonus.push_back(
                std::shared_ptr<Bonus>(new BonusB(m_game, bRect)));
            break;
          case 6:
            m_bonus.push_back(
                std::shared_ptr<Bonus>(new BonusP(m_game, bRect)));
            break;
          default:
            // do nothing
            break;
          }
        }

        m_game->addPointsToGame(currentBrick->getPoints());
        m_bricks.erase(m_bricks.begin() + i--);
      }
    }

    // check collision with lasers
    for (int j = 0; j < m_lasers.size(); j++) {
      std::shared_ptr<Laser> currentLaser = m_lasers.at(j);

      // check laser-brick collision
      if (SDL_HasIntersection(&currentLaser->getRect(),
                              &currentBrick->getRect())) {

        // add points for destructing this brick
        m_game->addPointsToGame(currentBrick->getPoints());

        // delete both if they collide
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
    std::shared_ptr<Bonus> current = m_bonus.at(i);
    Box current_rect = current->getRect();
    current->drawCallback();

    SDL_BlitSurface(m_sprites, &current->getSrc(), m_windowSurface,
                    &current_rect);

    // check bonus-player collision
    if (SDL_HasIntersection(&current->getRect(),
                            &m_game->getPlayer()->getRect())) {
      m_game->resetBonus();
      current->action();
      m_game->addPointsToGame(1000);

      if (m_bonus.size()) {
        m_bonus.erase(m_bonus.begin() + i--);
      }

      // start timer
      Bonus::activeBonus = true;
      Bonus::initTimer();
    }

    // remove bonus if it goes outside the window
    if (current->getRect().y >= m_windowSurface->h) {
      m_bonus.erase(m_bonus.begin() + i--);
    }
  }

  // display lasers
  for (int i = 0; i < m_lasers.size(); i++) {
    std::shared_ptr<Laser> current = m_lasers.at(i);
    Box lRect = current->getRect();
    SDL_BlitSurface(m_sprites, &current->getSrc(), m_windowSurface, &lRect);
    current->drawCallback();

    // remove laser if it goes outside the window
    if (current->getRect().y <=
        m_game->getWindowManager()->getWindowHeightStart()) {
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
  GraphicManager::printText(m_width - 100, 10, m_sprites, m_windowSurface,
                            level);

  GraphicManager::printText(40, 10, m_sprites, m_windowSurface,
                            std::to_string(m_game->getGamePoints()) +
                                " points");
}

// update window surface
void WindowManager::update() {
  SDL_UpdateWindowSurface(m_window);

  m_prev = m_now;
  m_now = GraphicManager::getPerformanceCounter();
  m_deltaTime =
      (double)((m_now - m_prev) * 1000 / (double)SDL_GetPerformanceFrequency());

  if (m_deltaTime < 20) {
    SDL_Delay(20 - m_deltaTime);
    m_now = GraphicManager::getPerformanceCounter();
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
  Box position = player->getRect();

  // check there is no lasers left in the game
  if (m_lasers.size() > 0)
    return;

  std::shared_ptr<Laser> l1(new Laser(position));
  std::shared_ptr<Laser> l2(
      new Laser({position.x + position.w, position.y, position.w, position.h}));
  m_lasers.push_back(l1);
  m_lasers.push_back(l2);
}
