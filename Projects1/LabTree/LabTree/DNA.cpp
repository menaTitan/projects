/* 
 file Name: DNA.cpp
 Author:  Mena Sergeyous
 Description SequenceDatabase.cpp it include SequenceDatabase.h
 Date: 9/24/2015

*/

# include"DNA.h"
# include <iostream>
#include<string>

// create constructor takes 5 arguments
DNA::DNA(int i){
	

    index =i;
}

// defult constructor
DNA :: DNA(){
    index =0;
 
}

// seter for index
void DNA ::  setindex(int ind){

	index= ind;
}

// getter index
int  DNA ::  getIndex(){

	return index;
}
// void function  print
void DNA :: print(){

	   std:: cout <<"DNA " <<"Label: "<< getlabel() <<"ID: " << getAccesionID()
	   <<"Sequence: "<< getSquence()<<"Length: "<< getLeSequence() << " cDNAStartIndex: "<< getIndex()<<std::endl;
	  std::cout<< std::endl;

}
