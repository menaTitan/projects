// Author: Hyrum Carroll
#include <iostream>
#include <string>
#include "date.h"

using namespace std;

int main() {
	DateClass today;  // Use "DateClass today{ }" with a C++11 compliant compiler
	cout << "Hello\n";
	today.readDate();
	today.printDate();

	return 0;
}