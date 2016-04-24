// associativeContainer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<utility>
#include<string>

using namespace std;


int main()
{
	pair<string, string>number1("Janes", "123");
	cout << number1.first << ":" << number1.second << endl;
	pair<string, int> student1("Brown", 80);
	cout << student1.first << " : " << student1.second << endl;
    return 0;
}

