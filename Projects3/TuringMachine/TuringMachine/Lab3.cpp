/*
Name: Mena Sergeyous
Date: 11/17/2015
Purpose: Creating program  that simulate  Turing Machine
*/
#include<iostream>
#include<string>
#include<sstream>
using namespace std;


int const rows = 50;
int const columns = 5;



int main() {
	char State = '0';
	int quintuples;
	string tape;
	char tapeArray[50];
	int count = 0;
	int steps = 0;
	// intializing the array to zero
	char array[rows][columns] = { {0} };
	cout << "Please input the number of quintuples: ";
	cin >> quintuples;
	cout << "Please input the " << quintuples << " quintuples:" << endl;
	for (int i = 0; i < quintuples; i++) {
		for (int j = 0; j < columns; j++) {
			cin >> array[i][j];
		}
	}
	//intializing array to b
	for (int i = 0; i < 50; i++) {
		tapeArray[i] = 'b';
	}
	// ask the user to in put the  tape in string varibale 
	cout << "Please input the initial tape configuration: " << endl;
	cin.ignore();
	getline(cin, tape);

	cout << "Please input the maximum number of steps: ";
	cin >> steps;
	cout << endl;
	cout << "initial tape " << tape << " start state 0" << endl;
	count = steps;

	int trackArray = 0;// keep track of the items in the array
	// put the string in array of char by using istringstream to ignore spaces
	istringstream get(tape);
	while (get >> tapeArray[trackArray]) {
		trackArray++;
	}
	// keep  track of  tape
	int tepeMove = 0;
	// keep tarck of quintuples array 
	int i = 0;
	do {
		for (; i < 50;) {

			int arrayMove = i;

			char checkTep = array[arrayMove][1];// this is going to be use to compare with tape array item
			char state1 = array[arrayMove][0];//  this is going to hold state in column 0
			char state2 = array[arrayMove][3];// this is going to hold state in column 3
			char LeftRight = array[arrayMove][4];// this get the direction of the quintuples array
			char write = array[arrayMove][2];// this going to write  to tape array
			char tepemove = tapeArray[tepeMove];// this move the direction inside the tape array
			if (checkTep == tepemove && State == state1 && LeftRight == 'R') {
				tapeArray[tepeMove] = array[i][2];
				State = array[i][3];
				cout << "Tape ";
				int k = 0;
				// keep printing the array until hit b 
				while (tapeArray[k] != 'b') {
					cout << tapeArray[k] << " ";
					k++;
				}
				cout << " state " << array[i][3] << endl;
				State = state2;
				//add 1 because direction equal R
				tepeMove += 1;
				i = 0;
			}
			else if (State == state1 && checkTep == tepemove && LeftRight == 'L') {
				tapeArray[tepeMove] = array[i][2];

				int k = 0;
				cout << "Tape ";
				// keep printing the array until hit b 
				while (tapeArray[k] != 'b') {
					cout << tapeArray[k] << " ";
					k++;
				}
				cout << " state " << array[i][3] << endl;
				State = state2;
				// subtract 1 because direction equal L
				tepeMove -= 1;
				i = 0;
			}
			else
			{
				i++;
			}
			//break if the  count equal  zero that mean  reach the max steps
			if (count == 0)
				break;
			count--;
		}
	} while (count > 0);


	return 0;
}
