/* 
file NAme SequenceDatabase.cpp
Author:  Mena Sergeyous
Description SequenceDatabase. cpp and implementation from squenceDatabase.h
Date: 9/24/2015


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
			cout<<"Adding "<<DNAObject->getAccesionID()<<" ..."<<endl;
			cout<<endl;
			 tree.AddSequence(DNAObject);
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
			cout<<"Adding "<<RNAObject->getAccesionID()<<" ..."<<endl;
			cout<<endl;
			 tree.AddSequence(RNAObject);
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
			cout<<"Adding "<<AAObject->getAccesionID()<<" ..."<<endl;
			cout<<endl;
		    tree.AddSequence(AAObject);
		}

		//O <ID> (obliterates the specified entry, if possible)
		else if(strncmp(tx,"O",1)==0){
			//inFile.getline(tx,1000,'\n'); 
			inFile>>tx;
			cout<<"Obliterating "<< tx <<" ..."<< endl;
			
		}



		// Delete the node pointer

		//cout<<"Obliterating " << tx  << " ..." <<endl;


		//P P <ID> (prints the specified entry, if possible)
		else if(strncmp(tx,"P",1)==0){
			sequence * sq;
			//inFile.getline(tx,1000,'\n');
			inFile>>tx;
			cout<<"Printing "<< tx <<"  ..."<<endl;
			if(tree.FindSequence(tx)!= nullptr){
				 cout<<" item  does exist"<<endl;
				 sq->print();
			}
			else{
			   cout<<"can not find a item"<<endl;
			}
			// cout<<"Can not delete DNA "<<"(" <<  tx << ")" <<", NOT found!"<<endl
		}
		//S  (displays the total number of entries)
		else if (strncmp(tx,"S",1)==0)
		{
			cout<<"Total Tree Nodes:"<<tree.size()<<endl;
			
			cout<<endl;

		}
			else if (strncmp(tx,"Q",1)==0)
		{

			
			cout<<endl;

		}
	}


	inFile.close();
}