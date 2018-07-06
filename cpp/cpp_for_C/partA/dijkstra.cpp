#include <iostream>
#include <vector>

using namespace std;

// Undirected graph
class Graph{
  vector<vector<bool>> matrices;
  int V_; // the number of vertices
  int E_; // the number of edges
  // use connectivity matrices
private:
  Graph(int V, int E): V_(V), E_(E){

  }
  bool adjacent(int node_x, int node_y){

  }

  bool add_edge(int x, int y){
    // check if this edge already exists
  }

  bool delete_edge(int x, y){

  }

  int get_node_value(int node_x){
    return 1;
  }

  void set_node_value(int x, int a){
    // returns the value associated with the node x to a

  }

  int get_edge_value(int x, int y){
    
  }


public:


  // Randomly generated set of edges with positive distances.
  void random_graph_generator(double density, double lower_dis_range, double higher_dis_range){
    // Density must be within 0 to 1

    // for all edges (i,j),
    // if a random prob is less than the density, place an edge
  }

};

class PriorityQueue{

};

class ShortestPath{

};

int main(){
  return 0;
}
