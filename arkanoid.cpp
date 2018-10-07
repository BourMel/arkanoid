#include "ball.h"
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
  Ball ball(wm.getWindowWidth(), wm.getWindowHeight());
  Board board(player, ball);

  while (!em.get_quit()) {
    em.listen(board);
    wm.draw(board);
    wm.update();
  }

  SDL_Quit();
  return 0;
}
