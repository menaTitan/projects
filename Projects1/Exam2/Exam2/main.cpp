#include <iostream>
#include <algorithm> // std::sort()
#include <time.h> // srand(), rand()
#include<string>
using namespace std;


int binarySearch(int a[], int size, int search){
	int lower=0;
	int upper= size-1;
    int middle;
	while (lower<=upper)
	{
		middle= (lower+upper)/2;
		if (a[middle]==search){
		
		   return middle;
		}
		else if (a[middle]>search){
		        
			    upper=middle-1;
		}
		else if (a[middle]<search){

               lower=middle+1;
		}
	
	}
	 
	return-1;
}

int main(){
    int arraySize = -1;
    int* array = nullptr;

    cout << "Please enter the size of the array:\n";
    cin >> arraySize;
    array = new int[arraySize]; // allocate memory for array

    srand( 0 ); // seed the random number generator

    for( int i = 0; i < arraySize; i++){ // populate with random values
        array[i] = rand() % 10;
    }

    sort( array, array + arraySize); // sort the random values

    int randomQuery = rand() % 10;


    // add call to binarySearch HERE

	int result= binarySearch(array,arraySize,randomQuery);


if (result ==-1){

 cout<< "can not  find "<< randomQuery <<endl;

}
else{

   cout<<" find "<< randomQuery << " at "<<result<<endl;


}

   

 
    return 0;
}
