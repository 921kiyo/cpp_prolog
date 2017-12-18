#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include "maze.h"

using namespace std;

/* You are pre-supplied with the functions below. Add your own
   function definitions to the end of this file. */

/* helper function which allocates a dynamic 2D array */
char **allocate_2D_array(int rows, int columns) {
  char **m = new char *[rows];
  assert(m);
  for (int r=0; r<rows; r++) {
    m[r] = new char[columns];
    assert(m[r]);
  }
  return m;
}

/* helper function which deallocates a dynamic 2D array */
void deallocate_2D_array(char **m, int rows) {
  for (int r=0; r<rows; r++)
    delete [] m[r];
  delete [] m;
}

/* helper function for internal use only which gets the dimensions of a maze */
bool get_maze_dimensions(const char *filename, int &height, int &width) {
  char line[512];

  ifstream input(filename);

  height = width = 0;

  input.getline(line,512);
  while (input) {
    if ( (int) strlen(line) > width)
      width = strlen(line);
    height++;
    input.getline(line,512);
  }

  if (height > 0)
    return true;
  return false;
}

/* pre-supplied function to load a maze from a file*/
char **load_maze(const char *filename, int &height, int &width) {

  bool success = get_maze_dimensions(filename, height, width);

  if (!success)
    return NULL;

  char **m = allocate_2D_array(height, width);

  ifstream input(filename);

  char line[512];

  for (int r = 0; r<height; r++) {
    input.getline(line, 512);
    strcpy(m[r], line);
  }

  return m;
}

/* pre-supplied function to print a maze */
void print_maze(char **m, int height, int width) {
  cout << setw(4) << " " << " ";
  for (int c=0; c<width; c++)
    if (c && (c % 10) == 0)
      cout << c/10;
    else
      cout << " ";
  cout << endl;

  cout << setw(4) << " " << " ";
  for (int c=0; c<width; c++)
    cout << (c % 10);
  cout << endl;

  for (int r=0; r<height; r++) {
    cout << setw(4) << r << " ";
    for (int c=0; c<width; c++)
      cout << m[r][c];
    cout << endl;
  }
}


void find_marker(char path, char** maze, int height, int width, int& row, int& column){
  row = -1;
  column = -1;
  for(int r = 0; r< width; r++){
    for(int c = 0; c<height; c++){
      if(maze[r][c] == path){
        row = r;
        column = c;
      }
    }
  }
}

bool valid_solution(const char* path, char** maze, int height, int width){
  // Assign the starting point
  int row_now = 0;
  int column_now = 0;
  // char direction;
  find_marker('>', maze, height, width, row_now, column_now);
  // int path_length = strlen(path);
  int path_length = 10;
  for(int i = 0; i < path_length-1; i++){
      if(move_forward(maze, height, width, path[i], row_now, column_now)&& (maze[row_now][column_now] != ' '));
        return false;
  }

  // Checking if it stops at the exit (X)
  move_forward(maze, height, width, path[path_length-1], row_now, column_now);

  if(maze[row_now][column_now] == 'X'){
    return true;
  }
  return false;
}

bool move_forward(char** maze, int height, int width, char direction, int& row_now, int& column_now){
  cout << "direction " << direction << endl;
  switch(direction){
    case 'N': row_now--; return true; break;
    case 'S': row_now++; return true; break;
    case 'E': column_now++; return true; break;
    case 'W': column_now--; return true; break;
    default: cout << "There was an error in direction" << endl;
    break;
  }
}

char* find_path(char** maze, int height, int width, char start, char end){
  // DFS or BFS, A* search algorithm
  int counter = 0;
  char explored[40];

  int row_now = 0;
  int column_now = 0;
  find_marker(start, maze, height, width, row_now, column_now);

  explore_path(maze, height, width, explored, row_now, column_now, counter);

  // cout << "explored " << explored << endl;
}

void explore_path(char** maze, int height, int width, char* explored, int& row_now, int& column_now, int counter){
  // Base case
  cout << maze[row_now][column_now] << endl;
  if(valid_solution(explored, maze, height, width)){
    cout << "valid solution " << endl;
    // return 'fa';
    return;
  }
  if(move_forward(maze, height, width, 'N', row_now, column_now)){
    cout << "counter " << counter << endl;
    explored[counter] = 'N';
    counter++;
    return explore_path(maze, height, width, explored, row_now, column_now, counter);
  }
  else if(move_forward(maze, height, width, 'S', row_now, column_now)){
    explored[counter] = 'S';
    counter++;
    return explore_path(maze, height, width, explored, row_now, column_now, counter);
  }
  else if(move_forward(maze, height, width, 'E', row_now, column_now)){
    explored[counter] = 'E';
    counter++;
    return explore_path(maze, height, width, explored, row_now, column_now, counter);
  }
  else if(move_forward(maze, height, width, 'W', row_now, column_now)){
    explored[counter] = 'W';
    counter++;
    return explore_path(maze, height, width, explored, row_now, column_now, counter);
  }
  else{
    cout <<  'no solution' << endl;
    return;
  }
}
