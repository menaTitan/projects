/* 
file Name SequenceDatabase.h
Author:  Mena Sergeyous
Description SequenceDatabase. provid implementation from squenceDatabase.cpp
Date: 10/29/2015
*/


#include<string>
using std::string;
#ifndef SEQUENCE_H
#define SEQUENCE_H

class sequence{
protected:
	string  label;
	int AccessionID;
	string Sequence;
	int leSequence;

public:
	void setLabel(string lab);
	void setAccessionID(int AccID);
	void setSequence(string seq);
	void setLeSequence(int leseq);
	string getlabel();
	int  getAccesionID();
	string getSquence();
	int getLeSequence();
	// *** pure virtual method ***
	virtual void print()=0;
	sequence();
};

#endif
