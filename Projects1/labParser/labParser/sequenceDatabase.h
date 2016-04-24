/*
 file Name:  main.cpp
 Author:  Mena Sergeyous
 Description gets the file from sequnceDatabase.cpp and implementation from squenceDatabase.h
 Date: 9/2/2015
 */
# include <string>
using namespace std;


#ifndef SEQUENCEDATABASE_H
#define SEQUENCEDATABASE_H
class SequenceDatabase{

public:
	// defult constructor
	SequenceDatabase();

	// void function that read a file as argument
	void importEntries(string fileName);

};


#endif