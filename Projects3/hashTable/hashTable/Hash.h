#include<iostream>
#include<string>
using namespace std;


#ifndef HASH_H
#define HASH_H
class hashc {
private:
	static const int tableSize = 10;

	struct item
	{
		string name;
		string drink;
		item* next;
	};

	item* HashTable[tableSize];

public:
	hashc();
	
int Hash(string key);
void AddItem(string name, string drink);
int NumberOfItemsInIndex(int index);
void printTable();
void printItem(int index);

};




#endif