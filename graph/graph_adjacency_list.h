//
// Created by elshahawy on 27.10.2019.
//

#ifndef CPP_OLYMPICS_GRAPH_ADJACENCY_LIST_H
#define CPP_OLYMPICS_GRAPH_ADJACENCY_LIST_H

#include <list>
#include <vector>
#include <iostream>
#include "graph_utils.h"

///@brief The adjacency list representation of a graph is linked list representation.
/// In this representation we have an array of lists The array size is V.
/// Here V is the number of vertices. In other words, we can say that we
/// have an array to store V number of different lists. If a list header is
/// vertex u, then it signifies that it will hold all of the adjacent vertices of u.
/// The adjacency matrix of a graph is a square matrix of size

/// space complexity O(V+E) if directed graph(di-graph)
/// space complexity O(V+2E) if un-directed graph

/// adding,removing and querying edges is O(1)
/// adding vertex is O(V^2)

using namespace std;

namespace al_graph
{

struct node
{
  int value{-1}, color{0};
};
class di_graph
{
private:
  vector<list<node>> adjacency_list;
public:
  di_graph(vector<edge>& edges, vector<int>& node_values, int number_of_nodes) : adjacency_list(number_of_nodes)
  {
    for (auto &edge : edges)
    {
      adjacency_list[edge.start].emplace_back(node{edge.end, edge.weight});
    }
//    for(auto i{0}; i < node_values.size(); ++i)
//    {
//      adjacency_list[i]
//    }
  }
  void visualize()
  {
    auto c{0};
    for(auto& node_list : adjacency_list)
    {
      cout << "node: " << c << " is connected to ";
      for(auto& node : node_list)
      {
        cout << node.value << ", ";
      }
      cout << "\n";
      ++c;
    }
  }
};
}
#endif // CPP_OLYMPICS_GRAPH_ADJACENCY_LIST_H
