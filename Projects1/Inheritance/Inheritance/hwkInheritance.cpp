/*
 Name: Mena Sergeyous
  Question 1) Why do we use inheritance?
  Answer:  1)
    we can reuse code from the base classes
   u 
  Question 2) Can a protected method in a derived class access a private data member in the base class? If not, name two changes that could be made to the base class to give the derived class access to the variable (without making the data member public).
  Answer:  2)
  derived class  can not access private data member in base class. to access data from base class need to be protected.
  another way to access data from the base class by using  friend to access private data from the base class.
*/

#include <iostream>
using std::cout;
using std::endl;
const double INTEREST_RATE = 1.2;
class Account{
protected:
	double balance;


public :
	double getBalance(){ return balance;}
	

	void deposit( double add){balance+=add;}
	
	double getInterestRate(){return INTEREST_RATE;}
	
	void withdraw(double min){ balance-=min;}

	void processCheck(double a , int checkNumber){balance-=a;}
	
                         
};


class SavingsAccount : public Account{
public:
	SavingsAccount( double bal, double INTEREST_RATE){
	
		balance=bal;
	}



};
class CheckingAccount :public  Account {
public:
	CheckingAccount( double ba){
		
		balance= ba;
	
		}
};



int main(){
    SavingsAccount firstHome( 1234.56, INTEREST_RATE);
    CheckingAccount gasMoney( 78.90);

    firstHome.deposit( 987.65);
    gasMoney.deposit( 12.34);

    firstHome.withdraw( 2000.00);
    int checkNumber = 234;
    gasMoney.processCheck( 55.55, checkNumber);

    cout << "Savings has $" << firstHome.getBalance() << " and is accruing interest at " << firstHome.getInterestRate() << "%" << endl;
    cout << "Checking has $" << gasMoney.getBalance() << endl;

    return 0;
}
    