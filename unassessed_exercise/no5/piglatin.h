#ifndef PIGLATIN_H
#define PIGLATIN_H

int findFirstVowel(const char* word);

bool check_vowels(char word, int position, int index);

void translateWord(const char* english, char* piglatin);

#endif
