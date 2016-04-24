// ExpcetionhandlingWithFile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<fstream>
using namespace std;



int main()
{
	ifstream file;
	file.exceptions(ifstream::failbit | ifstream::badbit);
	try {
		file.open(" file.text");
		while (!file.eof()) {
			cout << file.get();

		}
	}
	catch (ifstream::failure e){
		cout << e.what() << endl;
		cout << "Error opeing file." << endl;
		return (1);
	}
	file.close();

    return 0;
}

