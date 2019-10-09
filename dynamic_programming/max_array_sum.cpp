//
// Created by elshahawy on 04.10.2019.
//


#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Complete the maxSubsetSum function below.
int maxSubsetSum_rec(vector<int>& arr, int n) {
  if(n == 0)
    return arr[n];
  else if (n == 1)
  {
    return arr[n];
  }
  else
  {
    auto max1 = max(arr[n] + maxSubsetSum_rec(arr, n - 2),
                    maxSubsetSum_rec(arr, n - 1));
    return max(arr[n], max1);
  }
}

int maxSubsetSum_bottom_up(vector<int>& arr, int n) {
  unordered_map<int, int> tb;
  auto i{0};
  int max_el{};
  for (const auto& x : arr)
  {
    if(i == 0)
      max_el = arr[0];
    else if (i==1)
      max_el = max_el > arr[1] ? max_el : arr[1];
    else
    {
      auto max1 = max(arr[i] + tb[i-2],
                      tb[i - 1]);
      auto max2 = max(arr[i], max1);
      max_el = max_el > max2 ? max_el : max2;
    }
    tb.insert({i,max_el});
    ++i;
  }
  return max_el;
}


int maxSubsetSum(vector<int>& arr, int n) {
  static unordered_map<int, int> tb;
  if(n == 0 or n==1)
    tb.insert({n,arr[n]});
  else if (tb.find(n) == tb.end())
  {
  //  std::cout << "new n" << n << "\n";
    auto max1 = max(arr[n] + maxSubsetSum(arr, n - 2),
                    maxSubsetSum(arr, n - 1));
    tb.insert({n,max(arr[n], max1)});
  }
//  std::cout << "old n" << n << "\n";
  return tb[n];
}

int main()
{
  vector<int>  arr = {3,7, 4, 6, 5,23, 5,23 ,12 ,32,  2, 4, 0, 32, 1, 4,2  ,6,6 ,23,244,2};
//  vector<int>  arr = {2,1,5,8,4};
  auto start = high_resolution_clock::now();
  int res = maxSubsetSum_rec(arr, arr.size()-1);
  auto end = high_resolution_clock::now();
  std::cout << "recursion duration: " << duration_cast<nanoseconds>(end - start).count() << "\n";
  std::cout << res << std::endl;
  start = high_resolution_clock::now();
  int res2 = maxSubsetSum(arr, arr.size()-1);
  end = high_resolution_clock::now();
  std::cout << "dp top down duration: " << duration_cast<nanoseconds>(end - start).count() << "\n";
  std::cout << res2 << std::endl;
  start = high_resolution_clock::now();
  int res3 = maxSubsetSum_bottom_up(arr, arr.size()-1);
  end = high_resolution_clock::now();
  std::cout << "dp bottom up duration: " << duration_cast<nanoseconds>(end - start).count() << "\n";
  std::cout << res3 << std::endl;
  return 0;
}

