#ifndef PIGLATIN_H
#define PIGLATIN_H

#include <ostream>

using namespace std;

int findFirstVowel(const char* word);
bool isVowel(char letter, int position, int length);
void translateWord(const char* english, char* piglatin);
void getFirstHalf(const char* english, int position, char* first_half, bool begin_vowel);
void getSecondHalf(const char* english, int position, char* second_half, bool begin_vowel);

void translateStream(istream& inputStream, ostream& outputStream);

#endif
