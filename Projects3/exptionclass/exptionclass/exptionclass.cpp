// exptionclass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<stdexcept>
using namespace std;


double quotient(double numer, double denom) {
	
	if (denom == 0) {
		throw runtime_error(" Divide By Zero Expcetion");

	}
	else {
		return(numer / denom);
	}

	
}
int main()
{
	double number1, number2, ratio;
	cout << "Enter a numerator: ";
	cin >> number1;
	cout << "Enter a denominator: ";
	cin >> number2;
	try {
		ratio= quotient(number1, number2);
		cout << " Reuslt is: " << ratio << endl;
	}
	/*catch (runtime_error &error) {
		cout << "exception accurd " << endl;
		cout << error.what() << endl;
	}*/
	 // catch all errors 
	catch (...) {
		cout << " Exception  throrwn and caught " << endl;
	}

    return 0;
}

