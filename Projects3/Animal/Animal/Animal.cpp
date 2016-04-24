// Animal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<vector>
using namespace std;
class Animal {
	
public:
	virtual void talk() = 0;


};
class Dog :public Animal {

public:
	virtual void talk() {
		cout << " Bow WOW" << endl;

	}
};
class Cat :public Animal {
public:
	virtual void talk() {
		cout << "Meow!" << endl;
	}



};



int main()
{
	vector <Animal*> anl;
	Dog fido;
	Cat kitty;
	anl.push_back(&fido);
	anl.push_back(&kitty);

	for (int i = 0; i < anl.size(); i++) {

		anl.at(i)->talk();
	}

    return 0;
}

