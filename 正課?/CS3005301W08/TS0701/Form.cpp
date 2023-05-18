/***********************************************************************
 * File: Form.cpp
 * Author: È~çòÖÙ
 * Create Date: 2023/4/18
 * Editor: È~çòÖÙ
 * Update Date: 2023/4/18
 * Description: This program is compose new words.
 * ***********************************************************************/

#include"Form.h"

void Form::SetInputWord(string inputWord)
{
	this->inputWord = inputWord;
}

void Form::ProcessInputWord()
{
	transform(inputWord.begin(), inputWord.end(), inputWord.begin(), tolower);
}

void Form::SetFileName(string fileName)
{
	this->fileName = fileName;
}

void Form::Load_CompareWord()
{
	file.open(fileName, ios::in);

	int inputWordCount[26] = { 0 };
	string read;

	for (int i = 0; i < inputWord.length(); i++)
	{
		inputWordCount[inputWord[i] - 'a']++;
	}

	while (file >> read)
	{
		int readCount[26] = { 0 };
		for (int i = 0; i < read.length(); i++)
		{
			readCount[read[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++)
		{
			if (readCount[i] > inputWordCount[i])
				break;
			if (i == 25)
				foundWord.push_back(read);
		}

	}
	file.close();
}

void Form::PrintFoundWords()
{
	for (int i = 0; i < foundWord.size(); i++)
	{
		cout << foundWord[i] << endl;
	}
}