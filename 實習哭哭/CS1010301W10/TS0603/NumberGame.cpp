/***********************************************************************
 * File: NumberGame.cpp
 * Author: È~çòÖÙ
 * Create Date: 2023/5/3
 * Editor: È~çòÖÙ
 * Update Date: 2023/5/3
 * Description: This program is declare NumberGame Class
 * ***********************************************************************/

#include "NumberGame.h"

//constructor
NumberGame::NumberGame()
{
	number = 0;
	fileName = "";
}

/***********************************************************************
// Intent: setup number
// Pre: an interger
// Post: None
***********************************************************************/
void NumberGame::SetInput(int number)
{
	this->number = number;
}

/***********************************************************************
// Intent: decompose interger
// Pre: None
// Post: None
***********************************************************************/
void NumberGame::ProcessInput()
{
	while (number != 0)
	{
		numberList.push_back(number % 10);
		flag.push_back(0);
		number /= 10;
	}
}

/***********************************************************************
// Intent: setup file name
// Pre: input a file name it's type is string 
// Post: None
***********************************************************************/
void NumberGame::SetFileName(string fileName)
{
	this->fileName = fileName;
}

/***********************************************************************
// Intent: load valid number list
// Pre: None
// Post: None
***********************************************************************/
void NumberGame::LoadNumberList()
{
	for (int i = 1; i < pow(2, numberList.size()); i++)
	{
		int num = i;
		for (int j = 0; j < flag.size(); j++)
		{
			flag[j] = num % 2;
			num /= 2;
		}

		int result = 1;
		for (int j = 0; j < flag.size(); j++)
		{
			result = result * pow((int)numberList[j], (bool)flag[j]);
		}

		outputList.push_back(result);
	}
}

/***********************************************************************
// Intent: print valid number
// Pre: None
// Post: None
***********************************************************************/
void NumberGame::PrintAllValid()
{
	input.open(this->fileName);
	int number;

	while (input >> number)
	{
		for (int i = 0; i < outputList.size(); i++)
		{
			if (number == outputList[i])
			{
				cout << number << endl;
				break;
			}
		}
	}

	input.close();
}

/***********************************************************************
// Intent: reset all object
// Pre: None
// Post: None
***********************************************************************/
void NumberGame::Reset()
{
	this->number = 0;
	this->fileName = "";
	numberList.clear();
	outputList.clear();
	flag.clear();
}