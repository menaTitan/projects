
#ifndef SEQUENCETREE_H
#define SEQUENCETREE_H
#include<string>
#include"sequence.h"
using std::string;
	struct TreeNode
	{
		sequence * data;
		TreeNode * child[58];
		TreeNode * parent;
		char * key;
		TreeNode();
	
	};

class sequenceTree{
public:
	sequenceTree();
	unsigned int getChildIndex(char seqChar);
	void AddSequence(sequence* key);
	TreeNode* FindSequence(string  key);
	void FindSequence2(string  key);
	void print(string key);
	void printAll(TreeNode* tn);
	int size();
private:
	int length; // use with size function
	TreeNode* root;
}; 
#endif