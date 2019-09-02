//
// Created by elshahawy on 01.09.2019.
//

#ifndef CPP_OLYMPICS_VISITOR_H
#define CPP_OLYMPICS_VISITOR_H

#include <iostream>

using namespace std;
namespace basic_pattern
{
    class Animal
    {
        virtual void speak() = 0;
        virtual void jump() = 0;
        virtual void move() = 0;
    };
    // each animal will represent its own implementation
//    class monkey : public Animal
//    class dolphin : public Animal
}
namespace visitor_pattern {
// forward declaration
    class Monkey;
    class Lion;
    class Animal;
// visitor class
    class AnimalOperation {
    public:
        virtual void visitMonkey(Monkey &m) = 0;
        virtual void visitLion(Lion &l) = 0;
    };
// visited class
    class Animal {
    public:
        virtual void accept(AnimalOperation &aop) = 0;
    };
    class Monkey : public Animal {
    public:
        void speak() { cout << "monkey sound\n"; }
        void accept(AnimalOperation &aop) final { aop.visitMonkey(*this); }
    };
    class Lion : public Animal
    {
    public:
        void speak() {cout << "lion roar\n";}
        void accept(AnimalOperation& aop) override {aop.visitLion(*this);}
    };
    class speak : public AnimalOperation {
    public:
        void visitMonkey(Monkey &m) final { m.speak(); }
        void visitLion(Lion &l) final {l.speak();}
    };

    // another example
    class car;
    class airplane;
    class vehicle_visitor
    {
    public:
        virtual void visitCar(car& c) = 0;
        virtual void visitAirplane(airplane& a) = 0;
    };
    class vehicle
    {
    public:
        virtual void accept(vehicle_visitor& vvs) = 0;
    };
    class car : public vehicle
    {
    public:
        void drive(string destination){cout << "drive to destination\n";};
        void accept(vehicle_visitor& vvs) override {vvs.visitCar(*this);}
    };
    class airplane : public vehicle
    {
    public:
        void fly(string destination){cout << "fly to destination\n";};
        void accept(vehicle_visitor& vvs) override {vvs.visitAirplane(*this);}
    };
    class move_vehicle : public vehicle_visitor
    {
    private:
        string destination{"Home location"};
    public:
        void visitCar(car& c) override {c.drive(destination);};
        void visitAirplane(airplane& a) override {a.fly(destination);};
    };
}
#endif //CPP_OLYMPICS_VISITOR_H
