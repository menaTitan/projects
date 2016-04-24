/*
Name: Mena Sregyous
Data: 12/5/2015
Purpuse: create a program that correct 10 bits parity code by use Hamming Correction and convert it from gray to decimal then display
the Message
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;
//function prototype
void hammingCorrection(string Array[], int size);
void removeParity(string Array[], int size);
void GrayToBinary(string Array[], int size);
void BinaryToDecimal(string Array[], int Decimal[], int size);
string encryption(char Array[], int  Decimal[], int size);

int main() {

	fstream inFile;
	// variable help to read a file 
	string fileName;
	//cin >> fileName;
	string fileName2;

	// opening a file 
	inFile.open("chars.dat");
	// check if the file exist
	char getChar[100];
	string  getData[1000];
	int Decimal[1000] = {0};
	string stData;
	string CoutString;

	// checks if the file open correctly 
	if (!inFile) {
		cout << "File not found." << endl;
		exit(1);
	}
	int sizeChar = 0;
	// avoid to repeat the last item in the file 
	while (inFile.peek() != EOF) {
		inFile.get(getChar[sizeChar]);
		//inFile >> getChar[sizeChar];
		sizeChar++;
	}


	// open the second file 
	fstream inFile2;
	//cin >> fileName2;
	inFile2.open("packets.dat");
	// checks if the file open correctly
	if (!inFile2) {
		cout << "File not found." << endl;
		exit(1);
	}

	int sizeData = 0;
	// checkes if the file open correclty
	while (inFile2.peek() != EOF) {
		inFile2 >> stData;
		getData[sizeData] = stData;
		sizeData++;
	}

	// function call 
	hammingCorrection(getData, sizeData);
	removeParity(getData, sizeData);
	GrayToBinary(getData, sizeData);
	BinaryToDecimal(getData, Decimal, sizeData);
	cout << encryption(getChar, Decimal, sizeData) << endl;

	return 0;
}
string  encryption(char Array[], int  Decimal[], int DecimalSize) {
	// return the string to cout;
	string temp;
	for (int i = 0; i < DecimalSize; i++) {
		// add character to string
		temp += Array[Decimal[i]];
	}
	return temp;
}
// convert Binary to Decimal 
void BinaryToDecimal(string Array[], int Decimal[], int size) {
	int totalDecimal = 0;
	int count = 0;

	for (int i = 0; i < size; i++) {
		for (unsigned int s = 0; s < Array[i].length(); s++) {

			if (s == 0 && Array[i].at(s) == '1') {
				count += 32;
			}
			else if (s == 1 && Array[i].at(s) == '1') {
				count += 16;
			}
			else if (s == 2 && Array[i].at(s) == '1') {
				count += 8;
			}
			else if (s == 3 && Array[i].at(s) == '1') {
				count += 4;
			}
			else if (s == 4 && Array[i].at(s) == '1') {
				count += 2;
			}
			else if (s == 5 && Array[i].at(s) == '1') {
				count += 1;
			}
		}
		Decimal[i] = count;
		count = 0;
	}
}
void GrayToBinary(string Array[], int size) {
	char firstBit = '0';
	char SecondBit = '0';
	unsigned int  BreakOutofBound = 1;
	for (int i = 0; i < size; i++) {
		//cout << "this is the Array " << Array[i] << endl;
		BreakOutofBound = 1;
		for (unsigned int s = 0; s < Array[i].length(); s++) {
			firstBit = Array[i].at(s);
			//break before the array goes out of bound
			if ((BreakOutofBound + 1) > Array[i].length()) {
				break;
			}
			SecondBit = Array[i].at(s + 1);

			if (firstBit == '0'&& SecondBit == '0') {
				Array[i].at(s + 1) = '0';
			}
			else if (firstBit == '1'&& SecondBit == '1') {
				Array[i].at(s + 1) = '0';
			}
			else if (firstBit == '0'&& SecondBit == '1') {
				Array[i].at(s + 1) = '1';
			}
			else if (firstBit == '1'&& SecondBit == '0') {
				Array[i].at(s + 1) = '1';
			}
			//keep count to break before the array goes out of bound
			BreakOutofBound++;

			//cout << Array[i] << endl;
		}
	}

}
// remove the parity bits 
void removeParity(string Array[], int size) {
	for (int i = 0; i < size; i++) {
		//removeParity 1
		Array[i].erase(0, 1);
		//cout << Array[i] << endl;
		//remove Parity 2
		Array[i].erase(0, 1);
		//cout << Array[i] << endl;
		//remove parity 4
		Array[i].erase(1, 1);
		//cout << Array[i] << endl;
		//remove parity 8
		Array[i].erase(4, 1);
		//cout << Array[i] << endl;
		//cout << "---------------------------------" << endl;
	}
}
// correct the error in the array 
void hammingCorrection(string Array[], int size) {
	int countOne = 0;
	for (int i = 0; i < size; i++) {
		countOne = 0;
		bool p1 = false;
		bool p2 = false;
		bool p4 = false;
		bool p8 = false;
		int index = 0;
		// checks the p1 even parity		
		if (Array[i].at(0) == '1') {
			countOne++;
		}
		if (Array[i].at(2) == '1') {
			countOne++;
		}
		if (Array[i].at(4) == '1') {
			countOne++;
		}
		if (Array[i].at(6) == '1') {
			countOne++;
		}
		if (Array[i].at(8) == '1') {
			countOne++;
		}
		//checks if the parity are not even
		if (countOne % 2 != 0) {
			p1 = true;
			countOne = 0;
		}
		else {
			countOne = 0;
		}
		//checks the p2 even parity
		if (Array[i].at(1) == '1') {
			countOne++;
		}
		if (Array[i].at(2) == '1') {
			countOne++;
		}
		if (Array[i].at(5) == '1') {
			countOne++;
		}
		if (Array[i].at(6) == '1') {
			countOne++;
		}
		if (Array[i].at(9) == '1') {
			countOne++;
		}
		if (countOne % 2 != 0) {
			p2 = true;
			countOne = 0;
		}
		else {
			countOne = 0;
		}
		//checks the p4 even parity
		if (Array[i].at(3) == '1') {
			countOne++;
		}
		if (Array[i].at(4) == '1') {
			countOne++;
		}
		if (Array[i].at(5) == '1') {
			countOne++;
		}
		if (Array[i].at(6) == '1') {
			countOne++;
		}
		//checks if the parity are not even
		if (countOne % 2 != 0) {
			p4 = true;
			countOne = 0;
		}
		else {
			countOne = 0;
		}
		//checks the p8 even parity
		if (Array[i].at(7) == '1') {
			countOne++;
		}
		if (Array[i].at(8) == '1') {
			countOne++;
		}
		if (Array[i].at(9) == '1') {
			countOne++;
		}
		//checks if the parity are not even
		if (countOne % 2 != 0) {
			p8 = true;
			countOne = 0;
		}
		else {

			countOne = 0;
		}
		// add all of the parity which  the error accorded 
		if (p1 == true && p2 == true && p4 == true && p8 == true) {
			index = (1 + 2 + 4 + 8) - 1;
			if (Array[i].at(index) == '1') {
				Array[i].at(index) = '0';
			}
			else {
				Array[i].at(index) = '1';
			}
		}
		// add all of the parity which  the error accorded 
		if (p1 == true && p2 == true && p4) {
			index = (1 + 2 + 4) - 1;
			if (Array[i].at(index) == '1') {
				Array[i].at(index) = '0';
			}
			else {
				Array[i].at(index) = '1';
			}
		}
		// add all of the parity which  the error accorded 
		if (p1 == true && p2 == true) {
			index = (1 + 2) - 1;
			if (Array[i].at(index) == '1') {
				Array[i].at(index) = '0';
			}
			else {
				Array[i].at(index) = '1';
			}
		}
		// add all of the parity which  the error accorded 
		if (p1 == true && p8 == true) {
			index = (1 + 8) - 1;
			if (Array[i].at(index) == '1') {
				Array[i].at(index) = '0';
			}
			else {
				Array[i].at(index) = '1';
			}
		}
		// add all of the parity which  the error accorded 
		if (p1 == true && p4 == true) {
			index = (1 + 4) - 1;
			if (Array[i].at(index) == '1') {
				Array[i].at(index) = '0';
			}
			else {
				Array[i].at(index) = '1';
			}
		}
		// add all of the parity which  the error accorded 
		if (p2 == true && p4 == true && p8 == true) {
			index = (2 + 4 + 8) - 1;
			if (Array[i].at(index) == '1') {
				Array[i].at(index) = '0';
			}
			else {
				Array[i].at(index) = '1';
			}
		}
		// add all of the parity which  the error accorded 
		if (p2 == true && p8 == true) {
			index = (2 + 8) - 1;
			if (Array[i].at(index) == '1') {
				Array[i].at(index) = '0';
			}
			else {
				Array[i].at(index) = '1';
			}
		}
		// add all of the parity which  the error accorded 
		if (p2 == true && p4 == true) {
			index = (2 + 4) - 1;
			if (Array[i].at(index) == '1') {
				Array[i].at(index) = '0';
			}
			else {
				Array[i].at(index) = '1';
			}
		}
		// add all of the parity which  the error accorded 
		if (p4 == true && p8 == true) {
			index = (4 + 8) - 1;
			if (Array[i].at(index) == '1') {
				Array[i].at(index) = '0';
			}
			else {
				Array[i].at(index) = '1';
			}
		}
		//cout << Array[i] << endl;
	}
}