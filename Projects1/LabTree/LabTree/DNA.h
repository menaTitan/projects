/*
 file Name:  DNA.h
 Author:  Mena Sergeyous
 Date: 9/24/2015
 */
#include"sequence.h"
#include<string>
using std::string;
#ifndef DNA_H
#define DNA_H
class DNA: public sequence {
// private Data only member function can access it 
private:
	int index;

	
// public member for the interface
public:
	DNA();
	DNA(int i);
	// *** polymorphic method call ***
	void print();
	
	void setindex(int ind);
	
	int  getIndex();
	
};
#endif