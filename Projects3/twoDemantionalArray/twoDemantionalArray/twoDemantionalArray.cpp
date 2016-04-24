// twoDemantionalArray.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include<time.h>
#include<stdlib.h>
#include<iostream>
using namespace std;


int main()
{
	int rows, cols;
	int** randArray;
	cout << "how many of random number would you like: ";
	cin >> rows;
	cout << " how many cols of random number would you like: ";
	cin >> cols;
	randArray = new int*[rows];
	for (int i = 0; i < rows; i++) {
		randArray[i] = new int[cols];
	}

		if (randArray == NULL) {
			cerr << "Error: Memory coud not be allocated ";
			return 1;
		}
		srand(time(NULL));
		for (int j = 0; j < rows; j++) {
			for (int i = 0; i < cols; i++) {
			
				randArray  [j][i]= rand() % 100;
			
			}
		}
		for (int j = 0; j < rows; j++) {
			for (int i = 0; i < cols; i++) {

				cout << "   " << randArray[j][i];


			}
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < rows; i++) {
			

				delete randArray[i];
			
		}
		
		
    return 0;
}

