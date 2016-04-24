// GericFunction.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
template<typename T, typename U>
void equal(T arg1, U arg2) {
	if (arg1 == arg2) {
		cout << " the same " << endl;

	}
	else {
		cout << "is not the same" << endl;
	}

}
template<typename E>
bool equals(E value1, E value2) {
	if (value1 == value2) {
		return true;

	}
	else {
		return false;
	}
}


int main()
{
	int  n = 10;
	int  m = 10;
	equal(n, m);
	if (equals(n, m)) {
		cout << n << " and " << m << "are equal " << endl;
	}
	else {
		cout << n << " and " << m << "are not equal." << endl;
	}
    return 0;
}

