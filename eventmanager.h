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

  void setQuit(bool value);
  bool getQuit();

private:
  SDL_Event m_event;
  bool m_quit;
  Game *m_game;

  void listenMenu();
  void listenWin();
  void listenLose();
  void listenLevel();
};

#endif // EVENTMANAGER_H
