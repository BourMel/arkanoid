#include "graphicmanager.h"
#include <stdlib.h>

/**
 * Default constructor
 */
GraphicManager::GraphicManager() {}

/**
 * Get the SDL_Rect for a specific sprite
 */
SDL_Rect GraphicManager::getSprite(const SpriteType type) {
  SDL_Rect rect = {0, 0, 0, 0};

  /**************************/
  /** SET WIDTH AND HEIGHT **/
  /**************************/

  // operation for all bricks & bonus
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
  case BRICK_GREY:
  case BRICK_GOLD:
  case BONUS_S:
  case BONUS_C:
  case BONUS_L:
  case BONUS_E:
  case BONUS_D:
  case BONUS_B:
  case BONUS_P:
    rect.w = BRICK_WIDTH;
    rect.h = BRICK_HEIGHT;
    break;
  case LASER:
    rect.w = 10;
    rect.h = 36;
    break;
  default:
    // do nothing
    break;
  }

  // operation for all ascii symbols
  switch (type) {
  case CHAR_SPACE:
  case CHAR_UPPER_A:
  case CHAR_UPPER_B:
  case CHAR_UPPER_C:
  case CHAR_UPPER_D:
  case CHAR_UPPER_E:
  case CHAR_UPPER_F:
  case CHAR_UPPER_G:
  case CHAR_UPPER_H:
  case CHAR_UPPER_I:
  case CHAR_UPPER_J:
  case CHAR_UPPER_K:
  case CHAR_UPPER_L:
  case CHAR_UPPER_M:
  case CHAR_UPPER_N:
  case CHAR_UPPER_O:
  case CHAR_UPPER_P:
  case CHAR_UPPER_Q:
  case CHAR_UPPER_R:
  case CHAR_UPPER_S:
  case CHAR_UPPER_T:
  case CHAR_UPPER_U:
  case CHAR_UPPER_V:
  case CHAR_UPPER_W:
  case CHAR_UPPER_X:
  case CHAR_UPPER_Y:
  case CHAR_UPPER_Z:
  case CHAR_LOWER_A:
  case CHAR_LOWER_B:
  case CHAR_LOWER_C:
  case CHAR_LOWER_D:
  case CHAR_LOWER_E:
  case CHAR_LOWER_F:
  case CHAR_LOWER_G:
  case CHAR_LOWER_H:
  case CHAR_LOWER_I:
  case CHAR_LOWER_J:
  case CHAR_LOWER_K:
  case CHAR_LOWER_L:
  case CHAR_LOWER_M:
  case CHAR_LOWER_N:
  case CHAR_LOWER_O:
  case CHAR_LOWER_P:
  case CHAR_LOWER_Q:
  case CHAR_LOWER_R:
  case CHAR_LOWER_S:
  case CHAR_LOWER_T:
  case CHAR_LOWER_U:
  case CHAR_LOWER_V:
  case CHAR_LOWER_W:
  case CHAR_LOWER_X:
  case CHAR_LOWER_Y:
  case CHAR_LOWER_Z:
  case CHAR_0:
  case CHAR_1:
  case CHAR_2:
  case CHAR_3:
  case CHAR_4:
  case CHAR_5:
  case CHAR_6:
  case CHAR_7:
  case CHAR_8:
  case CHAR_9:
    rect.w = ASCII_SIZE;
    rect.h = ASCII_SIZE;
    break;
  default:
    // do nothing
    break;
  }

  /**********************/
  /** SET COORDONNATES **/
  /**********************/

  switch (type) {
  case BRICK_WHITE:
    // nothing to do anymore : x and y = 0 (defaults),
    // and w and h are already set
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
  case BRICK_GREY:
    rect.y = 2 * BRICK_HEIGHT;
    break;
  case BRICK_GOLD:
    rect.y = 3 * BRICK_HEIGHT;
    break;
  case BONUS_S:
    rect.x = 8 * BRICK_WIDTH;
    break;
  case BONUS_C:
    rect.x = 8 * BRICK_WIDTH;
    rect.y = BRICK_HEIGHT;
    break;
  case BONUS_L:
    rect.x = 8 * BRICK_WIDTH;
    rect.y = 2 * BRICK_HEIGHT;
    break;
  case BONUS_E:
    rect.x = 8 * BRICK_WIDTH;
    rect.y = 3 * BRICK_HEIGHT;
    break;
  case BONUS_D:
    rect.x = 8 * BRICK_WIDTH;
    rect.y = 4 * BRICK_HEIGHT;
    break;
  case BONUS_B:
    rect.x = 8 * BRICK_WIDTH;
    rect.y = 5 * BRICK_HEIGHT;
    break;
  case BONUS_P:
    rect.x = 8 * BRICK_WIDTH;
    rect.y = 6 * BRICK_HEIGHT;
    break;
  case LASER:
    if (rand() % 2 + 1 == 1) {
      rect.x = 2;
    } else {
      rect.x = 19;
    }

    rect.y = 5 * BRICK_HEIGHT;
    break;
  case PLAYER_LIFE:
    rect.x = 448;
    rect.y = 128;
    rect.w = 28;
    rect.h = 12;
    break;
  case PLAYER_1:
    rect.x = 384;
    rect.y = 128;
    rect.w = 64;
    rect.h = 16;
    break;
  case PLAYER_2:
    rect.x = 384;
    rect.y = 144;
    rect.w = 74;
    rect.h = 16;
    break;
  case PLAYER_3:
    rect.x = 384;
    rect.y = 160;
    rect.w = 82;
    rect.h = 16;
    break;
  case PLAYER_4:
    rect.x = 384;
    rect.y = 176;
    rect.w = 90;
    rect.h = 16;
    break;
  case PLAYER_5:
    rect.x = 384;
    rect.y = 192;
    rect.w = 98;
    rect.h = 16;
    break;
  case PLAYER_6:
    rect.x = 384;
    rect.y = 208;
    rect.w = 108;
    rect.h = 16;
    break;
  case PLAYER_7:
    rect.x = 384;
    rect.y = 224;
    rect.w = 118;
    rect.h = 16;
    break;
  case PLAYER_8:
    rect.x = 384;
    rect.y = 240;
    rect.w = 128;
    rect.h = 16;
    break;
  case CHAR_SPACE:
    rect.x = 0;
    rect.y = 0;
    break;
  case CHAR_UPPER_A:
    rect.x = ASCII_SIZE;
    rect.y = 2 * ASCII_SIZE;
    break;
  case CHAR_UPPER_B:
    rect.x = 2 * ASCII_SIZE;
    rect.y = 2 * ASCII_SIZE;
    break;
  case CHAR_UPPER_C:
    rect.x = 3 * ASCII_SIZE;
    rect.y = 2 * ASCII_SIZE;
    break;
  case CHAR_UPPER_D:
    rect.x = 4 * ASCII_SIZE;
    rect.y = 2 * ASCII_SIZE;
    break;
  case CHAR_UPPER_E:
    rect.x = 5 * ASCII_SIZE;
    rect.y = 2 * ASCII_SIZE;
    break;
  case CHAR_UPPER_F:
    rect.x = 6 * ASCII_SIZE;
    rect.y = 2 * ASCII_SIZE;
    break;
  case CHAR_UPPER_G:
    rect.x = 7 * ASCII_SIZE;
    rect.y = 2 * ASCII_SIZE;
    break;
  case CHAR_UPPER_H:
    rect.x = 8 * ASCII_SIZE;
    rect.y = 2 * ASCII_SIZE;
    break;
  case CHAR_UPPER_I:
    rect.x = 9 * ASCII_SIZE;
    rect.y = 2 * ASCII_SIZE;
    break;
  case CHAR_UPPER_J:
    rect.x = 10 * ASCII_SIZE;
    rect.y = 2 * ASCII_SIZE;
    break;
  case CHAR_UPPER_K:
    rect.x = 11 * ASCII_SIZE;
    rect.y = 2 * ASCII_SIZE;
    break;
  case CHAR_UPPER_L:
    rect.x = 12 * ASCII_SIZE;
    rect.y = 2 * ASCII_SIZE;
    break;
  case CHAR_UPPER_M:
    rect.x = 13 * ASCII_SIZE;
    rect.y = 2 * ASCII_SIZE;
    break;
  case CHAR_UPPER_N:
    rect.x = 14 * ASCII_SIZE;
    rect.y = 2 * ASCII_SIZE;
    break;
  case CHAR_UPPER_O:
    rect.x = 15 * ASCII_SIZE;
    rect.y = 2 * ASCII_SIZE;
    break;
  case CHAR_UPPER_P:
    rect.y = 3 * ASCII_SIZE;
    break;
  case CHAR_UPPER_Q:
    rect.x = ASCII_SIZE;
    rect.y = 3 * ASCII_SIZE;
    break;
  case CHAR_UPPER_R:
    rect.x = 2 * ASCII_SIZE;
    rect.y = 3 * ASCII_SIZE;
    break;
  case CHAR_UPPER_S:
    rect.x = 3 * ASCII_SIZE;
    rect.y = 3 * ASCII_SIZE;
    break;
  case CHAR_UPPER_T:
    rect.x = 4 * ASCII_SIZE;
    rect.y = 3 * ASCII_SIZE;
    break;
  case CHAR_UPPER_U:
    rect.x = 5 * ASCII_SIZE;
    rect.y = 3 * ASCII_SIZE;
    break;
  case CHAR_UPPER_V:
    rect.x = 6 * ASCII_SIZE;
    rect.y = 3 * ASCII_SIZE;
    break;
  case CHAR_UPPER_W:
    rect.x = 7 * ASCII_SIZE;
    rect.y = 3 * ASCII_SIZE;
    break;
  case CHAR_UPPER_X:
    rect.x = 8 * ASCII_SIZE;
    rect.y = 3 * ASCII_SIZE;
    break;
  case CHAR_UPPER_Y:
    rect.x = 9 * ASCII_SIZE;
    rect.y = 3 * ASCII_SIZE;
    break;
  case CHAR_UPPER_Z:
    rect.x = 10 * ASCII_SIZE;
    rect.y = 3 * ASCII_SIZE;
    break;
  case CHAR_LOWER_A:
    rect.x = ASCII_SIZE;
    rect.y = 4 * ASCII_SIZE;
    break;
  case CHAR_LOWER_B:
    rect.x = 2 * ASCII_SIZE;
    rect.y = 4 * ASCII_SIZE;
    break;
  case CHAR_LOWER_C:
    rect.x = 3 * ASCII_SIZE;
    rect.y = 4 * ASCII_SIZE;
    break;
  case CHAR_LOWER_D:
    rect.x = 4 * ASCII_SIZE;
    rect.y = 4 * ASCII_SIZE;
    break;
  case CHAR_LOWER_E:
    rect.x = 5 * ASCII_SIZE;
    rect.y = 4 * ASCII_SIZE;
    break;
  case CHAR_LOWER_F:
    rect.x = 6 * ASCII_SIZE;
    rect.y = 4 * ASCII_SIZE;
    break;
  case CHAR_LOWER_G:
    rect.x = 7 * ASCII_SIZE;
    rect.y = 4 * ASCII_SIZE;
    break;
  case CHAR_LOWER_H:
    rect.x = 8 * ASCII_SIZE;
    rect.y = 4 * ASCII_SIZE;
    break;
  case CHAR_LOWER_I:
    rect.x = 9 * ASCII_SIZE;
    rect.y = 4 * ASCII_SIZE;
    break;
  case CHAR_LOWER_J:
    rect.x = 10 * ASCII_SIZE;
    rect.y = 4 * ASCII_SIZE;
    break;
  case CHAR_LOWER_K:
    rect.x = 11 * ASCII_SIZE;
    rect.y = 4 * ASCII_SIZE;
    break;
  case CHAR_LOWER_L:
    rect.x = 12 * ASCII_SIZE;
    rect.y = 4 * ASCII_SIZE;
    break;
  case CHAR_LOWER_M:
    rect.x = 13 * ASCII_SIZE;
    rect.y = 4 * ASCII_SIZE;
    break;
  case CHAR_LOWER_N:
    rect.x = 14 * ASCII_SIZE;
    rect.y = 4 * ASCII_SIZE;
    break;
  case CHAR_LOWER_O:
    rect.x = 15 * ASCII_SIZE;
    rect.y = 4 * ASCII_SIZE;
    break;
  case CHAR_LOWER_P:
    rect.y = 5 * ASCII_SIZE;
    break;
  case CHAR_LOWER_Q:
    rect.x = ASCII_SIZE;
    rect.y = 5 * ASCII_SIZE;
    break;
  case CHAR_LOWER_R:
    rect.x = 2 * ASCII_SIZE;
    rect.y = 5 * ASCII_SIZE;
    break;
  case CHAR_LOWER_S:
    rect.x = 3 * ASCII_SIZE;
    rect.y = 5 * ASCII_SIZE;
    break;
  case CHAR_LOWER_T:
    rect.x = 4 * ASCII_SIZE;
    rect.y = 5 * ASCII_SIZE;
    break;
  case CHAR_LOWER_U:
    rect.x = 5 * ASCII_SIZE;
    rect.y = 5 * ASCII_SIZE;
    break;
  case CHAR_LOWER_V:
    rect.x = 6 * ASCII_SIZE;
    rect.y = 5 * ASCII_SIZE;
    break;
  case CHAR_LOWER_W:
    rect.x = 7 * ASCII_SIZE;
    rect.y = 5 * ASCII_SIZE;
    break;
  case CHAR_LOWER_X:
    rect.x = 8 * ASCII_SIZE;
    rect.y = 5 * ASCII_SIZE;
    break;
  case CHAR_LOWER_Y:
    rect.x = 9 * ASCII_SIZE;
    rect.y = 5 * ASCII_SIZE;
    break;
  case CHAR_LOWER_Z:
    rect.x = 10 * ASCII_SIZE;
    rect.y = 5 * ASCII_SIZE;
    break;
  case CHAR_0:
    rect.x = 0;
    rect.y = ASCII_SIZE;
    break;
  case CHAR_1:
    rect.x = ASCII_SIZE;
    rect.y = ASCII_SIZE;
    break;
  case CHAR_2:
    rect.x = 2 * ASCII_SIZE;
    rect.y = ASCII_SIZE;
    break;
  case CHAR_3:
    rect.x = 3 * ASCII_SIZE;
    rect.y = ASCII_SIZE;
    break;
  case CHAR_4:
    rect.x = 4 * ASCII_SIZE;
    rect.y = ASCII_SIZE;
    break;
  case CHAR_5:
    rect.x = 5 * ASCII_SIZE;
    rect.y = ASCII_SIZE;
    break;
  case CHAR_6:
    rect.x = 6 * ASCII_SIZE;
    rect.y = ASCII_SIZE;
    break;
  case CHAR_7:
    rect.x = 7 * ASCII_SIZE;
    rect.y = ASCII_SIZE;
    break;
  case CHAR_8:
    rect.x = 8 * ASCII_SIZE;
    rect.y = ASCII_SIZE;
    break;
  case CHAR_9:
    rect.x = 9 * ASCII_SIZE;
    rect.y = ASCII_SIZE;
    break;
  default:
    // do nothing
    break;
  }
  return rect;
}

/**
 * Get the type of a sprite needed for a char in a text zone
 */
GraphicManager::SpriteType GraphicManager::getSpriteTypeFromChar(const char c) {
  switch (c) {
  case 'A':
    return CHAR_UPPER_A;
  case 'B':
    return CHAR_UPPER_B;
  case 'C':
    return CHAR_UPPER_C;
  case 'D':
    return CHAR_UPPER_D;
  case 'E':
    return CHAR_UPPER_E;
  case 'F':
    return CHAR_UPPER_F;
  case 'G':
    return CHAR_UPPER_G;
  case 'H':
    return CHAR_UPPER_H;
  case 'I':
    return CHAR_UPPER_I;
  case 'J':
    return CHAR_UPPER_J;
  case 'K':
    return CHAR_UPPER_K;
  case 'L':
    return CHAR_UPPER_L;
  case 'M':
    return CHAR_UPPER_M;
  case 'N':
    return CHAR_UPPER_N;
  case 'O':
    return CHAR_UPPER_O;
  case 'P':
    return CHAR_UPPER_P;
  case 'Q':
    return CHAR_UPPER_Q;
  case 'R':
    return CHAR_UPPER_R;
  case 'S':
    return CHAR_UPPER_S;
  case 'T':
    return CHAR_UPPER_T;
  case 'U':
    return CHAR_UPPER_U;
  case 'V':
    return CHAR_UPPER_V;
  case 'W':
    return CHAR_UPPER_W;
  case 'X':
    return CHAR_UPPER_X;
  case 'Y':
    return CHAR_UPPER_Y;
  case 'Z':
    return CHAR_UPPER_Z;
  case 'a':
    return CHAR_LOWER_A;
  case 'b':
    return CHAR_LOWER_B;
  case 'c':
    return CHAR_LOWER_C;
  case 'd':
    return CHAR_LOWER_D;
  case 'e':
    return CHAR_LOWER_E;
  case 'f':
    return CHAR_LOWER_F;
  case 'g':
    return CHAR_LOWER_G;
  case 'h':
    return CHAR_LOWER_H;
  case 'i':
    return CHAR_LOWER_I;
  case 'j':
    return CHAR_LOWER_J;
  case 'k':
    return CHAR_LOWER_K;
  case 'l':
    return CHAR_LOWER_L;
  case 'm':
    return CHAR_LOWER_M;
  case 'n':
    return CHAR_LOWER_N;
  case 'o':
    return CHAR_LOWER_O;
  case 'p':
    return CHAR_LOWER_P;
  case 'q':
    return CHAR_LOWER_Q;
  case 'r':
    return CHAR_LOWER_R;
  case 's':
    return CHAR_LOWER_S;
  case 't':
    return CHAR_LOWER_T;
  case 'u':
    return CHAR_LOWER_U;
  case 'v':
    return CHAR_LOWER_V;
  case 'w':
    return CHAR_LOWER_W;
  case 'x':
    return CHAR_LOWER_X;
  case 'y':
    return CHAR_LOWER_Y;
  case 'z':
    return CHAR_LOWER_Z;
  case '0':
    return CHAR_0;
  case '1':
    return CHAR_1;
  case '2':
    return CHAR_2;
  case '3':
    return CHAR_3;
  case '4':
    return CHAR_4;
  case '5':
    return CHAR_5;
  case '6':
    return CHAR_6;
  case '7':
    return CHAR_7;
  case '8':
    return CHAR_8;
  case '9':
    return CHAR_9;
  default:
    return CHAR_SPACE;
  }
}

/**
 * Create a text zone on the screen at (`x`, `y`) and print the text `str`
 */
void GraphicManager::printText(int x, int y, SDL_Surface *src, SDL_Surface *dst,
                               std::string str) {
  SDL_Rect rect = {x, y, ASCII_SIZE, ASCII_SIZE};
  for (char &c : str) {
    SpriteType type = GraphicManager::getSpriteTypeFromChar(c);
    SDL_Rect srcrect = GraphicManager::getSprite(type);
    SDL_BlitSurface(src, &srcrect, dst, &rect);
    rect.x += ASCII_SIZE * 0.6;
  }
}
