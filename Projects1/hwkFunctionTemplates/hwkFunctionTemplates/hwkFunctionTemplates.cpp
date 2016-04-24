/*
Name: Mena Sergeyous
Date: 9/14/2015


*/



#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// Put add() function template here
template<typename T1, typename T2>
T1 add(T1 a ,T2 b){

	return(a+b);

}

int main(){
    int answer = 42;
    float pi = 3.14159;
    string str1("Yeah, my templated function ");
    string str2("works!");

    // Put a cout statement here that has a call to add(), where add() is passed "answer" and "pi"
       cout<< add<int,float>(answer,pi)<<endl;
    // Put a cout statement here that has a call to add(), where add() is passed "str1" and "st2"
       cout<< add<string,string>(str1,str2)<<endl;
    return 0;
}