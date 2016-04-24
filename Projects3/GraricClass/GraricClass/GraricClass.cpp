// GraricClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<string>
using namespace std;
template<typename T>
class Stack {
private:
	T datastore[1000];
	int top;
public :
	Stack() {
		top = -1;
	}
	void push(int  num) {
		++top;
		datastore[top] = num;
	}
	T pop() {
		int  val = datastore[top];
		datastore[top] = 0;
		--top;
		return val;
	}
	T peek() {
		return datastore[top];
	}
};
template<>
class Stack<string>
{
private:
	string  datastore[1000];
	int top;
public:
	Stack() {
		top = -1;
	}
	void push(string  vall) {
		++top;
		datastore[top] = vall;
	}
	string  pop() {
		string   val = datastore[top];
		datastore[top] = "";
		--top;
		return val;
	}
	string  peek() {
		return datastore[top];
	}

};




int main()
{ 
	Stack <string> number;
	number.push("mena");
	number.push("sergeyous");
	cout << number.peek() << endl;
	string value = number.pop();
	cout << number.peek() << endl;

	
    return 0;
}

