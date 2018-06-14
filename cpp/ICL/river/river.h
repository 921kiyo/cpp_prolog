const int SCENE_HEIGHT=24, SCENE_WIDTH=72;

enum Status {VALID_GOAL_STATE=2, VALID_NONGOAL_STATE=1,ERROR_INVALID_CANNIBAL_COUNT=-1, ERROR_INVALID_MISSIONARY_COUNT=-2, ERROR_INVALID_MOVE=-3, ERROR_MISSIONARIES_EATEN=-4, ERROR_INPUT_STREAM_ERROR=-5, ERROR_BONUS_NO_SOLUTION=-6};

char **allocate_2D_array(int rows, int columns);

/* internal helper function which deallocates a dynamic 2D array */
void deallocate_2D_array(char **m, int rows);
/* pre-supplied function which creates an empty ASCII-art scene */
char **create_scene();
/* pre-supplied function which frees up memory allocated for an ASCII-art scene */
void destroy_scene(char **scene);
/* pre-supplied function which displays an ASCII-art scene */
void print_scene(char **scene);
/* helper function which removes carriage returns and newlines from strings */
void filter(char *line);
bool add_to_scene(char **scene, int row, int col, const char *filename);

const char *status_description(int code);

char** make_river_scene(const char* left, const char* boat);
int count(const char* input, char letter);

void add_person(char** scene, int number,  int row, int col, const char* filename);

int perform_crossing(const char* left, const char* targets);

int play_game();

int in_play(char** scene, char* left, char* boat);

bool is_first_valid(char first);
bool is_second_valid(char second);
