// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int array[100] = { 15, 20, 25, 30, 35 };
	int array2[100] = { 15, 20, 25, 30, 35 };
	int *ptr;
	int *ptr2;
	int result;
	ptr = &array2[0];
	ptr2=&array[0];
	for (int i = 0; i <100; i++){
		result = *ptr * *ptr2;
		cout<< i <<"\t "<< result << endl;
		ptr++;
		ptr2++;
	}
	system("pause");
	return 0;
}

