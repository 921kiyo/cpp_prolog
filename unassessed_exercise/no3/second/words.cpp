#include <iostream>
#include <cstring>

#include "words.h"

using namespace std;

void reverse(const char* str1, char* str2){
    int length = strlen(str1);
    int x = 0;
    for(int i = length-1; i>=0; i--){
        str2[x] = str1[i];
        x++;
    }
    cout << x;
    str2[x] = '\0';
}

int compare(const char* one, const char* two){

}

int palindrome(const char* sentence){

}

int anagram(const char* str1, const char* str2){

}

using namespace std;