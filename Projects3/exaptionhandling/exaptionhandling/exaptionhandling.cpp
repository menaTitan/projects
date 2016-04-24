// exaptionhandling.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
const int DivingByZero = 1;


int main()
{
	try {
		int numer = 12;
		int denom = 0;
		if (denom == 0) {
			throw DivingByZero;
		}
		else {
			cout << numer / denom << endl;
		}
	}
	catch (int e) {
		if (e == DivingByZero) {
			cout << "Can't divide by zero" << endl;
		}
	}
    return 0;
}

