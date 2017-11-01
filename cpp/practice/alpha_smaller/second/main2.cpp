/* C++ Programming, Example answer, Exercise 2, Sheet 7  */

/* Author: Rob Miller and William Knottenbelt
   Program last changed: 30th September 2001    */

/* This program tests the string functions 'string_smaller_than' 
and 'string_ptr_smaller_than' */

#include <iostream>
using namespace std;

const int MAX_STR_LENGTH = 80;
enum Logical {False, True};

/* Function which returns 'True' if 'first' is alphabetically smaller than 'second' */
Logical string_smaller_than(char first[], char second[]);
	
/* Pointer arithmetic version of function which returns 'True' 
   if 'first' is alphabetically smaller than 'second' */
Logical string_ptr_smaller_than(char *first, char *second);

/* START OF MAIN PROGRAM */
int main() 
{
	char first_word[MAX_STR_LENGTH], second_word[MAX_STR_LENGTH];
	
	cout << "This program tests the string functions\n";
	cout << "'string_smaller_than' and 'string_ptr_smaller_than'.\n\n\n";

	/* input two strings: */
	cout << "Enter first word consisting of less than " << MAX_STR_LENGTH - 1;
	cout << " lower case letters:\n";
	cin >> first_word;
	cout << "Enter second word consisting of less than " << MAX_STR_LENGTH - 1;
	cout << " lower case letters:\n";
	cin >> second_word;
	
	/* test the array syntax version of the function: */
	cout << "\nAccording to the function 'string_smaller_than', ";
	cout << "'" << first_word << "' is ";
	if (!string_smaller_than(first_word,second_word))
		cout << "not ";
	cout << "smaller than '" << second_word << "'.\n";

	/* test the pointer arithmetic version of the function: */
	cout << "\nAccording to the function 'string_ptr_smaller_than', ";
	cout << "'" << first_word << "' is ";
	if (!string_ptr_smaller_than(first_word,second_word))
		cout << "not ";
	cout << "smaller than '" << second_word << "'.\n";
	
	return 0;
}
/* END OF MAIN PROGRAM */


/* DEFINITION OF FUNCTION string_smaller_than */
Logical string_smaller_than(char first[], char second[])
{
	int count = 0;
	
	while (first[count] != '\0' && second[count] != '\0')
	{
		if (first[count] < second[count])
			return True;
		if (first[count] > second[count])
			return False;
		count++;
	}
	
	if (first[count] == '\0' && second[count] != '\0')
		return True;
	else
		return False;
}
/*END OF FUNCTION */

/* DEFINITION OF FUNCTION string_smaller_than */
Logical string_ptr_smaller_than(char *first, char *second)
{
	while (*first != '\0' && *second != '\0')
	{
		if (*first < *second)
			return True;
		if (*first > *second)
			return False;
		first++;
		second++;
	}
	
	if (*first == '\0' && *second != '\0')
		return True;
	else
		return False;
}
/*END OF FUNCTION */
