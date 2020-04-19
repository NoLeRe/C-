#include<iostream>
using namespace std;

bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){

	/*for(int i=0;i<matrixSize;i++)
	{
	for(int j=0;j<(*matrixColSize);j++)
	{
	if(matrix[i][j]==target)
	return true;
	}
	}
	return false;*/
	int row = 0;
	int col = (*matrixColSize) - 1;
	if (matrixSize == 0 || *matrixColSize == 0)
		return false;
	while (row<matrixSize&&col >= 0)
	{
		if (matrix[row][col]<target)
			row++;
		else if (matrix[row][col]>target)
			col--;
		else if (matrix[row][col] == target)
			return true;
	}
	return false;
}