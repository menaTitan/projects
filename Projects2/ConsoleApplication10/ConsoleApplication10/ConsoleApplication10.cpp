// ConsoleApplication10.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
using namespace std;
class Account {

protected :
	double  balance;
public:
	Account(double bal){
		if (bal > 0){
			balance = bal;

		}
		else {
			bal = 0.0;
		}
	}
	void credit(double amount){
		balance += amount;

	}
	void debit(double amount){
		if (balance > amount){
			balance -= amount;

		}
		else {
			cout << "Insufficient funds" << endl;

		}
	}
	double getBalance(){
		return balance;
	}

	
};
class CheckingAccount :public Account{
private:
	double fee;
public:
	CheckingAccount(double bal, double f) : Account(bal){
		fee = f;
	}
	void debit(double amount){
		if (balance > amount){
			balance = balance - amount - fee;
		

		}
		else{
			cout << "Insufficient funds" << endl;
		}
	}






};


int _tmain(int argc, _TCHAR* argv[])
{
	CheckingAccount myAccount(500, .5);
	myAccount.credit(100);
	cout << myAccount.getBalance() << endl;
	myAccount.debit(50);
	cout << myAccount.getBalance() << endl;


	return 0;
}

