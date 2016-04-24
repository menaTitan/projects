#include<iostream>
#include<string>
#include<math.h>
#include"Hash.h"
using namespace std;

hashc::hashc() {
	for (int i = 0; i < tableSize; i++) {
		HashTable[i] = new item;
		HashTable[i]->name = " ";
		HashTable[i]->drink = " ";
		HashTable[i]->next = nullptr;
	}

}
int hashc::Hash(string key) {

	int hash = 0;
	int index;
	int power;
	for (int i = 0; i < key.length(); i++) {
		hash += (int)key[i];

	}
	///power = pow(hash, 3.0);
	index = hash%tableSize;
	return index;
}

int hashc::NumberOfItemsInIndex(int index) {
	int count = 0;
	if (HashTable[index]->name == " ") {

		return 0;
	}

	else {

		count++;
		item* ptr = HashTable[index];

		while (ptr->next != nullptr)
		{
			count++;
			ptr = ptr->next;
		}
	}

}
void hashc::printItem(int index) {
	item* ptr = HashTable[index];
	if (ptr->name == " ") {
		cout << "index = " << index << "is empty";
	}
	else {
	
		cout << "index" << index << "contains the following item\n";
		while (ptr != nullptr)
		{
			cout << "-------------------------\n";
			cout << ptr->name << endl;
			cout << ptr->drink << endl;
			cout << "------------------\n";
			ptr = ptr->next;
		}
	
	}

}

void hashc::printTable() {
	int number;
	for (int i = 0; i < tableSize; i++) {
		number = NumberOfItemsInIndex(i);
		cout << "------------------------------------------" << endl;
		cout << "index= " << i << endl;
		cout << HashTable[i]->name << endl;
		cout << HashTable[i]->drink << endl;
		cout << "# of items= " << number << endl;
		cout << "---------------------------\n";
	}

}
void hashc::AddItem(string name, string drink) {

	int index = Hash(name);
	if (HashTable[index]->name == " ") {

		HashTable[index]->name = name;
		HashTable[index]->drink = drink;
	}
	else {
		item * ptr = HashTable[index];
		item* n = new item;
		n->name = name;
		n->drink = drink;
		n->next = nullptr;
		while (ptr->next != nullptr) {
			ptr = ptr->next;
		}
		ptr->next = n;
	}

}
