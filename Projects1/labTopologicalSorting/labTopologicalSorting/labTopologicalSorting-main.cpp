/*
Name:Mena Sergeyous
Date:11/21/2015 
purpose: runs everything 
*/
#include <iostream>
#include <string>
#include "digraph.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;

int main( /*int argc, char* argv[] */){
    string prereqsFilename = "exsc-prereqs.tab";

    // Read in a filename from STDIN (or default to one)
    // If nothing is entered (really just a return) then use the listed filename.
    // Otherwise, read one from STDIN.
    string stdinFilename;
    cout << "Please enter the prereqs filename (or simply press return to use " << prereqsFilename << ")\n";
    getline( cin, stdinFilename);
    if( stdinFilename != ""){
        prereqsFilename = stdinFilename;
    }
    
    // create a new Digraph from prereqsFilename
    Digraph prereqsGraph( prereqsFilename);

	//prereqsGraph.print();
    cout << "Found " << prereqsGraph.getNumVertices() << " vertices and " << prereqsGraph.getNumEdges() << " edges in " << prereqsFilename << "\n";
	cout << "Course order:\n" << prereqsGraph.getTopoSort() << endl;
    
    return 0;
}