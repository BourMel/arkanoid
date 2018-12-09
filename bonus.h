#ifndef BONUS_H
#define BONUS_H

#include <string>

#include "ball.h"
#include "brick.h"
#include "drawable.h"

class Bonus : public Drawable {
public:
  Bonus();

  virtual void drawCallback();

protected:
  int m_countAnim;
};

/** BONUS TYPES **/

class BonusS : public Bonus {
public:
  BonusS(SDL_Rect pos);
  void drawCallback();
};

#endif // BONUS_H

// BONUS_S,
// BONUS_C,
// BONUS_L,
// BONUS_E,
// BONUS_D,
// BONUS_B,
// BONUS_P
