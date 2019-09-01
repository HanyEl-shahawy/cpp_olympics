//
// Created by elshahawy on 01.09.2019.
//

#ifndef CPP_OLYMPICS_VISITOR_H
#define CPP_OLYMPICS_VISITOR_H

#include <iostream>

using namespace std;
// forward declaration
class Monkey;
class lion;
class Animal;


// visitor class
class AnimalOperation
{
public:
    virtual void visitMonkey(Monkey& m) = 0;
};

// visited class
class Animal
{
public:
    virtual void accept(AnimalOperation& aop) = 0;
};

class Monkey : public Animal
{
public:
    void shout(){cout << "monkey\n";}
    void accept(AnimalOperation& aop) final {aop.visitMonkey(*this);}
};

class speak : public AnimalOperation
{
public:
    void visitMonkey(Monkey& m) final {m.shout();}
};

#endif //CPP_OLYMPICS_VISITOR_H
