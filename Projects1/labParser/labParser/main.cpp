
/* 
 file Name:  main.cpp
 Author:  Mena Sergeyous
 Description gets the file from sequnceDatabase.cpp and implementation from squenceDatabase.h
 Date: 9/2/2015

*/
#include<string> 
#include<iostream>
using namespace std;
#include "sequenceDatabase.h"

int main(int argc, char* argv[])
{
	
	

	string commandsFilename = "labParser-commands-short.tab";
    
    // Read in a filename from STDIN (or default to one)
    // If nothing is entered (really just a return) then use the listed filename.
    // Otherwise, read one from STDIN.
    char firstChar;
    string stdinFilename;
    cout << "Please enter the commands filename (or simply press return to use " << commandsFilename << ")\n";
    cin.get( firstChar);
    if( firstChar != '\n'){
        cin >> stdinFilename;
        // replace the default filename
        commandsFilename = firstChar + stdinFilename;
    }

    SequenceDatabase entries; // use SequenceDatabase entries{ }; for C++ 11
    cout << "Importing " << commandsFilename << endl;
   entries.importEntries( commandsFilename);

	return 0;

}