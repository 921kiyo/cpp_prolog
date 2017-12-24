#include <iostream>
#include <fstream>
using namespace std;

enum Day {Sun, Mon, Tue, Wed, Thu, Fri, Sat};

int closing_time(Day day_of_the_week);


void print_day(int count, ostream& out_stream){
  switch (count)
  {
  	case Sun: out_stream << "Sunday"; break;
  	case Mon: out_stream << "Monday"; break;
  	case Tue: out_stream << "Tuesday"; break;
  	case Wed: out_stream << "Wednesday"; break;
  	case Thu: out_stream << "Thursday"; break;
  	case Fri: out_stream << "Friday"; break;
  	case Sat: out_stream << "Saturday"; break;
  	default:	out_stream << "ERROR!";
  }
}

/* MAIN PROGRAM */
int main()
{
	int count;

              cout.setf(ios::left);
	/* Print table heading */
	cout.width(17);
	cout << "DAY";
	cout << "CLOSING TIME\n\n";

	/* Print table from Sunday to Saturday */
	for (count = static_cast<int>(Sun) ; count <= static_cast<int>(Sat) ; count++)
	{
		cout.width(19);
    print_day(static_cast<Day>(count), cout);

		cout << closing_time(static_cast<Day>(count)) << "pm\n";
	}

	return 0;
}
/* END OF MAIN PROGRAM */

/* FUNCTION TO GENERATE SHOP CLOSING TIMES FROM DAY OF THE WEEK */
int closing_time(Day day_of_the_week)
{
	switch(day_of_the_week){
    case Sun: return 1; break;
    case Sat: return 5; break;
    case Wed: return 8; break;
    default: return 6;
  }
}
