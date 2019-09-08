//
// Created by elshahawy on 08.09.2019.
//

#ifndef CPP_OLYMPICS_COPY_SWAP_IDIOM_H
#define CPP_OLYMPICS_COPY_SWAP_IDIOM_H

#include <algorithm> // std::copy
#include <cstddef> // std::size_t

///@brief
/// https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom
/// How does it work?
///Conceptually, it works by using the copy-constructor's functionality to create a local copy
/// of the data, then takes the copied data with a swap function, swapping the old data with
/// the new data. The temporary copy then destructs, taking the old data with it.
/// We are left with a copy of the new data.
///In order to use the copy-and-swap idiom, we need three things: a working copy-constructor,
///a working destructor (both are the basis of any wrapper, so should be complete anyway),
/// and a swap function.
///A swap function is a non-throwing function that swaps two objects of a class,
/// member for member. We might be tempted to use std::swap instead of providing our own,
/// but this would be impossible; std::swap uses the copy-constructor and copy-assignment
/// operator within its implementation, and we'd ultimately be trying to define the assignment
/// operator in terms of itself!
///(Not only that, but unqualified calls to swap will use our custom swap operator,
/// skipping over the unnecessary construction and destruction of our class that std::swap
/// would entail.)

class dumb_array
{
public:
    // (default) constructor
    dumb_array(std::size_t size = 0)
            : mSize(size),
              mArray(mSize ? new int[mSize]() : nullptr)
    {    }
    // copy-constructor
    dumb_array(const dumb_array& other)
    {
      mSize = other.mSize;
      mArray = (mSize ? new int[mSize] : nullptr);
      /// fine for int array case
      std::copy(other.mArray, other.mArray + mSize, mArray);
    }
    // destructor
    ~dumb_array()
    {
        delete [] mArray;
    }
    // why friend
    // https://stackoverflow.com/questions/5695548/public-friend-swap-member-function
    // https://stackoverflow.com/questions/8111677/what-is-argument-dependent-lookup-aka-adl-or-koenig-lookup
    friend void swap(dumb_array& first, dumb_array& second) // nothrow
    {
      using std::swap;
      // by swapping the members of two objects,
      // the two objects are effectively swapped
      // swap is non-throwing
      swap(first.mSize, second.mSize);
      swap(first.mArray, second.mArray);
    }
    // copy-operator
    dumb_array& operator=(dumb_array other) // (1)
    {
      swap(*this, other);
      return *this;
    }
private:
    std::size_t mSize;
    int* mArray;
};


#endif //CPP_OLYMPICS_COPY_SWAP_IDIOM_H
