//
// Created by elshahawy on 12/17/19.
//

#ifndef CPP_OLYMPICS_EXPLICIT_TEMPLATE_SPECIALIZATION_H
#define CPP_OLYMPICS_EXPLICIT_TEMPLATE_SPECIALIZATION_H

#include <iostream>

template <typename T> // primary template
struct is_void : std::false_type
{

};

template <> // explicit specialization for T = void
struct is_void<void> : std::true_type
{

};

//int main()
//{
//    // for any type T other than void, the
//    // class is derived from false_type
//    std::cout << is_void<char>::value << '\n';
//    // but when T is void, the class is derived
//    // from true_type
//    std::cout << is_void<void>::value << '\n';
//}

#endif //CPP_OLYMPICS_EXPLICIT_TEMPLATE_SPECIALIZATION_H
