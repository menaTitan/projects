/*
Name: Mena Sergeyous
Date: 9/30/2015
*/
#include<iostream>
#include<vector>
using namespace std;

int recursiveFunctionA(int x, int y) {
    if (x == 0 || y == 0)
        return 0;
    else
		cerr<<"= "<< x <<" + recursiveFunctionA("<< x<<","<<y <<")"<<endl;
	    cout<<'\t'<<'\t'<<'\t';
        return x + recursiveFunctionA(y-1, x);
		
}
int recursiveFunctionB(int a, int b) {
   if (a < b) {
      return 0;
   } else {
	    cerr<<"= "<< a <<" + recursiveFunctionA("<< a<<","<<b <<")"<<endl;
	    cout<<'\t'<<'\t'<<'\t';
      return 1 + recursiveFunctionB(a - b, b);
	 
   }
}

int gcd(int a, int b){
	int r= a%b;
	if (b%r==0)//base case
	  return r;
	else return gcd((b%r), b);
}
int find(int amount){
	vector<int> a;
	a.push_back(amount);
	for (int i=0; i<a.size();i++){
	
	   amount+=a.at(i);
	}

	return amount;
}

int makeChange(int amount  , int coins[], int ways){
	int pennies   = coins[0];
	int nickels   = coins[1];
	int dimes     = coins[2];
	int quarter   = coins[3];
	int fiftyCent = coins[4];
	int HundredCent = coins[5];
	int cal=0;
    int a;
	if (ways == 0){
            return 0;	
 	}
	else if((coins[ways])< amount){
			cal=coins[ways] +coins[ways];
		  
		  if(cal==amount){
			  
			  return 1+ makeChange(amount,coins, ways);
		  }
		 
		return  makeChange(amount, coins, ways);
	}
	else{

		return makeChange(amount, coins, ways-1);
	}

	
	
}
int  main(){
	
	

    /* 1. Mystery Method */
    cout << "Mystery Method:\n";
     int num1, num2, result;                        
    num1 = 7;  num2 = 2;                           
    result = recursiveFunctionB( num1,  num2);
   cout<<result <<endl;
	/* 1.a.1 Show the recursive method calls that are generated HERE
	                    = 7 + recursiveFunctionA(7,2)
                        = 5 + recursiveFunctionA(5,2)
                        = 3 + recursiveFunctionA(3,2)
                        3

    */

    num1 = 29;  num2 = 5;
    result = recursiveFunctionB( num1,  num2);
	cout<<result<<endl;
    /* 1.a.2 Show the recursive method calls that are generated HERE
                
				        = 29 + recursiveFunctionA(29,5)
                        = 24 + recursiveFunctionA(24,5)
                        = 19 + recursiveFunctionA(19,5)
                        = 14 + recursiveFunctionA(14,5)
                        = 9 + recursiveFunctionA(9,5)
                        5
    */
    
    num1 = 5;  num2 = 7;
    result = recursiveFunctionB( num1,  num2);
	cout<<result<<endl;
    /* 1.a.3 Show the recursive method calls that are generated HERE
       
	   0   Because the first condition execute 

    */

    /* 1.b In just a few words, state what the method is computing assuming a > 0 and b > 0 for the initial call.
       compute how many time b goes to a without remainder.

    */

    
    /* 2. Euclid's Algorithm */
    cout << "\nEuclid's Algorithm:\n";
    num1 = 36;
    num2 = 20;
    result = gcd( num1, num2);
    cout << "Greatest common denominator of " << num1 << " and " << num2 << " is " << result << endl;
    /* 3. Make Change (OPTIONAL) */
     cout << "\nMake Change:\n";
      //int initialAmount = 10;
      //int coinValues[] = {1, 5, 10, 25, 50, 100};
      //int numCoins = 5;
      //result = makeChange( initialAmount, coinValues, numCoins /*...*/);
      //cout << "There are " << result << " ways to make change for " << initialAmount << " with " << numCoins << " US coins\n";
     
     //initialAmount = 100;
     //result = makeChange( initialAmount, coinValues, numCoins /*...*/);
    // cout << "There are " << result << " ways to make change for " << initialAmount << " with " << numCoins << " US coins\n";
	
	
  
return 0;
}