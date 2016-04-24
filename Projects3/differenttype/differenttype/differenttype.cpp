// differenttype.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#include<vector>


int main()

{
	vector<int> number(10);
	for (unsigned i = 0; i < 11; ++i) {
		number.push_back(i);
	}
	int sum = 0;
	for (unsigned i = 0; i < number.size(); ++i) {
		sum += number.at(i);
	}
	cout << " the sum was : " << sum << endl;
    return 0;
}

