/***********************************************************************
 * File: PrintCombination.h
 * Author: »~ÁÚ÷Ÿ
 * Create Date: 2023/5/9
 * Editor: »~ÁÚ÷Ÿ
 * Update Date: 2023/5/9
 * Description: This program is declare PrintCombination Class.
 * ***********************************************************************/
#pragma once

#include<iostream>
#include<vector>

using namespace std;

class PrintCombination
{
public:
	//Constructor
	PrintCombination(int* arrayPtr,int n,int r);

	int* arrayPtr;
	int n;
	int r;

	//print all Combination
	void printResult(int n, int r,int pos, vector<int> result);
};

