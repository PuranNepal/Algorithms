#include "link.h"

//initializing the linked list
Link::Link() {
	head = nullptr; 
	tail = nullptr;
}

void Link::insert(int item) {
	//creating new node to store the item
	Node * newPtr = new Node;
	newPtr->data = item;
	//we want the node to be added at the end of the list
	newPtr->next = nullptr;

	//if the list is empyt
	if (head == nullptr) {
		head = newPtr;
		tail = head; //prev points to the head and we will 
					//this will point to end of the list
	}
	else {
		tail->next = newPtr;
		tail = newPtr; //points to the end of the list
	}
}

Link::Link(const Link & rhs) {
	head = nullptr;  
	tail = nullptr;

	//we want to iterate through the list we want copy from
	Node * curr = rhs.head;

	//we will use inseart function to add to the list
	while (curr != nullptr) {
		insert(curr->data);
		curr = curr->next;
	}
}


void Link::deleteItem(int item) {
	Node * curr = head;  // to iterate through the list
	Node * prev; //this will record the previous 
	Node * nodeToBeDeleted;  //this node will be deleted
					//however we want to keep point at it 
					//so we can free the memeory

	while (curr != nullptr) {
		
		//if we found the item in the list
		if (curr->data == item) {

			//
			if (curr == head) {
				nodeToBeDeleted = head; 
				head = curr->next;
				delete nodeToBeDeleted;
				break;
			}
			else {
				nodeToBeDeleted = curr;
				prev->next = curr->next;
				delete nodeToBeDeleted;
				break;
			}
		}

		prev = curr;
		curr = curr->next;
	}
	
}

//this will display the entire list
void Link::displayList() const {
	Node * curr = head;
	while (curr != nullptr)
	{
		std::cout << curr->data << std::endl;
		curr = curr->next;
	}
}


//if the list is empty it returns true
bool Link::isEmpty() const {
	if (head == nullptr) {
		return true;
	}
	return false;
}

//prints how many items are the in the list
int Link::getSize() const {
	Node * curr = head;
	int total = 0;
	while (curr != nullptr) {
		total += 1;
		curr = curr->next;
	}
	return total;
}

//overloading operator so we print the entire list
std::ostream & operator<<(std::ostream&os, const Link& obj) {
	Node * curr = obj.head;
	while (curr != nullptr)
	{
		std::cout << curr->data << std::endl;
		curr = curr->next;
	}

	return os;
}


//destructor to free up the memorey
Link::~Link() {
	Node * curr = head;
	Node * temp;
	while (curr != nullptr) {
		temp = curr;
		curr = curr->next;
		delete temp;
	}
}