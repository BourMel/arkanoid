#include "eventmanager.h"
#include "player.h"
#include <SDL2/SDL.h>
#include <iostream>

EventManager::EventManager() {}

void EventManager::listen(Player &player) {
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
        std::cout << "déplacement gauche. pos=" << player.get_x() << std::endl;
        break;
      case SDLK_RIGHT:
        player.set_x(player.get_x() + 10);
        std::cout << "déplacement droite. pos=" << player.get_x() << std::endl;
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
      std::cout << "mouse click " << m_event.button.button << std::endl;
      break;
    default:
      break;
    }
  }
}

void EventManager::set_quit(bool value) { m_quit = value; }

bool EventManager::get_quit() { return m_quit; }
