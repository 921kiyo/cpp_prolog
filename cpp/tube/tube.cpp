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

bool get_symbol_position(char** map, int height, int width, char target, int& r, int& c){
	for(int row = 0; row < height; row++){
		for(int col = 0; col < width; col++){
			if(map[row][col] == target){
				r = row;
				c = col;
				return true;
			}
		}
	}
	r = -1;
	c = -1;
	return false;
}

char get_symbol_for_station_or_line(const char* name){
	char symbol;
	if(!get_symbol("stations.txt", name, symbol)){
		get_symbol("lines.txt", name, symbol);
	}
	return symbol;
}

bool get_symbol(const char* filename, const char* name, char& sym){
	ifstream in_stream;
	in_stream.open(filename);
	char temp[80];
	if(in_stream.fail()){
		cout << "filename is not valid" << endl;
		in_stream.close();
		return false;
	}

	char line[80];
	// in_stream.get(symbol);
	while(!in_stream.eof()){
		in_stream.getline(line, 80);
		int counter = 2;
		int c = 0;
		while(line[counter] != '\0'){
			temp[c] = line[counter];
			c++;
			counter++;
		}
		temp[c] = '\0';
		if(strcmp(temp,name) == 0){
			sym = line[0];
			return true;
		}
	}

	in_stream.close();
	return false;
}

int validate_route(char** map, int height, int width, const char* start_station, char* route, char* destination){
	int changes = 0;
	char symbol;
	if(!get_symbol("stations.txt", start_station, symbol)){
		return ERROR_START_STATION_INVALID;
	}
	char path[100];
	strcpy(path, "");
	int path_counter = 0;

	int row_now, column_now;
	int row_previous, column_previous;
	char previous_direction[3];
	get_symbol_position(map, height, width, symbol, row_now, column_now);

	for(char* p=strtok(route, ","); p!=NULL; p=strtok(NULL, ",")){
		if(!is_route_valid(p)){
			return ERROR_INVALID_DIRECTION;
		}

		row_previous = row_now;
		column_previous = column_now;

		move(map, row_now, column_now,p);

		if(is_out_bound(height, width, row_now, column_now)){
			return ERROR_OUT_OF_BOUNDS;
		}

		if(is_off_track(map, row_now, column_now)){
			return ERROR_OFF_TRACK;
		}

    // checking if the train change only happens at a station
		if(path_counter >= 2 && map[row_now][column_now] != path[path_counter-2]){
			if(!isalnum(map[row_now][column_now]) && !isalnum(path[path_counter-2]) && !isalnum(map[row_previous][column_previous])){
				return ERROR_LINE_HOPPING_BETWEEN_STATIONS;
			}
		}

    // Check backtracking
		if(is_backtrack(previous_direction, p)){
			if(!isalnum(map[row_previous][column_previous])){
				return ERROR_BACKTRACKING_BETWEEN_STATIONS;
			}
		}

		// cout << "row now " << row_now << endl;
		// cout << "column now " << column_now << endl;
		// cout << map[row_now][column_now] << endl;

    // Check the change
		if(isalnum(map[row_previous][column_previous])){
			if(path_counter >= 2 && map[row_now][column_now] != path[path_counter-2]){
				changes++;
			}
		}

		path[path_counter] = map[row_now][column_now];
		path[path_counter+1] = '\0';
		cout << "counter " << path_counter << endl;
		path_counter++;

		strcpy(previous_direction, p);

	}

  // Check if the end point is a station
	if(!isalnum(map[row_now][column_now])){
		return ERROR_ROUTE_ENDPOINT_IS_NOT_STATION;
	}

	return changes;
}

bool is_backtrack(char* previous_direction, char* direction){
	if(strcmp(previous_direction,"N")==0 && strcmp(direction,"S") == 0){
		return true;
	}
	if(strcmp(previous_direction,"S")==0 && strcmp(direction,"N") == 0){
		return true;
	}
	if(strcmp(previous_direction,"W")==0 && strcmp(direction,"E") == 0){
		return true;
	}
	if(strcmp(previous_direction,"E")==0 && strcmp(direction,"W") == 0){
		return true;
	}
	if(strcmp(previous_direction,"NE")==0 && strcmp(direction,"SW") == 0){
		return true;
	}
	if(strcmp(previous_direction,"SW")==0 && strcmp(direction,"NE") == 0){
		return true;
	}
	if(strcmp(previous_direction,"SE")==0 && strcmp(direction,"NW") == 0){
		return true;
	}
	if(strcmp(previous_direction,"NW")==0 && strcmp(direction,"SE") == 0){
		return true;
	}

	return false;
}

void move(char** map, int& row, int& column, char* direction){
	if(strcmp(direction, "N") == 0){
		row--;
		return;
	}
	if(strcmp(direction, "S") == 0){
		row++;
		return;
	}
	if(strcmp(direction, "E") == 0){
		column++;
		return;
	}
	if(strcmp(direction, "W") == 0){
		column--;
		return;
	}
	if(strcmp(direction, "NE") == 0){
		row--;
		column++;
		return;
	}
	if(strcmp(direction, "NW") == 0){
		row--;
		column--;
		return;
	}
	if(strcmp(direction, "SE") == 0){
		row++;
		column++;
		return;
	}
	if(strcmp(direction, "SW") == 0){
		row++;
		column--;
		return;
	}
}

bool is_out_bound(int height, int width, int row_now, int column_now){
	if(row_now < 0 || row_now > height){
		return true;
	}
	if(column_now < 0 || column_now > width){
		return true;
	}
	return false;
}

bool is_off_track(char** map, int row, int column){
	if(map[row][column] == ' '){
		return true;
	}
	return false;
}

bool is_route_valid(char* route){
	if(strcmp(route,"N") == 0){
		return true;
	}
	if(strcmp(route,"S") == 0){
		return true;
	}
	if(strcmp(route,"W") == 0){
		return true;
	}
	if(strcmp(route,"E") == 0){
		return true;
	}
	if(strcmp(route,"NE") == 0){
		return true;
	}
	if(strcmp(route,"NW") == 0){
		return true;
	}
	if(strcmp(route,"SE") == 0){
		return true;
	}
	if(strcmp(route,"SW") == 0){
		return true;
	}
	return false;
}
