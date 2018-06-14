#ifndef SUDOKU_H
#define SUDOKU_H

void load_board(const char *filename, char board[9][9]);
void display_board(const char board[9][9]);

bool is_complete(const char board[9][9]);
void copy_board(char board[9][9], char board_copy[9][9]);
bool make_move(const char* position, char digit, char board[9][9]);
bool check_vertical(char board[9][9]);
bool check_horizontal(char board[9][9]);
bool check_cells(char board[9][9]);

bool no_duplicate(char array[]);
bool appear_before(char array[], char number, int position);
bool save_board(const char* filename, char board[9][9]);
bool solve_board(char board[9][9]);
void find_cell(char board[9][9], int& row, int& column);
void get_all_possibilities(char board[9][9], const char* position, char* possibilities);
void free_cells(char board[9][9], char* cells);
char get_row(int num);
char get_column(int num);
#endif
