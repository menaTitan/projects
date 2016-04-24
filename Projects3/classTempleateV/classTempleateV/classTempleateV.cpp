// classTempleateV.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include<sstream>

using namespace std;

template< class T, class U>
class CMap {
private:
	vector <T> keys;
	vector<U> values;
	
public:	
	CMap() {}
	void insert(T key, U value) {
		keys.push_back(key);
		values.push_back(value);
	}
	void get(int n) {
		stringstream stm;
		stm << keys[n] << ": " << values[n] << endl;
		cout << stm.str() << endl;
	}
};
int main()
{
	CMap <string, int > grades;
	grades.insert("Mena", 88);
	grades.insert("sergeyous", 90);
	grades.get(0);
	grades.get(1);


    return 0;
}

