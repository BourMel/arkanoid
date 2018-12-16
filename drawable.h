#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "graphicmanager.h"

class Drawable {
public:
  Drawable();
  Drawable(Box rect, Box src);

  // get object position
  const Box &getRect() const;

  // get sprite position
  const Box &getSrc() const;

  // callback when object is draw
  virtual void drawCallback();

  // x and y position setters and getters
  const int &getX() const;
  const int &getY() const;
  void setX(int value);
  void setY(int value);

protected:
  Box m_rect; // object position
  Box m_src;  // sprite position
};

#endif // DRAWABLE_H
