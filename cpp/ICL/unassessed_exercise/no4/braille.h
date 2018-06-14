#ifndef BRAILLE_H
#define BRAILLE_H
#include <ostream>

using namespace std;

int encode_character(char ch, char* braille);

void encode_punctuation(char letter, char* braille);

char convert_num_to_alpha(const char num);

void encode_alphabet(const char letter, char* braille);

char* encode(const char* plaintext, char* braille);

void print_braille(const char* plaintext, ostream& output);

#endif
