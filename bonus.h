#ifndef BONUS_H
#define BONUS_H

#include "ball.h"
#include "drawable.h"
#include <string>

class Bonus : public Drawable {
public:
  Bonus();

  void fall();
};

/** BONUS TYPES **/

class BonusS : public Bonus {
public:
  BonusS(SDL_Rect position);
};

#endif // BONUS_H

// BONUS_S,
// BONUS_C,
// BONUS_L,
// BONUS_E,
// BONUS_D,
// BONUS_B,
// BONUS_P
