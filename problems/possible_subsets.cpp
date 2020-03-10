
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> helper(vector<int>& input, int index)
{
    if (index >= input.size())
        return {{}};
    auto subset_ = helper(input, index + 1);
    vector<vector<int>> op;
    for (auto e : subset_)
    {
        op.push_back(e);
    }
    for (auto e : subset_)
    {
        vector<int> current{};
        current.insert(current.begin(), e.begin(), e.end());
        current.push_back(input[index]);
        op.push_back(current);
    }
    return op;
}

void subsets(vector<int> const& input, vector<vector<int>>& output)
{
    ///@brief given integer vector, output 2d vector of all possible subsets
    /// input = {9} , output = {{}, {9}}
    /// input = {9, 12, 15} , output = {{}, {15}, {12}, {12,15}, {9}, {9,15},{9,12}, {9,12,15}}
    /// note: order of subsets does not matter, order of numbers within subset should stay the same
    output = helper(const_cast<vector<int>&>(input), 0);
}

int main() {
    vector<vector<int>> v;
    ///@test
    /// input: {9}, output: {{}, {9}}
    /// input = {9, 12, 15} , output = {{}, {15}, {12}, {12,15}, {9}, {9,15},{9,12}, {9,12,15}}
    subsets({9,8,9,8}, v);
    for (auto& row : v)
    {
        for (auto& col : row)
        {
            cout << col << "\n";
        }
        cout << "**\n";
    }
    return 0;
}

