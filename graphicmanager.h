#ifndef GRAPHICMANAGER_H
#define GRAPHICMANAGER_H

#include <SDL2/SDL.h>

#define BRICK_HEIGHT 16
#define BRICK_WIDTH 32

class GraphicManager {
public:
  enum SpriteType {
    BRICK_WHITE = 0,
    BRICK_ORANGE,
    BRICK_CYAN,
    BRICK_GREEN,
    BRICK_DARKBLUE,
    BRICK_DARKGREEN,
    BRICK_RED,
    BRICK_BLUE,
    BRICK_PINK,
    BRICK_YELLOW,
    BRICK_DARKRED,
    BRICK_BLUEGREEN,

    PLAYER_1,
    PLAYER_2,
    PLAYER_3,
    PLAYER_4,
    PLAYER_5,
    PLAYER_6,
    PLAYER_7,
    PLAYER_8,
  };
  GraphicManager();

  static SDL_Rect getSprite(const SpriteType type);
};

#endif // GRAPHICMANAGER_H
