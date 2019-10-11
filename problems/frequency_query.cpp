//
// Created by elshahawy on 09.10.2019.
//
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {
    unordered_map<int, int> m;
    vector<int> r{};
    for (auto& v : queries)
    {
        if(v[0] == 1)
        {
          m[v[1]]++;
        }
        else if(v[0] == 2)
        {
          if (m.find(v[1]) != m.end())
            m[v[1]]--;
        }
          else if(v[0] == 3)
          {
            auto it{find_if(m.begin(), m.end(),
                [&v](const pair<int,int>& key_value)
                {return key_value.second == v[1];})};
            if (it != m.end())
              r.emplace_back(1);
            else
              r.emplace_back(0);
          }
    }
    return r;
}

int main()
{
  // given q queries, each is 2 integers:
  // 1 x: insert x
  // 2 y; delete one ocurrence of y if present
  // 3 z: check if any integer is present whose frequ is z
    vector<vector<int>> queries{
      {1,5},
      {1,6},
      {3,2},
      {1,10},
      {1,10},
      {1,6},
      {2,5},
      {3,2}};
    vector<int> ans = freqQuery(queries);

    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i];

        if (i != ans.size() - 1) {
          std::cout << "\n";
        }
    }
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
