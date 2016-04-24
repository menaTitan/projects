#include"stdafx.h"
#include"list.h"
#include<iostream>
using namespace std;
unsotredType::unsotredType() {
	length = 0;
	start = NULL;
}
void unsotredType::InsertItem(int item) {
	NodeType* temp = new NodeType;
	temp->data = item;
	temp->next = start;
	start = temp;

	length++;
}
//0(1)
bool unsotredType::IsFull()const {
	NodeType* location;
	try
	{
		location = new  NodeType;
		delete location;
		return false;
	}
	catch (bad_alloc exception)
	{
		return true;
	}

}

void unsotredType::MakeEmpty() {
	NodeType* temp;
	while (start !=NULL) {

		temp = start;
		start = start->next;
		delete temp;
		
	}
	length = 0;
}
unsotredType:: ~unsotredType() {
	MakeEmpty();
}

int unsotredType::Getlength()const {

	return length;

}
void unsotredType::show() {
	NodeType* temp = start;
	while ( temp!=NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;

	}


}
void unsotredType::DeleteItem(int item) {
	if (start != NULL) {

		NodeType*temp = start;
		if (item == start->data) {
		
			start = start->next;
			delete temp;
			length--;
		
		
		}
		else {
			while (temp->next != NULL && (!(item == (temp->next)->data))) {

				temp = temp->next;

			}

			NodeType* target = temp->next;
			if (target != NULL) {
				temp->next = target->next;
				delete target;
				length--;



			}
		}
				

		

		}


}
