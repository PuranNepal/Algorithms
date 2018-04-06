#include "WordTree.h"

//constructor
WordTree::WordTree(){
	root = nullptr;
}


//creates and returns new node
TreeNode* WordTree::newNode(string input) {
	TreeNode * newNode = new TreeNode; 
	newNode->word = input;
	newNode->wordCount = 1;
	newNode->leftChild = nullptr;
	newNode->rightChild = nullptr;
	return newNode;
}

//recursively adds new node
void WordTree::insertEl(string input, TreeNode *&curr) {
	if (curr == nullptr) {
		curr = newNode(input);
		return;
	}
	else {
		if (input < (curr->word)) {
			insertEl(input, (curr->leftChild));
		}

		if (input > (curr->word)) {
			insertEl(input, curr->rightChild);
		}

		if (input == (curr->word)) {
			curr->wordCount = curr->wordCount + 1;
		}
	}
}

//public insert fuction
void WordTree::insert(string word) {
	if (root == nullptr) {
		root = newNode(word);
	}
	else {
		insertEl(word, root);
	}
}


//recursively looks up all number
void WordTree::inOrder(TreeNode *curr, int num, int &count) {
	if (curr != nullptr) {
		inOrder(curr->leftChild, num, count);
		if ((curr->wordCount) >= num) {
			count += 1;
			cout << curr->word << "(" << curr->wordCount << ")" << endl;
		}
		inOrder(curr->rightChild, num, count);
	}
}

//print all the node that is greater than num in order manner
void WordTree::printInOrder(int num) {
	int count = 0;
	cout << "Finding all the words with " << num << " or more occurrrences: " << endl;
	inOrder(root, num, count);

	cout << count << " nodes had words with " << num << " or more occurrence(s)" << endl << endl;
}


//Basic binary search
int WordTree::search(string word) {
	int count = 0;
	TreeNode *curr = root;
	while (curr != nullptr) {
		if (word == curr->word) {
			count = curr->wordCount;
		}

		if (word < curr->word) {
			curr = curr->leftChild;
		}
		else {
			curr = curr->rightChild;
		}
	}
	return count;
}

//prints out the word count if the word is in the tree
void WordTree::findNode(string word) {
	cout << "Searching for occurrences of the word '"<< word << ".'"<<endl;

	int count = search(word);
	if (count > 0) {
		cout << "The word " << word << " occurs " << count << " time(s) in the text." << endl << endl;
	}
	else {
		cout << "The word " << word << " was not found in the text." << endl << endl;
	}

}


//visits each node using post order fashion and releases it from the memory
void WordTree::postOrder(TreeNode *curr) {
	if (curr != nullptr) {
		postOrder(curr->leftChild);
		postOrder(curr->rightChild);
		delete curr;
		curr = nullptr;
	}
}

//destructor
WordTree::~WordTree() {
	postOrder(root);
}
