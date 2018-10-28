#include "game.h"
#include <iostream>

Game::Game()
    : m_currentScreen(SCREEN_MENU), m_level(0), m_lives(3), m_points(0),
      m_cylinderMode(false) {
  init();
}

Game::~Game() {
  delete m_wm;
  delete m_em;
  delete m_player;
  delete m_ball;
}

void Game::init() {
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
