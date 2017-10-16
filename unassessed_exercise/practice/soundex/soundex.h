#ifndef SOUNDEX_H
#define SOUNDEX_H

void encode(const char* surname, char* soundex);
int compare(const char* one, const char* two);
int count(char* surname, char* sentence);
char encode_table(char letter);

#endif
