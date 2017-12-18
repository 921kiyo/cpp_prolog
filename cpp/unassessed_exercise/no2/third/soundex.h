#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>
using namespace std;
void encode(const char* surname, char* soundex);

int compare(const char* one, const char* two);

int count(const char* surname, const char* sentence);


bool is_vowel(char letter);
char convert(char letter);

#endif
