#include <iostream>
#include <cstring>
#include "two_d.h"

using namespace std;

void insert_n(int array[][N], int row){
  for(int i = 0; i< row; i++){
    cout << "Type in " << N << " values for row " << i << " separated by spaces: ";
    for(int x = 0; x< N; x++){
      cin >> array[i][x]; 
    }
  }
}

void insert_r(int array[][R], int row){
  for(int i = 0; i< row; i++){
    cout << "Type in " << R << " values for row " << i << " separated by spaces: ";
    for(int x = 0; x< R; x++){
      cin >> array[i][x];
    }
  }
}

void matrix_multiplication(int array1[][N], int array2[][R], int answer[][R]){
  for(int row=0; row < M; row++){
    for(int column=0; column < R; column++){
      answer[row][column] = entry_cell(row, column, array1, array2); 
    }
  }
}

int entry_cell(int a_row, int a_column, int array1[][N], int array2[][R]){
  int total = 0;
  for(int counter = 0; counter < N; counter++){
    total += array1[a_row][counter] * array2[counter][a_column];
  }

  return total;
}

void display_n(int array[][N], int row){
  for(int i = 0; i< row; i++){
    for(int x = 0; x < N; x++){
      cout << array[i][x];
    }
    cout << "\n";
  }
}

void display_r(int array[][R], int row){
  for(int i = 0; i< row; i++){
    for(int x = 0; x < R; x++){
      cout << array[i][x];
    }
    cout << "\n";
  }
}
