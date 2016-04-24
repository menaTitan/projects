#include<iostream>
#include<string>
using namespace std;



struct MyStruct
{
	string  name;
	MyStruct* link;

	void print(){

    cout<< " the name is "<< name <<endl;


	}

};

void add( string name){
	MyStruct * head;
	MyStruct * ptr;
	ptr= new MyStruct;
	if(ptr == nullptr){
	   ptr->name=name;
	   ptr->link=nullptr;
	   head=ptr;
	}
	else{
	
	   ptr->name=name;
	   ptr->link=head;
	   head=ptr;
	}
	
}

int main(){
	/*
	MyStruct * head ;
    MyStruct * ptr=new MyStruct;

	ptr->name="mena";
	ptr->link=nullptr;
	head=ptr;
	ptr=new MyStruct;
	ptr->name="sergeypous";
	ptr->link=head;
	head=ptr;
	ptr= new MyStruct;
	ptr->name="titan";
	ptr->link=head;
	head=ptr;
	while(ptr!=nullptr){
		if(ptr->name == "mena"){
		  cout<<"we found it"<<endl;
		}
	  cout<< ptr->name<<endl;
	 ptr=ptr->link;
	}
	
	*/
	add("mena");
	add("Sergeyous");
	add("Titan");



return 0;
}