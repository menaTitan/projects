// usingnamespce.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string>
#include<iostream>
int& change( ) {
	int x = 5;

	
	return x;

}

void count( int& num)
{
	num *= 2;


}

void print(std::string name) {
	std::cout << name;
}
int main()

{
	std::string name;

	name = "mena";
	print(name);

	int x = 5;
	int&T = x;
	std::cout << T << std::endl;

	int num = 3;
	count(num);
	std::cout << num << "  ";

    return 0;
}

