#include <iostream>
#include <string>
using namespace std;

#ifndef WORDTREE_H
#define WORDTREE_H

struct TreeNode {
	string word;
	int wordCount;
	TreeNode *leftChild;
	TreeNode *rightChild;
};

class WordTree {
public:
	WordTree(); //Constructor creates an empty tree
	~WordTree(); //destructor (recursive)
	void insert(string); //inserts word to the tree (recursive)
	void findNode(string); //prints out the word and the count (calls a private function)
	void printInOrder(int); //outputs the word which meets or exceeds the int value (recursive)

private:
	TreeNode *root;

	//private function
	TreeNode* newNode(string); //this creates new node
	void insertEl(string, TreeNode *&); //recursive function that insearts new nodes
	void postOrder(TreeNode *); //recursive fuction for destructor 
	void inOrder(TreeNode *, int num, int&); //recursive fuction for printInOrder
	int search(string); //searches the word in the tree for findNode function
};

#endif // 