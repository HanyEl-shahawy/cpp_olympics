//
// Created by elshahawy on 8/16/19.
//

#ifndef DYNAMIC_PROGRAMMING_KNAPSACK_H
#define DYNAMIC_PROGRAMMING_KNAPSACK_H

#include <vector>

using namespace std;

int knapsack_rec(vector<int>& value, vector<int>& weight, int W, int index)
{
    ///@brief takes inputs and index of an item, checks if it is below maximum capacity then calls same function
    /// 2 times, one time with the index-item included and thus the capacity is reduced,
    /// and other time just discarding it ... takes the maximum of 2 of them
    if(index == 0 || W == 0)
        return 0;

    if(weight[index] > W)
        return knapsack_rec(value,weight,W,index-1);
    else
        return max(value[index] + knapsack_rec(value,weight,W-weight[index], index-1),
                   knapsack_rec(value,weight,W,index-1));

}

int knapsack_rec_dp(vector<int>& value, vector<int>& weight, int W, int index)
{
    ///@brief using dynamic programming
    static vector<vector<int>> lookup(index + 1, vector<int>(W + 1, -1));

    for (auto i{0}; i <= index; ++i)
    {
        for(auto j{0}; j <= W; ++j)
        {
            if(i == 0 || j == 0)
                lookup[i][j] = 0;
            else if(weight[i-1] > j)
                lookup[i][j] = lookup[i-1][j];
            else
                lookup[i][j] = max(value[i-1] + lookup[i-1][j-weight[i-1]],
                                   lookup[i-1][j]);
        }
    }
    return lookup[index][W];

}

#endif //DYNAMIC_PROGRAMMING_KNAPSACK_H
