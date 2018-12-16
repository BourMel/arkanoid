#ifndef SPRITE_H
#define SPRITE_H

#include "graphicmanager.h"

class Sprite {
public:
  enum Type {
    // Bricks
    BRICK_WHITE,
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

    BRICK_GREY,
    BRICK_GOLD,

    // Player
    PLAYER_LIFE,
    PLAYER_1,
    PLAYER_2,
    PLAYER_3,
    PLAYER_4,
    PLAYER_5,
    PLAYER_6,
    PLAYER_7,
    PLAYER_8,

    // Ascii symbols
    CHAR_SPACE,

    CHAR_UPPER_A,
    CHAR_UPPER_B,
    CHAR_UPPER_C,
    CHAR_UPPER_D,
    CHAR_UPPER_E,
    CHAR_UPPER_F,
    CHAR_UPPER_G,
    CHAR_UPPER_H,
    CHAR_UPPER_I,
    CHAR_UPPER_J,
    CHAR_UPPER_K,
    CHAR_UPPER_L,
    CHAR_UPPER_M,
    CHAR_UPPER_N,
    CHAR_UPPER_O,
    CHAR_UPPER_P,
    CHAR_UPPER_Q,
    CHAR_UPPER_R,
    CHAR_UPPER_S,
    CHAR_UPPER_T,
    CHAR_UPPER_U,
    CHAR_UPPER_V,
    CHAR_UPPER_W,
    CHAR_UPPER_X,
    CHAR_UPPER_Y,
    CHAR_UPPER_Z,

    CHAR_LOWER_A,
    CHAR_LOWER_B,
    CHAR_LOWER_C,
    CHAR_LOWER_D,
    CHAR_LOWER_E,
    CHAR_LOWER_F,
    CHAR_LOWER_G,
    CHAR_LOWER_H,
    CHAR_LOWER_I,
    CHAR_LOWER_J,
    CHAR_LOWER_K,
    CHAR_LOWER_L,
    CHAR_LOWER_M,
    CHAR_LOWER_N,
    CHAR_LOWER_O,
    CHAR_LOWER_P,
    CHAR_LOWER_Q,
    CHAR_LOWER_R,
    CHAR_LOWER_S,
    CHAR_LOWER_T,
    CHAR_LOWER_U,
    CHAR_LOWER_V,
    CHAR_LOWER_W,
    CHAR_LOWER_X,
    CHAR_LOWER_Y,
    CHAR_LOWER_Z,

    CHAR_0,
    CHAR_1,
    CHAR_2,
    CHAR_3,
    CHAR_4,
    CHAR_5,
    CHAR_6,
    CHAR_7,
    CHAR_8,
    CHAR_9,

    // BONUS
    BONUS_S,
    BONUS_C,
    BONUS_L,
    BONUS_E,
    BONUS_D,
    BONUS_B,
    BONUS_P,

    LASER,

    LOGO,

    // BACKGROUNDS
    BG1,
    BG2,
    BG3,
    BG4,
    BG5,
    BG6,

    TOP
  };

  static Box get(const Type type);
  static Type getTypeFromChar(const char c);
};

#endif // SPRITE_H
