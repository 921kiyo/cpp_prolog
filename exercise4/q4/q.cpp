/* C++ Programming, Example answer, Exercise 4, Sheet 4  */

/* Author: William Knottenbelt
   Program last changed: 9th October 2001    */

/* This program prints itself backwards. */

/* IMPORTANT: TO GUARANTEE THAT THIS PROGRAM RUNS, PUT THE PROJECT 
   DOCUMENT (FILE) IN THE SAME FOLDER/DIRECTORY AS THIS FILE.        */

/* WARNING: THIS PROGRAM MIGHT TAKE A WHILE TO FINISH EXECUTING.     */

#include <iostream>
#include <fstream>
using namespace std;

int characters_in_file();
char character_at_position(int number);

int main ()
{
  int count;

  /* find out how many characters are in the file */
  count = characters_in_file();

  /* now run backwards through the file printing the character 
     found at each position */
  for (int number= count; number > 0; number--)
    cout << character_at_position(number);

  return 0;
}

int characters_in_file() {
  char ch;
  ifstream in_stream;

  int count = 0;

  in_stream.open("q.cpp");
  in_stream.get (ch);
  while (!in_stream.fail()) {
    count++;
    in_stream.get (ch);
  }
  in_stream.close();

  return count;
}

char character_at_position(int number) {
  char ch;
  ifstream in_stream;

  in_stream.open("q.cpp");

  for (int i=0; i<number; i++)
    in_stream.get(ch);

  in_stream.close();
  return ch;
}
