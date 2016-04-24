#include<iostream>
#include<string>
using namespace std;
template<typename T>

class LinkList
{
public:

	LinkList();
	//~LinkList();
	void add(T item);
	void print();
	void deleteLinkList();
	void deleteItem(T item);
	struct node
	{
		T Data;
		node *ptrNext;

	};

	int getSize();

private:
	node * head;
	int size;

};
template<typename T>
LinkList<T>::LinkList(){
	head=nullptr;
	size=0;


}
template<typename T>
int LinkList<T>::getSize(){

	return size;

}
template< typename T>
void LinkList<T>:: add(T item){
	node * temp = new node;
	temp->Data=item;
	temp->ptrNext=head;
	head=temp;
	size++;

}
template<typename T>
void LinkList<T>::print(){
	node * temp = new node;
	temp=head;
	while(head !=nullptr){

		cout<<temp->Data<<endl;
		temp=temp->ptrNext;
		head= temp;
	}
}
/*
template<typename T> 
void LinkList<T> :: deleteLinkList(){

	node* temp;
	while(head!= nullptr){
		temp= head;
		head=head->ptrNext;
		delete temp;
		temp=nullptr;

	}
	size=0;
}
*/
template<typename T>
void LinkList<T>:: deleteItem(T item){
	node * curr;
	node * prev=nullptr;
	curr= head;
	if(head!=nullptr){
		if(curr->Data== item){
		head=head->ptrNext;
		delete curr;
		curr=nullptr;
		}
	}
	else{

		while(curr != nullptr && curr->Data!= item){
			prev=curr;
			curr=curr->ptrNext;
		}
		if(curr== nullptr){
			cout<< "can not find the item"<<endl;
		}
		else{
			cout<<" item found"<<endl; 
			prev->ptrNext=curr->ptrNext;
		}
	}
}
int main(){
	LinkList<int> obj;
	obj.add(55);
	obj.add(66);
	obj.add(100);
	obj.add(200);
	obj.add(100);
	cout<< obj.getSize()<<endl;
	obj.print();
	obj.deleteItem(66);
	obj.print();


	return 0;
}