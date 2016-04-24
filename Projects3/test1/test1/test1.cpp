// test1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class list {

private:
	typedef struct node {
		int data;
		node*ptr;
	}nodePtr;
	nodePtr Head;
	nodePtr curr;
	nodePtr temp;

public:
	list();
	void AddNode(int AddNode);
	void DeleteNode(int DeleteNode);
	void printList();
};

list::list() {
	Head = nullptr;
	curr = nullptr;
	temp = nullptr;


}
int main()
{
	
	
    return 0;
}

