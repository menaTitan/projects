// listClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include <string>

using namespace std;
template <typename T>
class List {
private:
	vector<T> datastore;
public:
	List(){}
	void add(T item) {
		datastore.push_back(item);
	}
	void display() {
		for (int i = 0; i < datastore.size(); i++) {
			cout << datastore[i] << endl;
		}
	}
};


int main()
{
	List <string> grocery;
	grocery.add("milk");
	grocery.add("eggs");
	grocery.add("bread");
	grocery.display();
	cout << endl;
	List<int> grades;
	grades.add(72);
	grades.add(82);
	grades.add(70);
	grades.display();


    return 0;
}

