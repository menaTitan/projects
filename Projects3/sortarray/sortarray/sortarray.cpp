// sortarray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;


int main()
{
	int const size = 20;

	int list[size] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int itemFound;
	cout << "Enter item to  find int the list" << endl;
	cin >> itemFound;
	for (int i = 0; i < size; i++) {
		if (itemFound == list[i]) {
			cout << "found the item  at idenx: " << i << " the value was: " << list[i] << endl;
		}
		else {

			cout << "item is not found" << endl;
		}
	}
    return 0;
}

