#include "eventmanager.h"
#include "ball.h"
#include "game.h"
#include "graphicmanager.h"
#include "player.h"
#include <SDL2/SDL.h>
#include <iostream>

EventManager::EventManager() : m_quit(false) {}
EventManager::EventManager(Game *game) : m_game(game), m_quit(false) {}

void EventManager::listen() {
  Player *player = m_game->getPlayer();
  Ball *ball = m_game->getBall();

  while (!m_quit && SDL_PollEvent(&m_event)) {
    switch (m_event.type) {
    case SDL_QUIT:
      setQuit(true);
      break;
    case SDL_KEYDOWN:
      switch (m_event.key.keysym.sym) {
      case SDLK_LEFT:
        player->setX(player->getX() - 10);
        break;
      case SDLK_RIGHT:
        player->setX(player->getX() + 10);
        break;
      case SDLK_SPACE:
        ball->setMoving();
        break;
      case SDLK_1:
        player->setSprite(GraphicManager::PLAYER_1);
        break;
      case SDLK_2:
        player->setSprite(GraphicManager::PLAYER_2);
        break;
      case SDLK_3:
        player->setSprite(GraphicManager::PLAYER_3);
        break;
      case SDLK_4:
        player->setSprite(GraphicManager::PLAYER_4);
        break;
      case SDLK_5:
        player->setSprite(GraphicManager::PLAYER_5);
        break;
      case SDLK_6:
        player->setSprite(GraphicManager::PLAYER_6);
        break;
      case SDLK_7:
        player->setSprite(GraphicManager::PLAYER_7);
        break;
      case SDLK_8:
        player->setSprite(GraphicManager::PLAYER_8);
        break;
      case SDLK_c: // cylinderMode
        m_game->toggleCylinderMode();
        break;
      case SDLK_RETURN:
        m_game->setCurrentScreen(Game::SCREEN_LEVEL);
        break;
      case SDLK_q:
      case SDLK_ESCAPE:
        setQuit(true);
        break;
      default:
        break;
      }
      break;
    case SDL_MOUSEMOTION:
      player->setX(player->getX() + m_event.motion.xrel);
      break;
    case SDL_MOUSEBUTTONDOWN:
      ball->setMoving();
      break;
    default:
      break;
    }
  }
}

void EventManager::setQuit(bool value) { m_quit = value; }

bool EventManager::getQuit() { return m_quit; }
