#include"sequence.h"
#ifndef AA_h
#define AA_h
class AA:public sequence{
private:
	int ORF;
public:
	void setORF(int orf);
	int getORF();
	// *** polymorphic method call ***
	void print();
	AA();
};

#endif