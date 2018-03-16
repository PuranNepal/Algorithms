/*
Name: Puran Nepal
Project: N-Queen Problem (backtracking)
*/

#include <iostream>
using namespace std;

//Size of the chess board
const int SIZE = 8;

//a balanced row means that row only has 1 queen
bool isRowBalanced(int board[][SIZE], int row);
//a balanced column means that row only has 1 queen
bool isColBalanced(int board[][SIZE], int col);
//checks if there's more than 1 queen from :TopLeft to BottomRight diagonal
bool isRightDiagonalBalanced(int board[][SIZE], int row, int col);
//checks if there's more than 1 queen from :TopRight to Bottom left diagonal
bool isleftDiagonalBalanced(int board[][SIZE], int row, int col);
//this displays the chess board
void displayMatrix(int aMatrix[][SIZE]);
//this function checks if we can add a queen in a given square
bool isEntireColBalanced(int board[][SIZE], int row, int col);
//this is the backtracking algorithm which will add the queen
void putQueen(int board[][SIZE], int row);


int main() {
	//initializing a empty chessboard
	//0's are going to represent a empty square and 1's are going to represent a queen
	int chessboard[SIZE][SIZE] = { 0 };

	//this start adding queen in each row starting from row 0
	putQueen(chessboard, 0);

	system("pause");
	return 0;
}


//this checks if there is no more than 1 queen
//a balanced row means that row only has 1 queen
bool isRowBalanced(int board[][SIZE], int row) {
	int sum = 0;
	//we will sum all the number is in given row 
	for (int i = 0; i < SIZE; ++i)
	{
		sum += board[row][i];
	}

	//if the total is more than 1, then that implies there are more than 1 queen
	//therefore row is not balanaced
	if (sum > 1) {
		return false;
	}

	return true;
}

//this checks if there is no more than 1 queen in a column
//a balanced column means that row only has 1 queen
bool isColBalanced(int board[][SIZE], int col) {
	int sum = 0;
	//sums up the entire given column
	for (int i = 0; i < SIZE; ++i)
	{
		sum += board[i][col];
	}

	//if the total is more than 1, then that implies there are more than 1 queen
	//therefore column is not balanaced
	if (sum > 1) {
		return false;
	}

	return true;
}

//this checks if there are more than one queen in
//	the diagonal that starts from
//			:TopLeft to Bottom Right
bool isRightDiagonalBalanced(int board[][SIZE], int row, int col) {
	int topCol = 0;
	int topRow = 0;
	int sum = 0;

	
	//we want to divide the chess into upper and lower triangle matrix
	//to figure out the total sum
	if (col >= row) {
		topCol = col - row;

		int count = 0;
		while ((topCol + count) < SIZE) {
			sum += board[count][topCol + count];
			count += 1;
		}
	}
	else {
		topRow = row - col;
		int count = 0;
		while ((topRow + count) < SIZE) {
			sum += board[topRow + count][count];
			count += 1;
		}
	}

	if (sum > 1) {
		return false;
	}

	return true;
}


//this checks if there are more than one queen in the diagonal 
//that starts from
//			:TopRight to Bottom left
bool isleftDiagonalBalanced(int board[][SIZE], int row, int col) {
	int topCol = 0;
	int topRow = 0;
	int sum = 0;

	if ((row + col) < SIZE) {
		topCol = col + row;

		int count = 0;
		while ((topCol - count) >= 0) {
			sum += board[count][topCol - count];
			count += 1;
		}
	}
	else {

		topRow = ((col + row) - SIZE) + 1;

		int count = 0;
		while ((topRow + count) < SIZE) {
			sum += board[topRow + count][(SIZE - 1) - count];
			count += 1;
		}
	}


	if (sum > 1) {
		return false;
	}

	return true;
}

//this displays the chess board
void displayMatrix(int aMatrix[][SIZE]) {

	cout << "The Chess Board Matrix is: " << endl;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << aMatrix[i][j] << "  ";
		}
		cout << endl;
	}
}

//this function checks if we can add a queen in 
//	a given square
bool isEntireColBalanced(int board[][SIZE], int row, int col) {
	board[row][col] = 1;
	if (isRowBalanced(board, row) == true && isColBalanced(board, col) == true && isleftDiagonalBalanced(board, row, col) == true && isRightDiagonalBalanced(board, row, col) == true) {
		return true;
	}
	else {
		board[row][col] = 0;
	}

	return false;
}

//this is the backtracking algorithm which will add the queen
void putQueen(int board[][SIZE], int row) {
	for (int col = 0; col < SIZE; ++col)
	{
		if (isEntireColBalanced(board, row, col) == true) {
			board[row][col] = 1;
			if (row < SIZE - 1) {
				putQueen(board, row + 1);
			}
			else {
				cout << "Success !!!!!!!!!!!!!!!!" << endl;
				displayMatrix(board);
				cout << endl;
				cout << endl;
			}

			board[row][col] = 0;
		}
		else {
			board[row][col] = 0;
		}
	}
}
