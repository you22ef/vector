#include <iostream>
#include <cmath>
#include <map>
using namespace std;

map<int, string>days = {
	{1,"January"},
	{2,"February"},
	{3,"March"},
	{4,"April"},
	{5,"May"},
	{6,"June"},
	{7,"July"},
	{8,"August"},
	{9,"September"},
	{10,"October"},
	{11,"November"},
	{12,"December"} 
};

class MonthError {
public:
	MonthError(int month) {
		try {
			if (month > 12) {
				throw "error";
			}
		}
		catch (...) {
			cout << "illegal month" << endl;
			exit(0);
		}
		
	}
};
class DayError {
public:
	DayError(int day,int month) {
		try {
			switch (day) {
				case 31:
					if (month != 1 && month != 3 && month != 5 && month != 7 && month != 8 && month != 10 && month != 12) {
						throw "error";
					}
					break;
				case 30:
					if (month == 2) {
						throw "error";
					}
					break;
				default:
					break;

			}
		}
		catch (...) {
			
			cout << "illegal day" << endl;
			exit(0);
		}

	}
};

int main()
{
	int day;
	int month;
	cout << "please enter the data " << endl;
	cout << "month : ";
	cin >> month;
	MonthError m(month);
	cout << "day : ";
	cin >> day;
	if (log10(month) == 2) {
		month = month % 10;
	}
	else if (floor(log10(month)) > 2) {
		cout << "illegal month" << endl;
		exit(0);
	}

	else if (floor(log10(day)) > 2) {
		cout << "illegal day" << endl;
		exit(0);
	}
	DayError d(day, month);
	cout << days[month] << " " << day;
}
