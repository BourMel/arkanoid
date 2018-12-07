#ifndef BONUS_H
#define BONUS_H

#include "ball.h"
#include "drawable.h"
#include <string>

class Bonus : public Drawable {
public:
  Bonus();

protected:
  SDL_Rect m_src; // sprite
  int m_x;
  int m_y;
};

#endif // BONUS_H

/** BONUS TYPES **/

#ifndef BONUS_TYPES_H
#define BONUS_TYPES_H

#include "ball.h"
#include "drawable.h"

class BonusS : public Bonus {
public:
  BonusS();
};

#endif // BONUS_TYPES_H

// BONUS_S,
// BONUS_C,
// BONUS_L,
// BONUS_E,
// BONUS_D,
// BONUS_B,
// BONUS_P
