// template.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

template <typename T, typename U>
T max(T arg1, U arg2) {
	return (arg1 > arg2) ? arg1 : arg2;

	/// if number arg1 > arg2  return arg1
	// else return arg2

}
int main()
{
	string name = "mena";
	string number = "12.00";
	
	cout << max(name, number) << endl;
    return 0;
}

