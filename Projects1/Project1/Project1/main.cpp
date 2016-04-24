// project.cpp : Defines the entry point for the console application.
//

#include "slp.h"

#include "prog.h"

using namespace std;

int main( void )
{
	SymbolTable		symbols;

	cout <<  "Program prog1 produce the following output:" << endl;
    prog1.interp(symbols);
	cout << endl;

	symbols.clear();
	cout <<  "Program prog2 produce the following output:" << endl;
    prog2.interp(symbols);
	cout << endl;

	symbols.clear();
	cout <<  "Program prog3 produce the following output:" << endl;
    prog3.interp(symbols);
	cout << endl;

	symbols.clear();
	cout <<  "Program prog4 produce the following output:" << endl;
    prog4.interp(symbols);

	return 0;
}

