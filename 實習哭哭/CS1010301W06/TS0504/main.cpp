/***********************************************************************
 * File: Main.cpp
 * Author: »~ÁÚ÷Ÿ YE YAO ZHONG
 * Create Date: 2023/3/30
 * Editor: »~ÁÚ÷Ÿ YE YAO ZHONG
 * Update Date: 2023/3/30
 * Description: This program is management the student data.
 * ***********************************************************************/

#include<iostream>
#include<string>

#define MAX 9

using namespace std;

// check row
bool checkRow(char** number);
// check column
bool checkColumn(char** number);
//check square
bool checkSquare(char** number);
//clean bool array
bool cleanBool();

bool checkRepeat[MAX + 1] = { 0 };

int main(void)
{
	char** matrix;
	//Set up array.
	matrix = new char* [MAX];

	for (int i = 0; i < MAX; i++)
	{
		matrix[i] = new char[18];
	}

	// Get input until EOF.
	while (1)
	{

		int i = 0;
		bool checkInput = 1;

		while (cin >> matrix[i])
		{
			i++;
			if (i == 9)
				break;
		}

		if (i != 9)
			break;

		//if is leagal inpput ,checkInput = 1. 
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 18 - 1; j += 2)
			{
				if (matrix[i][j + 1] != ',' && matrix[i][j + 1] != '\0' || matrix[i][j] == '0')
				{
					checkInput = 0;
				}
			}
		}

		cleanBool();

		if (checkRow(matrix) && checkColumn(matrix) && checkSquare(matrix) && checkInput)
		{
			cout << "True";
		}
		else
			cout << "False";

		cout << endl;
	}
	return 0;
}

/***********************************************************************
// Intent: Check has repeat number in this matrix for any row.
// Pre: input a double char pointer.
// Post: If no repeat number in any row, return 1.
***********************************************************************/
bool checkRow(char** number)
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < 17; j += 2)
		{
			if (checkRepeat[number[i][j] - '0'] != 1)
				checkRepeat[number[i][j] - '0'] = 1;
			else
				return 0;
		}
		cleanBool();
	}
	return 1;
}

/***********************************************************************
// Intent: Check has repeat number in this matrix for any column.
// Pre: input a double char pointer.
// Post: If no repeat number in any column, return 1.
***********************************************************************/
bool checkColumn(char** number)
{
	for (int i = 0; i < 17; i += 2)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (checkRepeat[number[j][i] - '0'] != 1)
				checkRepeat[number[j][i] - '0'] = 1;
			else
				return 0;
		}
		cleanBool();
	}
	return 1;
}

/***********************************************************************
// Intent: Check has repeat number in this matrix for any small square.
// Pre: input a double char pointer.
// Post: If no repeat number in any small square, return 1.
***********************************************************************/
bool checkSquare(char** number)
{
	for (int i = 0; i < MAX; i += 3)
	{
		for (int j = 0; j < 17; j += 6)
		{
			for (int k = i; k < i + 3; k++)
			{
				for (int m = j; m < j + 6; m += 2)
				{
					if (checkRepeat[number[k][m] - '0'] != 1)
						checkRepeat[number[k][m] - '0'] = 1;
					else
						return 0;
				}
			}
			cleanBool();
		}

	}
	return 1;
}

/***********************************************************************
// Intent: Reset the bool array.
// Pre: None.
// Post: None.
***********************************************************************/
bool cleanBool()
{
	for (int i = 0; i < MAX + 1; i++)
		checkRepeat[i] = 0;
}
