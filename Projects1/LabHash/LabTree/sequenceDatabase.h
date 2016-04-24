/*
file Name: sequenceDatabase.cpp
Author: Mena Sergeyoush
Date: 9/24/2015
*/


#ifndef SEQUENCEDATABASE_H
#define SEQUENCEDATABASE_H

#include<string>
#include<list>
#include"sequence.h"
#include"HashTable.h"

using namespace std;

class SequenceDatabase{
private:
	HashTable<sequence> * hashObject;
public:
	// defult constructor
	SequenceDatabase();

	// void function that read a file as argument
	void importEntries(string fileName);

};


#endif