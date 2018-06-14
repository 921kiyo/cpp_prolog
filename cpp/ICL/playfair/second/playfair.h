#ifndef PLAYFAIR_H
#define PLAYFAIR_H

void prepare(const char* input, char* output);

void grid(const char* codeword, char square[][6]);

bool is_codeword_valid(const char* codeword);

void remove_dup(const char* codeword, char* temp);

void remove_dup(const char* codeword, char* temp);

bool appear_before(const char* codeword, char letter, int position);

void bigram(char square[][6], char inchar1, char inchar2, char& outchar1, char& outchar2);

void get_position(char square[][6], char inchar, int& row, int& col);

void encode(char square[][6], const char* prepared, char* encoded);

void encode_recursive(char square[][6], const char* prepared, char* encoded);

void decode(char square[][6], const char* prepared, char* decoded);

#endif
