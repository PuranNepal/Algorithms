/* 
	Author: Puran  Nepal
	Class: CSCI-002
	Project: Project 1
	Due: 2/2/2018
	
	Description: This program reads data from a file. It adds those data in a dynamically allocated array created 
				 by makeArray function and calculates the average of the allocated data using calAvg function. 

*/

#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

//constants
const int MAX_SIZE = 600;

double calAvg(int * arrayPointer, int numOfValue); //average calculating function
int* makeArray(int * arrayPointer, int aSize, double mul); //dynamically allocates a array

int main() {
	//opening our data file
	ifstream myfile;
	myfile.open("num.txt");
	assert(myfile);

	int input; // stores the data from the file
	int size; // saves the user input of size between 100 to 300
	int copy_size; //copys size varible 
	int count = 0; //saves the number of the data read from the file
	double avg; //average calulated
	double multiple = 1.5; //factor that we want to increase of array by

	//prompts user to enter the size of the array
	cout << "Enter a size: ";
	cin >> size;


	//this if statement forces user to only input size that is between 100 to 300 and all the x % 50 = 0
	if ((size % 50 == 0) && (size >= 100) && (size <= 300)) {

		//initializing the array
		int *myArray = nullptr;
		myArray = makeArray(myArray, size, 1);

		//tells user if the allocation has succeded or not
		cout << "Allocated " << size << " elements" << endl;

		//copies the size into the copy size variable
		copy_size = size;

		//reading the data from myfile 
		while ((myfile >> input)) {

			//saves the data into the array
			myArray[count] = input;

			//if the count exceeds the 95% of the size calculates average and increases the size by our factor avaribale
			if (count > 0.95*copy_size) {

				avg = calAvg(myArray, count);
				myArray = makeArray(myArray, copy_size, multiple);

				//gets the size of the new array
				if (multiple*copy_size < MAX_SIZE) {
					copy_size = multiple*copy_size;
				}
				else {
					copy_size = MAX_SIZE;
				}

				//outputs the avg and the increased size of the array
				cout << "Array size is " << copy_size << " - Average so far is " << avg << endl;
			}

			count += 1;
		}

		//outputs total average and number of data in the file
		cout << count << " integers were read and the average was " << calAvg(myArray, count) << endl;


		//deallocating our array
		delete[] myArray;
		myArray = NULL;

	}
	else {
		exit(1);
	}

	return 0;
}



//this function calculates and returns the average of a pointer array
double calAvg(int * arrayPointer, int numOfValue) {
	double total = 0;
	for (int i = 0; i < numOfValue; i++)
	{
		total += arrayPointer[i];
	}

	return total / numOfValue;
}



//this function dynamically allocates, returns and increases size a array pointer 
int* makeArray(int * arrayPointer, int aSize, double mul) {

	//creating a null pointer
	int * newArrayPtr = nullptr;

	//calculates the increased size if it has been increased
	int newSize = int(mul*aSize);

	//if the array has not been initialized
	if (arrayPointer == nullptr) {
		newArrayPtr = new int[newSize];
	}
	else {

		//if the new size is less than 600, it initializes the newArrayptr by new size and copies all the data from old array
		if (newSize < MAX_SIZE) {
			newArrayPtr = new int[newSize];

			for (int i = 0; i < aSize; i++)
			{
				newArrayPtr[i] = arrayPointer[i];
			}
		}
		else {
			//if the size is more than 600, it keeps it at 600 
			newSize = MAX_SIZE;
			newArrayPtr = new int[newSize];
			for (int i = 0; i < aSize; i++)
			{
				newArrayPtr[i] = arrayPointer[i];
			}
		}
	}

	//deallocates the old array
	delete[] arrayPointer;
	arrayPointer = NULL;

	//return new array which has increased size
	return newArrayPtr;
}
