#ifndef TWO_D_H
#define TWO_D_H

const int M = 2;
const int N = 2;
const int R = 2;

void insert_n(int array[][N],int row);

void insert_r(int array[][R],int row);

void matrix_multiplication(int array1[][N], int array2[][R], int answer[][R]);

int entry_cell(int a_row, int a_column, int array1[][N], int array2[][R]);

void display_n(int array[][N],int row);

void display_r(int array[][R],int row);

#endif
