#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <SDL2/SDL.h>
#include "player.h"

class EventManager {
public:
  EventManager();
  void listen(Player& player);

  void set_quit(bool value);
  bool get_quit();

private:
  SDL_Event m_event;
  bool m_quit;
};

#endif // EVENTMANAGER_H
