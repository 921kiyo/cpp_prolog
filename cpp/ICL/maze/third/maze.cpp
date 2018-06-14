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

void find_marker(char ch, char** maze, int height, int width, int& row, int& column){
  for(int r = 0; r < height; r++){
    for(int c = 0; c < width; c++){
      if(maze[r][c] == ch){
        row = r;
        column = c;
        return;
      }
    }
  }
  row = -1;
  column = -1;
}


bool valid_solution(const char* path, char** maze, int height, int width){
  int row_now, column_now;
  find_marker('>', maze, height, width, row_now, column_now);

  if(!is_path_valid(path)){
    return false;
  }

  for(int i = 0; path[i] != '\0'; i++){
    move(maze, height, width, path[i], row_now, column_now);
    if(!is_valid_square(maze[row_now][column_now], '>', 'X')){
      return false;
    }
  }

  int row_end, column_end;
  find_marker('X', maze, height, width, row_end, column_end);
  if(row_now != row_end || column_now != column_end){
    return false;
  }
  return true;
}

void move(char** maze, int height, int width, char direction, int& row, int& column){
  switch (direction) {
    case('N'): row--; break;
    case('S'): row++; break;
    case('E'): column++; break;
    case('W'): column--; break;
  }
}
bool is_valid_square(char square, char start, char end){
  if(square == ' ' || square == start || square == end){
    return true;
  }else{
    return false;
  }
}

bool is_path_valid(const char* path){
  for(int i = 0; path[i] != '\0'; i++){
    if(path[i] == 'N' || path[i] == 'S' || path[i] == 'E' || path[i] == 'W'){
      continue;
    }else{
      return false;
    }
  }
  return true;
}

string find_path(char** maze, int height, int width, char start, char end){
  char path[1000];
  strcpy(path, "");

  int row, column;
  find_marker(start, maze, height, width, row, column);
  cout << "end " << end << " row: " << row << " column: " << column << endl;
  if(recursive(maze, height, width, start, end, row, column, path, 0)){
    string path_str(path);
    return path_str;
  }else{
    return "so solution";
  }
}

bool recursive(char** maze, int height, int width, char start, char end, int row, int column, char* path, int path_length){
    // print_maze(maze, height, width);
    if(maze[row][column] == end){
      maze[row][column] = '#';
      path[path_length] = '\0';
      return true;
    }

    char freeDir[5];
    get_free(maze, height, width, row, column, start, end, freeDir);

    // No direction left, backtracking....
    if(!strcmp(freeDir, "")){
      // No solution
      if(!strcmp(path, "")){
        return false;
      }

      maze[row][column] = '.';
      char dir = path[path_length-1];
      path[path_length] = '\0';
      path_length --;

      move(maze, height, width, opposite(dir), row, column);
      return recursive(maze, height, width, start, end, row, column, path, path_length);
    }

    maze[row][column] = '#';

    move(maze, height,width, freeDir[0], row, column);
    path[path_length] = freeDir[0];
    path_length++;
    return recursive(maze, height, width, start, end, row, column, path, path_length);
}

char opposite(char dir){
  switch (dir) {
    case('N'): return 'S';
    case('S'): return 'N';
    case('W'): return 'E';
    case('E'): return 'W';
  }
}

void get_free(char** maze, int height, int width, int row, int column, char start, char end, char* freeDir){
  strcpy(freeDir, "");
  int counter = 0;
  if(column+1 <= width && is_valid_square(maze[row][column+1], start, end)){
    freeDir[counter] = 'E';
    counter++;
  }
  if(column-1 >= 0 && is_valid_square(maze[row][column-1], start, end)){
    freeDir[counter] = 'W';
    counter++;
  }
  if(row-1 >= 0 && is_valid_square(maze[row-1][column], start, end)){
    freeDir[counter] = 'N';
    counter++;
  }
  if(row+1 <= height && is_valid_square(maze[row+1][column], start, end)){
    freeDir[counter] = 'S';
    counter++;
  }

  freeDir[counter] = '\0';
}
