/* 
file Name:quicksort.cpp
Author:  Mena Sergeyous
Description : gets the implementation from quicksort.h.
Date: 11/9/2015
*/



#include"quicksort.h"
#include"timer.h"
#include<time.h>


void quicksort(int array[], int size){
	clock_t begin, end;
	begin=clock();
	// call function that take more argument 
	quick_sort(array, 0, size-1);
	end=clock();
	printTime(end, begin);
}

void quick_sort( int array[], int left , int right){
	
	// variable use for loop control 
	int i=left;
	int j=right;
	int temp; // use for swaping  
	// hold the pivot point of the array
	int pivot= array[(left+right)/2];
	while(i<=j){
		while(array[i]<pivot)
			i++;
		while(array[j]> pivot)
			j--;
		if(i<=j){
			temp=array[i];
			array[i]=array[j];
			array[j]=temp;
			i++;
			j--;
		}
	}
	//check to seee if need to keep sorting 
	if(left<j)
	// call the function again with new value
	quick_sort(array,left,j);
	if(i<right)
    // do the right side
	quick_sort(array,i,right);

	

}