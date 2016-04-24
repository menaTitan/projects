// cin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;



int main()
{
	string name;

	cout << "Enter your name: ";
	getline(cin, name);
	cout << "your name is " << name << endl;
	char c;
	c = cin.get();

	do {
		cout.put(c);
		c = cin.get();
	} while (!cin.eof());

    return 0;
}

