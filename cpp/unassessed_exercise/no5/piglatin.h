#ifndef PIGLATIN_H
#define PIGLATIN_H

#include <iostream>

using namespace std;

int findFirstVowel(const char* word);

bool check_vowels(char word, int position, int index);

void translateWord(const char* english, char* piglatin);

void move_character_before(const char* english, char* piglatin, int position, bool is_capital);

void translateStream(istream& inputStream, ostream& outputStream);

#endif
