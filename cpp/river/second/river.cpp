#include <iostream>
#include <fstream>
#include <cstring>
#include <cassert>

using namespace std;

#include "river.h"

/* You are pre-supplied with the functions below. Add your own
   function definitions to the end of this file. */

/* internal helper function which allocates a dynamic 2D array */
char **allocate_2D_array(int rows, int columns) {
  char **m = new (nothrow) char *[rows];
  assert(m);
  for (int r=0; r<rows; r++) {
    m[r] = new (nothrow) char[columns];
    assert(m[r]);
  }
  return m;
}

/* internal helper function which deallocates a dynamic 2D array */
void deallocate_2D_array(char **m, int rows) {
  for (int r=0; r<rows; r++)
    delete [] m[r];
  delete [] m;
}

/* pre-supplied function which creates an empty ASCII-art scene */
char **create_scene() {
  char **scene = allocate_2D_array(SCENE_HEIGHT, SCENE_WIDTH);

  for (int i=0; i<SCENE_HEIGHT; i++)
    for (int j=0; j<SCENE_WIDTH; j++)
      scene[i][j] = ' ';

  return scene;
}

/* pre-supplied function which frees up memory allocated for an ASCII-art scene */
void destroy_scene(char **scene) {
  deallocate_2D_array(scene, SCENE_HEIGHT);
}

/* pre-supplied function which displays an ASCII-art scene */
void print_scene(char **scene) {
  for (int i=0; i<SCENE_HEIGHT; i++) {
    for (int j=0; j<SCENE_WIDTH; j++)
      cout << scene[i][j];
    cout << endl;
  }
}

/* helper function which removes carriage returns and newlines from strings */
void filter(char *line) {
  while (*line) {
    if (*line >= ' ')
      line++;
    else
      *line = '\0';
  }
}

/* pre-supplied function which inserts an ASCII-art drawing stored in a file
   into a given ASCII-art scene starting at coordinates (row,col)  */
bool add_to_scene(char **scene, int row, int col, const char *filename) {

  ifstream in(filename);
  if (!in)
    return false;

  int start_col = col;
  char line[512];
  in.getline(line,512);
  filter(line);
  while (!in.fail()) {
    for (int n=0; n<strlen(line); n++) {
      if (row >= SCENE_HEIGHT)
	return false;
      if (col >= SCENE_WIDTH)
	break;
      scene[row][col++] = line[n];
    }
    row++;
    col = start_col;
    in.getline(line,512);
    filter(line);
  }
  return true;
}

/* pre-supplied helper function to report the status codes encountered in Question 3 */
const char *status_description(int code) {
  switch(code) {
  case ERROR_INVALID_CANNIBAL_COUNT:
    return "Invalid cannibal count";
  case ERROR_INVALID_MISSIONARY_COUNT:
    return "Invalid missionary count";
  case ERROR_INVALID_MOVE:
    return "Invalid move";
  case ERROR_MISSIONARIES_EATEN:
    return "The missionaries have been eaten! Oh dear!";
  case ERROR_INPUT_STREAM_ERROR:
    return "Unexpected input stream error";
  case ERROR_BONUS_NO_SOLUTION:
    return "No solution";
  case VALID_GOAL_STATE:
    return "Problem solved!";
  case VALID_NONGOAL_STATE:
    return "Valid state, everything is OK!";
  }
  return "Unknown error";
}


/* insert your functions here */

char** make_river_scene(const char* left, const char* boat){
  int left_length = strlen(left);
  if(left_length > 7){
    cerr << "left input is too large" << endl;
  }
  if(!is_left_valid(left)){
    cerr << "invalid left input" << endl;
  }

  // Checking for boat input
  int boat_length = strlen(boat);
  if(boat_length > 2){
    cerr << "boat input is too large" << endl;
  }
  if(!is_boat_valid(boat)){
    cerr << "invalid boat input" << endl;
  }

  // Drawing background
  char** scene = create_scene();
  add_to_scene(scene, 0,0, "bank.txt");
  add_to_scene(scene, 0,53, "bank.txt");
  add_to_scene(scene, 3,30, "sun.txt");
  add_to_scene(scene, 19,19, "river.txt");


  // Drawing missionary
  int number_m_left = count_char('M', left);
  int number_m_boat = count_char('M', boat);
  int number_m_right = 3 - number_m_left- number_m_boat;

  // Drawing cannibal
  int number_c_left= count_char('C', left);
  int number_c_boat = count_char('C', boat);
  int number_c_right = 3 - number_c_left - number_c_boat;

  add_person(scene, "missionary.txt", number_m_left, 3,2);
  add_person(scene, "missionary.txt", number_m_right, 3,55);

  add_person(scene, "cannibal.txt", number_c_left, 11,2);
  add_person(scene, "cannibal.txt", number_c_right, 11,55);

  // Drawing boat position
  int boat_left = count_char('B', left);
  draw_boat(scene, number_m_boat, number_c_boat, boat_left);

  return scene;
}

int perform_crossing(char* left, const char* target){
    int target_length = strlen(target);
    if(target_length == 0 || target_length > 2){
      return ERROR_INVALID_MOVE;
    }
    if(!is_boat_valid(target)){
      return ERROR_INVALID_MOVE;
    }

    char target_temp[3];
    strcpy(target_temp, target);

    // Left info
    int left_length = strlen(left);

    // Step1: Loading the boat
    remove_char(left, target_temp[0]);
    remove_char(left, target_temp[1]);
    char **scene = create_scene();
    scene = make_river_scene(left, target_temp);
    print_scene(scene);

    // Step2: Crossing the river
    int boat_left = count_char('B', left);

    if(boat_left == 0){
      // Moving from right to left
      scene = make_river_scene(left, target_temp);
      print_scene(scene);

      left[left_length] = 'B';
      left[left_length+1] = '\0';
    }else{
      // Moving from left to right
      scene = make_river_scene(left, target_temp);
      print_scene(scene);

      remove_char(left, 'B');
    }


    // Step 3: Unloading the boat
    remove_char(target_temp, target[0]);
    remove_char(target_temp, target[1]);
    scene = make_river_scene(left, target_temp);
    print_scene(scene);

    if(!is_missionary_safe(left)){
      return ERROR_MISSIONARIES_EATEN;
    }

    cout << "left status " << left << endl;
    if(strcmp(left,"") != 0){
      return VALID_NONGOAL_STATE;
    }

    return VALID_GOAL_STATE;
}

int play_game(){
  char left[8] = "MMMCCCB";
  char people_move[3];
  int status = VALID_NONGOAL_STATE;
  while(status == VALID_NONGOAL_STATE){
    cout << "Type one or two characters you want to move" << endl;
    cin.getline(people_move, 3);
    status = perform_crossing(left, people_move);
  }

  return status;
}

bool is_missionary_safe(char* left){
  int left_m = count_char('M', left);
  int left_c = count_char('C', left);
  int right_m = 3 - left_m;
  int right_c = 3 - left_c;

  if(left_m < left_c || right_m < right_c){
    return false;
  }else{
    return true;
  }
}

void remove_char(char* list, char target){
  for(int i = 0; list[i] != '\0'; i++){
    if(target == list[i]){
        shift(list, i);
        return;
    }
  }
}

void shift(char* list, int position){
  int length = strlen(list);
  for(int i = position; list[i] != '\0'; i++){
    list[i] = list[i+1];
  }
  list[length-1] = '\0';
}

void draw_boat(char** scene, int m, int c, int boat_left){
  if(boat_left == 1){
    add_to_scene(scene, 18, 20, "boat.txt");
    if(m == 0 &&  c== 2){
      add_person(scene, "cannibal.txt", 2, 13, 22);
    }else if(c == 0 && m == 2){
      add_person(scene, "missionary.txt", 2, 13, 22);
    }
    else if(m == 0 &&  c== 1){
      add_person(scene, "cannibal.txt", 1, 13, 22);
    }else if(c == 0 && m == 1){
      add_person(scene, "missionary.txt", 1, 13, 22);
    }else if(c == 1 && m == 1){
      add_person(scene, "missionary.txt", 1, 13, 22);
      add_person(scene, "cannibal.txt", 1, 13, 26);
    }
  }else{
    add_to_scene(scene, 18, 35, "boat.txt");
    if(m == 0 &&  c== 2){
      add_person(scene, "cannibal.txt", 2, 13, 35);
    }else if(c == 0 && m == 2){
      add_person(scene, "missionary.txt", 2, 13, 35);
    }
    else if(m == 0 &&  c== 1){
      add_person(scene, "cannibal.txt", 1, 13, 35);
    }else if(c == 0 && m == 1){
      add_person(scene, "missionary.txt", 1, 13, 35);
    }else if (c == 1 && m == 1){
      add_person(scene, "missionary.txt", 1, 13, 35);
      add_person(scene, "cannibal.txt", 1, 13, 41);
    }
  }
}

void add_person(char** scene, const char* filename, int numbers, int row, int col){
  int moving_col = col;
  for(int i = 0; i < numbers; i++){
    add_to_scene(scene, row, moving_col, filename);
    moving_col+= 5;
  }
}

int count_char(char target, const char* list){
  int count = 0;
  for(int i = 0; list[i] != '\0'; i++){
    if(target == list[i]){
      count++;
    }
  }
  return count;
}
bool is_left_valid(const char* left){
  for(int i = 0; left[i] != '\0'; i++){
    if(left[i] == 'M' || left[i] == 'C' ||left[i] == 'B'){
      continue;
    }else{
      return false;
    }
  }
  return true;
}

bool is_boat_valid(const char* boat){
  for(int i = 0; boat[i] != '\0'; i++){
    if(boat[i] == 'M' || boat[i] == 'C'){
      continue;
    }else{
      return false;
    }
  }
  return true;
}
