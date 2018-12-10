#ifndef PLAYER_H
#define PLAYER_H

#include "drawable.h"
#include "graphicmanager.h"

class Game;

class Player : public Drawable {
public:
  Player();
  Player(Game *game);

  void setX(int value);
  int getX() const;
  void looseLife();
  void winLife();
  void grow();
  int getLives() const;
  void setSprite(GraphicManager::SpriteType type);
  void reset();

private:
  int m_size; // player size
  int m_lives;
  int m_windowWidth;

  Game *m_game;

  void init();
};

#endif // PLAYER_H
