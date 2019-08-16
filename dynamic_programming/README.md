## Dynamic programming
What I hope to convey is that DP is a useful technique for optimization problems, those problems that seek the maximum or minimum solution given certain constraints, because it looks through all possible sub-problems and never recomputes the solution to any sub-problem. This guarantees correctness and efficiency, which we cannot say of most techniques used to solve or approximate algorithms. This alone makes DP special.
[demystifying-dynamic-programming](https://www.freecodecamp.org/news/demystifying-dynamic-programming-3efafb8d4296/)

Dynamic Programming is mainly an optimization over plain recursion. Wherever we see a recursive solution that has repeated calls for same inputs, we can optimize it using Dynamic Programming. The idea is to simply store the results of subproblems, so that we do not have to re-compute them when needed later. This simple optimization reduces time complexities from exponential to polynomial. For example, if we write simple recursive solution for Fibonacci Numbers, we get exponential time complexity O(2^n) and if we optimize it by storing solutions of subproblems, time complexity reduces to linear O(n).
[dynamic-programming](https://www.geeksforgeeks.org/dynamic-programming/)

![alt text](https://www.geeksforgeeks.org/wp-content/uploads/Dynamic-Programming-1-768x384.png)

![alt text](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Tabulation-vs-Memoization-1.png)

### Factorial problem
![alt text](https://media.geeksforgeeks.org/wp-content/cdn-uploads/factorial.png)

### Fibonacci problem
0,1,1,2,3,5,8,13,21...
Fn = Fn-1 + Fn-2; F0 = 0 and F1 = 1


### Knapsack problem

Given weights and values of n items. Put these items in a knapsack of capacity W to get maximum total value.
Need to try different combinations to get maximum; optimization problem.

![alt text](https://www.geeksforgeeks.org/wp-content/uploads/knapsack-problem-660x285.png)