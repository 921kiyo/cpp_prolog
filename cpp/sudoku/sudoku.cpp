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

  cout << "Loading Sudoku board from file '" << filename << "'... ";

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

  cout << ((row == 9) ? "Success!" : "Failed!") << endl;
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

bool is_complete(char board[9][9]){
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      if(board[i][j] == '.'){
        return false;
      }
    }
  }
  return true;
}

bool make_move(const char* position, char digit, char board[9][9]){
  if(strlen(position) != 2){
    return false;
  }
  if(!is_position_valid(position)){
    return false;
  }
  if(digit < '1' || digit > '9'){
    return false;
  }
  int row = position[0] - 'A';
  int column = position[1] - '1';
  board[row][column] = digit;

  return true;
}

bool is_position_valid(const char* position){
  if(position[0] < 'A' || position[0] > 'I'){
    return false;
  }
  else if(position[1] < '1' || position[1] > '9'){
    return false;
  }

  return true;
}

bool save_board(const char* filename, char board[9][9]){
  ofstream out_stream;
  out_stream.open(filename);
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      out_stream.put(board[i][j]);
    }
    out_stream.put('\n');
  }
  out_stream.close();
  return true;
}

bool solve_board(char board[9][9]){
  if(is_complete(board)){
    return true;
  }
  save_board("temp.dat", board);
  int digit = rand() % 9 + 1;
  int column = rand() % 9 + 1;
  int row = rand() % 9 + 1;
  char position[3];
  position[0] = row + 'A';
  position[1] = column + '1';
  position[2] = '\0';
  // cout << row << endl;
  make_move(position,digit, board);
  if(is_vertical_valid(board) && is_horizontal_valid(board) && \
     is_cell_valid(board)){
       // cout << "success!" << endl;
       return solve_board(board);
     }
   else{
     load_board("temp.dat", board);
     return solve_board(board);
   }
  return false;
}

bool is_horizontal_valid(char board[9][9]){
  char array[9];
  for(int i = 0; i< 9; i++){
    for(int j = 0; j< 9; j++){
      array[j] = board[i][j];
      // cout << array[j];
    }
    // cout << endl;
    if(!no_duplicate(array)){
      return false;
    }
  }
  return true;
}
bool is_vertical_valid(char board[9][9]){
  char array[9];
  for(int i = 0; i< 9; i++){
    for(int j = 0; j< 9; j++){
      array[j] = board[j][i];
      // cout << array[j];
    }
    // cout << endl;
    if(!no_duplicate(array)){
      return false;
    }
  }
  return true;
}

bool is_cell_valid(char board[9][9]){

  return true;
}

bool no_duplicate(char* array){
  for(int i = 0; i < 9; i++){
    // cout << array[i]  << endl;
    if(array[i] >= '1' && array[i] <= '9'){
      for(int j = 0; j < i; j++){
        if(array[i] == array[j]){
          return false;
        }
      }
    }
  }
  return true;
}
