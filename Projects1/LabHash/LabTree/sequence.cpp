/* 
 file Name: sequence.cpp
 Author:  Mena Sergeyous
 Description Sequence.cpp it include SequenceDatabase.h
 Date: 9/24/2015

*/
#include<iostream>
#include<string>
#include"sequence.h"

sequence :: sequence(){
}

void sequence:: setAccessionID(int AccID){
	AccessionID=AccID;
}
void sequence:: setLabel(string lab){
	label=lab;
}
void sequence::setSequence(string seq){
	Sequence=seq;
}
void sequence::setLeSequence(int leseq){
	leSequence=leseq;
}
string sequence:: getlabel(){

	return label;
}
int sequence:: getAccesionID(){
	return AccessionID;
}
string sequence:: getSquence(){
	return Sequence;
}
int sequence:: getLeSequence(){
	return leSequence;
}
