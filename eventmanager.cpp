#include "eventmanager.h"
#include "board.h"
#include "player.h"
#include <SDL2/SDL.h>
#include <iostream>

EventManager::EventManager() : m_quit(false) {}

void EventManager::listen(Board &board) {
  Player &player = board.getPlayer();
  Ball &ball = board.getBall();

  while (!m_quit && SDL_PollEvent(&m_event)) {
    switch (m_event.type) {
    case SDL_QUIT:
      set_quit(true);
      break;
    case SDL_KEYDOWN:
      switch (m_event.key.keysym.sym) {
      // touche clavier
      case SDLK_LEFT:
        player.set_x(player.get_x() - 10);
        break;
      case SDLK_RIGHT:
        player.set_x(player.get_x() + 10);
        break;
      case SDLK_SPACE:
        ball.set_moving();
        break;
      case SDLK_ESCAPE:
        set_quit(true);
        break;
      default:
        break;
      }
      break;
    case SDL_MOUSEMOTION:
      player.set_x(player.get_x() + m_event.motion.xrel);
      break;
    case SDL_MOUSEBUTTONDOWN:
      ball.set_moving();
      break;
    default:
      break;
    }
  }
}

void EventManager::set_quit(bool value) { m_quit = value; }

bool EventManager::get_quit() { return m_quit; }
