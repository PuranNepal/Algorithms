/*
Author: Puran Nepal
course: CSCI 3080
Lab number: ola3
*purpose:
	This program calculates the Inverse a square matrix whose size is 
	smaller than 11.
*/

#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

//displays a given matrix
void displayMatrix(float aMatrix[][MAX_SIZE], int aSize);

//initializes a identity matrix
void InitializeIdentity(float aMatrix[][MAX_SIZE], int aSize);

int main(){
	int size; //dimension of the square matrix 
	float A[MAX_SIZE][MAX_SIZE]; //given matrix we want to invert
	float I[MAX_SIZE][MAX_SIZE]; //identity matrix which will encode our answer


	//user input for Matrix A
	cout << "input the size of the matrix: ";
	cin >> size;

	//reading Matrix A
	cout << "Input the "  << size << "X" <<  size << " matrix:" << endl;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			cin >> A[i][j];
		}
	}

	//initializing our identity matrix
	InitializeIdentity(I, size); 


	//solving for the inverse
	for(int i = 0; i < size; i++){

		//finding our pivots in each row
		float div = A[i][i];

		for(int k = 0; k < size; k++){
			//dividing each of the column the by the pivot mi,nrt
			//   in the particular row so we can have
			//   1 as a pivot
			A[i][k] /= div;
			I[i][k] /= div;
		}

		for(int j = 0; j < size; j++){
			// we don't want to change the row we are in
			if(j != i){

				//mult will be all the number just above 
				//  and below the pivot
				float mult = -1 * A[j][i];

				for(int m = 0; m < size; m++){
					A[j][m] += mult*A[i][m];
					I[j][m] += mult*I[i][m];
				}
			}
		}
	}

	
	//displaying the inverse matrix
	displayMatrix(I, size);

	return 0;
}



//this function initializes a aSize X aSize Identity matrix 
//smaller than 11
void InitializeIdentity(float aMatrix[][MAX_SIZE], int aSize){


	for (int i = 0; i < aSize; i++)
	{
		for (int j = 0; j < aSize; j++)
		{
			// we want the diagonal columns to be 1 and
			// and the rest of the matrix to be 0
			if(i == j){
				aMatrix[i][j] = 1;
			}else{
				aMatrix[i][j] = 0;
			}
		}
	}

}


//this function displays a Matrix smaller than 11
void displayMatrix(float aMatrix[][MAX_SIZE], int aSize){

	cout << "The inverse Matrix is: " << endl;
		for (int i = 0; i < aSize; i++)
		{
			for (int j = 0; j < aSize; j++)
			{
				cout << aMatrix[i][j] << "  ";
			}
			cout << endl;
		}
}
