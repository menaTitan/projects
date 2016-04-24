// Deque2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<deque>
#include<iostream>
#include<sstream>
using namespace std;

int   Find(deque<string> Find, string name) {
	for (int i = 0; i < Find.size(); i++) {
		if (Find.at(i) == name) {
			return i;

		}
		
					
	}
	return -1;
}

int main()
{
	deque<string> line;
	string name;
	int index;
	line.push_back("David");
	line.push_back("Raymond");
	line.push_back("Cynthia");
	line.push_back("Brian");
	line.push_back("Jennifer");
	
	cout << "Name To find: ";
	cin >> name;
	int pos = Find(line, name);
	if (pos > -1) {
		cout << name << " Found at position: " << pos << endl;
	}
	else {
		cout << name << " is not found. " << endl;
	}

	cout << "Enter the index to add a name: ";
	cin >> index;

	deque <string>::iterator iter = line.begin();
	iter += index;

	line.insert(iter, "Donnie");
	for (iter = line.begin(); iter < line.end(); ++iter) {
		cout << *iter << endl;
	}


    return 0;
}

