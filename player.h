#ifndef PLAYER_H
#define PLAYER_H

class Game;

class Player {
public:
  Player();
  Player(Game *game);

  void set_x(int value);
  int get_x() const;
  void loose_life();
  bool is_alive() const;
  int get_lives() const;

private:
  int m_x;
  int m_lives;
};

#endif // PLAYER_H
