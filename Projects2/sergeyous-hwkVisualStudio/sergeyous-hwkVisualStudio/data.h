// Author: Hyrum Carroll
#include <string>

using namespace std;

class DateClass{

public:
	DateClass();
	void readDate();
	void printDate();

private:
	string month;
	int day;
	int year;
};