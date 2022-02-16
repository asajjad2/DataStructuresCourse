#include "pch.h"
#include "Header.h"
TEST(arraySum, T1) {
	int arr[][5] = { { 1,2,3,4,5 },{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5 },{1,2,3,4,5} };
	int sum = arraySum(arr, 5, 5);
	EXPECT_EQ(75, sum);
}

TEST(arraySum, T2) {
	int arr[][5] = { { 1,2,6,8,0},{10,6,8,3,5},{15,9,4,7,2},{8,5,2,7,6},{7,5,3,1,9} };
	int sum = arraySum(arr, 5, 5);
	EXPECT_EQ(139, sum);
}

//TEST(rowSum, T1) {
//	int arr[4][4] = { { 1,5,8,2},{1,4,10,8},{7,2,0,1},{1,23,3,4} };
//	int res[4] = { 16,23,10,31 };
//	int* sum = rowSum(arr,4,4);
//	for (int i = 0; i < 4; i++)
//		EXPECT_EQ(res[i], sum);
//}
//TEST(rowSum, T2) {
//	int arr[3][4] = { { 1,8,2,9},{4,10,8,2},{7,2,1,6} };
//	int res[4] = { 20,24,16 };
//	int* sum = rowSum(arr,3,4);
//	for (int i = 0; i < 4; i++)
//		EXPECT_EQ(res[i], sum);
//}

TEST(rowSum, T1) {
	int arr[][4] = { { 1,5,8,2},{1,4,10,8},{7,2,0,1},{1,23,3,4} };
	int res[4] = { 16,23,10,31 };
	int* sum = rowSum(arr, 4, 4);
	for (int i = 0; i < 4; i++)
		EXPECT_EQ(res[i], sum[i]);
}
TEST(rowSum, T2) {
	int arr[3][4] = { { 1,8,2,9},{4,10,8,2},{7,2,1,6} };
	int res[3] = { 20,24,16 };
	int* sum = rowSum(arr, 3, 4);
	for (int i = 0; i < 3; i++)
		EXPECT_EQ(res[i], sum[i]);
}

TEST(colSum, T1) {
	int arr[][4] = { { 1,5,8,2},{1,4,10,8},{7,2,0,1},{1,23,3,4} };
	int res[4] = { 10,34,21,15 };
	int* sum = colSum(arr, 4, 4);
	for (int i = 0; i < 4; i++)
		EXPECT_EQ(res[i], sum[i]);
}
TEST(colSum, T2) {
	int arr[][4] = { { 7,5,3,2},{0,4,3,8},{7,2,4,1},{3,8,5,0} };
	int res[4] = { 17,19,15,11 };
	int* sum = colSum(arr, 4, 4);
	for (int i = 0; i < 4; i++)
		EXPECT_EQ(res[i], sum[i]);
}

TEST(transposeMatrix, T1) {
	int arr[][2] = { {8,2},{1,4} };
	int res[][2] = { {8,1},{2,4} };
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			EXPECT_EQ(res[i][j], transposeMatrix(arr,i,j));
}
TEST(transposeMatrix, T2) {
	int arr[][2] = { {10,8},{3,9} };
	int res[][2] = { {10,3},{8,9} };
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			EXPECT_EQ(res[i][j], transposeMatrix(arr,i,j));
}

TEST(matrixSum, T1) {
	int arr[][3] = { {8,2,4},{1,4,9},{4,8,1} };
	int arr1[][3] = { {1,8,1},{2,5,4},{5,4,0} };
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			EXPECT_EQ(arr[0][0] + arr1[0][0], matrixSum(arr, arr1));
}
TEST(matrixSum, T2) {
	int arr[3][3] = { {10,8,7},{3,9,1} ,{3,8,5} };
	int arr1[3][3] = { {10,3,1},{8,9,10},{5,3,9} };
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			EXPECT_EQ(arr[0][0] + arr1[0][0], matrixSum(arr, arr1));
}

TEST(matrixMult, T1) {
	int mat1[4][4] = { { 1, 1, 1, 1 },{ 2, 2, 2, 2 },{ 3, 3, 3, 3 },{ 4, 4, 4, 4 } };// 4*4
	int mat2[4][4] = { { 1, 1, 1, 1 },{ 2, 2, 2, 2 },{ 3, 3, 3, 3 },{ 4, 4, 4, 4 } };//4*4
	EXPECT_EQ(400, matrixMult(mat1, mat2, 4, 4, 4, 4));
}
TEST(matrixMult, T2) {
	int mat1[4][4] = { { 0,0,0,0 },{ 2, 2, 2, 2 },{ 3, 3, 3, 3 },{ 4, 4, 4, 4 } };// 4*4
	int mat2[4][4] = { { 0,0,0,0 },{ 2, 2, 2, 2 },{ 3, 3, 3, 3 } , {4,4,4,4} };//4*4
	EXPECT_EQ(324, matrixMult(mat1, mat2, 4, 4, 4, 4));
}

TEST(leftDiagonalSum, T1)
{
	int arr[][4] = { {1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4} };
	EXPECT_EQ(10, leftDiagonalSum(arr));
}
TEST(leftDiagonalSum, T2)
{
	int arr[][4] = { {1,5,3,9},{54,8,9,4},{1,4,2,9},{4,9,2,0} };
	EXPECT_EQ(11, leftDiagonalSum(arr));
}

TEST(rightDiagonalSum, T1)
{
	int arr[][4] = { {1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4} };
	EXPECT_EQ(10, rightDiagonalSum(arr));
}
TEST(rightDiagonalSum, T2)
{
	int arr[][4] = { {1,5,3,9},{54,8,9,4},{1,4,2,9},{4,9,2,0} };
	EXPECT_EQ(26, rightDiagonalSum(arr));
}


TEST(displayMiddleRow, T1)
{
	int arr[][5] = { {1,5,9,3,5},{14,8,2,0,4},{4,4,0,1,2},{7,45,89,2,9},{5,2,8,5,0} };
	int res[5] = { 4,4,0,1,2 };
	EXPECT_EQ(res[0], displayMiddleRow(arr, 5));
}
TEST(displayMiddleRow, T2)
{
	int arr[][5] = { {1,2,3,4,5}, {6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25} };
	int res[5] = { 11,12,13,14,15 };
	EXPECT_EQ(res[0], displayMiddleRow(arr, 5));
}

TEST(displayMiddleCol, T1)
{
	int arr[][5] = { {1,5,9,3,5},{14,8,2,0,4},{4,4,0,1,2},{7,45,89,2,9},{5,2,8,5,0} };
	int res[5] = { 9,2,0,89,8 };
	EXPECT_EQ(res[0], displayMiddleCol(arr, 5));
}
TEST(displayMiddleCol, T2)
{
	int arr[][5] = { {1,2,3,4,5}, {6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25} };
	int res[5] = { 3,8,13,18,23 };
	EXPECT_EQ(res[0], displayMiddleCol(arr, 5));
}
