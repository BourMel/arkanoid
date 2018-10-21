#include "graphicmanager.h"

GraphicManager::GraphicManager() {}

SDL_Rect GraphicManager::getSprite(const SpriteType type) {
  SDL_Rect rect = {0, 0, 0, 0};
  switch (type) {
  case BRICK_WHITE:
    rect.w = BRICK_WIDTH;
    rect.h = BRICK_HEIGHT;
    break;
  case PLAYER_1:
    rect.x = 385;
    rect.y = 128;
    rect.w = 58;
    rect.h = 16;
    break;
  case PLAYER_2:
    rect.x = 385;
    rect.y = 144;
    rect.w = 68;
    rect.h = 16;
    break;
  case PLAYER_3:
    rect.x = 385;
    rect.y = 160;
    rect.w = 78;
    rect.h = 16;
    break;
  case PLAYER_4:
    rect.x = 385;
    rect.y = 176;
    rect.w = 88;
    rect.h = 16;
    break;
  case PLAYER_5:
    rect.x = 385;
    rect.y = 192;
    rect.w = 98;
    rect.h = 16;
    break;
  case PLAYER_6:
    rect.x = 385;
    rect.y = 208;
    rect.w = 108;
    rect.h = 16;
    break;
  case PLAYER_7:
    rect.x = 385;
    rect.y = 224;
    rect.w = 118;
    rect.h = 16;
    break;
  case PLAYER_8:
    rect.x = 385;
    rect.y = 240;
    rect.w = 128;
    rect.h = 16;
    break;
  default:
    // do nothing
    break;
  }
  return rect;
}
