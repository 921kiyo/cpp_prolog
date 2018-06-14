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

bool is_left_valid(const char* left);
bool is_boat_valid(const char* boat);
int count_char(char target, const char* list);

void add_person(char** scene, const char* filename, int numbers, int row, int col);

void draw_boat(char** scene, int m, int c, int boat_left);

int perform_crossing(char* left, const char* target);

void remove_char(char* list, char target);

void shift(char* list, int position);

bool is_missionary_safe(char* left);
int play_game();
