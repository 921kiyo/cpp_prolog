#ifndef CORRECT_H
#define CORRECT_H

void ascii_to_binary(char letter, char *output);
char binary_to_ascii(char *binary);

void text_to_binary(const char* str, char* binary);
void recursive(const char* str, char* binary);
void binary_to_text(const char* binary, char* text);
void recursive2(const char* binary, char* text);

void add_error_correction(const char* data, char* corrected);

void recursive3(const char* data, char* corrected);

char parity(char a, char b, char c, char d = '0');

int decode(char* received, char* decoded);

void recursive4(char* received, char* decoded, int& errors);
int get_decimal(char* total);
void flip(char& binary);
#endif
