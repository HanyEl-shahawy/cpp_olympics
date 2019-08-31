//
// Created by elshahawy on 31.08.2019.
//

#ifndef CPP_OLYMPICS_ADAPTER_H
#define CPP_OLYMPICS_ADAPTER_H

#include <iostream>

using namespace std;
class lion
{
    virtual void roar(){} = 0;
};

class african_lion : public lion
{
public:
    void override roar() final {cout << "african roar\n";}
};

class asian_lion : public lion
{
public:
    void override roar() final {cout << "asian roar\n";}
};

// hunter who can hunt any lion type

class hunter
{
public:
    void hunt(lion* prey)
    {
        prey->roar();
        cout << "kill prey\n";
    }
};

// now a new prey is added - wild dog- and hunter should hunt it as well

class wild_dog
{
public:
    void bark(){cout << "bark\n";}
};

// hunter expects lion type only, so an adapter is added

class wild_dog_adapter : public lion
{
protected:
    wild_dog* dog;
public:
    wild_dog_adapter(wild_dog* d) : dog(d){}
    void override roar() final {cout << dog->bark();}
};

#endif //CPP_OLYMPICS_ADAPTER_H
