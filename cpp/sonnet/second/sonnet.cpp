#include <iostream>
#include <cstring>
#include <cctype>
#include <cassert>
#include <map>
#include <string>
#include <fstream>

using namespace std;

#include "sonnet.h"

/* PRE-SUPPLIED HELPER FUNCTIONS START HERE */

/* NOTE: It is much more important to understand the interface to and
   the "black-box" operation of these functions (in terms of inputs and
   outputs) than it is to understand the details of their inner working. */

/* get_word(...) retrieves a word from the input string input_line
   based on its word number. If the word number is valid, the function
   places an uppercase version of the word in the output parameter
   output_word, and the function returns true. Otherwise the function
   returns false. */

bool get_word(const char *input_line, int word_number, char *output_word) {
  char *output_start = output_word;
  int words = 0;

  if (word_number < 1) {
    *output_word = '\0';
    return false;
  }

  do {
    while (*input_line && !isalnum(*input_line))
      input_line++;

    if (*input_line == '\0')
      break;

    output_word = output_start;
    while (*input_line && (isalnum(*input_line) || *input_line=='\'')) {
      *output_word = toupper(*input_line);
      output_word++;
      input_line++;
    }
    *output_word = '\0';

    if (++words == word_number)
      return true;

  } while (*input_line);

  *output_start = '\0';
  return false;
}

/* char rhyming_letter(const char *ending) generates the rhyme scheme
   letter (starting with 'a') that corresponds to a given line ending
   (specified as the parameter). The function remembers its state
   between calls using an internal lookup table, such that subsequents
   calls with different endings will generate new letters.  The state
   can be reset (e.g. to start issuing rhyme scheme letters for a new
   poem) by calling rhyming_letter(RESET). */

char rhyming_letter(const char *ending) {

  // the next rhyming letter to be issued (persists between calls)
  static char next = 'a';
  // the table which maps endings to letters (persists between calls)
  static map<string, char> lookup;

  // providing a way to reset the table between poems
  if (ending == RESET) {
    lookup.clear();
    next = 'a';
    return '\0';
  }

  string end(ending);

  // if the ending doesn't exist, add it, and issue a new letter
  if (lookup.count(end) == 0) {
    lookup[end]=next;
    assert(next <= 'z');
    return next++;
  }

  // otherwise return the letter corresponding to the existing ending
  return lookup[end];
}

/* START WRITING YOUR FUNCTION BODIES HERE */

// int count_words(const char* line){
//   int counter = 0;
//   char str[80];
//   strcpy(str, line);
//   for(char* p= strtok(str, " "); p !=NULL; p=strtok(NULL, " ")){
//     cout << "p " << p << endl;
//     counter++;
//   }
//
//   return counter;
// }

int count_words(const char* sentence){
  int tokens= 0;
  if(*sentence == '\0')
    return 0;
  if(isalpha(*sentence) || ispunct(*sentence)){
    sentence++;
    if(!isalpha(*sentence) && !ispunct(*sentence))
      tokens++;
    if(*sentence == '-' && *(sentence+1) != '\0')
      tokens++;
    }
  else {sentence++;}
  return tokens + count_words(sentence);
}

bool find_phonetic_ending(const char* word, char* phonetic_ending){
  ifstream in_stream;
  char phonetic[512];
  char ending[512];
  in_stream.open("dictionary.txt");
  strcpy(phonetic_ending, "");

  while(!in_stream.eof()){
    in_stream >> phonetic;
    in_stream.getline(ending, 512);
    if(!strcmp(word,phonetic)){
      get_phonetic_ending(ending, phonetic_ending);
      in_stream.close();
      return true;
    }
  }
  in_stream.close();
  return false;
}

void get_phonetic_ending(char* list, char* phonetic_ending){
  int length = strlen(list);
  int vowel_position;
  for(int i = length; i >= 0; i--){
    if(is_vowel(list[i])){
      vowel_position = i;
      break;
    }
  }
  int counter = 0;
  for(int i = vowel_position; i < length; i++){
    if(isalpha(list[i])){
      phonetic_ending[counter] = list[i];
      counter++;
    }
  }
  phonetic_ending[counter] = '\0';
}

bool is_vowel(char letter){
  switch(letter){
    case('A'):
    case('E'):
    case('I'):
    case('O'):
    case('U'): return true;
    default: return false;
  }
}

bool find_rhyme_scheme(const char* filename, char* scheme){
  ifstream in_stream;
  in_stream.open(filename);
  if(in_stream.fail()){
    return false;
  }
  char line[512];
  char word[512];
  char phonetic_ending[512];
  int count;
  int c = 0;
  strcpy(scheme, "");
  rhyming_letter(RESET);
  while(in_stream.getline(line, 512)){
    get_last_word(line, word);
    // cout << "word " << word << endl;
    find_phonetic_ending(word, phonetic_ending);
    // cout << "phonetic_ending " << phonetic_ending << endl;
    scheme[c] = rhyming_letter(phonetic_ending);
    c++;
  }

  in_stream.close();

  return true;
}

void get_last_word(char* line, char* word){
  int length = strlen(line);
  int counter = 0;
  char temp[20];
  for(int i = length; i >=0; i--){
    if(isalnum(line[i])){
      while(isalnum(line[i])){
        temp[counter] = line[i];
        counter++;
        i--;
      }
      temp[counter] = '\0';
      break;
    }
  }
  int c = 0;
  for(int i = counter-1; i >= 0; i--){
    word[c] = toupper(temp[i]);
    c++;
  }
  word[c] = '\0';
}

const char* identify_sonnet(const char* filename){
  char scheme[100];
  find_rhyme_scheme(filename, scheme);

  char scheme_shakespean[100];
  find_rhyme_scheme("shakespeare.txt", scheme_shakespean);

  char scheme_petrarch[100];
  find_rhyme_scheme("petrarch.txt", scheme_petrarch);

  char scheme_spenser[100];
  find_rhyme_scheme("spenser.txt", scheme_spenser);

  if(!strcmp(scheme,scheme_shakespean)){
    return "Shakespearean";
  }
  else if(!strcmp(scheme,scheme_petrarch)){
    return "Petrarchan";
  }
  else if(!strcmp(scheme,scheme_spenser)){
    return "Spenserian";
  }
  else{
    return "Unknown";
  }
}
