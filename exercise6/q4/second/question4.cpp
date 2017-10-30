#include<iostream>

using namespace std;

const int M = 2;
const int N = 2;
const int R = 2;


void input_m_n(int matrix_m_n[][N]){
  for(int row=0; row < M; row++){
    cout << "Type in " << M << " values for row " << row << " separated by spaces: ";
    for(int column=0; column<N; column++){
      cin >> matrix_m_n[row][column];
    }
  }
}

void display_m_n(int matrix_m_n[][N]){
  for(int row=0; row < M; row++){
    for(int column=0; column<N; column++){
      cout << matrix_m_n[row][column];
    }
    cout << endl;
  }
}

void input_n_r(int matrix_m_n[][R]){
  for(int row=0; row < N; row++){
    cout << "Type in " << R << " values for row " << row << " separated by spaces: ";
    for(int column=0; column<R; column++){
      cin >> matrix_m_n[row][column];
    }
  }
}

void display_n_r(int matrix_m_n[][R]){
  for(int row=0; row < N; row++){
    for(int column=0; column<R; column++){
      cout << matrix_m_n[row][column];
    }
    cout << endl;
  }
}

void display_result(int result[][R]){
  for(int row=0; row < M; row++){
    for(int column=0; column<R; column++){
      cout << result[row][column];
    }
    cout << endl;
  }
}

int entry(int row, int column, int matrix_m_n[][N], int matrix_n_r[][R]){
  int total = 0;
  for(int counter = 0; counter< N; counter++){
    total+= matrix_m_n[row][counter] * matrix_n_r[counter][column];
  }

  return total;
}

void matrix_mult(int matrix_m_n[][N], int matrix_n_r[][R], int result[][R]){
    for(int row=0; row<M; row++){
      for(int column=0; column<N; column++){
        result[row][column] = entry(row, column, matrix_m_n, matrix_n_r);
      }
    }
}

int main(){
  int matrix_m_n[M][N];
  int matrix_n_r[N][R];
  int result[M][R];
  cout << "INPUT FIRST (" << M << "x" << N << ") MATRIX: " << endl;
  input_m_n(matrix_m_n);
  cout << "INPUT SECOND (" << N << "x" << R << ") MATRIX: " << endl;
  input_n_r(matrix_n_r);
  cout.width(5);
  display_m_n(matrix_m_n);
  display_n_r(matrix_n_r);
  cout << endl;
  matrix_mult(matrix_m_n, matrix_n_r, result);
  display_result(result);
  return 0;
}
