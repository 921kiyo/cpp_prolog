#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <string>
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
  for(int r = 0; r< height; r++){
    for(int c = 0; c< width; c++){
      // cout << "row " << r << endl;
      // cout << "col " << c << endl;
      // cout << "maze[r][c] " << maze[r][c] << endl;
      // cout << "path " << path << endl;
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
  for(int i = 0; path[i] != '\0'; i++){
      if(!move_forward(maze, height, width, path[i], row_now, column_now)){
        return false;
      }
      if((maze[row_now][column_now] == ' ' || maze[row_now][column_now] == '>' || maze[row_now][column_now] == 'X')){
        continue;
      }
      else{
        return false;
      }
  }

  // Checking if it stops at the exit (X)
  int row_goal = 0;
  int column_goal = 0;
  find_marker('X', maze, height, width, row_goal, column_goal);
  if(row_now == row_goal && column_goal == column_goal){
    return true;
  }
  return false;
}

bool move_forward(char** maze, int height, int width, char direction, int& row_now, int& column_now){
  switch(direction){
    case 'N': row_now--; return true; break;
    case 'S': row_now++; return true; break;
    case 'E': column_now++; return true; break;
    case 'W': column_now--; return true; break;
    default: cout << "There was an error in direction" << direction << endl;
    return false;
    break;
  }
}

string find_path(char** maze, int height, int width, char start, char end){

  int current_row = 0;
  int current_column = 0;
  find_marker(start, maze, height, width, current_row, current_column);
  char path[1000];

  strcpy(path, "");
  if(explore_path(maze, height, width, current_row, current_column, path, 0, start, end)){
    string path_str(path);
    remove_dot(maze, height, width);
    return path_str;
  }else{
    return "no solution";
  }
}

void remove_dot(char** maze, int height, int width){
  for(int r = 0; r < height; r++){
    for(int c = 0; c < width; c++){
      if(maze[r][c] == '.'){
        maze[r][c] = ' ';
      }
    }
  }
}

bool explore_path(char** maze, int height, int width, int& row_now, int& column_now, char* path, int path_length, char start, char end){
  // Base case
  // print_maze(maze, height, width);
  if(maze[row_now][column_now] == end){
    // cout << "finish!" << endl;
    path[path_length] = '\0';
    return true;
  }

  char freeDir[5];
  strcpy(freeDir, "");
  get_free_direction(maze, height, width, row_now, column_now, freeDir, start, end);
  // // It's stuck,
  if(!strcmp(freeDir, "")){
    // if position is the first one, return false
    if(maze[row_now][column_now] == start){
      return false;
    }
    // When going back, put . to the cell
    // Reduce the path
    maze[row_now][column_now] = '.';
    move_forward(maze, height, width, opposite(path[path_length-1]), row_now, column_now);
    path[path_length-1] = '\0';
    path_length--;
    return explore_path(maze, height, width, row_now, column_now, path, path_length, start, end);
  }

  if(maze[row_now][column_now] == ' '){
    maze[row_now][column_now] = '#';
  }
  move_forward(maze, height, width, freeDir[0], row_now, column_now);
  path[path_length] = freeDir[0];
  path_length++;

  return explore_path(maze, height, width, row_now, column_now, path, path_length, start, end);
  // if(explore_path(maze, height, width, row_now, column_now, path, path_length)){
  //   return true;
  // }
  // maze[row_now][column_now] = '.';
  // move_forward(maze, height, width, opposite(freeDir[i]), row_now, column_now);
  // for(int i = 0; freeDir[i] != '/0'; i++){
  //     move_forward(maze, height, width, freeDir[i], row_now, column_now);
  //     maze[row_now][column_now] = '#';
  //     path[path_length] = freeDir[i];
  //     path_length++;
  //     if(explore_path(maze, height, width, row_now, column_now, path, path_length)){
  //       return true;
  //     }
  //     maze[row_now][column_now] = '.';
  //     move_forward(maze, height, width, opposite(freeDir[i]), row_now, column_now);
  // }

  // maze[row_now][column_now] = '#';
  // return explore_path(maze, height, width, row_now, column_now, path, path_length);
}

char opposite(char direction){
  switch(direction){
    case 'N': return 'S';
    case 'S': return 'N';
    case 'W': return 'E';
    case 'E': return 'W';
  }
}

void get_free_direction(char** maze, int height, int width, int row, int column, char* freeDir, char start, char end){
  int new_row = row;
  int new_column = column;
  new_row++;
  if(is_available(maze, new_row, new_column, start, end) && new_row <= height){
    strcat(freeDir, "S");
  }
  new_row = row;
  new_row--;
  if(is_available(maze, new_row, new_column, start, end) && new_row >= 0){
    strcat(freeDir, "N");
  }
  new_row = row;
  new_column++;
  if(is_available(maze, new_row, new_column, start, end) && new_row <= width){
    strcat(freeDir, "E");
  }
  new_column = column;
  new_column--;
  if(is_available(maze, new_row, new_column, start, end) && new_row >= 0){
    strcat(freeDir, "W");
  }
}

bool is_available(char** maze, int row, int column, char start, char end){
  return (maze[row][column] == ' ' || maze[row][column] == start || maze[row][column] == end);
}
