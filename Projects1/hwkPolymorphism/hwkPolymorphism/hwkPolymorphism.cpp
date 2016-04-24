//Mena Sergeyous.
/* Four essential ingredients for having a polymorphic method call:
 * 1) Inheritance 
 * 2) Virtual mehtod (base class)
 * 3) Virtual method overidden in derived class
 * 4) pointer or refernce of the base class type, but pointing to/referencing the
 derived class.
*/


#include <iostream>
using std::cout;
using std::endl;
const double SAVINGS_INTEREST_RATE = 1.2;
const double CD_INTEREST_RATE = 2.5;
const int NUM_BANK_ACCOUNTS = 3;
// Add class declarations and implementations HERE
class  Account{

protected:
 double balance;

public:
	
	Account(){balance=0;}
	double getBalance(){ return balance;}
	void setBalance(double a){balance=a;}
    void deposit(double ba){balance+=ba;}
     
	virtual void printInfo(){}//Virtual mehtod (base class)

    void  withdraw(double bal){balance-=bal;}
};
class SavingsAccount:public Account/*inheritance*/{

public:
	SavingsAccount(double bal ,double SAVINGS_INTEREST_RATE){balance=bal;}
	//Virtual method overidden in derived class
	void printInfo(){
	cout<<"Savings Account Information:"<<endl;
	cout<<"   Balance: $"<<getBalance()<<endl; 
	cout<<"   Interest rate: "<<  SAVINGS_INTEREST_RATE <<"%"<<endl;
	}


};
class  CheckingAccount:public Account/*inheritance*/{
protected:
	int check;
public:
	CheckingAccount(double bal){balance=bal;}
	void processCheck(double bal , int checkNumber){balance-=bal; check=checkNumber; }
	//Virtual method overidden in derived class
	void printInfo(){
	cout<<"Checking Account Information:"<<endl;
	cout<<"   Balance: $"<<getBalance()<<endl; 
	cout<<"   Last check number processed "<< check  <<endl;
	}
};
class CDAccount:public Account /*inheritance*/{
protected:
	double Cd;
	int m;
public:
	CDAccount(double bal, double  CD_INTEREST_RATE, int num){balance=bal; Cd=CD_INTEREST_RATE;m=num;}
	//Virtual method overidden in derived class
	void printInfo(){
	cout<<"CD Account Information"<<endl;
	cout<<"   Balance: $"<<getBalance()<<endl; 
	cout<<"   Interest rate: "<< Cd  <<"%"<<endl;
	cout<<"   Maturity: "<< m <<" months"<<endl;
	}
};


int main(){
    SavingsAccount firstHome( 1234.56, SAVINGS_INTEREST_RATE);
    CheckingAccount gasMoney( 78.90);
    CDAccount tuition( 5000.00, CD_INTEREST_RATE, 6);
    Account* bankAccounts[ NUM_BANK_ACCOUNTS ]; // array of 3 Account pointers

    firstHome.deposit( 987.65);
    gasMoney.deposit( 12.34);

    firstHome.withdraw( 2000.00);
    int checkNumber = 234;
    gasMoney.processCheck( 55.55, checkNumber);
    //pointer or refernce of the base class type, but pointing to/referencing the derived class.
    bankAccounts[0] = &firstHome;
    bankAccounts[1] = &gasMoney;
    bankAccounts[2] = &tuition;

    bankAccounts[1]->deposit( 20.00);
    bankAccounts[1]->withdraw( 50.00);

    for( int i = 0; i < NUM_BANK_ACCOUNTS; i++){
        cout << "(Bank account index " << i << ")\n";
        bankAccounts[i]->printInfo();
        cout << endl;
    }
    return 0;
}
    