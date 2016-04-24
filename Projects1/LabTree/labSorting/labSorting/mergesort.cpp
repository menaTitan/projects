/* 
file Name:mergesort.cpp
Author:  Mena Sergeyous
Description : gets the implementation from mergsort.h.
Date: 11/9/2015
*/


#include<time.h>
#include"timer.h"

void merge(int array[], int size, int low, int middle, int high) {
	//create temp array to hold the value
	int *temp;
	temp = new int[size];
	for (int i = low; i <= high; ++i) {
		temp[i] = array[i];
	}
	int i = low;
	int j = middle + 1;
	int k = low;
	// if the value in the temp array is less than j value the place that value in the perment array
	while (i <= middle && j <= high) {
		if (temp[i] <= temp[j]) {
			array[k] = temp[i];
			++i;
		}
		else {
			// take the j value and put it perment array
			array[k] = temp[j];
			++j;
		}
		++k;
	}
	while (i <= middle) {
		//perment array value equal at the temporay array
		array[k] = temp[i];
		++k;
		++i;
	}
	// clean up memory
	delete[] temp;
}

void merge_sort(int array[], int size, int low, int high) {
	// check if low less than high
	if (low < high) {
		// find the middle value
		int middle = (low + high) / 2;
		//call merge_sort on the lower half of the array
		merge_sort(array, size, low, middle);
		//call merge_sort on the upper half of the array
		merge_sort(array, size, middle + 1, high);
		//marge it all together
		merge(array, size, low, middle, high);
	}
}
void mergesort(int array[], int size){
	clock_t begin, end;
	begin=clock();
	// call function that take more argument.
	merge_sort(array,size,0, size-1);
	end=clock();
	printTime(end,begin);
}