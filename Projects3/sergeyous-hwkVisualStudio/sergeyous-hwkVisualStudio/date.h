#pragma once
#include <string>

using namespace std;

class DateClass {

public:
	DateClass();
	DateClass(int d, int y);
	void readDate();
	void printDate();

private:
	string month;
	int day;
	int year;
};