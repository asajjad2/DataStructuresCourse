#pragma once
#include <iostream>
#include <fstream>
using namespace std;
int arraySum(int arr[][5], int row, int col) {
	int sum=0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			sum += arr[i][j];
	}
	return sum;
}

int* rowSum(int arr[][4], int row, int col) {

	int* sum = new int[4];
	for (int i = 0; i < row; i++) {
		sum[i] = 0;
	}
	int count=0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			sum[i] += arr[i][j];
		}
	}
	
	int* ptr = sum;
	return ptr;
}


int* colSum(int arr[][4], int row, int col) {
	int* sum = new int[4];

	for (int i = 0; i < row; i++)
		sum[i] = 0;

	int count=0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			sum[i] += arr[j][i];
		}
	}
	int* ptr = sum;
	return ptr;
}

int transposeMatrix(int arr[][2], int row, int col) {
	return arr[col][row];
}

int matrixSum(int arr[3][3], int arr1[3][3]) {

	int arr2[3][3] = { 0 };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			arr2[i][j] = arr[i][j] + arr1[i][j];
		}
	}

	return arr2[0][0];
}

int matrixMult(int arr1[][4], int arr2[][4], int row1, int col1, int row2, int col2) {

	int sum = 0;
	const int x = col2;
	int temp[4][4];
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col2; j++) {
			temp[i][j] = 0;
		}
	}

	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col2; j++) {
			for (int k = 0; k < col1; k++) {
				temp[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}

	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col2; j++) {
			sum += temp[i][j];
		}
	}

	return sum;
}

int leftDiagonalSum(int arr[][4]) {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j) {
				sum += arr[i][j];
			}
		}
	}
	return sum;

}


int rightDiagonalSum(int arr[][4]) {
	int sum = 0;
	int size = 4;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i + j == size -1 ) {
				sum += arr[i][j];
			}
		}
	}
	return sum;

}


int displayMiddleRow(int arr[][5], int row) {
	int midRow = (row + 1) / 2;
	int arr1[5] = { 0 };
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == midRow-1) {
				arr1[j] = arr[i][j];
			}
		}
	}

	return arr1[0];

}

int displayMiddleCol(int arr[][5], int row) {

	int midCol = (row + 1) / 2;
	int count = 0;
	int arr1[5] = { 0 };
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < 5; j++) {
			if (j == midCol - 1) {
				arr1[count] = arr[i][j];
				count++;
			}
		}
	}

	return arr1[0];

}


//void dataManip() {
//	ifstream in_file;
//	in_file.open()
//}
