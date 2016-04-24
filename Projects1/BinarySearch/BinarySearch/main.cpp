#include<iostream>
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
	int size=10;
	int a[]={1,2,3,4,5,6,7,8,9,10};
	int searchNumnber;
      

	cout<<"Enter a Number to search for"<<endl;
	cin>>searchNumnber;


int result =	binarySearch( a,  size,searchNumnber);

if (result ==-1){

 cout<< "can not the find the item for where looking for"<< searchNumnber<<endl;

}
else{

   cout<<"we find the item at "<<result<<endl;


}


}