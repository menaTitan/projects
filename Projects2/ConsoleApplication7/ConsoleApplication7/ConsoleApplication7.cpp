// ConsoleApplication7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


// write a menu drive c++ to perform multiple operation.
//christen Sergeyous 
// December 9, 2010
// DR. Ling Hong.
// ENGR 2230 Project.


//required for the cout.
#include <iostream>
//required for math operation.
#include < cmath>
//required for setprecision(), fixed, setw().
#include <iomanip>
//required for srand(), rand().
#include <cstdlib> 
// Required for srand().
#include <ctime>

using namespace std;

// functions prototypes.
//function header defines the type of the value that is returned by the function,
//the function name and the parameter list.
void TempConversion(double, int);
double SalaryCalculator(double);
void hollowSquare(int);
double estimatePi(int);
void Lottery(int);
void Exit();

//The main function starts.
//The operating system begins execution with the block of statement defined in main ().
int main()
{

	//declare and initialize objects.
	double  the_gross_sale, temperature_in_celsius;
	int size, number_of_operation, number_of_term, number_of_drawings, increment;

	//set number of opration to zero.
	number_of_operation = 0;

	//prompot the user to enter the number of operation in order.
	cout << "          % This is a menu driven c++ program to perform multiple operation %" << endl;
	cout << "      **************************************************************************" << endl;
	cout << endl;
	cout << endl;
	cout << " These operation are in order as the fellowing" << endl;
	cout << " please enter the number of operation you want to select " << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	//using while loop so the user can perform another operation. 
	while (number_of_operation != 6)
	{
		cout << setw(24) << left << " to perform another operation please select number of operation from the main manu" << endl;
		cout << setw(24) << left << "otherwise select operation number six to exit the program" << endl;
		cout << "\n";
		cout << "\n";
		cout << setw(24) << left << "1. Temperature Conversion" << endl;
		cout << setw(24) << left << "2. Salary Calculator" << endl;
		cout << setw(24) << left << "3. Print a Hollow Square" << endl;
		cout << setw(24) << left << "4. Estimate the Value of PI" << endl;
		cout << setw(24) << left << "5. Lottery Drawing" << endl;
		cout << setw(24) << left << "6. Exit" << endl;
		cout << endl;
		cout << endl;

		//ask the user to enter the number of operation.
		cin >> number_of_operation;
		cout << endl;

		// using switch selection.
		switch (number_of_operation)
		{
			// case one starts; the Temperature Conversion form celsius to fahrenheit.
		case 1:
			cout << "           1. Temperature Conversion" << endl;
			cout << "       =======================================" << endl;

			cout << endl;
			cout << endl;

			//prompt the user to enter the starting temperature.
			cout << "please enter temperaturem in Celsius" << endl;

			//ask the user to input temperature_in_celsius.
			cin >> temperature_in_celsius;
			cout << "\n";

			//prompt the user to enter the increment.
			cout << "please enter the increment" << endl;

			//ask user to input the increment.
			cin >> increment;
			cout << "\n";

			//Title the table.
			cout << "temperature_in_celsius      temperature_in_farhrenheit" << endl;
			//call the TempConversion fuction.
			TempConversion(temperature_in_celsius, increment);
			cout << "\n";

			// case one ends.
			break;

			// case two starts the Salary Calculator.
		case 2:
			cout << "            2. Salary Calculator" << endl;
			cout << "         *****************************" << endl;
			cout << endl;
			cout << endl;

			//prompot the user to enter the money worth of chemicals .
			cout << "please enter the gross sale of one person" << endl;

			//ask the user to input the sale price.
			cin >> the_gross_sale;

			//print the salary and call the function SalaryCalculator.
			cout << "saleperson_earning is:" << SalaryCalculator(the_gross_sale) << endl;
			cout << "\n";
			//case two ends.
			break;

			//case three starts printing a Hollow Square.
		case 3:
			cout << "         3. Print a Hollow Square" << endl;
			cout << "      +++++++++++++++++++++++++++++++" << endl;
			cout << endl;
			cout << endl;

			// prompt the user to enter the size  of the square.
			cout << "please enter the size of the square" << endl;

			//ask the user to input the size of the square.
			cin >> size;

			//call for function.
			hollowSquare(size);
			cout << "\n";
			//case three ends.
			break;

			// case four starts Estimate the value of PI.
		case 4:
			cout << "           4. Estimate the Value of PI" << endl;
			cout << "       ------------------------------------" << endl;
			cout << endl;
			cout << endl;

			//prompt user to enter number of terms.
			cout << "please enter the number of terms" << endl;

			//ask the user to input the number of term.
			cin >> number_of_term;

			//call the function.
			cout << "pI=" << estimatePi(number_of_term);
			cout << endl;
			// case four ends.
			break;

			//case five starts The lottery drawing.
		case 5:
			cout << "       5. Lottery drawing" << endl;
			cout << "    ########################" << endl;
			cout << endl;
			cout << endl;

			// Prompt the user to enter number of drawings.
			cout << "Please enter the number of drawings:" << endl;

			//ask the user to input the number of drawings.
			cin >> number_of_drawings;

			// call the function.
			Lottery(number_of_drawings);
			cout << "\n";
			//case five ends.
			break;
			//case six starts the exit.
		case 6:
			cout << "       6. Exit" << endl;
			cout << "    !!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "\n";

			//call the Exit function.
			Exit();
			//case six ends.
			break;

		case '\t':
		case '\n':
		case ' ':

		default:
			cout << "you have enter the valid number" << endl;
			break;
		}

	}
	//exit program.
	return 0;
}
/****************************************************************/
//Function TempConversion Definition
void TempConversion(double temperature_in_celsius, int increment)
{
	// declare and initialize objects.
	double temperature_in_fahrenheit;

	// using for loop.
	for (int counter = 1; counter <= 20; counter++)
	{
		// compute value of temperature in Fahrenheit and temperature in celsius.
		temperature_in_fahrenheit = 1.8 * temperature_in_celsius + 32;

		cout << fixed << setw(28) << setprecision(3) << temperature_in_celsius
			<< setw(40) << setprecision(3) << temperature_in_fahrenheit << endl;

		temperature_in_celsius = temperature_in_celsius + increment;
	}
	// exit program.
	return;
}

/*************************************************************************************/

//Function SalaryCalculator Definition.

double SalaryCalculator(double the_gross_sale)
{
	//declare and initialize objects.
	double saleperson_earning;

	// compute the value of the salesperson earning and send the result to the main function.

	saleperson_earning = 200 + the_gross_sale * 0.09;
	cout << "\n";

	//exit program.
	return  saleperson_earning;
}


/************************************************************************************/
//Function hollowSquare Definition.
void hollowSquare(int size)

{
	// using for loop.
	for (int line = 1; line <= size; line++)
	{

		//using if selection. 
		if (line == 1 || line == size)
		{
			//using for loop.
			for (int colum = 1; colum <= size; colum++)
			{
				cout << "*";
			}

			cout << endl;
		}
		else
		{
			//using for loop.
			for (int colum = 1; colum <= size; colum++)
			{
				//using if selection.
				if (colum == 1 || colum == size)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}

			cout << endl;
			cout << "\n";

		}
	}
}
/*********************************************************************************/

//Function estimatePi Definition.
double estimatePi(int number_of_term)
{
	// Declare and initialize objects
	double bottom_number, pie, sum, sign;

	//set dottom number to three.
	bottom_number = 3;
	//set pie to zero
	pie = 0;
	//set sum to 4.
	sum = 4;
	//set sign to negative number.
	sign = -1;

	//using if selection.
	if (number_of_term == 1)
		sum = 4;

	else if (number_of_term < 0)
		return 0;

	else
	{
		pie = (4 / bottom_number);

		//using for loop.
		for (int i = 2; i <= number_of_term; i++)
		{
			// compute the result and send the result to main function.
			sum = sum + (sign * pie);
			bottom_number = bottom_number + 2;
			pie = 4 / bottom_number;
			sign = sign * -1;
		}
	}
	//exit program.
	return sum;
}


/***********************************************************************************/
//Function lottery Definition.
void Lottery(int number_of_drawings)
{
	// Declare and initialize objects.
	double even_percentage;
	int number_of_drawings_1, number_of_drawings_2, number_of_drawings_3, counter,
		counter_number_7, even_counter;
	//set counter to zero.
	counter = 0;
	//set evencounter to zero.
	even_counter = 0;
	//set counter number 7 to zero.
	counter_number_7 = 0;

	//using current time.
	srand((unsigned)time(0));

	//using for loop.
	for (int i = 1; i <= number_of_drawings; i++)
	{
		// compute the value of number of drawings.
		number_of_drawings_1 = (rand() % 10) + 1;
		number_of_drawings_2 = (rand() % 10) + 1;
		number_of_drawings_3 = (rand() % 10) + 1;
		//using if selection.

		if (number_of_drawings_1 == 7 || number_of_drawings_2 == 7 || number_of_drawings_3 == 7)
			counter_number_7++;

		if (number_of_drawings_1 % 2 == 0 && number_of_drawings_2 % 2 == 0 && number_of_drawings_3 % 2 == 0)
			even_counter++;
	}
	// print the result.
	even_percentage = (double)even_counter / number_of_drawings;
	cout << "the percentage of the time drawings contain the even numbers in  this simulation is: "
		<< even_percentage * 100 << " %" << endl;
	cout << '\n';
	cout << "the time 7 occurs in these three numbers in the simulation " << counter_number_7
		<< " " << "times" << endl;
	cout << endl;
	//exit program.
	return;

}

/**********************************************************/
//Function Exit Definition.
void Exit()
{
	cout << "end of the operation" << endl;
	cout << '\n';
	//exit program.
	return;
}


