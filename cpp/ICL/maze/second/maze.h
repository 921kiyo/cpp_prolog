/* You are pre-supplied with the functions below. Add your own
   function prototypes to the end of this file. */
#include <string>

using namespace std;
/* helper functions to allocate and deallocate dynamic 2D arrays */
char **allocate_2D_array(int rows, int columns);
void deallocate_2D_array(char **m, int rows);

/* pre-supplied function to load a maze from a file */
char **load_maze(const char *filename, int &height, int &width);

/* pre-supplied function to print a maze */
void print_maze(char **m, int height, int width);

void find_marker(char ch, char** maze, int height, int width, int& row, int& column);
bool is_path_valid(char path);
void move_forward(int& row, int& column, char path);

bool valid_solution(const char* path, char** maze, int height, int width);

const char* find_path(char** maze, int height, int width, char start, char end);

bool recursive(char** maze, char pos, int row, int column, char* path, int path_length, char start, char end, int height, int width);

string free_directions(char** maze, int row, int column, int height, int width, char start, char end);
// const char* free_directions(char** maze, int row, int column, int height, int width, char start, char finish);
char next_pos(int& row, int& column, char direction, char** maze, int height, int width);
char opposite(char ch);
bool isValid(char** maze, int row, int column, int height, int width, char start, char finish);
