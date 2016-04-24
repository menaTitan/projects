// dynamticArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<iostream>
using namespace std;
const int CAPACITY = 1000;
int main()
{
	int*dArray;
	dArray = new int[CAPACITY];
	dArray[0] = 3;
	dArray[1]= 3;
	dArray[2 ] = 3;
	dArray[3]=3;
	cout << "Array" << endl;
	for (int i = 0; i < 4;i++){
	
		cout << dArray[i] << endl;
	
	}
	delete[] dArray;
	dArray = nullptr;
	
	return 0;

}

