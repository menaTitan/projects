// Deque3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include<deque>
using namespace std;




int main()
{
	
	deque <string> names;
	ifstream File;
	string line;
	File.open("C:\\Users\\Mena\\Documents\\deque.txt");
	
	while (!File.eof()) {
		getline(File, line);
		string::iterator it = line.end();
		--it;
		
		size_t pos = line.find(" ");
		string name = line.substr(0, pos); 
		if (*it == 'p') {
			names.push_front(name);

		}
		else {
			names.push_back(name);

		}
		
	}
	deque<string>::iterator it = names.begin();
	while (it !=names.end()) {
		cout << *it << endl;
		++it;

	}
	
							
	File.close();
	return 0;
	
}

