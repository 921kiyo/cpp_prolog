void load_board(const char *filename, char board[9][9]);
void display_board(const char board[9][9]);
bool is_complete(char board[9][9]);
bool make_move(const char* position, char digit, char board[9][9]);
bool is_position_valid(const char* position);
bool save_board(const char* filename, char board[9][9]);
bool solve_board(char board[9][9]);

bool is_vertical_valid(char board[9][9]);
bool is_horizontal_valid(char board[9][9]);
// bool is_diagonal_valid(char board[9][9]);
bool is_cell_valid(char board[9][9]);
bool no_duplicate(char* array);
