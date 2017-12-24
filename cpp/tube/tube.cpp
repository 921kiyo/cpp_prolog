#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

#include "tube.h"

/* You are pre-supplied with the functions below. Add your own
	 function definitions to the end of this file. */

/* internal helper function which allocates a dynamic 2D array */
char** allocate_2D_array(int rows, int columns) {
	char** m = new char* [rows];
	assert(m);
	for(int r=0; r<rows; r++) {
		m[r] = new char[columns];
		assert(m[r]);
	}
	return m;
}

/* internal helper function which deallocates a dynamic 2D array */
void deallocate_2D_array(char** m, int rows) {
	for(int r=0; r<rows; r++)
		delete [] m[r];
	delete [] m;
}

/* internal helper function which gets the dimensions of a map */
bool get_map_dimensions(const char* filename, int& height, int& width) {
	char line[512];

	ifstream input(filename);

	height = width = 0;

	input.getline(line, 512);
	while(input) {
		if( (int) strlen(line) > width)
			width = strlen(line);
		height++;
		input.getline(line, 512);
	}

	if(height > 0)
		return true;
	return false;
}

/* pre-supplied function to load a tube map from a file*/
char** load_map(const char* filename, int& height, int& width) {

	bool success = get_map_dimensions(filename, height, width);

	if(!success) return NULL;

	char** m = allocate_2D_array(height, width);

	ifstream input(filename);

	char line[512];
	char space[] = " ";

	for(int r = 0; r<height; r++) {
		input.getline(line, 512);
		strcpy(m[r], line);
		while( (int) strlen(m[r]) < width ) {
			strcat(m[r], space);
		}
	}

	return m;
}

/* pre-supplied function to print the tube map */
void print_map(char** m, int height, int width) {
	cout << setw(2) << " " << " ";
	for(int c=0; c<width; c++) {
		if(c && (c % 10) == 0) {
			cout << c/10;
		} else {
			cout << " ";
		}
	}

	cout << endl;
	cout << setw(2) << " " << " ";

	for(int c=0; c<width; c++) cout << (c % 10);

	cout << endl;

	for(int r=0; r<height; r++) {
		cout << setw(2) << r << " ";
		for(int c=0; c<width; c++) cout << m[r][c];
		cout << endl;
	}
}

/* pre-supplied helper function to report the errors encountered in Question 3 */
const char* error_description(int code) {
	switch(code) {
	case ERROR_START_STATION_INVALID:
		return "Start station invalid";
	case ERROR_ROUTE_ENDPOINT_IS_NOT_STATION:
		return "Route endpoint is not a station";
	case ERROR_LINE_HOPPING_BETWEEN_STATIONS:
		return "Line hopping between stations not possible";
	case ERROR_BACKTRACKING_BETWEEN_STATIONS:
		return "Backtracking along line between stations not possible";
	case ERROR_INVALID_DIRECTION:
		return "Invalid direction";
	case ERROR_OFF_TRACK:
		return "Route goes off track";
	case ERROR_OUT_OF_BOUNDS:
		return "Route goes off map";
	}
	return "Unknown error";
}

/* presupplied helper function for converting string to direction enum */
Direction string_to_direction(const char* token) {
	const char* strings[] = {"N", "S", "W", "E", "NE", "NW", "SE", "SW"};
	for(int n=0; n<8; n++) {
		if(!strcmp(token, strings[n])) return (Direction) n;
	}
	return INVALID_DIRECTION;
}

bool get_symbol_position(char** map, int height, int width, char letter, int& r, int& c){
	for(int h = 0; h < height; h++){
		for(int w = 0; w < width; w++){
			if(letter == map[h][w]){
				r = h;
				c = w;
				return true;
			}
		}
	}
	r = -1;
	c = -1;
	return false;
}

char get_symbol_for_station_or_line(const char* name){
	char letter = ' ';
	letter = get_symbol(name, "stations.txt");
	if(letter == ' '){
		letter = get_symbol(name, "lines.txt");
	}
	return letter;
}

char get_symbol(const char* name, const char* filename){
	ifstream in_stream;
	in_stream.open(filename);

	const int MAX_LINE = 40;
	char line[MAX_LINE];
	char n[MAX_LINE];
	while(!in_stream.eof()){
		in_stream.getline(line, MAX_LINE);
		int counter = 0;
		for(int i = 2; line[i] != '\0'; i++){
			n[counter] = line[i];
			counter++;
		}
		n[counter] = '\0';

		if(!strcmp(n, name)){
			in_stream.close();
			return line[0];
		}
	}

	in_stream.close();
	return ' ';
}

void move_forward(char** map, int height, int width, Direction direction, int& current_row, int& current_column){
	switch(direction){
		case(N): current_row--; break;
		case(S): current_row++; break;
		case(W): current_column--; break;
		case(E): current_column++; break;

		case(NE): current_row--; current_column++; break;
		case(NW): current_row--; current_column--; break;
		case(SE): current_row++; current_column++; break;
		case(SW): current_row++; current_column--; break;
		default: break;
	}
}

int validate_route(char** map, int height, int width, const char* start_station, char* route, char* destination){
	int train_change = 0;
	char symbol = ' ';
	symbol = get_symbol(start_station, "stations.txt");
	if(symbol == ' '){
		return ERROR_START_STATION_INVALID;
	}
	if(!is_route_valid(route)){
		return ERROR_INVALID_DIRECTION;
	}

	char start_symbol = get_symbol_for_station_or_line(start_station);
	int current_row, current_column, previous_row, previous_column;
	get_symbol_position(map, height, width, start_symbol, current_row, current_column);

	char str[80];
	strcpy(str, route);
	for(char* p = strtok(str, ","); p != NULL; p=strtok(NULL, ",")){

		previous_row = current_row;
		previous_column = current_column;

		Direction direction = string_to_direction(p);
		move_forward(map, height, width, direction, current_row, current_column);

		if(is_off_bound(height, width, current_row, current_column)){
			return ERROR_OUT_OF_BOUNDS;
		}
		if(is_off_track(map, current_row, current_column)){
			return ERROR_OFF_TRACK;
		}

    // If the symbol is different, check if the previous symbol is a station
		if(map[previous_row][previous_column] != map[current_row][current_column]){
			if(!is_station(map[previous_row][previous_column])){
				return ERROR_LINE_HOPPING_BETWEEN_STATIONS;
			}
		}
	}

  // Check is the destination is a station
	destination[0] = '\0';
	char dest_symbol = map[current_row][current_column];
	get_name(dest_symbol, destination);
	if(destination[0] == '\0'){
		return ERROR_ROUTE_ENDPOINT_IS_NOT_STATION;
	}
	return train_change;
}

void get_name(char symbol, char* name){
	ifstream in_stream;
	in_stream.open("stations.txt");
	const int MAX_LINE = 40;
	char line[MAX_LINE];
	int counter = 0;
	while(!in_stream.eof()){
		in_stream.getline(line, MAX_LINE);
		if(symbol == line[0]){
			for(int i = 2; line[i] != '\0'; i++){
				name[counter] = line[i];
				counter++;
			}
			name[counter] = '\0';
			in_stream.close();
			return;
		}
	}
	in_stream.close();
}

bool is_off_track(char** map, int row, int column){
	char symbol = map[row][column];
	if(symbol == ' '){
		return true;
	}
	return false;
}

bool is_off_bound(int height, int width, int current_row, int current_column){
	if(current_row > height || current_row < 0 || current_column > width || current_column < 0){
		return true;
	}
	return false;
}

bool is_route_valid(char* route){
	for(char* p = strtok(route, ","); p != NULL; p=strtok(NULL, ",")){
		if(!strcmp(p, "N") || \
			 !strcmp(p, "S") || \
			 !strcmp(p, "E") || \
			 !strcmp(p, "W") || \
			 !strcmp(p, "NE") || \
			 !strcmp(p, "NW") || \
			 !strcmp(p, "SE") || \
			 !strcmp(p, "SW")){
			continue;
		}else{
			return false;
		}
	}
	return true;
}

bool is_station(char symbol){
	ifstream in_stream;
	in_stream.open("stations.txt");
	const int MAX_LINE = 40;
	char line[MAX_LINE];
	while(!in_stream.eof()){
		in_stream.getline(line, MAX_LINE);
		if(symbol == line[0]){
			return true;
		}
	}
	return false;
}
