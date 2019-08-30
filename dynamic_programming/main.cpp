#include <iostream>
#include "factorial.h"
#include "fibonacci.h"
#include "partition_problem.h"
#include <vector>

static vector<int> value {60,100,120};
static vector<int> weight {10,20,30};
static int W = 50;
static vector<vector<int>> lookup(value.size() + 1, vector<int> (W + 1, -1));

int knapsack_rec_dp(int W, int n)
{
    for(auto i{0}; i <= n; ++i)
    {
        for(auto j{0}; j <= W; ++j)
        {
            if(i == 0 || j == 0)
                lookup[i][j] = 0;
            else if(weight[i-1] > j)
                lookup[i][j] = lookup[i-1][j];
            else
                lookup[i][j] = std::max(value[i-1] + lookup[i-1][j-weight[i-1]], lookup[i-1][j]);
        }
    }
    return lookup[n][W];
}

int main() {
    std::cout << "********* partition **********" << std::endl;
    vector<int> v{3,1,5,9,12};
    std::cout << is_partition_possible(v) << std::endl;

    std::cout << "********* knapsack **********" << std::endl;
    std::cout << knapsack_rec_dp( W, static_cast<int>(value.size())) << std::endl;
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