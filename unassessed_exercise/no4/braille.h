#ifndef BRAILLE_H
#define BRAILLE_H

void encode_character(char ch, char* braille);

char* encode_punctuation(char letter);

char convert_num_to_alpha(const char num);

char* encode_alphabet(const char letter);

#endif