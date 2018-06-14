#ifndef BRAILLE_H
#define BRAILLE_H

#include <fstream>

using namespace std;

int encode_character(char ch, char* braille);

void encode(const char* plaintext, char* braille);

const char* encode_letter(char ch);
const char* encode_digit(char ch);
const char* encode_punct(char ch);
void print_braille(const char* plaintext, ostream& output);



#endif
