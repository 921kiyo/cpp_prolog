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
Pair lookup[100];
void clear_array(Pair* lookup){

  for(int i = 0; i < 100; i++){
    strcpy(lookup[i].str,"");
    lookup[i].letter = '1';
  }
}

// char rhyming_letter(const char *ending) {
//   char end[10];
//   // the next rhyming letter to be issued (persists between calls)
//   static char next = 'a';
//
//   // providing a way to reset the table between poems
//   if (ending == RESET) {
//     clear_array(lookup);
//     next = 'a';
//     return '\0';
//   }
//
//
//   // if the ending doesn't exist, add it, and issue a new letter
//   for(int i = 0; strcmp(lookup[i].str,""); i++){
//     // cout << "------------" << endl;
//     // cout << "ending " << ending << endl;
//     // cout << "lookup[i].str " << lookup[i].str << endl;
//     // cout << "lookup[i].letter " << lookup[i].letter << endl;
//     if(!strcmp(lookup[i].str,ending)){
//       return lookup[i].letter;
//     }
//     next++;
//   }
//
//   // otherwise return the letter corresponding to the existing ending
//   for(int i = 0; i < 100; i++){
//     if(!strcmp(lookup[i].str,"")){
//       strcpy(end, ending);
//       lookup[i].str = end;
//       lookup[i].letter = next;
//       return lookup[i].letter;
//     }
//   }
// }


/* START WRITING YOUR FUNCTION BODIES HERE */

int count_words(const char* line){
  // TODO Check two spaces
  int count = 0;
  char sentence[255];
  strcpy(sentence, line);
  for(char* p = strtok(sentence, " "); p!= NULL; p=strtok(NULL, " ")){
    count++;
  }
  return count;
}

bool find_phonetic_ending(const char* word, char* phonetic_ending){
  // TODO Check uppercase
  ifstream in_stream;
  const int MAX = 255;
  char line[MAX];
  char w[MAX];
  in_stream.open("dictionary.txt");
  int index;
  while(!in_stream.eof()){
    in_stream >> w;
    in_stream.getline(line, MAX);
    // cout << "w: " << w << endl;
    // cout << "word: " << word << endl;
    if(!strcmp(w,word)){
      index = find_first_vowel(line);
      get_rest(line, index, phonetic_ending);
      in_stream.close();
      return true;
    }
  }
  in_stream.close();
  return false;
}

int find_first_vowel(char* line){
  int length = strlen(line);
  for(int i = length - 1; i>=0 ;i--){
    if(is_vowel(line[i])){
      return i;
    }
  }
  return -1;
}

bool is_vowel(char letter){
  if(letter == 'A'||letter == 'E'||letter == 'I'||letter == 'O'||letter == 'U'){
    return true;
  }
  return false;
}
void get_rest(char* line, int index, char* phonetic_ending){
  int counter = 0;
  for(int i = index; line[i] != '\0';i++){
    if(isalpha(line[i])){
      phonetic_ending[counter] = line[i];
      counter++;
    }
  }
  phonetic_ending[counter] = '\0';
}

bool find_rhyme_scheme(const char* filename, char* scheme){
  ifstream in_stream;
  in_stream.open(filename);
  if(in_stream.fail()){
    return false;
  }
  char line[255];
  char word[255];
  char phonetic_ending[255];
  int counter;
  int c = 0;
  rhyming_letter(RESET);
  while(in_stream.getline(line, 255)){
    counter = count_words(line);
    cout << "--------- " << endl;
    cout << "line " << line << endl;
    cout << "counter " << counter << endl;
    get_word(line, counter, word);
    cout << "word " << word << endl;
    find_phonetic_ending(word, phonetic_ending);
    cout << "phonetic_ending " << phonetic_ending << endl;
    scheme[c] = rhyming_letter(phonetic_ending);
    c++;
  }
  scheme[c] = '\0';
  in_stream.close();
  return true;
}

const char* identify_sonnet(const char* filename){
  char shakespeare[512];
  find_rhyme_scheme("shakespeare.txt", shakespeare);
  char petrarch[512];
  find_rhyme_scheme("petrarch.txt", petrarch);
  char spenser[512];
  find_rhyme_scheme("spenser.txt", spenser);

  char scheme[512];
  find_rhyme_scheme(filename, scheme);
  if(!strcmp(scheme,shakespeare)){
    return "Shakespearean";
  }
  else if(!strcmp(scheme,petrarch)){
    return "Petrarchan";
  }
  else if(!strcmp(scheme,spenser)){
    return "Spenserian";
  }
  else{
    return "Unknown";
  }
}
