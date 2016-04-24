// string.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Person {
private:
	string first, middle, last;
	int age;
public:
	Person(string f, string m, string l, int ag) {
		first = f;
		middle = m;
		last = l;
		age = ag;

	}
	string ToString() {
		stringstream ms;
		ms<< first<<  " " << middle <<" " << last << " " << age;
		return ms.str();
	}
};




int main()
{
	Person p("Mena", "Kamal", "Sergeyous", 23);
	cout << p.ToString() << endl;

    return 0;
}

