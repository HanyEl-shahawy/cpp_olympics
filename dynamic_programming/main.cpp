#include <iostream>
#include "factorial.h"
#include "fibonacci.h"
#include "knapsack.h"
#include <vector>

int main() {
    vector<int> value {60,100,120};
    vector<int> weight {10,20,30};
    int W = 50;
    std::cout << "********* knapsack **********" << std::endl;
    std::cout << knapsack_rec(value, weight, W, static_cast<int>(value.size()) - 1) << std::endl;
    std::cout << knapsack_rec_dp(value, weight, W, static_cast<int>(value.size())) << std::endl;
    int n = 9;
    std::cout << "********* fibonacci **********" << std::endl;
    std::cout << fib_rec(n) << std::endl;
    std::cout << fib_dp_tabulation(n) << std::endl;
    std::cout << fib_dp_memoization(n) << std::endl;
    n = 10;
    std::cout << "********* factorial **********" << std::endl;
    std::cout << fac_rec(n) << std::endl;
    std::cout << fac_dp_tabulation(n) << std::endl;
    std::cout << fac_dp_memoization(n) << std::endl;
    return 0;
}