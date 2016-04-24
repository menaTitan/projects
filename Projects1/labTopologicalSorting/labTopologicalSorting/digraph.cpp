/*
Name:Mena Sergeyous
Date:11/21/2015 
purpose:gets the implementation from digraph.h and calculate list of classes that are prerequisites 
*/

#include<iostream>
#include<algorithm>
#include<string>
#include<fstream>
#include"digraph.h"
#include<vector>
#include<list>
#include<set>
using namespace std;

// add item to map 
void Digraph::addEdge(string  graph1,string  graph2){
	// first is string which is the key, second one is list of string  to
	adjList[graph1].push_back(graph2);
}

void Digraph:: TopologicalSorting(){
	bool flag1= false;
	bool flag2= false;
	// goes until adjacency list is empty
	while ( !adjList.empty())
	{
		// creating iterator that goes through the map 
		map<string,list<string>>::iterator it;
		flag1 =false;
		//create the iterator for the second part of the graphList2 to compare with adjacency matrix
		for(list<string> ::iterator iter=graphList2.begin(); iter!= graphList2.end() && ! flag1; ++ iter){
			//checks is the iter in graphList2  in the first part of the map
			it=adjList.find(*iter);
			if (it == adjList.end()){
				//add to TopLogSort list
				TopLogSort.push_front(*iter);
				// delete the item from graphList2
				deleteRoot(*iter);
				//remove item for the map
				graphList2.remove(*iter);
				flag1= true;
			}
			//checks if the string list in the map is empty then delete the root 
			else if (it ->second.empty()){
				//add item to the TopLogSort list
				TopLogSort.push_front(*iter);
				// call delete the second item in the map
				deleteRoot(*iter);
				flag1= true;
				// remove the item from the graphList2
				graphList2.remove(*iter);
			}
		}

	}
}
// Delete the vertices 
void Digraph:: deleteRoot( string find){

	//  it looks to all of the vertices in the first side of the map  and delete it
	if( adjList.find(find)!= adjList.end()){

		adjList.erase(find);
	}
	//it delete  the  second part in the map  which is string of list
	for (map<string,list<string>>::iterator it=adjList.begin(); it!=adjList.end(); ++it){
		// goes through each item in the second map
		for(auto c : it->second)
		{
			// find it and it delete it 
			if(c == find){
				(it->second).remove(c);
				break;
			}
		}
	}
}
//  add all  the number of Edges
void Digraph::NumberEdges(){

	for (map<string,list<string>>::iterator it=adjList.begin(); it!=adjList.end(); ++it){
		// count all of the second side of the map  which has all  the number of edges
		for(auto c : it->second)
		{
			NumEdges++;
		}
	}

}
// add all  the vertices  
void Digraph::NumberVertices(){
	// it calcualte the number of the  vertices bty iterating through the set 
	for (set<string>::iterator it=addset.begin(); it!=addset.end(); ++it){

		NumVertices++;
	}
}
// returns the number of  Edges
int Digraph:: getNumEdges(){

	return NumEdges;
}
// return the number of Vertices
int Digraph:: getNumVertices(){

	return NumVertices;
}
// this  print was for testing 
void Digraph:: print2(){
	for (list<string>::iterator it=TopLogSort.begin(); it!=TopLogSort.end(); ++it){
		cout<< *it <<endl;
	}

}
// returns string to get print in main
string Digraph::getTopoSort(){
	// temp variable to add it  to string so it return the hole thing
	string temp;
	//goes through the TopLogSort list and append to a string
	for (list<string>::iterator it=TopLogSort.begin(); it!=TopLogSort.end(); ++it){
		if( *it!="NONE"){
			temp.append(*it);
			temp.append("\n");
		}
	}
	return temp;
}
// mad this print to  test if the item in the second map was deleting 
void Digraph:: print(){
	// print adjacency list
	for (std::map<string,list<string>>::iterator it=adjList.begin(); it!=adjList.end(); ++it){
		std::cout << it->first << " => ";
		for(auto c : it->second)
		{
			cout << c << " ";
		}
		cout <<endl;
	}
}

// constroctor that read a file 
Digraph::Digraph(string  fileName){
	NumVertices=0;
	NumEdges=0;
	fstream  inFile;
	// it open a file 
	inFile.open(fileName);
	// string varaible that take the file and put in list 
	string  graph1;
	string  graph2;
	// chceks if the file has write 
	if(! inFile){
		cout<<"File not found."<<endl;
		exit(1);
	}
	// read  the file and put in temp  variable
	inFile>> graph1 >> graph2;
	while(inFile.peek()!=EOF){
		
		//avoid duplicate numbers to goes int graphList2 
		if(find(graphList2.begin(),graphList2.end(), graph1)== graphList2.end()){
			graphList2.push_back(graph1);
		}
		//avoid duplicate numbers to goes int graphList2 
		if(find(graphList2.begin(),graphList2.end(), graph2)== graphList2.end()){
			graphList2.push_back(graph2);
		}
		// add the first side of the graph  to the set to calcuate the number of vertices
		addset.insert(graph1);
		// add the second side of the graph to the set to calcuate the number of vertices
		addset.insert(graph2);
		// call  addEdge  to all the edge to the ad
		addEdge(graph1, graph2); 
		inFile>> graph1 >> graph2;
	}
	// close file
	inFile.close();
	// call  NumberEdges
	print();
	NumberEdges();
	// call   NumberVertices
	NumberVertices();
	// call TopologicalSorting 
	TopologicalSorting();
}