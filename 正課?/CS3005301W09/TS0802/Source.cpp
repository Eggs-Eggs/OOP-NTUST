/***********************************************************************
 * File: Main.cpp
 * Author: »~ÁÚ÷Ÿ
 * Create Date: 2023/4/23
 * Editor: »~ÁÚ÷Ÿ
 * Update Date: 2023/4/23
 * Description: This program is compute matrix multiplication
 * ***********************************************************************/

#include<iostream>

using namespace std;

int main()
{
	// Declear martix
	double** martix1;
	double** martix2;
	double** result;

	int col1, row1;
	int col2, row2;

	// Input col and row
	cin >> col1 >> row1 >> col2 >> row2;

	martix1 = new double* [col1];
	martix2 = new double* [col2];
	result = new double* [col1];

	for (int i = 0; i < col1; i++)
		martix1[i] = new double[row1];
	for (int i = 0; i < col2; i++)
		martix2[i] = new double[row2];
	for (int i = 0; i < col1; i++)
		result[i] = new double[row2];

	if (row1 == col2)
	{
		// Input data
		for (int i = 0; i < col1; i++)
		{
			for (int j = 0; j < row1; j++)
			{
				cin >> martix1[i][j];
			}
		}

		for (int i = 0; i < col2; i++)
		{
			for (int j = 0; j < row2; j++)
			{
				cin >> martix2[i][j];
			}
		}

		// Comput result
		for (int i = 0; i < col1; i++)
		{
			for (int j = 0; j < row2; j++)
			{
				int sum = 0;
				for (int k = 0; k < row1; k++)
				{
					sum += martix1[i][k] * martix2[k][j];
				}
				result[i][j] = sum;
				cout << result[i][j];
				if (j != row2 - 1)
					cout << " ";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "Matrix multiplication failed." << endl;
	}

	// Delete data
	for (int i = 0; i < col1; i++)
		delete[] martix1[i];
	for (int i = 0; i < col2; i++)
		delete[] martix2[i];
	for (int i = 0; i < col1; i++)
		delete[] result[i];

	delete[] martix1;
	delete[] martix2;
	delete[] result;

	return 0;
}
