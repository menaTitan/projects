// list2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<list>
using namespace std;
void display(list<int> lyst) {
	list <int> ::iterator iter = lyst.begin();
	while (iter != lyst.end()) {
		cout << *iter << endl;
		++iter;

	}
}
void Maxlist(list<int> &lis, int value) {

	lis.sort();
	int MaxNumber = lis.back();
		if (MaxNumber < value ) {
			
			lis.push_back(value);
		}
		
	
	
}


int main()
{
	int num;
	list<int> number;
	number.push_back(0);
	
	for (int i = 1; i < 10; i++) {
		cout << "Enter A Number: ";
		cin >> num;
		Maxlist(number, num);
	}
	
	
	display(number);
    return 0;
}

