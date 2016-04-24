/* 
file Name:bubbleSort.cpp
Author:  Mena Sergeyous
Description : gets the implementation from bubbleSort.h.
Date: 11/9/2015
*/

#include"bubbleSort.h"
#include"timer.h"
#include<time.h>

void bubbleSort(int array[], int size){
	clock_t begin , end;
	begin=clock();
	// go through the number
	for(int i=0;i<size;i++){
		// for loop to compaire numbers
		for(int j=0;j< size-1;j++){
			// swap if the number if is biger then the next number
			if(array[j]>array[j+1]){
				int swap=array[j];
				array[j]=array[j+1];
				array[j+1]=swap;
			}
		}
	}
	end=clock();
	printTime(end, begin);

} 