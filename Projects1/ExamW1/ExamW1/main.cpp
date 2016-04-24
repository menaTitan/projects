#include <iostream>
#include <algorithm> // std::sort()
#include <time.h> // srand(), rand()
#include<string>
using namespace std;

void moveDiscs(int numDiscs, string t1, string t3, string t2){
	if(numDiscs==1)// base case
	{
	  
	  cout << "Move disc " <<numDiscs << " from " << t1 << " to " << t3 << endl;
	}
	else{
	 moveDiscs(numDiscs-1,t1 ,t2,t3);
	 cout << "Move disc " <<numDiscs<< " from " << t1 << " to " << t3<< endl;
	 moveDiscs(numDiscs-1,t2 ,t1,t3);

	}

}
int main(){

	 int numDiscs = -1;
    cout << "Please enter the number of discs to start with:\n";
    cin >> numDiscs;
    moveDiscs( numDiscs, "t1", "t3", "t2");

	return 0;

}