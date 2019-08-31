//
// Created by elshahawy on 24.08.2019.
//

#ifndef DYNAMIC_PROGRAMMING_PARTITION_PROBLEM_H
#define DYNAMIC_PROGRAMMING_PARTITION_PROBLEM_H

#include <vector>
#include <numeric>

using namespace std;

bool is_subset_sum(vector<int>& vec, size_t n, int sum)
{
    ///@brief base case: sum is 0
    if (sum == 0)
        return true;
    ///@brief failure case: no more elements and still sum != 0
    if(n == 0 and sum != 0)
        return false;

    ///@brief if last element is > sum, drop it
    if(vec[n-1] > sum)
        return is_subset_sum(vec, n-1, sum);

    ///@brief 2 cases: either last element included or excluded
    return is_subset_sum(vec, n-1, sum - vec[n-1]) ||
    is_subset_sum(vec, n-1, sum);
}

bool is_partition_possible(vector<int>& vec)
{
    size_t n{vec.size()};
    auto sum{accumulate(vec.begin(), vec.end(), 0)};
    auto val{(int)(sum / 2)};
    if(sum % 2 != 0)
        return false;
    else
        return is_subset_sum(vec, n, val);

}

#endif //DYNAMIC_PROGRAMMING_PARTITION_PROBLEM_H
