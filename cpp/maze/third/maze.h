/* You are pre-supplied with the functions below. Add your own
   function prototypes to the end of this file. */
#ifndef MAZE_H
#define MAZE_H

#include <string>
/* helper functions to allocate and deallocate dynamic 2D arrays */
char **allocate_2D_array(int rows, int columns);
void deallocate_2D_array(char **m, int rows);

/* pre-supplied function to load a maze from a file */
char **load_maze(const char *filename, int &height, int &width);

/* pre-supplied function to print a maze */
void print_maze(char **m, int height, int width);

void find_marker(char ch, char** maze, int height, int width, int& row, int& column);

bool valid_solution(const char* path, char** maze, int height, int width);
void move(char** maze, int height, int width, char direction, int& row, int& column);
bool is_valid_square(char square, char start, char end);

bool is_path_valid(const char* path);

std::string find_path(char** maze, int height, int width, char start, char end);

bool recursive(char** maze, int height, int width, char start, char end, int row, int column, char* path, int path_length);

void get_free(char** maze, int height, int width, int row, int column, char start, char end, char* freeDir);

char opposite(char dir);

#endif
