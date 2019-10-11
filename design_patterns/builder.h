//
// Created by elshahawy on 12.10.2019.
//

#ifndef CPP_OLYMPICS_BUILDER_H
#define CPP_OLYMPICS_BUILDER_H
namespace ver1
{
class burger
{
public:
  class builder;
  burger(bool cheese, bool triple, bool tomato) : cheese_{cheese}, triple_{triple}, tomato_{tomato}{}
  bool cheese_;
  bool triple_;
  bool tomato_;
};

class burger::builder
{
public:
  burger build() const
  {
    return burger(cheese_,triple_,tomato_);
  }
  builder& add_cheese(bool cheese){cheese_ = cheese;
    return *this;};
  builder& add_triple(bool triple){triple_ = triple;
    return *this;};
  builder& add_tomato(bool tomato){tomato_ = tomato;
    return *this;};
private:
  bool cheese_{false};
  bool triple_{false};
  bool tomato_{false};
};
}


#endif // CPP_OLYMPICS_BUILDER_H
