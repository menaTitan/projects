/* 
 file Name: DNA.cpp
 Author:  Mena Sergeyous
 Description SequenceDatabase. cpp it include SequenceDatabase.h
 Date: 9/2/2015

*/

# include"DNA.h"
# include <iostream>
#include<string>

// create constructor takes 5 arguments
DNA::DNA(string l, int  a, string  s, int le, int i){
	
	label =l;
    AccessionID =a;
	sequence =s;
	leSequence =le;
    index =i;
}

// defult constructor
DNA :: DNA(){
	label ="";
    AccessionID = 0;
	sequence = "";
	leSequence =0;
    index =0;
 
}
//seter  for label
void DNA :: setlabel(string la){


	label = la;

}

//seter  for AessionID
void DNA :: setAessionID(int Ac){
	AccessionID = Ac;


}
//seter  for sequence
void DNA :: setSequence(string  seq){

	sequence = seq;

}
//seter  for length sequence
void DNA ::  setleSequence(int les){
	leSequence=les;

}
// seter for index
void DNA ::  setindex(int ind){

	index= ind;

}
// getter for label
string DNA ::  getlabel(){

	return label;


}
// getter for Accesion ID
int DNA ::  getAccesionID(){

	return AccessionID;

}
// getter sequence
string DNA:: getSequence(){

	return sequence;
}
// getter length  sequence
int DNA ::  getLeSequence(){
	return leSequence;

}
// getter index
int  DNA ::  getIndex(){

	return index;

}
// void function  print
void DNA :: print(){

	


}
