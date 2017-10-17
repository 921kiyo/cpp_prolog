#ifndef PIGLATIN_H
#define PIGLATIN_H

int findFirstVowel(const char* word);

bool check_vowels(char word, int position, int index);

void translateWord(const char* english, char* piglatin);

void move_character_before(const char* english, char* piglatin, int position);

#endif
