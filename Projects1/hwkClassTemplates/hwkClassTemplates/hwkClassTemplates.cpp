/*
Name: Mena Sergeyous
Date: 9/14/2015
FileName:hwkClassTemplates
*/
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// Put templated Calculator class here
template<typename T1 , typename T2>

class Calculator{
private:
	T1 a;
	T2 b;
public:
	// constructor
	Calculator(T1 a ,T2 b);
	// copy constructor
     Calculator(const Calculator <T1,T2>&rhs);
	 //setter 
	 void setValue1(T1 a1){a=a1;}
	 void setValue2(T2 b1){b=b1;}
	 // add function 
	 T1 add(){ return (a+b);}
     //  mutilay function
	 T1 multiply(){return (a*b);}


};
// implanation for constrouctor
template<typename T1 , typename T2>
Calculator<T1,T2>:: Calculator(T1 a1, T2 b1){
    this->a=a1;
	this->b=b1;

}

 // copy constructor implantation
 template<typename T1 , typename T2>
 Calculator<T1,T2>:: Calculator (const  Calculator <T1 ,T2 >&rhs)
	
 {
    a=rhs.a;
	b=rhs.b;

 
 }

int main(){
	
    Calculator<int,int> simpleCalc(42, 3);
    cout << "Adding: " << simpleCalc.add() << endl;
    cout << "Multiplying: " << simpleCalc.multiply() << endl;
    simpleCalc.setValue1( 7);
    cout << endl;
    
    Calculator<int,int> copyCalc( simpleCalc);
    cout << "Adding: " << simpleCalc.add() << endl;
    cout << "Multiplying: " << simpleCalc.multiply() << endl;
    cout << endl;
    
    Calculator<float,double> realCalc(1.41421, 2.718281828459045);
    cout << "Adding: " << realCalc.add() << endl;
    cout << "Multiplying: " << realCalc.multiply() << endl;
    cout << endl;
	
    return 0;
}