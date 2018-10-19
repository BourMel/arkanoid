#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "player.h"
#include <SDL2/SDL.h>

class Game;

class EventManager {
public:
  EventManager();
  EventManager(Game *game);

  void listen();

  void set_quit(bool value);
  bool get_quit();

private:
  SDL_Event m_event;
  bool m_quit;
  Game *m_game;
};

#endif // EVENTMANAGER_H
