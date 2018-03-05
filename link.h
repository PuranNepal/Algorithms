/*
	Author: Puran Nepal
	Course: ADS
	Purpose: Singly Linked List
*/

#ifndef LINK_H
#define LINK_H
#include <iostream>

struct Node {
	int data;
	Node *next;
};

class Link {
public:
	Link(); //default constructor
	Link(const Link &);
	void insert(int item); //adding new add to the end of the linked list
	void deleteItem(int item); //deletes exiting element
	bool isEmpty() const; //returns if the linked list is empty or not
	int getSize() const; ///returns the length of the linked list
	void displayList() const;
	friend std::ostream & operator<<(std::ostream&, const Link&);


	~Link(); //distructor 
private:
	Node *head; 
	Node *tail; //points to the end of the list
};
#endif