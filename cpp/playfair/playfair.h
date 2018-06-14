#ifndef PLAYFAIR_H
#define PLAYFAIR_H

const int SQ_SIZE = 6;

void prepare(const char* input, char* output);

void grid(const char* codeword, char square[][SQ_SIZE]);

bool occurs_before(const char str[], char letter, int pos);

void bigram(char square[][SQ_SIZE], char inchar1, char inchar2, char& outchar1, char& outchar2);
void find_position(char square[][SQ_SIZE], char inchar, int& inchar_row, int& inchar_column);

void encode(char square[][SQ_SIZE], const char* prepared, char* encoded);
void decode(char square[][SQ_SIZE], const char* encoded, char* decoded);

#endif
