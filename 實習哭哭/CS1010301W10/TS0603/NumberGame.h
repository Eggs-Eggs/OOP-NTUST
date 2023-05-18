/***********************************************************************
 * File: NumberGame.h
 * Author: »~ÁÚ÷Ÿ
 * Create Date: 2023/5/3
 * Editor: »~ÁÚ÷Ÿ
 * Update Date: 2023/5/3
 * Description: This program is declare NumberGame Class
 * ***********************************************************************/

#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

class NumberGame
{
private:
	int number;
	ifstream input;
	vector<int> numberList;
	vector<bool> flag;
	vector<unsigned int> outputList;
	string fileName;
public:

	NumberGame();

	void SetInput(int);
	void ProcessInput();
	void SetFileName(string);
	void LoadNumberList();
	void PrintAllValid();
	void Reset();
};

