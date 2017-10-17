#include <iostream>
#include <cstring>
#include "braille.h"

using namespace std;

int encode_character(char ch, char* braille){
    int braille_size = 6;
    char character = ch;
    if(ispunct(ch)){
        braille = encode_punctuation(ch);
    }
    else{
        if(isdigit(ch)){
            braille_size = 12;
            braille = '..0000';
            character = convert_num_to_alpha(ch);
        }
        if(isupper(ch)){
            braille_size = 12;
            braille = '.....0';
            character = tolower(ch);
        }
        //TODO change this
        braille = encode_alphabet(character);
    }   
    // change it later
    return 1;
}

char* encode_punctuation(char letter){
    switch(letter){
        case '.': return ".0..00";
        break;
        case ',': return ".0....";
        break;
        case ";": return ".00...";
        break;
        case '-': return "..0..0";
        break;
        case '!': return ".00.0.";
        break;
        case '?': return ".00..0";
        break;
        case '(':
        case ')': return ".0..00";
    }
}

char convert_num_to_alpha(const char num){
    switch(num){
        case '1': return 'a';
        break;
        case '2': return 'a';
        break;
        case '3': return 'a';
        break;
        case '4': return 'a';
        break;
        case '5': return 'a';
        break;
        case '6': return 'a';
        break;
        case '7': return 'a';
        break;
        case '8': return 'a';
        break;
        case '9': return 'a';
        break;
    }
}

char* encode_alphabet(const char letter){
    switch(letter){
        case 'a': return "0.....";
        break;
        case 'b': return "00....";
        break;
        case 'c': return "0..0..";
        break;
        case 'd': return "0..00.";
        break;
        case 'e': return "0...0.";
        break;
        case 'f': return "00.0..";
        break;
        case 'g': return "00.00.";
        break;
        case 'h': return "00..0.";
        break;
        case 'i': return ".0.0..";
        break;
        case 'j': return ".0.00.";
        break;
        case 'k': return "0.0...";
        break;
        case 'l': return "000...";
        break;
        case 'm': return "0.00..";
        break;
        case 'n': return "0.000.";
        break;
        case 'o': return "0.0.0.";
        break;
        case 'p': return "0000..";
        break;
        case 'q': return "00000.";
        break;
        case 'r': return "000.0.";
        break;
        case 's': return ".000..";
        break;
        case 't': return ".0000.";
        break;
        case 'u': return "0.0..0";
        break;
        case 'v': return "000..0";
        break;
        case 'w': return ".0.000";
        break;
        case 'x': return "0.00.0";
        break;
        case 'y': return "0.0000";
        break;
        case 'z': return "0.0.00";
    }
}


