#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
  Player();

  void set_x(int value);
  int get_x();

private:
  int m_x;
};

#endif // PLAYER_H
