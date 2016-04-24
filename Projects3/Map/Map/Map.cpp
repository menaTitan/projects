// Map.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<map>

using namespace std;


int main()
{
	map<string, string> numbers;
	numbers["Jones"] = "365";
	numbers["Smith"] = "467";
	numbers["Brown"] = "111";
	cout << "Jones: " << numbers["Jones"] << endl;
	cout << "Number of numbers: " << numbers.size() << endl;
	numbers.erase("Smith");
	cout << "Number of numbers: " << numbers.size() << endl;

    return 0;
}

