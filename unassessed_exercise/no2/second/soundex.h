#ifndef SOUNDEX_H
#define SOUNDEX_H

void encode(const char* surname, char* soundex);

char encode_table(char letter);

int compare(const char* one, const char* two);

int count(const char* surname, const char* sentence);

#endif
