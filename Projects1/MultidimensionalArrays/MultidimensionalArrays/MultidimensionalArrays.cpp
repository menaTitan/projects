/*
Name: Mena Sergeyous



*/

#include<iostream>
using namespace std;


// function prototype.
void printNumberOfChildren(int numberOfParents, int* numberOfChildren);
void InitializeGrandchildrenNames2DArray(int numberOfParents, int* numberOfChildren);

void  x_InitializeGrandchildrenNames2DArray(int numberOfParents, int* numberOfChildren);


int main(){

      int parenets =4;
	  int *ptr;
	  int children;
	  int* numberOfChildren ;
	  cout<<" Enter the number of Parents: ";
	cin>> parenets;
	numberOfChildren= new int [parenets];
	  for(int i=0; i<parenets;i++){
		  cout<<"Enter you children amounts"<<endl;
		  cin>>children;
		  numberOfChildren[i] = children;
	  }

	
	 
	
	InitializeGrandchildrenNames2DArray( parenets,  numberOfChildren);
	 
	
	 

	return 0;

}

void printNumberOfChildren(int numberOfParents, int* numberOfChildren){

	

	for(int i=0; i<  numberOfParents;i++){
	
	 cout<<"Parent " <<  i << " has "<< numberOfChildren[i]<< " children"<<endl;
	
	
	}

}

void InitializeGrandchildrenNames2DArray(int numberOfParents, int* numberOfChildren){


	
		bool flag =true;
	string  ** array = new string *[numberOfParents];

	for(int i=0; i<numberOfParents;i++){
	   
		array[i]=new string[numberOfChildren[i]];
	      
		
		
		
	

	 printNumberOfChildren(numberOfParents,numberOfChildren);
 
	
	}
	
	  

	
}


void x_FreeGrandchildrenNames2DArray( int numberOfChildren){
for(int i = 0; i < numberOfChildren; ++i) {
    
  
   }
}