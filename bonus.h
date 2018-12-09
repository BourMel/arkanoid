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

class BonusC : public Bonus {
public:
  BonusC(SDL_Rect pos);
  void drawCallback();
};

class BonusL : public Bonus {
public:
  BonusL(SDL_Rect pos);
  void drawCallback();
};

class BonusE : public Bonus {
public:
  BonusE(SDL_Rect pos);
  void drawCallback();
};

class BonusD : public Bonus {
public:
  BonusD(SDL_Rect pos);
  void drawCallback();
};

class BonusB : public Bonus {
public:
  BonusB(SDL_Rect pos);
  void drawCallback();
};

class BonusP : public Bonus {
public:
  BonusP(SDL_Rect pos);
  void drawCallback();
};

#endif // BONUS_H
