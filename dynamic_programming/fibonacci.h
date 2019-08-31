//
// Created by elshahawy on 8/16/19.
//

#ifndef DYNAMIC_PROGRAMMING_FIBONACCI_H
#define DYNAMIC_PROGRAMMING_FIBONACCI_H

int fib_rec(int n)
{
    ///@brief return nth element in fibonacci sequence
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return fib_rec(n-1) + fib_rec(n-2);
}

int fib_dp_tabulation(int n)
{
    ///@brief dp using tabulation method
    vector<int> lookup(n+1, -1);

    lookup[0] = 0;
    lookup[1] = 1;

    for(auto i{2}; i <= n; ++i)
    {
        lookup[i] = lookup[i-1] + lookup[i-2];
    }
    return lookup[n];
}

int fib_dp_memoization(int n)
{
    ///@brief dp using tabulation method
    static vector<int> lookup(n+1, -1);

    if(lookup[n] == -1)
    {
        if(n==0)
            lookup[0] = 0;
        else if(n==1)
            lookup[1] = 1;
        else
            return fib_dp_memoization(n-1) + fib_dp_memoization(n-2);
    }
    return lookup[n];
}


#endif //DYNAMIC_PROGRAMMING_FIBONACCI_H
