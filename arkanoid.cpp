#include "board.h"
#include "eventmanager.h"
#include "player.h"
#include "windowmanager.h"
#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char **argv) {
  WindowManager wm;
  EventManager em;
  Player player;
  Board board(&player);

  SDL_Rect ball;
  struct {
    int x;
    int y;
  } speed;

  ball.x = wm.getWindowWidth() / 2;
  ball.y = wm.getWindowWidth() / 2;
  speed.x = 5;
  speed.y = 7;

  while (!em.get_quit()) {
    em.listen(player);
    wm.draw(board);
    wm.update();
  }

  SDL_Quit();
  return 0;
}
