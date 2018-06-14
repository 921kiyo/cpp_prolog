#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "sudoku.h"

using namespace std;

/* You are pre-supplied with the functions below. Add your own
   function definitions to the end of this file. */

/* pre-supplied function to load a Sudoku board from a file */
void load_board(const char *filename, char board[9][9]) {

  // cout << "Loading Sudoku board from file '" << filename << "'... ";

  ifstream in(filename);
  if (!in)
    cout << "Failed!" << endl;
  assert(in);

  char buffer[512];

  int row = 0;
  in.getline(buffer,512);
  while (in && row < 9) {
    for (int n=0; n<9; n++) {
      assert(buffer[n] == '.' || isdigit(buffer[n]));
      board[row][n] = buffer[n];
    }
    row++;
    in.getline(buffer,512);
  }

  // cout << ((row == 9) ? "Success!" : "Failed!") << endl;
  assert(row == 9);
}

/* internal helper function */
void print_frame(int row) {
  if (!(row % 3))
    cout << "  +===========+===========+===========+" << endl;
  else
    cout << "  +---+---+---+---+---+---+---+---+---+" << endl;
}

/* internal helper function */
void print_row(const char *data, int row) {
  cout << (char) ('A' + row) << " ";
  for (int i=0; i<9; i++) {
    cout << ( (i % 3) ? ':' : '|' ) << " ";
    cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
  }
  cout << "|" << endl;
}

/* pre-supplied function to display a Sudoku board */
void display_board(const char board[9][9]) {
  cout << "    ";
  for (int r=0; r<9; r++)
    cout << (char) ('1'+r) << "   ";
  cout << endl;
  for (int r=0; r<9; r++) {
    print_frame(r);
    print_row(board[r],r);
  }
  print_frame(9);
}

/* add your functions here */
bool is_complete(const char board[9][9]){
  for(int row = 0; row < 9; row++){
    for(int column = 0; column < 9; column++){
      if(board[row][column] < '1' || board[row][column] > '9'){
        return false;
      }
    }
  }
  return true;
}

bool make_move(const char* position, char digit, char board[9][9]){
  save_board("temp.txt", board);
  int position_length = strlen(position);
  if(position_length != 2){
    // cout << "length wrong" << endl;
    return false;
  }
  if(position[0] > 'I' || position[0] < 'A'){
    // cout << "position[0] is wrong " << endl;
    return false;
  }

  if(position[1] > '9' || position[1] < '1'){
    // cout << "position[1] is wrong " << endl;
    return false;
  }

  if((digit > '9' && digit != '.')|| (digit < '1' && digit != '.')){
    // cout << "digit is wrong" << endl;
    return false;
  }

  int row = position[0] - 'A';
  int column = position[1] - '1';
  if(board[row][column] >= '1' && board[row][column] <= '9'){
    cout << "already number placed in that cell " << board[row][column] << endl;
    return false;
  }
  board[row][column] = digit;

  if(check_vertical(board) && check_horizontal(board) && check_cells(board)){
    // If everything is okay
    return true;
  }else{
    load_board("temp.txt", board);
    // cout << "something was wrong " << endl;
    return false;
  }
}

bool check_vertical(char board[9][9]){
  char array[9];
  for(int column = 0; column < 9; column++){
    for(int row = 0; row < 9; row++){
      array[row] = board[row][column];
    }
    if(!no_duplicate(array)){
      // cout << "vertical duplicate" << endl;
      return false;
    }
  }
  return true;
}
bool check_horizontal(char board[9][9]){
  char array[9];
  for(int row = 0; row < 9; row++){
    for(int column = 0; column < 9; column++){
      // cout << board[row][column];
      array[column] = board[row][column];
    }
    if(!no_duplicate(array)){
      // cout << "horizontal duplicate " << endl;
      return false;
    }
  }
  return true;
}
bool check_cells(char board[9][9]){
  char array[9];
  int counter = 0;
  for(int x = 0; x < 9; x=x+3){
    for(int y = 0; y < 9; y=y+3){
      counter = 0;
      for(int row = x; row < x+3; row++){
        for(int column = y; column < y+3; column++){
          array[counter] = board[row][column];
          counter++;
        }
      }
      if(!no_duplicate(array)){
        // cout << "duplicate!!" << endl;
        return false;
      }
    }
  }

  return true;
}

bool no_duplicate(char array[]){
  for(int i = 0; i<9; i++){
    if(array[i] >= '1' && array[i] <= '9' && appear_before(array, array[i], i)){
      return false;
    }
  }
  return true;
}

bool appear_before(char array[], char number, int position){
  for(int i = 0; i < position; i++){
    if(array[i] == number){
      return true;
    }
  }
  return false;
}

bool save_board(const char* filename, char board[9][9]){
  ofstream out_stream;
  out_stream.open(filename);
  if(out_stream.fail()){
    return false;
  }

  for(int row = 0; row < 9; row++){
    for(int column = 0; column < 9; column++){
      out_stream.put(board[row][column]);
    }
    out_stream.put('\n');
  }
  out_stream.close();
  return true;
}

bool solve_board(char board[9][9]){
  int row;
  int column;
  char position[3];
  // If the board is full, exit the recursion
  if(is_complete(board)){
    cout << "is_complete true" << endl;
    return true;
  }
  // Find the first spot
  find_cell(board, row, column);
  position[0] = get_row(row);
  position[1] = get_column(column);
  position[2] = '\0';
  // Find all possibilities for the spot
  char possibilities[10];

  get_all_possibilities(board, position, possibilities);
  // int possibility_length = strlen(possibilities);
  for(int i = 0; i < 10; i++){
    if(possibilities[i] >= '1' && possibilities[i] <= '9'){
      board[row][column] = possibilities[i];
      if(solve_board(board)){
        return true;
      }
      board[row][column] = '.';
    }
  }
  return false;
}

void find_cell(char board[9][9], int& row, int& column){
  for(int r = 0; r < 9; r++){
    for(int c = 0; c < 9; c++){
      if(board[r][c] < '1' || board[r][c] > '9'){
        row = r;
        column = c;
        return;
      }
    }
  }
}

void get_all_possibilities(char board[9][9], const char* position, char* possibilities){
  // display_board(board);
  int counter = 0;
  char input;
  for(int i = 0; i < 9; i++){
    // cout << "position " << position << endl;
    input = get_column(i);
    // cout << "input " << input << endl;
    if(make_move(position,input,board)){
      // cout << "possi " << input << endl;;
      possibilities[counter] = input;
      counter++;
      board[position[0] -65][position[1] -49] = '.';
    }
  }
}

void free_cells(char board[9][9], char* cells){
  // Reset cells
  strcpy(cells, "");

  int counter=0;
  for(int row = 0; row < 9; row++){
    // cout << endl;
    for(int column = 0; column < 9; column++){
      if(board[row][column] == '.'){
        // cout << "get_row(row) " << get_row(row) << endl;
        cells[counter] = get_row(row);
        counter++;
        cells[counter] = get_column(column);
        // cout << "get_column(row) " << get_column(column) << endl;
        counter++;
      }
    }
  }
  cells[counter] = '\0';
}

char get_row(int num){
  char temp = num + 65;
  return temp;
}

char get_column(int num){
  return num+ 49;
}
