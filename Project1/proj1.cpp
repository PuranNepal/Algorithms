// proj1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;


double calAvg(int * arrayPointer, int numOfValue);
int* makeArray(int * arrayPointer, int aSize, double mul);

int main() {
	ifstream myfile;
	myfile.open("num.txt");
	assert(myfile);
	int input;
	int size;
	int copy_size;
	int count = 0;
	double avg;
	cout << "Enter a size: ";
	cin >> size;
	
	if ((size % 50 == 0) && (size >= 100) && (size <= 300)) {
		int *myArray = nullptr;
		myArray = makeArray(myArray, size, 1);
		cout << "Allocated " << size << " elements" << endl;
		copy_size = size;
		while ((myfile >> input)) {
			myArray[count] = input;

			if (count > 0.95*copy_size) {
				avg = calAvg(myArray, count);
				myArray = makeArray(myArray, copy_size, 1.5);
				if (1.5*copy_size < 600) {
					copy_size = 1.5*copy_size;
				}
				else {
					copy_size = 600;
				}
				cout << "Array size is " << copy_size << " - Average so far is " << avg << endl;
			}

			count += 1;
		}


		cout << count << " integers were read and the average was " << calAvg(myArray, count) << endl;

		delete[] myArray;
		myArray = NULL;

	}
	else {
		exit(1);
	}
	return 0;
}



double calAvg(int * arrayPointer, int numOfValue) {
	double total = 0;
	for (int i = 0; i < numOfValue; i++)
	{
		total += arrayPointer[i];
	}

	return total / numOfValue;
}

int* makeArray(int * arrayPointer, int aSize, double mul) {

	int * newArrayPtr = nullptr;
	int newSize = int(mul*aSize);

	if (arrayPointer == nullptr) {
		newArrayPtr = new int[newSize];
	}
	else {
		if (newSize < 600) {
			newArrayPtr = new int[newSize];

			for (int i = 0; i < aSize; i++)
			{
				newArrayPtr[i] = arrayPointer[i];
			}
		}
		else {
			newSize = 600;
			newArrayPtr = new int[newSize];
			for (int i = 0; i < aSize; i++)
			{
				newArrayPtr[i] = arrayPointer[i];
			}
		}
	}

	delete[] arrayPointer;
	arrayPointer = NULL;

	return newArrayPtr;
}
