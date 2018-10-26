#ifndef PLAYER_H
#define PLAYER_H

#include "drawable.h"
#include "graphicmanager.h"

class Game;

class Player : public Drawable {
public:
  Player();
  Player(Game *game);

  void set_x(int value);
  int get_x() const;
  void loose_life();
  bool is_alive() const;
  int get_lives() const;
  void setSprite(GraphicManager::SpriteType type);

private:
  int m_lives;
  int m_windowWidth;

  Game *m_game;

  void init();
};

#endif // PLAYER_H
