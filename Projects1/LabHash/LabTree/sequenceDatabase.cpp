/* 
file NAme SequenceDatabase.cpp
Author:  Mena Sergeyous
Description SequenceDatabase. cpp and implementation from squenceDatabase.h
Date: 10/29/2015
*/


#include "sequenceDatabase.h"
#include <fstream>
#include <string>
#include "sequence.h"
#include <iostream>
#include<cstring>
#include<vector>
#include"DNA.h"
#include"RNA.h"
#include"AA.h"

//defult  constructor 

SequenceDatabase :: SequenceDatabase(){}

void SequenceDatabase:: importEntries(string fileName){
	// ftream object helps to read a file
	fstream inFile;

	char tx[1000];
	bool flag = false;
	bool fag2= false;
	int TableSize;
	//vector<sequence> seqObject ;
	DNA * DNAObject;
	RNA * RNAObject;
	AA  *  AAObject;
	
	// it open  a file
	inFile.open(fileName);

	// check if the file open or not 
	if (!inFile){
		std::cout << "File not found." << std::endl;
		exit(1);
	}
	// while loop goes until the end of the file
	  inFile>>TableSize;
	  hashObject=new HashTable<sequence> (TableSize);
	while (!inFile.eof()){
		//get the line in the file and put in in char array
		//inFile.getline(tx,1000,'\t');

		inFile>>tx;
		// checks if tx  the == D 
		if (strncmp(tx,"D",1)==0){

			// create memory on the heap
			DNAObject=new DNA;

			// find  the data and puts on the heap
			//inFile.getline(tx,1000,'\t');
			inFile>>tx;
			DNAObject->setLabel(tx);
			inFile>>tx;
			DNAObject->setAccessionID(stoi(tx));
			inFile>>tx;
			DNAObject->setSequence(tx);
			inFile>>tx;
			DNAObject->setLeSequence(atoi(tx));
			inFile>>tx;
			DNAObject->setindex(atoi(tx));
			hashObject->insert(DNAObject);
			cout<<"Adding "<<DNAObject->getlabel()<<" ..."<<endl;
			 // check the load factor
			if(hashObject->LoadFactor()>1){
			   hashObject->rehash();
			   cout<<"Load Factor: "<< hashObject->LoadFactor()<<endl;
			}
			else{
			 cout<<"Load Factor: "<< hashObject->LoadFactor()<<endl;
			}
			
			cout<<endl;
		}
		if (strncmp(tx,"R",1)==0){
			// create memory on the heap
			RNAObject=new RNA;

			// find  the data and puts on the heap
			inFile>>tx;
			RNAObject->setLabel(tx);
			inFile>>tx;
			RNAObject->setAccessionID(stoi(tx));
			inFile>>tx;
			RNAObject->setSequence(tx);
			inFile>>tx;
			RNAObject->setLeSequence(atoi(tx));
			inFile>>tx;			
			RNAObject->SetRna(tx);
			hashObject->insert(RNAObject);
			cout<<"Adding "<<RNAObject->getlabel()<<" ..."<<endl;
			 // check the load factor
			if(hashObject->LoadFactor()>1){
			   hashObject->rehash();
			   cout<<"Load Factor: "<< hashObject->LoadFactor()<<endl;
			}
			else{
			cout<<"Load Factor: "<< hashObject->LoadFactor()<<endl;
			}
			cout<<endl;
		}

		if (strncmp(tx,"A",1)==0){
			// create memory on the heap
			AAObject=new AA;
			inFile>>tx;		
			AAObject->setLabel(tx);
			inFile>>tx;		
			AAObject->setAccessionID(stoi(tx));
			inFile>>tx;			
			AAObject->setSequence(tx);
			inFile>>tx;
			AAObject->setLeSequence(atoi(tx));
			inFile>>tx;
			AAObject->setORF(atoi(tx));
		    hashObject->insert(AAObject);
			cout<<"Adding "<<AAObject->getlabel()<<" ..."<<endl;
			// check the load factor
			if(hashObject->LoadFactor()>1){
			  hashObject->rehash();
			  cout<<"Load Factor: "<< hashObject->LoadFactor()<<endl;
			}
			else{
			cout<<"Load Factor: "<< hashObject->LoadFactor()<<endl;
			}
			cout<<endl;
		}

		//O <ID> (obliterates the specified entry, if possible)
		else if(strncmp(tx,"O",1)==0){
			//inFile.getline(tx,1000,'\n'); 
			inFile>>tx;
			cout<<"Obliterating "<< tx <<" ..."<< endl;
			hashObject->Delete(tx);

		}

		//P P <ID> (prints the specified entry, if possible)
		else if(strncmp(tx,"P",1)==0){
			
			//inFile.getline(tx,1000,'\n');
			inFile>>tx;
			cout<<"Printing "<< tx <<" ..."<<endl;
	        hashObject->print(tx);
			// cout<<"Can not delete DNA "<<"(" <<  tx << ")" <<", NOT found!"<<endl
		}
		//S  (displays the total number of entries)
		else if (strncmp(tx,"S",1)==0)
		{
			hashObject->Entries();
			
			cout<<endl;

		}
			
	}


	inFile.close();
}