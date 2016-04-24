/*
Name:Mena Sergeyous
Date:11/21/2015 
purpose:proved implemenation to  digraph.cpp
*/


#ifndef DIAGRAPH_H
#define DIAGRAPH_H
#include<iostream>
#include<list>
#include<string>
#include<vector>
#include<map>
#include<set>
using std::string;
using std::list;
using std::vector;
using std:: map;
using std:: set;

class Digraph{

public:
	// constructor that take string has argument 
	Digraph(string fileName);
	// set the number of vertices
	void setNumVertices( int NumV);
	// set the number of edges
	void setNumEdges(int NumE);
	// returns the number of Vertices
	int getNumVertices();
	//  retuns the number of Edges
	int getNumEdges();
	// it add  edge
	void addEdge(string  v, string adj);
	void print();
	void print2();
	string getTopoSort();
	//calculate  the number of Edges
	void NumberEdges();
	// calculate the number of Vertices
	void NumberVertices();
	// calculate the TopolgicalSorting
	void TopologicalSorting();
	void  deleteRoot(string find);

private:
	string vertices; // number of vertices
	list<string> TopLogSort;
	list<string> graphList1;
	list<string> graphList2;
	// it helps  to calcualte the number of vertices by avoiding duplicate items
	set<string> addset;
	// create the adjacncy list
	map<string, list<string>> adjList;
	// keeps tracks of the number of vertices
	int NumVertices;
	// keeps tracks if the number of edges
	int NumEdges;
};
#endif 
