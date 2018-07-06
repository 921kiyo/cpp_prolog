#include <iostream>
#include <stdlib.h>

using namespace std;

const int size = 7;


int main(){
  bool** graph;
  srand(time(0));
  graph = new bool*[size];
  for(int i = 0; i < size; i++){
    graph[i] = new bool[size];
  }
  return 0;
}
