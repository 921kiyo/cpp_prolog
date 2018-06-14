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
  for(int h = 0; h < height; h++){
    for(int w = 0; w < width; w++){
      if(ch == maze[h][w]){
        row = h;
        column = w;
        return;
      }
    }
  }
  row = -1;
  column = -1;
  return;
}

bool valid_solution(const char* path, char** maze, int height, int width){
  int current_row, current_column, goal_row, goal_column;
  find_marker('>', maze, height, width, current_row, current_column);
  find_marker('X', maze, height, width, goal_row, goal_column);

  // Checking the start
  if(current_row == -1 && current_column == -1){
    return false;
  }

  for(int i = 0; path[i] != '\0'; i++){
    if(!is_path_valid(path[i])){
      return false;
    }
    move_forward(current_row, current_column, path[i]);
    if(maze[current_row][current_column] == ' ' || maze[current_row][current_column] == 'X'){
      continue;
    }else{
      return false;
    }
  }

  if(current_row == goal_row && current_column == goal_column){
    return true;
  }else{
    return false;
  }
}

bool is_path_valid(char path){
  switch(path){
    case('N'):
    case('S'):
    case('E'):
    case('W'): return true;
    default: return false;
  }
}

void move_forward(int& row, int& column, char path){
  switch(path){
    case('N'): row--; break;
    case('S'): row++; break;
    case('E'): column++; break;
    case('W'): column--; break;
  }
}

const char* find_path(char** maze, int height, int width, char start, char end){
  char *path = new char[100];
  // char path[100];
  int current_row, current_column;
  find_marker(start, maze, height, width, current_row, current_column);

  if(maze[current_row][current_column] == end){
    return path;
  }

  char pos = maze[current_row][current_column];

  strcpy(path, "");
  if(!recursive(maze, pos, current_row, current_column, path,0, start, end, height, width)){
    return "no solution";
  }
  const char* solution = path;
  return solution;
}

bool recursive(char** maze, char pos, int row, int column, char* path, int path_length, char start, char end, int height, int width){
  if(pos == end){
    path[path_length] = '\0';
    return true;
  }

  char freeDir[4];
  string f = free_directions(maze, row, column, height, width, start, end);
  const char* ff = f.c_str();
  strcpy(freeDir, ff);

  // Backpropagating
  if(strcmp(freeDir, "") == 0){
    if(pos == start || strcmp(path, "") ==0){
      return false;
    }

    maze[row][column] = '.';

    pos = next_pos(row, column, opposite(path[path_length-1]), maze, height, width);
    path[path_length-1] = '\0';
    path_length--;

    return recursive(maze, pos, row, column, path, path_length, start, end, height, width);
  }

  // Moving forward
  if(maze[row][column]==' '){
    maze[row][column] = '#';
  }

  pos = next_pos(row, column, freeDir[0], maze, height, width);

  path[path_length] = freeDir[0];
  path_length++;

  return recursive(maze, pos, row, column, path, path_length, start, end, height, width);

}

char next_pos(int& row, int& column, char direction, char** maze, int height, int width){
  char pos;

  switch(direction) {
  case'N':
    row -= 1; break;
  case'E':
    column += 1; break;
  case'S':
    row += 1; break;
  case'W':
    column -= 1; break;
  }

  if(row >= height || row < 0 || column >= width || column < 0){
    return '!';
  }

  pos = maze[row][column];

  if(pos == '|'|| pos == '-'){
    return '!';
  }

  return pos;
}

string free_directions(char** maze, int row, int column, int height, int width, char start, char end){
  char freeDir[4];
  strcpy(freeDir, "");

  if (isValid(maze, row-1, column, height, width, start, end))
    strcat(freeDir, "N");

  if (isValid(maze,row+1,column, height, width, start, end))
    strcat(freeDir, "S");

  if (isValid(maze,row,column-1, height, width, start, end))
    strcat(freeDir, "W");

  if (isValid(maze,row,column+1, height, width, start, end))
    strcat(freeDir, "E");

  // const char* solution = freeDir;
  // cout << "solution " << solution << endl;
  return freeDir;
}


bool isValid(char** maze, int row, int column, int height, int width, char start, char end) {
  if ((maze[row][column]==' ' || maze[row][column]==end || maze[row][column]==start) && !(row >= height || row < 0 || column >= width || column < 0))
    return true;
  return false;
}

char opposite(char ch) {
  if (ch == 'N')
    return 'S';
  if (ch == 'E')
    return 'W';
  if (ch == 'S')
    return 'N';
  return 'E';
}
