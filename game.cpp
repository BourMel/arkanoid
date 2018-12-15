#include <iostream>

#include "game.h"
#include "laser.h"

#define NB_LEVELS 8

Game::Game()
    : m_currentScreen(SCREEN_MENU), m_level(1), m_points(0),
      m_cylinderMode(false), m_wm(nullptr), m_em(nullptr), m_player(nullptr) {}

Game::~Game() {
  delete m_wm;
  delete m_em;
  delete m_player;
}

/**
 * draw the right screen
 */
void Game::run() {
  m_wm = new WindowManager(this);
  m_em = new EventManager(this);
  m_player = new Player(this);

  m_balls.push_back(std::shared_ptr<Ball>(new Ball(this)));

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

/**
 * Get the value of cylinder mode
 */
bool Game::getCylinderMode() const { return m_cylinderMode; }

/**
 * Toggle cylinder mode
 */
void Game::toggleCylinderMode() { m_cylinderMode = !m_cylinderMode; }

/**
 * Add a given value to points
 */
void Game::addPointsToGame(int points) { m_points += points; }

/**
 * Get current points in game
 */
int Game::getGamePoints() const { return m_points; }

/**
 * Get instance of window manager
 */
WindowManager *Game::getWindowManager() const { return m_wm; }

/**
 * Get instance of event manager
 */
EventManager *Game::getEventManager() const { return m_em; }

/**
 * Get instance of player
 */
Player *Game::getPlayer() const { return m_player; }

/**
 * Get all balls instances
 */
std::vector<std::shared_ptr<Ball>> Game::getBalls() const { return m_balls; }

/**
 * Change current screen
 */
void Game::setCurrentScreen(screen s) { m_currentScreen = s; }

/**
 * Get current screeen
 */
Game::screen Game::getCurrentScreen() const { return m_currentScreen; }

/**
 * Get current level
 */
int Game::getLevel() const { return m_level; }

/**
 * Pass to next level
 */
void Game::nextLevel() {
  for (auto ball : m_balls) {
    ball->setMoving(false);
  }
  resetAllBonus();
  if (m_level == NB_LEVELS) { // if it was the last level, the player won!
    m_currentScreen = SCREEN_WIN;
    reset();
  } else {
    // read next level file
    m_wm->readLevelFile(++m_level);
  }
}

/**
 * Reset game informations
 */
void Game::reset() {
  m_points = 0;
  m_level = 1;
  m_player->reset();
  resetAllBonus();
}

/**
 * Remove all bonus actions EXCEPT cumulative ones (E has multiple states)
 */
void Game::resetBonus() {
  m_player->setCatchBall(false);
  for (auto ball : m_balls) {
    ball->resetSpeed();
  }
  Laser::setState(false);
}

/**
 * Remove all bonus actions
 */
void Game::resetAllBonus() {
  resetBonus();
  m_player->setSprite(GraphicManager::PLAYER_1);

  // only one ball
  m_balls.clear();
  m_balls.push_back(std::shared_ptr<Ball>(new Ball(this)));
}

/**
 * Spawn three balls
 */
void Game::threeBalls() {
  for (int i = m_balls.size(); i < 3; i++) {
    m_balls.push_back(
        std::shared_ptr<Ball>(new Ball(this, m_balls.at(0).get())));
  }
}

/**
 * Remove a specific ball
 */
void Game::removeBall(Ball *b) {
  if (m_balls.size() <= 1)
    return;
  for (int i = 0; i < m_balls.size(); i++) {
    if (m_balls.at(i).get() == b) {
      m_balls.erase(m_balls.begin() + i--);
    }
  }
}
