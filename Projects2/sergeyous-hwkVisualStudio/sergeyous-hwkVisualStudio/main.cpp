// Author: Hyrum Carroll
#include <iostream>
#include <string>
#include "data.h"
#include<string>
using namespace std;
int assignPicture(int*h){

	return *h;
}


double Amount(int&num){
	 
	
	return(num = 14);
}
int main(){
	DateClass today;  // Use "DateClass today{ }" with a C++11 compliant compiler
	cout << "Hello\n";
	today.readDate();
	today.printDate();

	DateClass *h = new DateClass;
	h->printDate();
	h = new DateClass;
	
	double rainfall[7];
	double tickerValues[12][31];
	double *ptr = new double[10];
	string**carMakes;
	carMakes = new string*[6];
	for (int row = 0; row < 6; row++)
		carMakes[row] = new string[20];

	int number = 7;
	int * nu;
	nu = &number;
	cout << "assignPicture()" << assignPicture(nu) << endl;
	
	int num = 7;
	Amount(num);
	cout << num << endl;
	return 0;
}