#include"AA.h"
#include<iostream>
using namespace std;
AA::AA(){}
void AA:: setORF(int orf){

	ORF=orf;

}
int AA::getORF(){


	return ORF;
}

void AA:: print(){

	cout<<"AA: "<<"Label: " << getlabel() <<" ID: " << getAccesionID() <<" Sequence: "<<getSquence()
		<< "Length: " << getLeSequence()<< " ORF: "<< getORF()<<endl;

}