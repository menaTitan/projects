// Gnaric.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<string>
using namespace std;

template<typename T>

void display(T arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}
template <typename T>
T max(T &arg1, T &arg2) {
	if (arg1 > arg2) {
		return arg1;
	}
	else  {
		return arg2;
	}
}
int main()
{
	const int size = 10;
	int number[size];
	for (int i = 0; i < size; i++) {
		number[i] = i + 1;
	}
	display(number, size);
	string name[] = { "jim","fred","jane","bob","Mary",
	"mike","Terri","Allison","Mason","Meredith" };
	display(name, size);
    
	
	string  m = "mena";
	string  b = "sergeyous";
	cout << max(m, b) << endl;
	
	
	
	return 0;

}

