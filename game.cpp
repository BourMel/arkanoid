#include "game.h"
#include <iostream>

#define NB_LEVELS 5

Game::Game()
    : m_currentScreen(SCREEN_MENU), m_level(1), m_points(0),
      m_cylinderMode(false), m_wm(nullptr), m_em(nullptr), m_player(nullptr),
      m_ball(nullptr) {}

Game::~Game() {
  delete m_wm;
  delete m_em;
  delete m_player;
  delete m_ball;
}

void Game::run() {
  m_wm = new WindowManager(this);
  m_em = new EventManager(this);
  m_player = new Player(this);
  m_ball = new Ball(this);

  while (!m_em->getQuit()) {
    m_em->listen();
    switch (m_currentScreen) {
    case SCREEN_LEVEL:
      m_wm->drawLevel();
      break;
    case SCREEN_WIN:
      m_wm->drawWin();
      break;
    case SCREEN_LOSE:
      m_wm->drawLose();
      break;
    case SCREEN_MENU:
    default:
      m_wm->drawMenu();
      break;
    }
    m_wm->update();
  }

  SDL_Quit();
}

bool Game::getCylinderMode() const { return m_cylinderMode; }
void Game::toggleCylinderMode() { m_cylinderMode = !m_cylinderMode; }
void Game::addPointsToGame(int points) { m_points += points; }
int Game::getGamePoints() const { return m_points; }

WindowManager *Game::getWindowManager() const { return m_wm; }
EventManager *Game::getEventManager() const { return m_em; }
Player *Game::getPlayer() const { return m_player; }
Ball *Game::getBall() const { return m_ball; }

void Game::setCurrentScreen(screen s) { m_currentScreen = s; }
Game::screen Game::getCurrentScreen() const { return m_currentScreen; }

int Game::getLevel() const { return m_level; }

void Game::nextLevel() {
  m_ball->setMoving(false);
  if (m_level == NB_LEVELS) { // if it was the last level, the player won!
    m_currentScreen = SCREEN_WIN;
    reset();
  } else {
    m_wm->readLevelFile(++m_level); // read next level file
  }
}

/**
 * Reset game informations
 */
void Game::reset() {
  m_points = 0;
  m_level = 1;
  m_player->reset();
}
