/* 
file Name RNA.cpp
Author:  Mena Sergeyous
Description RNA.cpp  gets  implementation for RNA.h
Date: 10/29/2015

*/
#include"RNA.h"
#include<iostream>
#include<string>
using std:: cout;
using std:: endl;

RNA::RNA(){}

void RNA::SetRna(string tyRna){
	if (tyRna=="mRNA"){
		typeRna=mRNA;
	}
	else if(tyRna=="rRNA"){
		typeRna=rRNA;

	}
	else if(tyRna=="tRNA"){
		typeRna=tRNA;
	}
}
string RNA::getRna(){
	if (typeRna==0){
		return "mRNA";
	}
	else if(typeRna==1){
		return "rRNA";

	}
	else if(typeRna==2){
		return "tRNA";
	}
}

void RNA::print(){

	cout<<"RNA:	"<<"Label: " << getlabel()<<"	ID: "<< getAccesionID()<< "	Sequence: "<< getSquence()
		<< "	Length: "<< getLeSequence()<< "	Type: "<< getRna()<<endl;
	cout<<endl;

}

