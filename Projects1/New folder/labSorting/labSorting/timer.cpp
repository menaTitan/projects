/* 
file Name:timer.cpp
Author: Mena Sergeyous
Description : gets the implementation from timer.h and calculate time  for each soring alogrthm and print the time.
Date: 11/9/2015
*/

#include"timer.h"
#include<time.h>
#include<iomanip>
#include<iostream>
using namespace std;
// function that calculate time 
double diffClocks(clock_t clock1, clock_t clock2){
    double diffticks = clock1 - clock2;
    double diffsecs = diffticks / CLOCKS_PER_SEC;
    return diffsecs;
}
// print out the time by calling diffClocks
void printTime( clock_t end, clock_t begin){
	cout << "\t" << std::setprecision(5) <<  diffClocks( end, begin);
}