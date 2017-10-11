#ifndef SOUNDEX_H
#define SOUNDEX_H


char* encode(const char *surname, char *soundex);

char encode_translate(const char* surname, int num);

int compare(const char *one, const char *two);

//int count(const char surname[], const char sentence[]);

#endif
