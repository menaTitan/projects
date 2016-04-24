/* 
file Name RNA.h
Author:  Mena Sergeyous
Description RNA.h  provide  implementation for RNA.h
Date: 10/29/2015
*/

#include"sequence.h"
#ifndef RNA_H
#define RNA_H
class RNA : public sequence{

public:
	enum Rna{mRNA, rRNA, tRNA};
	// *** polymorphic method call ***
	void print();
	RNA();
	string getRna();
	void SetRna(string tyRna);
private:
	Rna typeRna;


};
#endif