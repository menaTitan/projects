/* 
file Name HashTable.h
Author:  Mena Sergeyous
Description HashTable.h create hashtable that rehash when load factor is greater than one.
Date: 10/29/2015
*/


#include<string>
#include"sequence.h"
#include<iostream>
#include<math.h>
#include<list>
using std::string;
using std::list;
using std:: cout;
using std:: endl;
#ifndef HASHTABLE_H
#define HASHTABLE_H

template<typename T>
class HashTable{
public:
	//HashTable();
	HashTable(int val);
	unsigned int  HashFunction(string key);
	void addTableSize(int value);
	void insert(sequence * key);
	double LoadFactor();
	void Delete(string key);
	void print(string key);
	void  Entries();
	void rehash ();
private:

	// the total hash size
	int TableSize;
	list<T*> *Hashlist;
	//keeps tracks of enties
	int size;

};


template<typename T>
HashTable<T>::HashTable(int val)
	: TableSize(val)
{
	//create a list of array 
	Hashlist= new list<sequence*>[TableSize];
	size=0;
}

template<typename T>
void HashTable<T>:: print(string key){
	bool flag2=false;
	// call the hash function to get the index 
	int index=HashFunction(key);
	// create iterator that iterate through the list array
	list<sequence*>::iterator it=Hashlist[index].begin();
	while (it!=Hashlist[index].end())
	{
		if((*it)->getlabel()== key){
			//cout<<"Printing "<< (*it)->getAccesionID()<<"  ..."<<endl;
			flag2= true;
			(*it)->print();
			break;
		}
		++it;
	}
	if (flag2==false){
		cout<<"Can not find item ("<< key <<")"<<", NOT found!"<<endl;
		cout<<endl;
	}
	flag2=false;

}

template<typename T>
void HashTable<T>:: insert(sequence* key){
	//get the index from HashFunction and puch to the front of the list
	int index=HashFunction(key->getlabel());
	Hashlist[index].push_front(key);
	size++;

}
template<typename T>
double HashTable<T>::LoadFactor(){
	//calculate the load factor by number of entries divide by tableSize
	return ((double)size/(double)TableSize);

}
template<typename T>
void HashTable<T>::addTableSize(int value){
	TableSize=value;

}

template<typename T>
unsigned int HashTable<T>::HashFunction(string key){

	int hash = 0;
	unsigned int index;
	int power;
	// calucalte length of the string and get the ASCII value and assign to hash
	for (unsigned int i = 0; i < key.length(); i++) {
		hash += (int)key[i];
	}
	//multiply hash by  power of 3 to get big number;
	power = pow(hash, 3.0);
	index = power%TableSize;
	return index;
}
template<typename T>
void HashTable<T>::Entries(){

	//cout the number of Entries
	cout<<"Entries: "<<size<<endl;

}

template<typename T>
void HashTable<T>:: Delete(string key){
	int index=HashFunction(key);
	bool flag=false;
	list<sequence*>::iterator iter=Hashlist[index].begin();
	while (iter!=Hashlist[index].end())
	{
		if((*iter)->getlabel()== key){
			//	delete *iter;
			iter=Hashlist[index].erase(iter);
			size--;
			flag= true;
			break;
		}
		++iter;
	}
	if (flag == true){
		cout<<"Load Factor: "<<LoadFactor()<<endl;
		cout<<endl;
	}
	if (flag == false){
		cout<<"Can not delete item ("<< key <<")"<<", NOT found!"<<endl;
		cout<<endl;
	}
	flag=false;
}

template<typename T>
void HashTable<T>::rehash(){
	int rehash=0;
	int prime=0;
	int oldTableSize=0;
	if(LoadFactor()>1){
		int rehash= TableSize *2;
		// is not  prime number keep going until get prime number
		while(rehash %2 ==0){

			rehash++;
		}
		prime= rehash;
	}
	// creating temprary list  hold  old hash table 
	list<T*>*tempArray=Hashlist;
	oldTableSize=TableSize;
	TableSize=prime;
	size=0;
	// create new array  list to hold the new hash table
	Hashlist=new list<T*>[TableSize];
	// get the old item in the old hash table to the new hash table
	for(int i=0; i<oldTableSize;i++){
		list<sequence*>::iterator iter=tempArray[i].begin();
		while (iter!=tempArray[i].end())
		{
			//insert old item to the new table 
			insert((*iter));
			iter++;
		}

	}
	// delete the temp arry 
	delete[] tempArray;


	cout<<"Rehashing (new hash table has "<< prime <<" buckets)"<<" . . ."<<endl;
}

#endif

