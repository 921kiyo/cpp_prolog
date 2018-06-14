void load_board(const char *filename, char board[9][9]);
void display_board(const char board[9][9]);
bool is_complete(const char board[9][9]);

bool make_move(const char* position, char digit, char board[9][9]);
bool is_position_valid(const char* position);

int get_row_int(char row);
int get_column_int(char column);

bool is_vertical_valid(char board[9][9]);
bool is_horizontal_valid(char board[9][9]);
bool is_cell_valid(char board[9][9]);

bool no_duplicate(char* array);
bool appear_before(char* array, char letter, int position);

bool save_board(const char* filename, char board[9][9]);

bool solve_board(char board[9][9]);
void find_empty_cell(char board[9][9], int& row, int& column);

void get_numbers(char board[9][9], int row, int column, char* numbers);
