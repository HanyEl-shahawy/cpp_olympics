//
// Created by elshahawy on 27.10.2019.
//

#include "graph_adjacency_matrix.h"
#include "graph_adjacency_list.h"

int main()
{
  vector<edge> edges{{0,2,1},
                     {2,1,1},
                     {3,4,1},
                     {4,1,1},
                     {0,3,1},
                     {2,2,1},
                     {3,3,1}};
  al_graph::di_graph graph{edges, NUM_OF_VERTICES};
  graph.visualize();

  am_graph::add_edge(edges);
  am_graph::display_graph();
  return 0;
}