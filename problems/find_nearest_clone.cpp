//
// Created by elshahawy on 27.10.2019.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <deque>

using namespace std;

// Complete the findShortest function below.

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */
struct node
{
  int color{0};
  int path{0};
  vector<node*> neighbours{};
};
class di_graph
{
private:
  vector<node> nodes_;
  unordered_map<long, int> nodes_ids{};
public:
  di_graph(int graph_nodes, vector<int>& graph_from_, vector<int>& graph_to_,
           vector<long>& ids_) : nodes_(vector<node>(graph_nodes,node{}))
  {
    for(auto i{0}; i < ids_.size(); ++i)
    {
      nodes_ids[ids_[i]]++;
      nodes_[i].color = ids_[i];
    }
    for (size_t i{0}; i < graph_from_.size(); ++i)
    {
      auto ref{&(nodes_.at(graph_to_[i]-1))};
      nodes_[graph_from_[i]-1].neighbours.emplace_back(ref);
      ref->neighbours.emplace_back(&(nodes_[graph_from_[i]-1]));
    }
  }
  int breadth_first_search_for_same_color(node* source)
  {
    int path{0};
    std::set<node*> visited{};
    std::deque<node*> unvisited{};
    unvisited.emplace_back(source);
    while (!unvisited.empty())
    {
      auto n{unvisited.front()};
      visited.emplace(n);
      unvisited.pop_front();
      for(auto i{0}; i < n->neighbours.size(); ++i)
      {
        if (visited.find(n->neighbours[i]) == visited.end())
        {
          n->neighbours[i]->path = n->path + 1;
          if(n->neighbours[i]->color == source->color)
          {
            return n->neighbours[i]->path;
          } else
          {
            unvisited.emplace_back(n->neighbours[i]);
          }
        }
      }
    }
    return path;
  }
  int get_shortest_path(int val)
  {
    int shortest_path{999};
    for(size_t i{0}; i < nodes_.size(); ++i)
    {
      if(nodes_[i].color == val)
      {
        auto value{breadth_first_search_for_same_color(&(nodes_[i]))};
        if (value != 0 and value < shortest_path)
          shortest_path = value;
      }
    }
    return shortest_path;
  }
  bool is_path_possible(int val)
  {
    if(nodes_ids.count(val))
    {
      if(nodes_ids[val] > 1)
        return true;
    }
    return false;
  }
};

int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to,
    vector<long> ids, int val)
{
  int ans{-1};
  di_graph g(graph_nodes, graph_from, graph_to, ids);
  if (g.is_path_possible(val))
  {
    ans = g.get_shortest_path(val);
  }
  return ans;

}

int main()
{
  int graph_nodes{4};
  vector<int> graph_from{1,1,4};
  vector<int> graph_to{2,3,2};
  vector<long> ids{1,2,1,1};
  int val{1};
  int ans;
  ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);
  std::cout << "expected answer: 1" << "\n";
  std::cout << "answer is " << ans << "\n";

  graph_nodes = 4;
  graph_from = {1,1,4};
  graph_to={2,3,2};
  ids={1,2,3,4};
  val=2;
  ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);
  /// expected answer: -1
  std::cout << "expected answer: -1" << "\n";
  std::cout << "answer is " << ans << "\n";

  graph_nodes = 5;
  graph_from = {1,1,2,3};
  graph_to = {2,3,4,5};
  ids = {1,2,3,3,2};
  val = {2};
  ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);
  /// expected answer: 3
  std::cout << "expected answer: 3" << "\n";
  std::cout << "answer is " << ans << "\n";

  return 0;
}