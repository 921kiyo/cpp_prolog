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

bool is_complete(const char board[9][9]){
  for(int row = 0; row < 9; row++){
    for(int col = 0; col < 9; col++){
      if(board[row][col] < '1' || board[row][col] > '9'){
        return false;
      }
    }
  }
  return true;
}

bool make_move(const char* position, char digit, char board[9][9]){
  if(!is_position_valid(position)){
    cout << "position not valid " << endl;
    return false;
  }
  if(digit < '1' || digit > '9'){
    cout << "digit not valid " << endl;
    return false;
  }

  int row = get_row_int(position[0]);
  int col = get_column_int(position[1]);

  // Check if a number is already in the square
  if(board[row][col] >= '1' && board[row][col] <= '9'){
    cerr << "number already in the square " << endl;
    return false;
  }

  board[row][col] = digit;

  if(!is_vertical_valid(board) || !is_horizontal_valid(board) || !is_cell_valid(board)){
    cout << "it is not valid vertically/horizontally/by cell" << endl;
    board[row][col] = '.';
    return false;
  }
  return true;
}

bool no_duplicate(char* array){
  for(int i = 0; i < 9; i++){
    if(array[i] >= '1' && array[i] <= '9'){
      if(appear_before(array, array[i], i)){
        return false;
      }
    }
  }
  return true;
}

bool appear_before(char* array, char letter, int position){
  for(int i = 0; i < position; i++){
    if(letter == array[i]){
      return true;
    }
  }
  return false;
}

bool is_vertical_valid(char board[9][9]){
  char array[9];
  for(int col = 0; col < 9; col++){
    for(int row = 0; row < 9; row++){
      array[row] = board[row][col];
    }
    if(!no_duplicate(array)){
      return false;
    }
  }
  return true;
}
bool is_horizontal_valid(char board[9][9]){
  char array[9];
  for(int row = 0; row < 9; row++){
    for(int col = 0; col < 9; col++){
      array[col] = board[row][col];
    }
    if(!no_duplicate(array)){
      return false;
    }
  }
  return true;
}
bool is_cell_valid(char board[9][9]){
  char array1[9];
  int  counter1 = 0;
  char array2[9];
  int  counter2 = 0;
  char array3[9];
  int  counter3 = 0;

  for(int row = 0; row < 9; row++){
    for(int col = 0; col < 9; col++){
      if(col <= 2){
        array1[counter1] = board[row][col];
        counter1++;
      }
      if(counter1 == 9){
        array1[counter1] = '\0';
        // cout << endl;
        // cout << "array 1" << endl;
        // cout << "-------" << endl;
        // for(int i = 0; i <= counter1; i++){
        //   cout << array1[i] << endl;
        // }
        if(!no_duplicate(array1)){
          // cout << "duplicate 1" << endl;
          return false;
        }
        else{
          counter1 = 0;
        }
      }

      if(col >= 3 && col <= 5){
        array2[counter2] = board[row][col];
        counter2++;
      }

      if(counter2 == 9){
        array2[counter2] = '\0';
        if(!no_duplicate(array2)){
          // cout << "duplicate 2" << endl;
          return false;
        }else{
          counter2 = 0;
        }
      }

      if(col >= 6 && col <= 8){
        array3[counter3] = board[row][col];
        counter3++;
      }

      if(counter3 == 9){
        array3[counter3] = '\0';
        if(!no_duplicate(array3)){
          // cout << "duplicate 3" << endl;

          return false;
        }
        else{
          counter3 = 0;
        }
      }
    }
  }

  return true;
}

int get_row_int(char row){
  return row - 'A';
}

int get_column_int(char column){
  return column - '1';
}

bool is_position_valid(const char* position){
  int length = strlen(position);
  if(length != 2){
    return false;
  }
  if(position[0] < 'A' || position[0] > 'I'){
    return false;
  }
  if(position[1] < '1' || position[1] > '9'){
    return false;
  }
  return true;
}

bool save_board(const char* filename, char board[9][9]){
  ofstream out_stream;
  out_stream.open(filename);
  if(out_stream.fail()){
    return false;
  }
  for(int row = 0; row < 9; row++){
    for(int col = 0; col < 9; col++){
      out_stream.put(board[row][col]);
    }
    out_stream.put('\n');
  }
  out_stream.close();
  return true;
}

bool solve_board(char board[9][9]){
  // Base case
  if(is_complete(board)){
    return true;
  }

  int row, column;
  char numbers[10];
  strcpy(numbers, "");
  find_empty_cell(board, row, column);
  get_numbers(board, row, column, numbers);

  for(int i = 0; numbers[i] != '\0'; i++){
    board[row][column] = numbers[i];
    if(solve_board(board)){
      return true;
    }
  
    board[row][column] = '.';
  }
  return false;
}

void find_empty_cell(char board[9][9], int& row, int& column){
  for(int r = 0; r < 9; r++){
    for(int c = 0; c < 9; c++){
      if(board[r][c] == '.'){
        row = r;
        column = c;
        return;
      }
    }
  }
}

void get_numbers(char board[9][9], int row, int column, char* numbers){
  int counter = 0;
  for(char i = '1'; i <= '9'; i++){
    board[row][column] = i;
    if(is_vertical_valid(board) && is_horizontal_valid(board) && is_cell_valid(board)){
      numbers[counter] = i;
      counter++;
    }
    board[row][column] = '.';
  }
  numbers[counter] = '\0';
}
