#include "eventmanager.h"
#include "player.h"
#include "windowmanager.h"

#include <SDL2/SDL.h>
#include <iostream>

WindowManager wm;
EventManager em;
Player player;

SDL_Rect ball;
struct {
  int x;
  int y;
} speed;

void init() {
  ball.x = wm.getWindowWidth() / 2;
  ball.y = wm.getWindowWidth() / 2;
  speed.x = 5;
  speed.y = 7;
}

//// fonction qui met à jour la surface de la fenetre "win_surf"
// void draw() {
//  // remplit le fond
//  SDL_Rect dest = {0, 0, 0, 0};
//  for (int j = 0; j < win_surf->h; j += 128)
//    for (int i = 0; i < win_surf->w; i += 96) {
//      dest.x = i;
//      dest.y = j;
//      SDL_BlitSurface(plancheSprites, &srcBg, win_surf, &dest);
//    }

//  // affiche balle
//  SDL_BlitSurface(plancheSprites, &srcBall, win_surf, &ball);

//  // dedplacement
//  ball.x += speed.x;
//  ball.y += speed.y;

//  // collision bord
//  if ((ball.x < 1) || (ball.x > (win_surf->w - 25)))
//    speed.x *= -1;
//  if ((ball.y < 1) || (ball.y > (win_surf->h - 25)))
//    speed.y *= -1;

//  // touche bas -> rouge
//  if (ball.y > (win_surf->h - 25))
//    srcBall.y = 64;

//  // collision vaisseau
//  if ((ball.x > x_vault) && (ball.x < x_vault + 128) &&
//      (ball.y > win_surf->h - 32 - 20)) {
//    speed.y *= -1;
//    srcBall.y = 96; // -> vert
//  }

//  // vaisseau
//  dest.x = x_vault;
//  dest.y = win_surf->h - 32;
//  SDL_BlitSurface(plancheSprites, &scrVaiss, win_surf, &dest);
//}

int main(int argc, char **argv) {
  init();

  em.set_quit(false);

  while (!em.get_quit()) {
    em.listen(player);
    wm.draw();
    wm.update();
  }

  SDL_Quit();
  return 0;
}
