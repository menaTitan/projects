/* 
 file NAme SequenceDatabase.cpp
 Author:  Mena Sergeyous
 Description SequenceDatabase. cpp and implementation from squenceDatabase.h
 Date: 9/2/2015


*/


#include "SequenceDatabase.h"
#include <fstream>
#include <string>
#include "DNA.h"
#include <iostream>

//defult  constructor 

SequenceDatabase :: SequenceDatabase(){



}


void SequenceDatabase:: importEntries(string fileName){
	 // ftream object helps to read a file
	 fstream inFile;
	 
	 char tx[1000];
	 
		// pointer to object DNA
	 DNA* DNARecords; 
	  
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
		inFile.getline(tx,1000,'\t');

			 // checks if the == D 
		if (strncmp(tx,"D",1)==0){
			
			// create memory on the heap
			DNARecords = new DNA;
			
			// find  the data and puts on the heap
			inFile.getline(tx,1000,'\t');
			DNARecords->setlabel(tx);
			
			inFile.getline(tx,1000,'\t');
			DNARecords->setAessionID(stoi(tx));
			
			inFile.getline(tx,1000,'\t');
			DNARecords->setindex(atoi(tx));
			
			inFile.getline(tx,1000,'\t');
			DNARecords->setleSequence(atoi(tx));
			
			inFile.getline(tx,1000,'\n');
			DNARecords->setSequence(tx);

			// by find "D" cout adding Accession ID
			cout<<"Adding " << DNARecords->getAccesionID() << " ..."<<endl; 

		}
		//O <ID> (in labLinkedLists, obliterates the specified DNA entry; for now, print out "Obliterating <ID> ...")
		else if(strncmp(tx,"O",1)==0){
			inFile.getline(tx,1000,'\n');
		
			cout<<"Obliterating " << tx  << " ..." <<endl;
		
		
		}
		//P <ID> (in labLinkedLists, prints the specified DNA entry; for now, print out "Printing <ID> ...")
		else if(strncmp(tx,"P",1)==0){
		
			inFile.getline(tx,1000,'\n');

		
			cout<<"Printing"<< tx<< " ..." <<endl;
		
		
		}
		//S (in labLinkedLists, displays the number of DNA entries; for now, print out "Entries: NYI")
		else if (strncmp(tx,"S",1)==0)
		{

		
			cout<< "Entries: NYI"<< endl;
			inFile.getline(tx,1000,'\n');
			 
		}




	}

inFile.close();
}