/* 
file Name:heapsort
Author: Mena Sergeyous
Description: gets the implementation from heapsort.h.
Date: 11/9/2015
*/
/* 
file Name:heapsort.cpp
Author:  Mena Sergeyous
Description : gets the implementation from heapsort.h.
Date: 11/9/2015
*/
#include"heapsort.h"
#include"timer.h"
#include<iostream>
#include<time.h>
using namespace std;


void maxHeap(int array[], int parent, int last){
	//child =parent*2;
	int child = parent * 2;
	//goes until the last element in the heap
	while (child+1<=last)
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
	for (int i = last / 2; i >=0; i--){
		// call maxHeap to sort the heap to MaxHeap
		maxHeap(array, i, last);
	}
}

void heapsort(int array[], int size)
{  
	clock_t begin, end;
	begin=clock();
	/*This will put max element in the index 0*/
	buildHeap(array,size-1);
	while (size-1 > 0)
	{
		//put the biger element to the last of the array
		swap(array[0], array[size-1]);
		--size;
		//ensure heap property on remaining elements
		maxHeap(array, 0 ,size-1);
	}
	end=clock();
	printTime(end,begin);

}


