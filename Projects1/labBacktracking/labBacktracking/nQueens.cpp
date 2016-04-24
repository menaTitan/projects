/*
Name: Mena Sergeyous
Date: 12/7/2015
purpose: to implement backtracking algorithm to solve N Queen problem
*/

#include<iostream>
#include<fstream>
#include<string>
#include"nQueens.h"
using namespace std;


bool ChecksBoard(int **chessBoard, int row, int column, int size) {
	int i, j;
	//checks the raws and left
	for (i = 0; i < column; i++) {
		if (chessBoard[row][i] == 1)
			return false;
	}
	//checks Diagonally and top left
	for (i = row, j = column; i >= 0 && j >= 0; i--, j--) {
		if (chessBoard[i][j] == 1)
			return false;
	}
	//checks Diagonaly and bottom left
	for (i = row, j = column; j >= 0 && i < size; i++, j--) {
		if (chessBoard[i][j] == 1)
			return false;
	}
	return true;
}
bool chessBoardSolver(int **chessBoard, int column,int size) {
	// checks if the columns gerater than the number of Queen
	//Base Case
	if (column >= size)
		return true;
	//traverse  the rows  
	for (int i = 0; i < size; i++) {
		// start from 0 colums 0
		// if there no queen attaking each other the assign one to the spost.
		if (ChecksBoard(chessBoard, i, column,size)) {
			chessBoard[i][column] = 1;
			//move to the next column
			//recursive call
			if (chessBoardSolver(chessBoard, column + 1,size))
				return true;
			/*** BACKTRACKING HERE ***/
			chessBoard[i][column] = 0;
		}
	}
	return false;
}

void printNQueensSolution(int N, string FileName){
	// creating ofstream object to write to a file 
	ofstream writeFile;
	//open a file
	writeFile.open(FileName);
	// creating dynamic array 
	int **chessBoard;
	//initializingthe number of raw
	chessBoard=new int *[N];
	//initializing the number of columns
	for(int i=0;i<N;++i){
		chessBoard[i]=new int [N];
	}
	//checks if the solution possible  if possible print the board  else print no solution
	if (!chessBoardSolver(chessBoard, 0,N)) {
		cout<<"No solution possible for " << N <<" queens!"<<endl;
		writeFile<<"No solution possible for " << N <<" queens!"<<endl;
	}
	else{
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(chessBoard[i][j]==1){
					//output to the console 
					cout<< "Q  ";
					// write to the file 
					writeFile<<"Q  ";
				}
				else{
					//output to the console
					cout<<"_  ";
					// write to the file
					writeFile<<"_  ";
				}
			}
			cout<<endl;
			writeFile<<endl;
		}
	}
	// closefile
	writeFile.close();
	//clean memory  
	for(int i=0;i<N;i++){
		delete[]chessBoard[i];
	}
	delete[]chessBoard;
}