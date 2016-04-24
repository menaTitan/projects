// p5.cpp : Defines the entry point for the console application.
//



#include"stdafx.h"
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
//#include"opcodes.h"

#include <iomanip>

using namespace std;
string foundString(int &found);
int main(int argc, char* argv[])
{
	char line1;
	int line2, line3, line4, line5;
	vector<int> ram(16000);
	int lp = atoi(argv[2]);
	int cmp = 0;
	int holder;
	int holder2;
	int holder3;
	vector<int>regRam(32);
	vector<char> column1;
	vector<int> column2;
	vector<int> column3;
	vector<int> column4;
	vector<int> column5;
	vector<char> def1;
	vector<int>def2;
	vector<int>def3;
	vector<int>def4;
	ifstream inFile;
	string tx;
	bool halted = false;
	vector<string>whole;
	string*op;
	inFile.open(argv[1]);
	if (!inFile){
		cout << "File not found." << endl;
		//exit(1);
	}

	while (inFile.peek() != EOF){
		getline(inFile, tx);
		istringstream iss(tx);
		iss >> line1;
		column1.push_back(line1);
		if (column1.back() == 'T'){
			iss >> line2;
			column2.push_back(line2);
			iss >> line3;
			column3.push_back(line3);
			iss >> line4;
			column4.push_back(line4);
			iss >> line5;
			column5.push_back(line5);
			ram[column2.back() + lp] = column3.back();
			ram[column2.back() + 1 + lp] = column4.back();
			ram[column2.back() + 2 + lp] = column5.back();
		}
		if (column1.back() == 'R'){
			def1.push_back(column1.back());
			column1.pop_back();
			iss >> line2;
			def2.push_back(line2);
			cmp = def2.back() - column2.back();

		}
		switch (cmp){
		case 1:
			ram[column2.back() + 1 + lp] = column4.back() + lp;
			break;
		case 2:
			ram[column2.back() + 2 + lp] = column5.back() + lp;
			break;
		default:
			break;
		}
		cmp = 0;
		if (halted)
		{
			def3.push_back(column3.back());
			column3.pop_back();
			iss >> line2;
			def4.push_back(line2);
			ram[column2.back() + lp] = line3;

		}


		if (column3.back() == 33){
			halted = true;
		}



	}


	cout << "\n\n\n";

	/*for (int i = 0; i < 80; i++)
	{
	if (i % 3 == 0)
	cout << endl;
	cout << setw(5) << right << ram[i];
	}

	cout << "\n\n\n";
	*/

	for (;;){
		int r1 = ram[regRam[31] + 1];
		int r2 = ram[regRam[31] + 2];
		regRam[31] += 3;
		switch (ram[regRam[31]]){

		case 1:
			break;
		case 2:
			regRam[r1] = ram[r2 + lp];
			break;
		case 3:
			regRam[r1] = ram[r2];
			break;
		case 4:
			//	load into r1 the fullword at the address in r2
			regRam[r1] = ram[regRam[r2]];
			break;
		case 5:
			//	  load reg r with contents of memory loc n; indexed

			regRam[r1] = ram[r2];

			break;
		case 6:
			regRam[r1] = r2;
			break;
		case 7:
			//	store reg r at loc n
			ram[r2] = regRam[r1];
			break;
		case 8:
			//store the contents of r1 at the address in r2
			regRam[r2] = regRam[r1];
			break;
		case 9:
			//	 store reg r at loc n; indexed
			ram[r2 + regRam[29]] = regRam[r1];
			break;
		case 10:
			//add contents of loc n to reg r
			regRam[r1] += ram[r2];
			break;
		case 11:
			//add contents of reg r2 to reg r1
			regRam[r1] += regRam[r2];
			break;
		case 12:
			//subtract contents of loc n from reg r
			regRam[r1] -= regRam[r2];
			break;
		case 13:
			//subtract contents of reg r2 from reg r1
			regRam[r1] -= regRam[r2];
			break;
		case 14:
			if (regRam[r1] < ram[r2])
				regRam[30] = -1;
			else if (regRam[r1] > ram[r2])
				regRam[30] = 1;
			else
				regRam[30] = 0;

			break;
		case 15:
			// CMPR r1,r2
			//compare reg r1 to contents of reg r2 and set CC
			if (regRam[r1] < regRam[r2])
				regRam[30] = -1;
			else if (regRam[r1] > regRam[r2])
				regRam[30] = 1;
			else
				regRam[30] = 0;

			break;

		case 16:

			for (int i = 0; i < regRam[r2 + 2]; i++){
				ram[regRam[r2] + i] = ram[regRam[r2 + 1] + i];
			}

			break;

		case 17:
			regRam[31] = r2;
			break;
		case 18:
			regRam[31] = regRam[r2];
			break;
		case 19:
			if (regRam[30] == 0)
				regRam[31] = r2;
			break;
		case 20:
			if (regRam[30] == 0)
				regRam[31] = r2;
			break;
		case 21:
			if (regRam[30] != 0)
				regRam[31] = r2;
			break;
		case 22:
			if (regRam[30] != 0)
				regRam[31] = regRam[r2];
			break;
		case 23:
			if (regRam[30] == -1)
				regRam[31] = r2;
			break;
		case 24:
			if (regRam[30] == -1)
				regRam[31] = regRam[r2];
			break;
		case 25:
			if (regRam[30] == 1)
				regRam[31] = r2;
			break;
		case 26:
			if (regRam[30] == 1)
				regRam[31] = regRam[r2];
			break;
		case 27:
			if (regRam[30] == 0 || regRam[30] == -1)
				regRam[31] = r2;
			break;
		case 28:
			if (regRam[30] == 0 || regRam[30] == -1)
				regRam[31] = regRam[r2];
			break;
		case 29:
			if (regRam[30] == 0 || regRam[30] == 1)
				regRam[31] == r2;
			break;
		case 30:
			if (regRam[30] == 0 || regRam[30] == 1)
				regRam[31] = regRam[r2];
			break;
		case 31:
			regRam[r1] = regRam[31];
			regRam[31] = r2;
			break;
		case 32:
			regRam[r1] = regRam[31];
			regRam[31] = regRam[r2];
			break;
		case 33:
			//end
			return 0;
			break;
		case 34:
			for (int i = 0; i <= (r2 - r2); i++)
			{
				if (i % 8 == 0 && i != 0)
					cout << endl;
				cout << regRam[r1 + i] << "\t";
			}
			cout << endl;

			break;
		case 35:

			for (int i = 0; i <r1; i++){
				if (i % 8 == 0 && i != 0)
					cout << endl;
				cout << ram[r2 + i] << "\t";
			}

			cout << endl;

			break;
		default:

			break;

		}

	}
	/////////////////////////////////////////////////////////////////


	///system("pause");
	return 0;
}
string foundString(int& found){

	string fileIn;
	string line1, line2, line3;
	vector<string>column1;
	vector<string>column2;
	vector<string>column3;

	ifstream inFile("opcodes.h", ios::in);
	if (!inFile){
		cout << "File not found." << endl;
		exit(1);
	}
	while (!inFile.eof()){
		getline(inFile, fileIn);
		istringstream iss(fileIn);
		iss >> line1 >> line2 >> line3;
		column1.push_back(line1);
		column2.push_back(line2);
		column3.push_back(line3);

	}


	for (int i = 0; i < column3.size(); i++){
		int INcolumn3 = atoi(column3.at(i).c_str());
		if (INcolumn3 == found){

			return column2.at(i);

		}


	}
}
