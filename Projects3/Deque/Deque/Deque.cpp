// Deque.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<string>
#include<deque>

using namespace std;

int main()
{
	deque<string>line;
	line.push_back("Customer 1");
	line.push_front("Customer 2");
	line.push_back("Customer 3");
	for (int i = 0; i < line.size(); i++) {
		cout << line.at(i) << endl;
	}
	line.pop_back();
	line.pop_front();
	cout << "---------------------------------" << endl;
	for (int i = 0; i < line.size(); i++) {
		cout << line.at(i) << endl;
	}
	cout << "size of line: " << line.size() << endl;

    return 0;
}

