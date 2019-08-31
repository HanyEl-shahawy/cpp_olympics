//
// Created by elshahawy on 8/16/19.
//

#ifndef DYNAMIC_PROGRAMMING_FACTORIAL_H
#define DYNAMIC_PROGRAMMING_FACTORIAL_H

#include <vector>

using namespace std;

int fac_rec(int n)
{
    ///@brief return n!
    if(n == 1 || n == 0)
        return 1;
    else
        return n*fac_rec(n-1);
}

int fac_dp_tabulation(int n)
{
    ///@brief create lookup table to avoid re-calculating
    /// with length of n and initalized to -1
    /// tabulation method (bottom - up)
    vector<int> lk (n+1, -1);

    for(auto i{0}; i <= n; ++i)
    {
        if (i == 0 || i == 1)
            lk[i] = 1;
        else
            lk[i] = i * lk[i-1];
    }
    return lk[n];
}

int fac_dp_memoization(int n)
{
    ///@brief create lookup table to avoid re-calculating
    /// with length of n and initalized to -1
    /// memoization method (up-bottom)
    static vector<int> lk(n+1, -1);

    if(n == 0)
        return  1;
    else
        lk[n] = n * fac_dp_memoization(n-1);
    return lk[n];
}

#endif //DYNAMIC_PROGRAMMING_FACTORIAL_H
