/* 
file Name:timer.h
Author:  Mena Sergeyous
Description : it calculate time  for each soring alogrthm and print the time.
Date: 11/9/2015
*/


#ifndef TIMER_H
#define TIMER_H
#include<time.h>
#include<iomanip>
double diffClocks(clock_t clock1, clock_t clock2);
void printTime(clock_t end, clock_t begin);
#endif