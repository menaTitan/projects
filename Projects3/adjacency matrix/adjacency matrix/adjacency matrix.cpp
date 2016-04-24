// adjacency matrix.cpp :
//Mena Sergeyous

#include "stdafx.h"
#include <iostream>


using namespace std;
int const  rows = 20;
int const calum = 2;

void isolatedNodes(int a[][calum], int nodes) {
	// goes through the list until have negitive one;
	for (int i = 0; i < nodes; i++) {
			if (a[i][1] == -1) {

				cout << a[i][0] << " is an isolated node" << endl;
		    }
	}
}
 
int degreeNode(int a[][calum], int node) {
	// incrment count until equal to negtive one
	int count = 0;
	int degree;

	degree = a[node - 1][1];
	if (degree == -1) {
		return count;
	}
	
		while (degree != -1)
		{
			count++;
			degree = a[degree - 1][1];
		}
	
	return count;
}
void  adjacentAnother(int a[][calum], int node1, int node2) {
	//checks the two  nodes equal to each other until negtive one.
	int cpNode1 = 0;
	int cpNode2 = 0;
	int temp3 = 0;
	int temp4 = 0;
	int cp1 = 0;
	int cp2 = 0;
	int count = 0;
	int temp5;
	bool flag = false;
	cpNode1 = a[node1 - 1][0];
	cpNode2 = a[node2 - 1][0];
	temp5 = a[count][1];
	temp3 = a[node1 - 1][1];
	temp4 = a[node2 - 1][1];
		while ((temp3!=-1) && (temp4 !=-1) && (temp5!=-1))
		{
			cpNode1 = a[temp3-1][0];
			cpNode2 = a[temp4-1][0];
			cp1= a[temp3 - 1][1];
			cp2= a[temp4 - 1][1];
			if (cpNode1 == node2 || cpNode2==node1) {
				flag = true;
				break;
			}
			temp3 = a[cp1 - 1][1];
			temp4 = a[cp2 - 1][1];
			count++;
	}
		if (flag == true) {
			cout << "Node " << node1 << " is  adjacent to node " << node2 << endl;
			
		}
		else {
			cout << "Node " << node1 << " is NOT adjacent to node " << node2 << endl;
			
		}
}

void PrintAdjacencyList(int a[][calum], int node) {
	//print the adjancy list
	int temp1;
	int temp2;
	for (int i = 0; i < node; i++) {
		cout << a[i][0] << " ";
		temp1 = a[i][1];
		while (temp1 !=-1)
		{
			cout << a[temp1 - 1][0] << " ";
			temp2 = a[temp1-1][1];
			cout<< a[temp2 - 1][0]<<" ";
			temp1 = a[temp2-1][1];
		}

		cout << endl;
	}
	
	


}
void printAdjacencyMatrix(int a[][calum], int node) {
	
	// print Adjency matrix
	int temp1;
	int temp2;
	int temp3;
	int temp4;
	int temp5;
	bool flag = false;
	int count = 0;
	for (int r =0; r<node; r++) {
		for (int c = 0; c<node; c++) {
			temp1 = a[c][1];
			temp1 = a[c][0];
			temp2 = a[c][1];
			temp3 = a[temp2 - 1][0];
			temp4 = a[temp2 - 1][1];
			temp5 = a[temp4 - 1][0];
			temp1 = a[temp4 - 1][1];
				if (a[r][0] == temp3|| a[r][0] == temp5) {

					cout << 1 << " ";
				}
				else {


					cout << 0 << " ";
				}
			
		}
	
		cout << endl;
	}
	
}

int main()
{
	
	// declaring variable
	int Darray[rows][calum] = { {0} };
	int input1;
	int input2;
	int input3;

	//variable for asking the user for the number of rows
	int inputRows = 0;
	// declaring  varabile for the number of nodes
	int nodes = 0;
	
	//ask the user to enter the  number of nodes
	cout << "Please input the number of nodes: ";
	cin >> nodes;
	
	// ask the users to enter the number of raws 
	cout << "Please input the number of rows in the array pointer representation: ";
	cin >> inputRows;
	
	// ask the user to  array pointer representation
	cout << "Please input the array pointer representation" << endl;
	for (int r = 0; r < inputRows; r++) {
		for (int c = 0; c < calum; c++)
			cin >> Darray[r][c];
}

	do {
		cout<<"What would you like to do now ?" << endl;
		cout << "1. Print the adjacency matrix" << endl;
		cout << "2. Determine if there are any isolated nodes" << endl;
		cout << "3. Determine the degree of a node" << endl;
		cout << "4. Determine if one node is adjacent to another" << endl;
		cout << "5. Print an adjacency list representation" << endl;
		cout << "6. Quit" << endl;
		cin >> input1;
		switch (input1)
		{
		case 1:
			cout << "The adjacency matrix is:" << endl;
			printAdjacencyMatrix(Darray, nodes);
			cout << endl;
			break;
		case 2:
			isolatedNodes(Darray, nodes);
			cout << endl;
			break;
		case 3:
			cout << "Input the node in question :" << endl;
			cin >> input2;
			cout << "The degree of node " << input2 << " is " << degreeNode(Darray, input2) << endl;
			cout << endl;
			break;
		case 4:
			cout << "Input the two nodes:" << endl;
			cin >> input2;
			cin >> input3;
			adjacentAnother(Darray, input2, input3);
			cout << endl;
			break;
		case 5: 
			cout << "The adjacency list representation is:" << endl;
			PrintAdjacencyList(Darray,nodes);
			cout << endl;
			break;
		case 6:
			cout << "Goodbye" << endl;
			cout << endl;
			break;
		default:
			break;
		}

	} while (input1 != 6);
	
	
    return 0;
}

