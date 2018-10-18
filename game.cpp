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

  Board board(*m_player, *m_ball);

  while (!m_em->get_quit()) {
    m_em->listen(board);
    m_wm->draw(board);
    m_wm->update();
  }

  SDL_Quit();
}

WindowManager *Game::getWindowManager() const { return m_wm; }
