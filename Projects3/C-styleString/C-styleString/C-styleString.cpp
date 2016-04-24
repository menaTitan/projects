// C-styleString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <cstring>
#include<string>

using namespace std;

int main()

{
	char  oldSchoolString[] = "low overhead";
		// Declare a C-style string name oldSchoolString and initalize it to "low overhead".
	cout << sizeof(oldSchoolString) << endl;
		std::cout << "There are " << strlen(oldSchoolString) << " characters in \"" << oldSchoolString << "\"\n";

		
	
    return 0;
}

