//
// Created by elshahawy on 01.09.2019.
//

#include "visitor.h"
#include "builder.h"
#include "strategy.h"

int main()
{
  duck d;
  asian_duck_quack as_duck;
  d.set_quack_type(&as_duck);
  d.do_quack();

  ver1::burger b = ver1::burger::builder{}.add_cheese(true).add_tomato(true).build();


  auto l{new visitor_pattern::Lion()};
    auto m{new visitor_pattern::Monkey()};

    auto speak{new visitor_pattern::speak()};
    l->accept(*speak);
    m->accept(*speak);

    auto move_to_home{new visitor_pattern::move_vehicle()};
    auto car{new visitor_pattern::car()};
    auto airplane{new visitor_pattern::airplane()};
    car->accept(*move_to_home);
    airplane->accept(*move_to_home);
    return 0;
}