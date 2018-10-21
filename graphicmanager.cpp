#include "graphicmanager.h"

GraphicManager::GraphicManager() {}

SDL_Rect GraphicManager::getSprite(const SpriteType type) {
  SDL_Rect rect = {0, 0, 0, 0};

  // operation for all bricks
  switch (type) {
  case BRICK_WHITE:
  case BRICK_ORANGE:
  case BRICK_CYAN:
  case BRICK_GREEN:
  case BRICK_DARKBLUE:
  case BRICK_DARKGREEN:
  case BRICK_RED:
  case BRICK_BLUE:
  case BRICK_PINK:
  case BRICK_YELLOW:
  case BRICK_DARKRED:
  case BRICK_BLUEGREEN:
    rect.w = BRICK_WIDTH;
    rect.h = BRICK_HEIGHT;
    break;
  default:
    // do nothing
    break;
  }

  switch (type) {
  case BRICK_WHITE:
    // nothing to do anymore : x and y = 0 (defaults), and w and h are already
    // set
    break;
  case BRICK_ORANGE:
    rect.x = BRICK_WIDTH;
    break;
  case BRICK_CYAN:
    rect.x = 2 * BRICK_WIDTH;
    break;
  case BRICK_GREEN:
    rect.x = 3 * BRICK_WIDTH;
    break;
  case BRICK_DARKBLUE:
    rect.x = 4 * BRICK_WIDTH;
    break;
  case BRICK_DARKGREEN:
    rect.x = 5 * BRICK_WIDTH;
    break;
  case BRICK_RED:
    rect.y = BRICK_HEIGHT;
    break;
  case BRICK_BLUE:
    rect.x = BRICK_WIDTH;
    rect.y = BRICK_HEIGHT;
    break;
  case BRICK_PINK:
    rect.x = 2 * BRICK_WIDTH;
    rect.y = BRICK_HEIGHT;
    break;
  case BRICK_YELLOW:
    rect.x = 3 * BRICK_WIDTH;
    rect.y = BRICK_HEIGHT;
    break;
  case BRICK_DARKRED:
    rect.x = 4 * BRICK_WIDTH;
    rect.y = BRICK_HEIGHT;
    break;
  case BRICK_BLUEGREEN:
    rect.x = 5 * BRICK_WIDTH;
    rect.y = BRICK_HEIGHT;
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
