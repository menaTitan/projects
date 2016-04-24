/* 
file Name:mergesort.cpp
Author:  Mena Sergeyous
Description : gets the implementation from mergsort.h.
Date: 11/9/2015
*/
#include"insertionSort.h"
#include<time.h>
#include<iostream>
#include<iomanip>
#include"timer.h"



void insertionSort(int array[], int size){
	clock_t begin, end;
	begin= clock();
	int j, temp;

	// go through the array except the first element becase is sotted portion
	for (int i = 0; i < size; i++){

		j = i;//represnts the index into the unsorted portion 
		// going through the sorted portion from right to left
		//stop iterating once the element to the left is less than the element we are trying to insert
		while (j > 0 && array[j] < array[j-1]){
			// keep track of our current place in the unsoted portion
			temp = array[j];
			//shifting each element we encounter one space to the right
			array[j] = array[j-1];
			array[j-1] = temp;
			// updating out counter to continue to move left through the sorted portion
			j--;
		}
	}
	end=clock();
	printTime(end,begin);
}