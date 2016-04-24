// Author: Hyrum Carroll
#include <string>
#include "date.h"
#include <iostream>


using namespace std;

DateClass::DateClass(int d, int y) {

	day = d;
	year = y;

}

DateClass::DateClass() {
	month = "August";
	day = 1;
	year = 2012;
}

void DateClass::printDate() {
	cout << "\n\nMonth: " << month << endl;
	cout << "Day: " << day << endl;
	cout << "Year: " << year << endl;
}

void DateClass::readDate() {
	cout << "What is the current month?\n";
	getline(cin, month, '\n');
	cout << "What is the current day?\n";
	cin >> day;
	cout << "What is the current year?\n";
	cin >> year;
	cout << "Thank you\n";
}