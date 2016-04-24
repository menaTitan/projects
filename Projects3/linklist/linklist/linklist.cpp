// linklist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"list.h"

int main()
{

	unsotredType name;

	name.InsertItem(100);
	name.InsertItem(20);
	name.InsertItem(20);
	name.DeleteItem(20);
	name.show();
    return 0;
}

