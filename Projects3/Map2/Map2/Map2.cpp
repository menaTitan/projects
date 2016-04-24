// Map2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string>
#include<iostream>
#include<map>
using namespace std;

int main()
{
	map<string, int> grades;
	grades["Jones"] = 78;
	grades["Smith"] = 83;
	grades["Green"] = 92;
	string name;

	cout << "Enter a Name to Find: ";
	cin >> name;
	if (grades.find(name) != grades.end()){

		cout << name << ": " << grades[name] << endl;
}
	else {
		cout << name << " not found." << endl;
	}
	double average = 0.0;
	int sum = 0;
	map<string, int> ::iterator it = grades.begin();
	while (it != grades.end()) {
		cout << it->first << " " << it->second << endl;
		sum += it->second;
		++it;
	}
	cout << endl;
	average = sum / grades.size();
	cout << "the averge grade is: " << average << endl;


    return 0;
}

