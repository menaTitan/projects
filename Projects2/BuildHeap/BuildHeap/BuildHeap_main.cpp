#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

//#include"mergesort.h"







void maxHeap(int array[], int parent, int last){
	//child =parent*2;
	int child = parent * 2;
	//goes until the last element in the heap
	while (child + 1 <= last)
	{
		//check if the child less then parent than we incrment child
		if (child + 1 <= last &&array[child + 1] > array[child]){
			child++;
		}
		//if the child greater than parent than we swap the elements 
		if (array[child] > array[parent]){
			swap(array[child], array[parent]);
			// than parent will= child
			parent = child;
			child = parent * 2;
		}
		else
		{
			break;
		}
	}
	return;
}
void buildHeap(int array[], int last){
	//last divid bt 2 beacuse the leave are good
	for (int i = last / 2; i >= 0; i--){
		// call maxHeap to sort the heap to MaxHeap
		maxHeap(array, i, last);
	}
}
int main(){

	int const ten= 4;
	int array[ten] = {12,1,13,14};
	/*
	int array[ten];
	srand(time(NULL));
	for (int i = 0; i < ten; i++){
	
		
		array[i]= rand() % 100;
	
	}
	*/
	buildHeap(array, ten);
	for (int i = 1; i < ten; i++){
	
		cout << array[i] << " ";
	
	}









	return 0;
}