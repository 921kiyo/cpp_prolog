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
const int TOTAL_M = 3;
const int TOTAL_C = 3;
char** make_river_scene(const char* left, const char* boat){
  // TODO Check if it contains any other characters

  int number_left_m = count(left,'M');
  int number_left_c = count(left,'C');
  int boat_left_bank = count(left,'B');
  int boat_column;
  // Set the position of the boat
  if(boat_left_bank == 1){
    boat_column = 20;
  }else{
    boat_column = 27;
  }

  int number_boat_m = count(boat,'M');
  int number_boat_c = count(boat,'C');
  int number_right_m = TOTAL_M - number_left_m - number_boat_m;
  int number_right_c = TOTAL_C - number_left_c - number_boat_c;

  char **scene = create_scene();
  // Setting background
  add_to_scene(scene, 2, 24, "sun.txt");
  add_to_scene(scene, 2, 1, "bank.txt");
  add_to_scene(scene, 2, 45, "bank.txt");
  add_to_scene(scene, 16, boat_column, "boat.txt");
  add_to_scene(scene, 20, 15, "river.txt");

  // Setting cannibal
  add_person(scene, number_left_c, 13, 2, "cannibal.txt");
  add_person(scene, number_right_c, 13, 45, "cannibal.txt");

  // Setting missionary
  add_person(scene, number_left_m, 4, 2, "missionary.txt");
  add_person(scene, number_right_m, 4, 45, "missionary.txt");

  // Setting people on the boat
  add_person(scene, number_boat_m, 10, boat_column + 5, "missionary.txt");
  add_person(scene, number_boat_c, 10, boat_column + 25, "cannibal.txt");

  return scene;
}

void add_person(char** scene, int number, int row, int col, const char* filename){
  // int column = col;
  for(int i = 0; i < number; i++){
    add_to_scene(scene, row, col, filename);
    col+= 6;
  }
}

int count(const char* input, char letter){
  int count = 0;
  for(int i = 0; input[i] != '\0'; i++){
    if(input[i] == letter){
      count++;
    }
  }
  return count;
}

int perform_crossing(const char* left, const char* targets){
  int target_length = strlen(targets);
  int number_m_left = count(left, 'M');
  int number_c_left = count(left, 'C');
  int number_b_left = count(left, 'B');

  int number_m_target = count(targets, 'M');
  int number_c_target = count(targets, 'C');

  int missionary_boat = 0;
  int cannibal_boat = 0;

  // Check if the target input is correct
  if(target_length < 1 || target_length > 2){
    return ERROR_INVALID_MOVE;
  }
  // Check if there is enough entity in the leftbank compared to targets
  if(number_m_left < number_m_target || number_c_left < number_c_target){
    return ERROR_INVALID_MOVE;
  }

  // Loading the boat
  missionary_boat = number_m_target;
  cannibal_boat = number_c_target;
  number_m_left -= number_m_target;
  number_c_left -= number_c_target;
  char input_left[10];
  strcpy(input_left, "");
  for(int i = 0; i < number_m_left; i++){
    strcat(input_left, "M");
  }
  for(int i = 0; i < number_c_left; i++){
    strcat(input_left, "C");
  }
  if(number_b_left != 1){
    // no boart on the left bank
  }
  strcat(input_left, "B");
  cout << "missionary_boat " << missionary_boat << endl;
  cout << "cannibal_boat " << cannibal_boat << endl;
  // Loading people on the boat
  char input_boat[3];
  strcpy(input_boat, "");
  for(int i = 0; i < missionary_boat; i++){
    strcat(input_boat, "M");
  }
  for(int i = 0; i < cannibal_boat; i++){
    strcat(input_boat, "C");
  }

  // TODO check if the length of the boat is less than 2
  if(!strcmp(input_boat, "")){
    // No one in the boat
    cout << "no one in the boat" << endl;
    return ERROR_INVALID_MOVE;
  }
  char **scene = create_scene();
  scene = make_river_scene(input_left, input_boat);
  print_scene(scene);

  // After the boat crossed
  int input_left_length = strlen(input_left);
  input_left[input_left_length-1] = '\0';
  scene = make_river_scene(input_left, input_boat);
  print_scene(scene);

  // Unload people from the boat
  strcpy(input_boat, "");
  scene = make_river_scene(input_left, input_boat);
  print_scene(scene);

  if(count(left, 'M') != count(left, 'C')){
    return ERROR_MISSIONARIES_EATEN;
  }

  if(count(left, 'M') > 0 || count(left, 'C') > 0){
    return VALID_NONGOAL_STATE;
  }
  cout << "left " << left << endl;
  return VALID_GOAL_STATE;
}

int play_game(){
  cout << "Let's play a game" << endl;
  cout << "starting point is below" << endl;
  char **scene = create_scene();

  char left[8] = "MMMCCCB";
  char boat[3] = "";
  in_play(scene, left, boat);
}

int in_play(char** scene, char* left, char* boat){
  char first, second;
  cout << "Type first value (M or C)" << endl;
  cin >> first;
  if(!is_first_valid(first)){
    cout << "First value is not valid. Try again" << endl;
    return in_play(scene, left, boat);
  }
  cout << "Type second value (M, C or . to stop)" << endl;
  cin >> second;
  if(!is_second_valid(first)){
    cout << "Second value is not valid. Try again" << endl;
    return in_play(scene, left, boat);
  }

  boat[0]=first;
  if(second == '.'){
    boat[1] = '\0';
  }else{
    boat[1]=second;
    boat[2]='\0';
  }
  cout << "boat " << boat << endl;
  cout << "left " << left << endl;
  int result = perform_crossing(left, boat);
  cout << "result " << result << endl;
  if(result == VALID_NONGOAL_STATE){
    scene = make_river_scene(left,boat);
    print_scene(scene);
    return in_play(scene, left, boat);
  }
  else{
    scene = make_river_scene(left,boat);
    print_scene(scene);
    return result;
  }
}

bool is_first_valid(char first){
  return (first == 'M' || first == 'C');
}

bool is_second_valid(char second){
  return (second == 'M' || second == 'C' || second == '.');
}
