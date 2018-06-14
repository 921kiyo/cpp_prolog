#ifndef MULTITAP_H
#define MULTITAP_H

int encode_character(char ch, char* multitap);
void apply_multitap(char* multitap, int digit, int times);
void encode(const char* plaintext, char* multitap);

#endif
