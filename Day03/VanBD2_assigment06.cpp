#include<iostream>
using namespace std;

/**
***********************************************************
* @Param: pArr the pointer point to allocated memory
*		  szRow size of matrix's row
*		  szCol size of matrix's colum
* description: import matrix's data
***********************************************************
*/
bool imporData(int*** pArr, int szRow, int szCol) {
	*pArr = new int* [szRow];
	for (int row = 0; row < szRow; row++)
		*(*pArr + row) = new int[szCol];
	if (pArr == NULL)
		return false;
	printf("Enter Matrix data from keyboard: \n");
	for (int row = 0; row < szRow; row++) {
		for (int col = 0; col < szCol; col++)
			cin >> *(*(*pArr + row) + col);
	}
	return true;
}

/**
*************************************************************
* @Param: pArr1,pArr2 the pointers point to allocated memory
*		  szRow size of matrix's row
*		  szCol size of matrix's colum
* description: add two matrix
*************************************************************
*/
int** add2Matrix(int** pArr1, int** pArr2, int szRow, int szCol) {
	int** Result = new int* [szRow];
	for (int row = 0; row < szRow; row++)
		Result[row] = new int[szCol];
	for (int row = 0; row < szRow; row++) {
		for (int col = 0; col < szCol; col++)
			*(Result[row] + col) = *(pArr1[row] + col) + *(pArr2[row] + col);
	}
	return Result;
}

/**
*************************************************************
* @Param: pArr the pointers point to allocated memory
*		  szRow size of matrix's row
*		  szCol size of matrix's colum
* description: display pArr matrix to console screen
*************************************************************
*/
void printMatrix(int** pArr, int szRow, int szCol) {
	for (int row = 0; row < szRow; row++) {
		for (int col = 0; col < szCol; col++)
			printf("%d ", *(pArr[row] + col));
		printf("\n");
	}
}

/**
*************************************************************
* @Param: pArr the pointers point to allocated memory
*		  szRow size of matrix's row
*		  szCol size of matrix's colum
* description: free memory
*************************************************************
*/
void freeMem(int** pArr, int szRow, int szCol) {
	for (int col = 0; col < szCol; col++)
		delete[]pArr[col];
	delete[]pArr;
}

int main() {
	int** pArr1, ** pArr2, ** sum, szRow, szCol;
	printf("Enter size of Matrix Row: ");
	cin >> szRow;
	printf("\nEnter size of Matrix Col: ");
	cin >> szCol;
	if (imporData(&pArr1, szRow, szCol))
		printf("success\n");
	else
		printf("fail\n");
	if (imporData(&pArr2, szRow, szCol)) {
		printf("success\n");
		printf("The sum of 2 matrix: \n");
		sum = add2Matrix(pArr1, pArr2, szRow, szCol);
		printMatrix(sum, szRow, szCol);
		freeMem(sum, szRow, szCol);
	}
	else
		printf("fail\n");
	freeMem(pArr1, szRow, szCol);
	freeMem(pArr2, szRow, szCol);
	return 0;
}