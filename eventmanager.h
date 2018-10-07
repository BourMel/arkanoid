#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "board.h"
#include "player.h"
#include <SDL2/SDL.h>

class EventManager {
public:
  EventManager();
  void listen(Board &board);

  void set_quit(bool value);
  bool get_quit();

private:
  SDL_Event m_event;
  bool m_quit;
};

#endif // EVENTMANAGER_H
