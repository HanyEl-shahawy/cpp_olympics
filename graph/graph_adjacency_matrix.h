//
// Created by elshahawy on 27.10.2019.
//

#ifndef CPP_OLYMPICS_GRAPH_ADJACENCY_MATRIX_H
#define CPP_OLYMPICS_GRAPH_ADJACENCY_MATRIX_H

#include "graph_utils.h"
#include <iostream>
#include <vector>

///@brief The adjacency matrix of a graph is a square matrix of size
/// V x V. The V is the number of vertices of the graph G.
/// In this matrix in each side V vertices are marked.
/// If the graph has some edges from i to j vertices,
/// then in the adjacency matrix at ith row and jth column
/// it will be 1 (or some non-zero value for weighted graph),
/// otherwise that place will hold 0.

/// space complexity O(V^2) if directed graph(di-graph)
/// space complexity O(V^2)/2 if un-directed graph
/// adding,removing and querying edges is O(1)
/// adding vertex is O(V^2)

using namespace std;

namespace am_graph
{
static vector<vector<int>> di_graph(NUM_OF_VERTICES, vector<int>(NUM_OF_VERTICES));


void display_graph()
{
  for(auto &row : di_graph)
  {
       for(auto &col : row)
      {
        cout << col <<  ",";
      }
      cout << "\n";
  }
}

void add_edge(vector<edge>& edges)
{
  ///@brief add edge from v1 to v2 with weight
  for (auto &edge : edges)
  {
    di_graph[edge.start][edge.end] = edge.weight;
  }
}
}


#endif // CPP_OLYMPICS_GRAPH_ADJACENCY_MATRIX_H
