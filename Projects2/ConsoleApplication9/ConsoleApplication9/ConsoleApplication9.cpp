// ConsoleApplication9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


class Employee{
protected :
	string name;
	double pay;
public :
	Employee(){
		name = "";
		pay = 0;
	}
	Employee(string empName, double payRate){
		name = empName;
		pay = payRate;
	}
	~Employee(){

	}
	string getName(){
		return name;
	}
	void setName(string empName){
		name = empName;
	}
	double getPay(){
		return  pay;
	}
	void setPay(double payRate){
		pay = payRate;
	}
	string toString(){
		stringstream stm;
		stm << name << ": " << pay;
		return stm.str();
	}
	virtual  double grossPay(int hours){
		return pay * hours;
	}
};
// derived class 
class Manager: public Employee  {
private :
	bool salaried;

public :
	/*Manager(string name, double payRate, bool isSalaried)
		:Employee(name, payRate)
	{
		salaried = isSalaried;
	}*/
	
	// default constructor
	Manager() : salaried(true){}
	Manager(string name, double payRate, bool isSalaried)
		:Employee(name,payRate){

	}
	~Manager(){
		//free allocated resources
	}
	bool getSalaried(){
		return salaried;
	}
	virtual  double grossPay(int hours ){
		if (salaried){
			return pay;
		}
		else{
			return pay * hours;
		}
		
	}
	string toString(){
		stringstream stm;
		string salary;
		if (salaried){
			salary = " salaried";

		}
		else{
			salary = "hourly";

		}
		stm << name << ": " << pay << " :" << salary << endl;
		return stm.str();
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	
	
	
	
	Employee mp("Mena", 25.00);
	Manager	mg("mena", 1200, true);
	
	Employee *mpptr;
	Manager *mgpoter;
	mpptr = &mp;
	cout << "name :" << mpptr->getName() << endl;
	cout << "Pay :" << mpptr->grossPay(40) << endl;
	mpptr = &mg;
	cout << "name :" << mpptr->getName() << endl;
	cout << "pay :" << mpptr->grossPay(40) << endl;
	vector<Employee*>  vep;
	vep.push_back(&mp);
	vep.push_back(&mg);
	
	for (unsigned i = 0; i< vep.size(); i++){
		cout << " Name :" << vep[i]->getName() << endl;
		cout << " Pay : " << vep[i]->grossPay(40) << endl;
		
	
	}

	
	return 0;
}

