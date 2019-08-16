#include <iostream>
#include "factorial.h"
#include "fibonacci.h"

int main() {
    int n = 7;
    std::cout << "********* fibonacci **********" << std::endl;
    std::cout << fib_rec(n) << std::endl;
    std::cout << fac_db_tabulation(n) << std::endl;
    std::cout << fac_db_memoization(n) << std::endl;

    std::cout << "********* factorial **********" << std::endl;
    std::cout << fac_rec(n) << std::endl;
    std::cout << fac_db_tabulation(n) << std::endl;
    std::cout << fac_db_memoization(n) << std::endl;
    return 0;
}