// #include <iostream>
// #include <cassert>
// #include <cstring>
//
// using namespace std;
//
// #include "tube.h"
//
// int main() {
//
// 	/* This code illustrates the use of the pre-supplied helper functions and the
// 	 * functions that you are supposed to write. */
//
// 	cout << "============== Pre-supplied functions ==============" << endl << endl;
//
// 	char** map;
// 	int height, width;
//
// 	cout << "Loading tube map with load_map():";
//
// 	/* loads the map from the file "map.txt" and sets height and width */
// 	map = load_map("map.txt", height, width);
// 	assert(map);
// 	cout << " done (height = " << height << ", width = " << width
// 			 << ")." << endl << endl;
// 	cout << "Printing map with print_map():" << endl;
//
// 	/* prints the map with row and column numbers */
// 	print_map(map,height,width);
// 	cout << endl;
//
// 	cout << "====================== Question 1 ==================" << endl << endl;
//
// 	int r, c;
// 	bool success = get_symbol_position(map, height, width, 'T', r, c);
// 	cout << "The symbol 'T' is ";
// 	if(success) {
// 		cout << "found at (" << r << "," << c << ")";
// 	} else {
// 		cout << "not found.";
// 	}
// 	cout << endl << endl;
//
// 	success = get_symbol_position(map, height, width, '4', r, c);
// 	cout << "The symbol '4' is ";
// 	if(success) {
// 		cout << "found at (" << r << "," << c << ")";
// 	} else {
// 		cout << "not found.";
// 	}
// 	cout << endl << endl;
//
// 	success = get_symbol_position(map, height, width, 'z', r, c);
// 	cout << "The symbol 'z' is ";
// 	if(success) {
// 		cout << "found at (" << r << "," << c << ")";
// 	} else {
// 		cout << "not found.";
// 	}
// 	cout << endl << endl;
//
// 	cout << "====================== Question 2 ==================" << endl << endl;
//
// 	cout << "The symbol for Victoria station is '" <<
// 		get_symbol_for_station_or_line("Victoria") << "'" << endl << endl;
//
// 	cout << "The symbol for Oxford Circus station is '" <<
// 		get_symbol_for_station_or_line("Oxford Circus") << "'" << endl << endl;
//
// 	cout << "The symbol for the District Line is '" <<
// 		get_symbol_for_station_or_line("District Line") << "'" << endl << endl;
//
// 	/* Birmingham station is not on the Tube map, so this should return ' ' */
// 	cout << "The symbol for Birmingham station is '" <<
// 		get_symbol_for_station_or_line("Birmingham") << "'" << endl << endl;
//
// 	cout << "====================== Question 3 ==================" << endl << endl;
//
// 	char route[512];
// 	char destination[512] = "nowhere";
//
// 	/* valid route to Leicester Square with 1 line change */
// 	strcpy(route, "S,SE,S,S,E,E,E,E,E,E,E,E,E,E,E");
// 	cout << "Starting at Oxford Circus and taking the steps:" << endl;
// 	cout << route << endl;
// 	int result = validate_route(
// 			map, height, width, "Oxford Circus", route, destination);
// 	if(result >= 0) {
// 		cout << "is a valid route with " << result <<
// 			" line change(s) ending at " << destination << "." << endl;
// 	} else {
// 		cout << "is an invalid route (" << error_description(result) << ")" << endl;
// 	}
// 	cout << endl;
//
// 	/* invalid route because of backtracking between stations */
// 	strcpy(route, "W,W,E,W,W,W");
// 	cout << "Starting at Sloane Square and taking the steps:" << endl;
// 	cout << route << endl;
// 	result = validate_route(
// 			map, height, width, "Sloane Square", route, destination);
// 	if(result >= 0) {
// 		cout << "is a valid route with " << result
// 			<< " line change(s) ending at " << destination << "." << endl;
// 	} else {
// 		cout << "is an invalid route (" << error_description(result) << ")" << endl;
// 	}
// 	cout << endl;
//
// 	/* invalid route because route goes outside of map bounds */
// 	strcpy(route, "E,NE,SE,SE,SE");
// 	cout << "Starting at Marylebone and taking the steps:" << endl;
// 	cout << route << endl;
// 	result = validate_route(map, height, width, "Marylebone", route, destination);
// 	if(result >= 0) {
// 		cout << "is a valid route with " << result <<
// 			" line change(s) ending at " << destination << "." << endl;
// 	} else {
// 		cout << "is an invalid route (" << error_description(result) << ")" << endl;
// 	}
// 	cout << endl;
//
// 	/* Add more of your own tests here. */
//
// 	return 0;
// }

#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

#include "tube.h"

int main() {

	/* This code illustrates the use of the pre-supplied helper functions and the
	 * functions that you are supposed to write. */

	cout << "============== Pre-supplied functions ==============" << endl << endl;

	char** map;
	int height, width;

	cout << "Loading tube map with load_map():";

	/* loads the map from the file "map.txt" and sets height and width */
	map = load_map("map.txt", height, width);
	assert(map);
	cout << " done (height = " << height << ", width = " << width
			 << ")." << endl << endl;
	cout << "Printing map with print_map():" << endl;

	/* prints the map with row and column numbers */
	print_map(map,height,width);
	cout << endl;

	cout << "====================== Question 1 ==================" << endl << endl;

	int r, c;
	bool success = get_symbol_position(map, height, width, 'T', r, c);
	cout << "The symbol 'T' is ";
	if(success) {
		cout << "found at (" << r << "," << c << ")";
	} else {
		cout << "not found.";
	}
	cout << endl << endl;

	success = get_symbol_position(map, height, width, '4', r, c);
	cout << "The symbol '4' is ";
	if(success) {
		cout << "found at (" << r << "," << c << ")";
	} else {
		cout << "not found.";
	}
	cout << endl << endl;

	success = get_symbol_position(map, height, width, 'z', r, c);
	cout << "The symbol 'z' is ";
	if(success) {
		cout << "found at (" << r << "," << c << ")";
	} else {
		cout << "not found.";
	}
	cout << endl << endl;

	cout << "====================== Question 2 ==================" << endl << endl;

	cout << "The symbol for Victoria station is '" <<
		get_symbol_for_station_or_line("Victoria") << "'" << endl << endl;

	cout << "The symbol for Oxford Circus station is '" <<
		get_symbol_for_station_or_line("Oxford Circus") << "'" << endl << endl;

	cout << "The symbol for the District Line is '" <<
		get_symbol_for_station_or_line("District Line") << "'" << endl << endl;

	/* Birmingham station is not on the Tube map, so this should return ' ' */
	cout << "The symbol for Birmingham station is '" <<
		get_symbol_for_station_or_line("Birmingham") << "'" << endl << endl;

	cout << "====================== Question 3 ==================" << endl << endl;

	char route[512];
	char destination[512] = "nowhere";

	/* valid route to Leicester Square with 1 line change */
	strcpy(route, "S,SE,S,S,E,E,E,E,E,E,E,E,E,E,E");
	cout << "Starting at Oxford Circus and taking the steps:" << endl;
	cout << route << endl;
	int result = validate_route(
			map, height, width, "Oxford Circus", route, destination);
	if(result >= 0) {
		cout << "is a valid route with " << result <<
			" line change(s) ending at " << destination << "." << endl;
	} else {
		cout << "is an invalid route (" << error_description(result) << ")" << endl;
	}
	cout << endl;

	/* invalid route because of backtracking between stations */
	strcpy(route, "W,W,E,W,W,W");
	cout << "Starting at Sloane Square and taking the steps:" << endl;
	cout << route << endl;
	result = validate_route(
			map, height, width, "Sloane Square", route, destination);
	if(result >= 0) {
		cout << "is a valid route with " << result
			<< " line change(s) ending at " << destination << "." << endl;
	} else {
		cout << "is an invalid route (" << error_description(result) << ")" << endl;
	}
	cout << endl;

	/* invalid route because route goes outside of map bounds */
	strcpy(route, "E,NE,SE,SE,SE");
	cout << "Starting at Marylebone and taking the steps:" << endl;
	cout << route << endl;
	result = validate_route(map, height, width, "Marylebone", route, destination);
	if(result >= 0) {
		cout << "is a valid route with " << result <<
			" line change(s) ending at " << destination << "." << endl;
	} else {
		cout << "is an invalid route (" << error_description(result) << ")" << endl;
	}
	cout << endl;

	/* Add more of your own tests here. */
	cout << "================== Additional Tests ==================" << endl << endl;

	cout << "---------------------- Q2 Additional Tests ---------------------" << endl << endl;
	/* Passing ' ' */
	cout << "The symbol for ' ' is '" <<
		get_symbol_for_station_or_line("' '") << "'" << endl << endl;

	/* Passing brank */
	cout << "The symbol for brank is '" <<
		get_symbol_for_station_or_line("") << "'" << endl << endl;

	cout << "---------------------- Q3 Valid route ---------------------" << endl << endl;

	/* Passing passing a few stations til the destination station  */
	strcpy(route, "E,E,E,E,E,E,E,E,E,E,E,E,E,E,E,E,E,E,E,E,E,E,E,E");
	cout << "1. Starting at Notting Hill Gate (passing a few stations) and taking the steps:" << endl;
	cout << route << endl;
	result = validate_route(map, height, width, "Notting Hill Gate", route, destination);
	if(result >= 0) {
		cout << "is a valid route with " << result <<
			" line change(s) ending at " << destination << "." << endl;
	} else {
		cout << "is an invalid route (" << error_description(result) << ")" << endl;
	}
	cout << endl;

	/* Passing an empty route */
	strcpy(route, "");
	cout << "2. Starting at Liverpool Street (empty route) and taking the steps:" << endl;
	cout << route << endl;
	result = validate_route(map, height, width, "Liverpool Street", route, destination);
	if(result >= 0) {
		cout << "is a valid route with " << result <<
			" line change(s) ending at " << destination << "." << endl;
	} else {
		cout << "is an invalid route (" << error_description(result) << ")" << endl;
	}
	cout << endl;

	/* Backtracking at the station */
	strcpy(route, "E,E,E,E,W,W,W,W");
	cout << "3. Starting at Notting Hill Gate (backtracking at the station) and taking the steps:" << endl;
	cout << route << endl;
	result = validate_route(map, height, width, "Notting Hill Gate", route, destination);
	if(result >= 0) {
		cout << "is a valid route with " << result <<
			" line change(s) ending at " << destination << "." << endl;
	} else {
		cout << "is an invalid route (" << error_description(result) << ")" << endl;
	}
	cout << endl;

	/* Very very long journey    */
	strcpy(route, "NE,E,E,E,SE,E,E,E,E,SE,E,SE,S,SE,SE,E,E,E,N,N,N,N,N,NW,W,W,W,W,W,W,W,W,W,W,SW,NW,W,W,W,SW");
	cout << "4. Starting at Euston/Euston Square (very long journey) and taking the steps:" << endl;
	cout << route << endl;
	result = validate_route(map, height, width, "Euston/Euston Square", route, destination);
	if(result >= 0) {
		cout << "is a valid route with " << result <<
			" line change(s) ending at " << destination << "." << endl;
	} else {
		cout << "is an invalid route (" << error_description(result) << ")" << endl;
	}
	cout << endl;

	/* Going around the 2 lines */
	strcpy(route, "E,E,E,NE,W,W,W,SW,E,E,E,NE,W,W,W,SW,E,E,E,NE,W,W,W,SW");
	cout << "5. Starting at Temple (Going around the 2 lines) and taking the steps:" << endl;
	cout << route << endl;
	result = validate_route(map, height, width, "Temple", route, destination);
	if(result >= 0) {
		cout << "is a valid route with " << result <<
			" line change(s) ending at " << destination << "." << endl;
	} else {
		cout << "is an invalid route (" << error_description(result) << ")" << endl;
	}
	cout << endl;

	cout << "----------------------- Invalid route --------------------" << endl << endl;
	/* Invalid station name */
	strcpy(route, "E,NE,SE,SE,SE");
	cout << "1. Starting at Hello (invalid name) and taking the steps:" << endl;
	cout << route << endl;
	result = validate_route(map, height, width, "Hello", route, destination);
	if(result >= 0) {
		cout << "is a valid route with " << result <<
			" line change(s) ending at " << destination << "." << endl;
	} else {
		cout << "is an invalid route (" << error_description(result) << ")" << endl;
	}
	cout << endl;

	/* Empty station name */
	strcpy(route, "E,NE,SE,SE,SE");
	cout << "2. Starting at \"\" (empty station name) and taking the steps:" << endl;
	cout << route << endl;
	result = validate_route(map, height, width, "", route, destination);
	if(result >= 0) {
		cout << "is a valid route with " << result <<
			" line change(s) ending at " << destination << "." << endl;
	} else {
		cout << "is an invalid route (" << error_description(result) << ")" << endl;
	}
	cout << endl;

	/* Passing only one valid route */
	strcpy(route, "SW");
	cout << "3. Starting at Liverpool Street (only one valid route) and taking the steps:" << endl;
	cout << route << endl;
	result = validate_route(map, height, width, "Liverpool Street", route, destination);
	if(result >= 0) {
		cout << "is a valid route with " << result <<
			" line change(s) ending at " << destination << "." << endl;
	} else {
		cout << "is an invalid route (" << error_description(result) << ")" << endl;
	}
	cout << endl;

	/* Passing only one invalid route */
	strcpy(route, "N");
	cout << "4. Starting at Liverpool Street (only one invalid route) and taking the steps:" << endl;
	cout << route << endl;
	result = validate_route(map, height, width, "Liverpool Street", route, destination);
	if(result >= 0) {
		cout << "is a valid route with " << result <<
			" line change(s) ending at " << destination << "." << endl;
	} else {
		cout << "is an invalid route (" << error_description(result) << ")" << endl;
	}
	cout << endl;

	/* Backtracking near the passing station */
	strcpy(route, "E,E,E,E,E,W,W,W,W,W");
	cout << "5. Starting at Notting Hill Gate (backtracking near the passing station) and taking the steps:" << endl;
	cout << route << endl;
	result = validate_route(map, height, width, "Notting Hill Gate", route, destination);
	if(result >= 0) {
		cout << "is a valid route with " << result <<
			" line change(s) ending at " << destination << "." << endl;
	} else {
		cout << "is an invalid route (" << error_description(result) << ")" << endl;
	}
	cout << endl;

	/* Backtracking near the passing station ver2*/
	strcpy(route, "S,SE,S,S,SE,NW");
	cout << "6. Starting at Oxford Circus (backtracking near the passing station) and taking the steps:" << endl;
	cout << route << endl;
	result = validate_route(map, height, width, "Oxford Circus", route, destination);
	if(result >= 0) {
		cout << "is a valid route with " << result <<
			" line change(s) ending at " << destination << "." << endl;
	} else {
		cout << "is an invalid route (" << error_description(result) << ")" << endl;
	}
	cout << endl;

	/* One illigal input letter in the route*/
	strcpy(route, "E,E,Z,E,E,W,W,W,W");
	cout << "7. Starting at Notting Hill Gate (one illigal input letter in the route) and taking the steps:" << endl;
	cout << route << endl;
	result = validate_route(map, height, width, "Notting Hill Gate", route, destination);
	if(result >= 0) {
		cout << "is a valid route with " << result <<
			" line change(s) ending at " << destination << "." << endl;
	} else {
		cout << "is an invalid route (" << error_description(result) << ")" << endl;
	}
	cout << endl;

	/* One illigal input input (int) in the route*/
	strcpy(route, "E,E,E,2,E,W,W,W,W");
	cout << "8. Starting at Notting Hill Gate (one illigal input input (int) in the route) and taking the steps:" << endl;
	cout << route << endl;
	result = validate_route(map, height, width, "Notting Hill Gate", route, destination);
	if(result >= 0) {
		cout << "is a valid route with " << result <<
			" line change(s) ending at " << destination << "." << endl;
	} else {
		cout << "is an invalid route (" << error_description(result) << ")" << endl;
	}
	cout << endl;

	/* One illigal input input (empty) in the route*/
	strcpy(route, "E,E,E,E,,W,W,W,W");
	cout << "9. Starting at Notting Hill Gate (one illigal input input (empty) in the route) and taking the steps:" << endl;
	cout << route << endl;
	result = validate_route(map, height, width, "Notting Hill Gate", route, destination);
	if(result >= 0) {
		cout << "is a valid route with " << result <<
			" line change(s) ending at " << destination << "." << endl;
	} else {
		cout << "is an invalid route (" << error_description(result) << ")" << endl;
	}
	cout << endl;

	/* One illigal input input (long illigal input) in the route*/
	strcpy(route, "E,E,E,E,NELLL,W,W,W,W");
	cout << "10. Starting at Notting Hill Gate (one illigal input input (long illigal input) in the route) and taking the steps:" << endl;
	cout << route << endl;
	result = validate_route(map, height, width, "Notting Hill Gate", route, destination);
	if(result >= 0) {
		cout << "is a valid route with " << result <<
			" line change(s) ending at " << destination << "." << endl;
	} else {
		cout << "is an invalid route (" << error_description(result) << ")" << endl;
	}
	cout << endl;

	/* Backtracking at the station and off track */
	strcpy(route, "E,E,E,E,E,W,W,W,W,W,W");
	cout << "7. Starting at Notting Hill Gate (backtracking at the station and off track) and taking the steps:" << endl;
	cout << route << endl;
	result = validate_route(map, height, width, "Notting Hill Gate", route, destination);
	if(result >= 0) {
		cout << "is a valid route with " << result <<
			" line change(s) ending at " << destination << "." << endl;
	} else {
		cout << "is an invalid route (" << error_description(result) << ")" << endl;
	}
	cout << endl;

	/* Wrong types in route station name */
	strcpy(route, "E,NE,SE,SE,SE");
	cout << "Starting at Hello and taking the steps:" << endl;
	cout << route << endl;
	result = validate_route(map, height, width, "", route, destination);
	if(result >= 0) {
		cout << "is a valid route with " << result <<
			" line change(s) ending at " << destination << "." << endl;
	} else {
		cout << "is an invalid route (" << error_description(result) << ")" << endl;
	}
	cout << endl;

	/* The train goes off the track */
	strcpy(route, "E,E,S,S,S");
	cout << "Starting at Oxford Circus (off track) and taking the steps:" << endl;
	cout << route << endl;
	result = validate_route(map, height, width, "Oxford Circus", route, destination);
	if(result >= 0) {
		cout << "is a valid route with " << result <<
			" line change(s) ending at " << destination << "." << endl;
	} else {
		cout << "is an invalid route (" << error_description(result) << ")" << endl;
	}
	cout << endl;

	/* The train does not finish at a station */
	strcpy(route, "S,SE,S,S,E,E,E,E,E,E,E,E,E,E");
	cout << "Starting at Oxford Circus (wrong destination) and taking the steps:" << endl;
	cout << route << endl;
	result = validate_route(map, height, width, "Oxford Circus", route, destination);
	if(result >= 0) {
		cout << "is a valid route with " << result <<
			" line change(s) ending at " << destination << "." << endl;
	} else {
		cout << "is an invalid route (" << error_description(result) << ")" << endl;
	}
	cout << endl;

	/* The train changing lines not at a station (hopping) */
	strcpy(route, "W,S,W,W,W,W");
	cout << "Starting at Liverpool Street (hopping) and taking the steps:" << endl;
	cout << route << endl;
	result = validate_route(map, height, width, "Liverpool Street", route, destination);
	if(result >= 0) {
		cout << "is a valid route with " << result <<
			" line change(s) ending at " << destination << "." << endl;
	} else {
		cout << "is an invalid route (" << error_description(result) << ")" << endl;
	}
	cout << endl;

	/* The train changing lines not at a station (hopping) */
	strcpy(route, "S,W,W,W,W,W,W,W,N");
	cout << "Starting at Liverpool Street (hopping) and taking the steps:" << endl;
	cout << route << endl;
	result = validate_route(map, height, width, "Liverpool Street", route, destination);
	if(result >= 0) {
		cout << "is a valid route with " << result <<
			" line change(s) ending at " << destination << "." << endl;
	} else {
		cout << "is an invalid route (" << error_description(result) << ")" << endl;
	}
	cout << endl;

	return 0;
}
