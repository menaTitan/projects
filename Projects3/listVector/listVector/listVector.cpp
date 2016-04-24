// listVector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<list>
#include<string>
using namespace std;

void displyList(list<string> name) {
	list<string>::iterator iter = name.begin();
	while (iter != name.end())
	{
		cout << *iter << endl;
		++iter;
	}
}
int main(){
	list<string> names;
	names.push_back("Mary");
	names.push_back("Zach");
	names.push_back("elizabeth");
	list<string>::iterator iter = names.begin();
	while (iter !=names.end())
	{
		cout << *iter << endl;
		++iter;
	}
	cout << "first item: " << names.front() << endl;
	cout << "last item: " << names.back() << endl;
	names.reverse();
	list<string> :: iterator riter = names.begin();
	while (riter != names.end())
	{
		cout << *riter << endl;
		++riter;

	}
		cout << "-----------------------------------------" << endl;
		names.sort();

		displyList(names);
		names.push_front("Barry");
		displyList(names);
		cout << " size of list: " << names.size() << endl;
		names.remove("elizabeth");
		displyList(names);
		names.pop_front();
		names.pop_back();
		cout << "-------------------------------" << endl;
		displyList(names);
		names.clear();
		if (names.empty()) {
			cout << "The List is empty" << endl;
		}


		return 0;
	
}

