//
// Created by elshahawy on 27.09.2019.
//
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int makeAnagram_multiset(vector<char>& a, vector<char>& b) {
  ///@brief store chars of a in multiset then compare with what in b
  /// 
  unordered_multiset<char> multiset_a;
  unordered_multiset<char> multiset_b;
  for (auto& i : a)
  {
    multiset_a.insert(i);
  }
  for (auto& i : b)
  {
    if (multiset_a.erase(i) == 0)
    {
      multiset_b.insert(i);
    }
  }
  return multiset_a.size() + multiset_b.size();
}
vector<int> get_char_counts(vector<char>& a)
{
  static constexpr int NUM_LETTERS{26};
  vector<int> a_char_counts(NUM_LETTERS);
  for (auto & i: a)
  {
    auto char_place{i - 'a'};
    a_char_counts[char_place]++;
  }
  return a_char_counts;
}

int makeAnagram_arrays(vector<char>& a, vector<char>& b){
  /// @brief put each char array in an array of letters size in which every
  /// element is number of occurrences
  auto a_chars{get_char_counts(a)};
  auto b_chars{get_char_counts(b)};
  /// compute the difference
  int diff{0};
  for (size_t i{0} ; i < a_chars.size(); ++i)
  {
    diff += abs(a_chars[i] - b_chars[i]);
  }
  return diff;
}

int main()
{
  vector<pair<pair<string, string>, int>> ip
  {make_pair<pair<string, string>, int>
      (make_pair<string, string>({"fcrxzwscanmligyxyvym"},{"jxwtrhvujlmrpdoqbisbwhmgpmeoke"}), 30),
  make_pair<pair<string, string>, int>
      (make_pair<string, string>({"cde"},{"abc"}), 4),
  make_pair<pair<string, string>, int>
      (make_pair<string, string>({"showman"},{"woman"}), 2)};

  for (auto& i : ip)
  {
    vector<char> vec_a(i.first.first.begin(), i.first.first.end());
    vector<char> vec_b(i.first.second.begin(), i.first.second.end());
    int res = makeAnagram_multiset(vec_a, vec_b);
    cout << "res: " << res << ", exp: " << i.second << "\n";
    assert(res == i.second);
    res = makeAnagram_arrays(vec_a, vec_b);
    cout << "res: " << res << ", exp: " << i.second << "\n";
    assert(res == i.second);
  }
  return 0;
}
