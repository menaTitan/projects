#include<iostream>
#include<cstdlib>
#include"sequenceTree.h"


sequenceTree:: sequenceTree(){
	root=new TreeNode;
	length=0;
}

TreeNode:: TreeNode(){

	for(int i=0;i<58;i++){
				child[i]=nullptr;
	}
}

unsigned int sequenceTree::getChildIndex(char seqChar){
	return  seqChar-'A';
}

void sequenceTree:: AddSequence(sequence*key){
 	TreeNode * temp;
	temp=root;

	int index=0;
	
	for (unsigned int i=0;  i<key->getSquence().length();i++){

		index = getChildIndex(key->getSquence()[i]);
		if(temp->child[index]==nullptr){
			// add a tree node  
			temp->child[index]= new TreeNode;
			temp->child[index]->parent = root->child[index];
			length++;
		}
		temp=temp->child[index];
	}
	temp->child[index]= new TreeNode;
	temp->child[index]->data=key;
	//temp->child[index]->data->print();
	length++;
}


TreeNode * sequenceTree::FindSequence(string key){
	TreeNode * temp;
	temp=root;

	int index=0;
	
	for (unsigned int i=0;  i<key.length();i++){

		index = getChildIndex(key[i]);
		if(temp->child[index]==nullptr){
			return nullptr;
		}
		temp=temp->child[index];
	}	

	return temp;
}
void sequenceTree::FindSequence2(string key){
	TreeNode * temp;
	temp=root;

	int index=0;
	
	for (unsigned int i=0;  i<key.length();i++){

		index = getChildIndex(key[i]);
		if(temp->child[index]==nullptr){
		}
		temp->child[index]->data->print();
	}	


}
int sequenceTree:: size(){

	return length;
}
void sequenceTree::printAll(TreeNode*  tn){
	
	if (tn->data!=nullptr){
			
			 tn->data->print();
		}
	for ( int i=0; i <58 ;i++){
	
		
		if(tn->child[i]!=nullptr){
			printAll(tn->child[i]);
		}
	}
	
}
void sequenceTree:: print(string key){
	TreeNode * temp;
	temp=root;

	int index=0;
	
	for (unsigned int i=0;  i<key.length();i++){

		index = getChildIndex(key[i]);
		if(temp->child[index]!=nullptr){
			temp->child[index]->data->print();
		}
		temp=temp->child[index];
	}	

	
}
