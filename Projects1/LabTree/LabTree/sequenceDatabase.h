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
#include"sequenceTree.h"
using namespace std;

class SequenceDatabase{
private:
	 sequenceTree tree ;
	 TreeNode * tn;
public:
	// defult constructor
	SequenceDatabase();

	// void function that read a file as argument
	void importEntries(string fileName);

};


#endif