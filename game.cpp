#include "game.h"
#include <iostream>

Game::Game() { init(); }

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

  m_level = 1;
  m_lives = 3;
  m_cylinderMode = false;

  while (!m_em->get_quit()) {
    m_em->listen();
    m_wm->draw();
    m_wm->update();
  }

  SDL_Quit();
}

bool Game::getCylinderMode() const { return m_cylinderMode; }
void Game::toggleCylinderMode() { m_cylinderMode = !m_cylinderMode; }

WindowManager *Game::getWindowManager() const { return m_wm; }
EventManager *Game::getEventManager() const { return m_em; }
Player *Game::getPlayer() const { return m_player; }
Ball *Game::getBall() const { return m_ball; }
