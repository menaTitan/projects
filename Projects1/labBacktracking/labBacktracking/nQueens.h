/*
Name: Mena Sergeyous
Date: 12/6/2015
purpose: provide implementation for n Queens.cpp
*/

#ifndef NQUEENS_H
#define NQUEENS_H
#include<iostream>
#include<string>
using std::string;

bool ChecksBoard(int **chessBoard, int row, int column, int size);
bool chessBoardSolver(int **chessBoard, int column,int size);
void printNQueensSolution(int N, string FileName);

#endif 
