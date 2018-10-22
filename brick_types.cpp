#include "brick.h"
#include "brick_types.h"
#include <SDL2/SDL.h>

#include <cmath>
#include <iostream>

#define BRICK_HEIGHT 16
#define BRICK_WIDTH 32

/** BRICK 1 **/

Brick1::Brick1() : Brick() {}

Brick1::Brick1(int lives, int line, int col) : Brick(lives, line, col) {
  m_rect.x = col * BRICK_WIDTH;
  m_rect.y = line * BRICK_HEIGHT;
}

/** BRICK2 **/

Brick2::Brick2() : Brick() {}

Brick2::Brick2(int lives, int line, int col) : Brick(lives, line, col) {
  m_rect.x = col * BRICK_WIDTH;
  m_rect.y = line * BRICK_HEIGHT;
}

/** BRICK3 **/

Brick3::Brick3() : Brick() {}

Brick3::Brick3(int lives, int line, int col) : Brick(lives, line, col) {
  m_rect.x = col * BRICK_WIDTH;
  m_rect.y = line * BRICK_HEIGHT;
}

/** BRICK4 **/

Brick4::Brick4() : Brick() {}

Brick4::Brick4(int lives, int line, int col) : Brick(lives, line, col) {
  m_rect.x = col * BRICK_WIDTH;
  m_rect.y = line * BRICK_HEIGHT;
}

/** BRICK5 **/

Brick5::Brick5() : Brick() {}

Brick5::Brick5(int lives, int line, int col) : Brick(lives, line, col) {
  m_rect.x = col * BRICK_WIDTH;
  m_rect.y = line * BRICK_HEIGHT;
}

/** BRICK6 **/

Brick6::Brick6() : Brick() {}

Brick6::Brick6(int lives, int line, int col) : Brick(lives, line, col) {
  m_rect.x = col * BRICK_WIDTH;
  m_rect.y = line * BRICK_HEIGHT;
}

/** BRICK7 **/

Brick7::Brick7() : Brick() {}

Brick7::Brick7(int lives, int line, int col) : Brick(lives, line, col) {
  m_rect.x = col * BRICK_WIDTH;
  m_rect.y = line * BRICK_HEIGHT;
}

/** BRICK8 **/

Brick8::Brick8() : Brick() {}

Brick8::Brick8(int lives, int line, int col) : Brick(lives, line, col) {
  m_rect.x = col * BRICK_WIDTH;
  m_rect.y = line * BRICK_HEIGHT;
}

/** BRICK9 **/

Brick9::Brick9() : Brick() {}

Brick9::Brick9(int lives, int line, int col) : Brick(lives, line, col) {
  m_rect.x = col * BRICK_WIDTH;
  m_rect.y = line * BRICK_HEIGHT;
}

/** BRICK10 **/

Brick10::Brick10() : Brick() {}

Brick10::Brick10(int lives, int line, int col) : Brick(lives, line, col) {
  m_rect.x = col * BRICK_WIDTH;
  m_rect.y = line * BRICK_HEIGHT;
}

/** BRICK11 **/

Brick11::Brick11() : Brick() {}

Brick11::Brick11(int lives, int line, int col) : Brick(lives, line, col) {
  m_rect.x = col * BRICK_WIDTH;
  m_rect.y = line * BRICK_HEIGHT;
}

/** BRICK12 **/

Brick12::Brick12() : Brick() {}

Brick12::Brick12(int lives, int line, int col) : Brick(lives, line, col) {
  m_rect.x = col * BRICK_WIDTH;
  m_rect.y = line * BRICK_HEIGHT;
}

/** BRICK 13 **/

Brick13::Brick13() : Brick() {}

Brick13::Brick13(int lives, int line, int col) : Brick(lives, line, col) {
  m_rect.x = col * BRICK_WIDTH;
  m_rect.y = line * BRICK_HEIGHT;
}

/** BRICK 14 **/

Brick14::Brick14() : Brick() {}

Brick14::Brick14(int lives, int line, int col) : Brick(lives, line, col) {
  m_rect.x = col * BRICK_WIDTH;
  m_rect.y = line * BRICK_HEIGHT;
}
