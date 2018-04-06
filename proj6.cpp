#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include "wordtree.h"
using namespace std;

//split function for parsing text
void split(const std::string& s, char c, std::vector<std::string>& v);
//lowers each word in that vector
void toLowerWord(std::vector<std::string>& v);

int main() {
	WordTree myTree; //our WordTree object
	
	ifstream myfile("input.txt"); //opens the input file which contains the text
	assert(myfile);
	string texts; //we will read entire file in this one string variable
	getline(myfile, texts); 

	
	vector<string> wordVector; //we will hold the each word in this vector
	char myChar = ' '; //we will parse(split) out the document with blankspace (space)
	split(texts, myChar, wordVector); 
	toLowerWord(wordVector); //this will lower any word that has capital letter
	
	//insearting each word into the tree
	int count = 0;
	while (count < wordVector.size()) {
		myTree.insert(wordVector[count]);
		count += 1;
	}

	cout << "Word Tree build and loaded" << endl << endl;

	myTree.printInOrder(3); //print words in order above that number
	myTree.findNode("a"); //prints our how many words are their
	myTree.findNode("man");

	system("pause");
	return 0;
}


void toLowerWord(std::vector<std::string>& v) {
	string temp;
	for (int i = 0; i < v.size(); i++) {
		temp = v[i];
		for (int j = 0; j < temp.length(); j++) {
			temp[j] = tolower(temp[j]);
		}
		v[i] = temp;
	}
}


void split(const std::string& s, char c, std::vector<std::string>& v) {

	std::string::size_type i = 0;
	std::string::size_type j = s.find(c);

	while (j != std::string::npos) {
		v.push_back(s.substr(i, j - i));
		i = ++j;
		j = s.find(c, j);

		if (j == std::string::npos)
			v.push_back(s.substr(i, s.length()));
	}
}

