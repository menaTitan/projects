// fstream2.cpp : Defines the entry point for the console application.
//

// fstream.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<sstream>
#include<fstream>
#include <iostream>
using namespace std;



int main()
{
	ifstream gradeFile;
	stringstream grades;
	int grade;
	int total = 0;
	gradeFile.open("C:\\Users\\Mena\\Documents\\grade2.txt");
	string line;
	int i = 0;
	int div = 0;
	int avg;

	getline(gradeFile, line);
	grades << line;

	for (int i = 0; i < 5; i++) {
		grades >> grade;
		total += grade;

	}
	

	avg = total / 5;
	cout << avg << endl;
	
	/*while (!gradeFile.eof()) {



		gradeFile >> line;
		grade = atoi(line.c_str());
		cout << grade << endl;
		total += grade;
		++i;
		div = i;
	}

	gradeFile.close();
	int averge = total / div;
	cout << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << " The averge is: " << averge << endl;*/
	

	return 0;
}



