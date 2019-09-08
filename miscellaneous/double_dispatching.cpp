//
// Created by elshahawy on 08.09.2019.
//

#ifndef CPP_OLYMPICS_DOUBLE_DISPATCHING_H
#define CPP_OLYMPICS_DOUBLE_DISPATCHING_H

#include <iostream>
class SpaceShip;
class ApolloSpacecraft;
class Asteroid {
public:
    virtual void CollideWith(SpaceShip&) {
        std::cout << "Asteroid hit a SpaceShip\n";
    }
    virtual void CollideWith(ApolloSpacecraft&) {
        std::cout << "Asteroid hit an ApolloSpacecraft\n";
    }
};
class ExplodingAsteroid : public Asteroid {
public:
    void CollideWith(SpaceShip&) override {
        std::cout << "ExplodingAsteroid hit a SpaceShip\n";
    }
    void CollideWith(ApolloSpacecraft&) override {
        std::cout << "ExplodingAsteroid hit an ApolloSpacecraft\n";
    }
};
class SpaceShip
{
public:
    ///@brief solution to issue using double dispatching
    virtual void CollideWith(Asteroid& inAsteroid) {
        inAsteroid.CollideWith(*this);
    }
};
class ApolloSpacecraft : public SpaceShip {
public:
    ///@brief solution to issue using double dispatching
    virtual void CollideWith(Asteroid& inAsteroid) {
        inAsteroid.CollideWith(*this);
    }
};
int main()
{
    Asteroid theAsteroid;
    SpaceShip theSpaceShip;
    ApolloSpacecraft theApolloSpacecraft;
    ExplodingAsteroid theExplodingAsteroid;
    ///@brief Issue in the following code:
    /// expected o/p:
    /// Asteroid hit an ApolloSpacecraft and
    /// ExplodingAsteroid hit an ApolloSpacecraft
    /// The problem is that, while virtual functions are
    /// dispatched dynamically in C++, function overloading
    /// is done statically.
    SpaceShip& theSpaceShipReference = theApolloSpacecraft;
    Asteroid& theAsteroidReference = theExplodingAsteroid;
    theAsteroid.CollideWith(theSpaceShipReference);
    theAsteroidReference.CollideWith(theSpaceShipReference);
    /// applying double dispatching
    /// The key is that theSpaceShipReference.CollideWith(theAsteroidReference);
    /// does the following at run time: theSpaceShipReference is a reference,
    /// so C++ looks up the correct method in the vtable. In this case,
    /// it will call ApolloSpacecraft::CollideWith(Asteroid&).
    /// Within ApolloSpacecraft::CollideWith(Asteroid&),
    /// inAsteroid is a reference, so inAsteroid.CollideWith(*this)
    /// will result in another vtable lookup. In this case,
    /// inAsteroid is a reference to an ExplodingAsteroid so
    /// ExplodingAsteroid::CollideWith(ApolloSpacecraft&) will be called.
    /// https://pabloariasal.github.io/2017/06/10/understanding-virtual-tables/
    theSpaceShipReference.CollideWith(theAsteroid);
    theSpaceShipReference.CollideWith(theAsteroidReference);

}

#endif //CPP_OLYMPICS_DOUBLE_DISPATCHING_H
