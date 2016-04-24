/*
 file Name:  DNA.h
 Author:  Mena Sergeyous
 Description gets the implementation
 Date: 9/2/2015
 */
#include<string>
using std::string ;
#ifndef DNA_H
#define DNA_H
class DNA{
// private Data only member function can access it 
private:
	string  label;
	int AccessionID;
	string  sequence;
	int leSequence;
	int index;

	
// public member for the interface
public:
	DNA();
	DNA(string  l, int  a, string  s, int le, int i);
	void print();
	
	
	void setlabel(string  la);
	void setAessionID(int Ac);
	void setSequence(string  seq);
	void setleSequence(int les);
	void setindex(int ind);
	
	string getlabel();
	int  getAccesionID();
	string getSequence();
	int getLeSequence();
	int  getIndex();

};
#endif