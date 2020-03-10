//
// Created by elshahawy on 28.08.2019.
//
//#include <iostream>
//#include "shared_pointer.h"
#include <memory>

using namespace std;

class ref_count
{
private:
    int rc{};
public:
    ref_count() : rc(0) {};

    int get() const {return rc;}

    // pre increment
    void operator++ (){ ++rc;}
    void operator-- (){--rc;}
    // post increment
    void operator++(int) {++rc;}
    void operator--(int) {--rc;}

};

template <typename T>
class shared_pointer
{
private:
    T* pointer{nullptr};
    ref_count* rc{nullptr};
public:
    explicit shared_pointer(T* ptr = nullptr)
    {
//        cout << "shared_pointer" << endl;
        pointer = ptr;
        rc = new ref_count();
        if(ptr)
            (*rc)++;
    }
    // copy constructor
    shared_pointer(shared_pointer<T> &sp)
    {
//        cout << "shared_pointer copy constructor" << endl;
        pointer = sp.pointer;
        rc = sp.rc;
        ++(*rc);
    }
    ~shared_pointer()
    {
//        cout << "destructor" << endl;
        --(*rc);
        if (rc->get() == 0)
        {
            delete pointer;
            delete rc;

        }
    }

    // get raw pointer
    T* get(){ return pointer;}
};

///@brief make_unique for c++11
template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return unique_ptr<T>(new T(std::forward<Args>(args)...));
}



int main()
{
    shared_pointer<int> sp (new int(5));
    {
        auto sp2{sp};
    }
//    std::cout << "end " << std::endl;
}
