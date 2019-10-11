//
// Created by elshahawy on 12.10.2019.
//

#ifndef CPP_OLYMPICS_STRATEGY_H
#define CPP_OLYMPICS_STRATEGY_H
#include <iostream>

// while a rubber duck will not quack, an african or asian duck will set quack type
// accordingly

class quack
{
public:
  virtual void quack_sound_tone() = 0;
};

class asian_duck_quack : public quack
{
public:
  void quack_sound_tone() override {std::cout << "asian duck sound \n";}
};

class african_duck_quack : public quack
{
public:
  void quack_sound_tone() override {std::cout << "african duck sound \n";}
};

class duck
{
public:
  void do_quack(){quack_->quack_sound_tone();}
  void set_quack_type(quack* q) {quack_ = q;}
  quack* quack_{nullptr};
};

#endif // CPP_OLYMPICS_STRATEGY_H
