#ifndef BRICK_TYPES_H
#define BRICK_TYPES_H

#include "brick.h"

/** BRICK1 **/

class Brick1 : public Brick {
public:
  Brick1();
  Brick1(int lives, int line, int col);

protected:
  int m_lives = 1;
  int m_id = 1;
  int m_points = 50;
  std::string m_color = "white";
};

/** BRICK2 **/

class Brick2 : public Brick {
public:
  Brick2();
  Brick2(int lives, int line, int col);

protected:
  int m_lives = 1;
  int m_id = 2;
  int m_points = 55;
  std::string m_color = "green";
};

/** BRICK3 **/

class Brick3 : public Brick {
public:
  Brick3();
  Brick3(int lives, int line, int col);

protected:
  int m_lives = 1;
  int m_id = 3;
  int m_points = 60;
  std::string m_color = "yellow";
};

/** BRICK4 **/

class Brick4 : public Brick {
public:
  Brick4();
  Brick4(int lives, int line, int col);

protected:
  int m_lives = 1;
  int m_id = 4;
  int m_points = 65;
  std::string m_color = "cyan";
};

/** BRICK5 **/

class Brick5 : public Brick {
public:
  Brick5();
  Brick5(int lives, int line, int col);

protected:
  int m_lives = 1;
  int m_id = 5;
  int m_points = 70;
  std::string m_color = "blue-green";
};

/** BRICK6 **/

class Brick6 : public Brick {
public:
  Brick6();
  Brick6(int lives, int line, int col);

protected:
  int m_lives = 1;
  int m_id = 6;
  int m_points = 75;
  std::string m_color = "dark-green";
};

/** BRICK7 **/

class Brick7 : public Brick {
public:
  Brick7();
  Brick7(int lives, int line, int col);

protected:
  int m_lives = 1;
  int m_id = 7;
  int m_points = 80;
  std::string m_color = "blue";
};

/** BRICK8 **/

class Brick8 : public Brick {
public:
  Brick8();
  Brick8(int lives, int line, int col);

protected:
  int m_lives = 1;
  int m_id = 8;
  int m_points = 85;
  std::string m_color = "purple";
};

/** BRICK9 **/

class Brick9 : public Brick {
public:
  Brick9();
  Brick9(int lives, int line, int col);

protected:
  int m_lives = 1;
  int m_id = 9;
  int m_points = 90;
  std::string m_color = "orange";
};

/** BRICK10 **/

class Brick10 : public Brick {
public:
  Brick10();
  Brick10(int lives, int line, int col);

protected:
  int m_lives = 1;
  int m_id = 10;
  int m_points = 95;
  std::string m_color = "red";
};

/** BRICK11 **/

class Brick11 : public Brick {
public:
  Brick11();
  Brick11(int lives, int line, int col);

protected:
  int m_lives = 1;
  int m_id = 11;
  int m_points = 100;
  std::string m_color = "dark-red";
};

/** BRICK12 **/

class Brick12 : public Brick {
public:
  Brick12();
  Brick12(int lives, int line, int col);

protected:
  int m_lives = 1;
  int m_id = 12;
  int m_points = 120;
  std::string m_color = "dark-blue";
};

/** BRICK 13 **/

class Brick13 : public Brick {
public:
  Brick13();
  Brick13(int lives, int line, int col);

protected:
  int m_lives = 2; // to increase with number of rounds
  int m_id = 13;
  int m_points = 150; // to increase with number of rounds
  std::string m_color = "grey";
};

/** BRICK 14 **/

class Brick14 : public Brick {
public:
  Brick14();
  Brick14(int lives, int line, int col);

protected:
  int m_lives = 10; // infinite
  int m_id = 14;
  int m_points = 0; // not meant to be destroyed
  std::string m_color = "gold";
};

#endif // BRICK_TYPES_H
