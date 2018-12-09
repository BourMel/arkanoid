#include <iostream>

#include "eventmanager.h"
#include "ball.h"
#include "game.h"
#include "graphicmanager.h"
#include "player.h"

EventManager::EventManager() : m_quit(false) {}
EventManager::EventManager(Game *game) : m_game(game), m_quit(false) {}

/**
 * Depending on the current screen, call the right function to
 * handle the events
 */
void EventManager::listen() {
  while (!m_quit && SDL_PollEvent(&m_event)) {
    switch (m_game->getCurrentScreen()) {
    case Game::SCREEN_WIN:
      listenWin();
      break;
    case Game::SCREEN_LOSE:
      listenLose();
      break;
    case Game::SCREEN_LEVEL:
      listenLevel();
      break;
    case Game::SCREEN_MENU:
    default:
      listenMenu();
      break;
    }
  }
}

/**
 * Handle Menu events : quit, go to first level...
 */
void EventManager::listenMenu() {
  switch (m_event.type) {

  case SDL_QUIT:
    setQuit(true);
    break;
  case SDL_KEYDOWN:
    switch (m_event.key.keysym.sym) {
    case SDLK_RETURN:
      m_game->setCurrentScreen(Game::SCREEN_LEVEL);
      m_game->getWindowManager()->readLevelFile(1);
      break;
    case SDLK_q:
    case SDLK_ESCAPE:
      setQuit(true);
      break;
    default:
      break;
    }
    break;
  case SDL_MOUSEBUTTONDOWN:
    m_game->setCurrentScreen(Game::SCREEN_LEVEL);
    m_game->getWindowManager()->readLevelFile(1);
    break;
  default:
    break;
  }
}

/**
 * Handle events on winning screen : return to menu or quit
 */
void EventManager::listenWin() {
  switch (m_event.type) {
  case SDL_QUIT:
    setQuit(true);
    break;
  case SDL_KEYDOWN:
    switch (m_event.key.keysym.sym) {
    case SDLK_RETURN:
      m_game->setCurrentScreen(Game::SCREEN_MENU);
      break;
    case SDLK_q:
    case SDLK_ESCAPE:
      setQuit(true);
      break;
    default:
      break;
    }
    break;
  case SDL_MOUSEBUTTONDOWN:
    m_game->setCurrentScreen(Game::SCREEN_MENU);
    break;
  default:
    break;
  }
}

/**
 * Handle events on gameOver screen : return to menu, exit...
 */
void EventManager::listenLose() {
  switch (m_event.type) {
  case SDL_QUIT:
    setQuit(true);
    break;
  case SDL_KEYDOWN:
    switch (m_event.key.keysym.sym) {
    case SDLK_RETURN:
      m_game->setCurrentScreen(Game::SCREEN_MENU);
      break;
    case SDLK_q:
    case SDLK_ESCAPE:
      setQuit(true);
      break;
    default:
      break;
    }
    break;
  case SDL_MOUSEBUTTONDOWN:
    m_game->setCurrentScreen(Game::SCREEN_MENU);
    break;
  default:
    break;
  }
}

/**
 * Listen to events in game : allows the player to move
 */
void EventManager::listenLevel() {
  Player *player = m_game->getPlayer();
  Ball *ball = m_game->getBall();

  switch (m_event.type) {
  case SDL_QUIT:
    setQuit(true);
    break;
  case SDL_KEYDOWN:
    switch (m_event.key.keysym.sym) {

    // move player
    case SDLK_LEFT:
      player->setX(player->getX() - 10);
      break;
    case SDLK_RIGHT:
      player->setX(player->getX() + 10);
      break;

    // remove magnet mode
    case SDLK_SPACE:
      ball->setMoving(true);
      break;
    // case SDLK_1:
    //   player->setSprite(GraphicManager::PLAYER_1);
    //   break;
    // case SDLK_2:
    //   player->setSprite(GraphicManager::PLAYER_2);
    //   break;
    // case SDLK_3:
    //   player->setSprite(GraphicManager::PLAYER_3);
    //   break;
    // case SDLK_4:
    //   player->setSprite(GraphicManager::PLAYER_4);
    //   break;
    // case SDLK_5:
    //   player->setSprite(GraphicManager::PLAYER_5);
    //   break;
    // case SDLK_6:
    //   player->setSprite(GraphicManager::PLAYER_6);
    //   break;
    // case SDLK_7:
    //   player->setSprite(GraphicManager::PLAYER_7);
    //   break;
    // case SDLK_8:
    //   player->setSprite(GraphicManager::PLAYER_8);
    //   break;

    // cylinderMode
    case SDLK_c:
      m_game->toggleCylinderMode();
      break;

    // pass to next level
    case SDLK_n:
      m_game->nextLevel();
      break;

    // quit game
    case SDLK_q:
    case SDLK_ESCAPE:
      setQuit(true);
      break;
    default:
      break;
    }
    break;

  // same commands with mouse
  case SDL_MOUSEMOTION:
    player->setX(m_event.motion.x - (player->getRect().w / 2));
    break;
  case SDL_MOUSEBUTTONDOWN:
    ball->setMoving(true);
    break;
  default:
    break;
  }
}

/**
 * Change the m_quit value, which is used to know when to exit the game
 */
void EventManager::setQuit(bool value) { m_quit = value; }

/**
 * Get m_quit value
 */
bool EventManager::getQuit() { return m_quit; }
