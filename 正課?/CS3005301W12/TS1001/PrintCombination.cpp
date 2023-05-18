/***********************************************************************
 * File: PrintCombination.cpp
 * Author: È~çòÖÙ
 * Create Date: 2023/5/9
 * Editor: È~çòÖÙ
 * Update Date: 2023/5/9
 * Description: This program is define PrintCombination Class.
 * ***********************************************************************/
#include "PrintCombination.h"

//Constructor
PrintCombination::PrintCombination(int* arrayPtr, int n, int r)
{
	this->arrayPtr = arrayPtr;
	this->n = n;
	this->r = r;

	for (int i = 0; i <= n - r; i++)
		printResult(n - i, r, i, vector<int>());
}

/***********************************************************************
// Intent: print all combination result
// Pre: input number n (int), number r (int), start position (int), all result (vector<int>)
// Post: None
***********************************************************************/
void PrintCombination::printResult(int n, int r, int pos, vector<int> result)
{
	//save result number
	result.push_back(arrayPtr[pos]);
	if (r != 1)
	{
		for (int i = 1; i <= n - r + 1; i++)
			printResult(n - 1 - i + 1, r - 1, pos + i, result);
	}
	else
	{
		//output all result
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i];
			if (i + 1 < result.size())
				cout << " ";
		}
		cout << endl;

		return;
	}
}