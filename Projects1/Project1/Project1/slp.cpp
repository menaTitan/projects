#include <algorithm>
#include "slp.h"
/*
    PROGRAMMER:	    Mena Sergeyous

	PROGRAM #:		to  implement  slp.cp and to write interpeter to  interpeate  a program and display  the result.

	DUE DATE		Tuesday/2/2016

	INSTRUCTOR:   	Dr. Zhijiang Dong



*/

using namespace std;

/* To be implemented by stduents */
void CompoundStm::interp( SymbolTable& symbols )
{
	stm1->interp(symbols);
	stm2->interp(symbols);

}

/* To be implemented by stduents */
void AssignStm::interp( SymbolTable& symbols )
{

	int x;
	x=exp->interp(symbols);
	symbols[id]=x;
}

void PrintStm::interp( SymbolTable& symbols )
{
	
	exps->interp(symbols);
}

int IdExp::interp( SymbolTable& symbols )
{
	return symbols.at(id);
}

int NumExp::interp( SymbolTable& symbols )
{
	return num;
}


int OpExp::interp( SymbolTable& symbols )
{
	switch (oper)
	{
	case OpExp::PLUS:

		return (left->interp(symbols) + right->interp(symbols));
		break;
	case OpExp::MINUS:
		return (left->interp(symbols) - right->interp(symbols)); 
		break;
	case OpExp::TIMES:
		return (left->interp(symbols) * right->interp(symbols));
		break;
	case OpExp::DIV:
		return (left->interp(symbols) / right->interp(symbols));
		break;
	default:
		break;
	}

}



int EseqExp::interp( SymbolTable& symbols )
{
	stm->interp(symbols);
	return exp->interp(symbols);
}


void PairExpList::interp( SymbolTable& symbols)
{
	cout<< head->interp(symbols) <<" " ; 
	tail->interp(symbols);
}


int PairExpList::size() const
{
	return 2;
}


void LastExpList::interp( SymbolTable& symbols)
{
	cout<<head->interp(symbols)<<endl;
}


int LastExpList::size() const
{
	return 1;

}

