/* 
file Name RNA.cpp
Author:  Mena Sergeyous
Description RNA.cpp  gets  implementation for RNA.h
Date: 9/24/2015


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
		typeRna==tRNA;
	}
}
string RNA::getRna(){
	if (typeRna==mRNA){
		return "mRNA";
	}
	else if(typeRna==rRNA){
		return "rRNA";

	}
	else if(typeRna==tRNA){
		return "tRNA";
	}
}

void RNA::print(){

	cout<<"RNA: "<<"Label: " << getlabel()<<" ID: "<< getAccesionID()<< " Sequence: "<< getSquence()
		<< " Length: "<< getLeSequence()<< " Type: "<< getRna()<<endl;
	cout<<endl;

}

