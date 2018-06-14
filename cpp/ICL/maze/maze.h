/* You are pre-supplied with the functions below. Add your own
   function prototypes to the end of this file. */
#ifndef MAZE_H
#define MAZE_H

#include <string>
using namespace std;
/* helper functions to allocate and deallocate dynamic 2D arrays */
char **allocate_2D_array(int rows, int columns);
void deallocate_2D_array(char **m, int rows);

/* pre-supplied function to load a maze from a file */
char **load_maze(const char *filename, int &height, int &width);

/* pre-supplied function to print a maze */
void print_maze(char **m, int height, int width);


void find_marker(char path, char** maze, int height, int width, int& row, int& column);

bool valid_solution(const char* path, char** maze, int height, int width);

bool move_forward(char** maze, int height, int width, char direction, int& row_now, int& column_now);

string find_path(char** maze, int height, int width, char start, char end);

bool explore_path(char** maze, int height, int width, int& row_now, int& column_now, char* path, int path_length, char start, char end);
void get_free_direction(char** maze, int height, int width, int row, int column, char* freeDir, char start, char end);
bool is_available(char** maze, int row, int column, char start, char end);
char opposite(char direction);

void remove_dot(char** maze, int height, int width);

#endif
