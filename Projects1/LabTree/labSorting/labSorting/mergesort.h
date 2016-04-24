/* 
file Name: mergesort.h
Author:  Mena Sergeyous
Description : it provide implementation for mergesort.cpp
Date: 11/9/2015
*/


#ifndef MERGESORT_H
#define MERGESORT_H

void mergesort(int array[], int size);
void merge_sort(int array[], int size, int low, int high);
void merge(int array[], int size, int low, int middle, int high);
#endif