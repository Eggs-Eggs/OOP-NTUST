/***********************************************************************
 * File: Main.cpp
 * Author: »~ÁÚ÷Ÿ
 * Create Date: 2023/5/10
 * Editor: »~ÁÚ÷Ÿ
 * Update Date: 2023/5/10
 * Description: This program is desing a word game.
 * ***********************************************************************/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

char grid[2][4][4] = { 0 };

typedef struct
{
	int x;
	int y;
}Pos;

//Check word is viald
bool isViald(string words, int gridNum);
//Check position is viald
bool vialdPos(int x, int y, vector<Pos> appearPos);
bool visit(int x, int y, string word, vector<Pos> appearPos, int gridNum);

int main(void)
{
	//Input grid
	for (int k = 0; k < 2; k++)
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cin >> grid[k][i][j];

	//open file
	ifstream input("words.txt");

	if (input.is_open())
	{
		string word;
		while (input >> word)
			if (isViald(word, 0))	//Check word is viald
				cout << word << endl;
	}

	input.close();

	cout << endl;

	input.open("words.txt");

	if (input.is_open())
	{
		string word;
		while (input >> word)
			if (isViald(word, 1))
				cout << word << endl;
	}

	input.close();
	return 0;
}

/***********************************************************************
// Intent: Check word is viald
// Pre: input a word and grid number
// Post: return 1 if word is viald
***********************************************************************/
bool isViald(string word, int gridNum)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (grid[gridNum][i][j] == word[0])
			{
				if (visit(j, i, word, vector<Pos>(), gridNum) == 1)
					return 1;
			}

	return 0;
}

/***********************************************************************
// Intent: Check grid word include words
// Pre: input two position ,word ,appear position and grid number
// Post: return 1 if word is viald
***********************************************************************/
bool visit(int x, int y, string word, vector<Pos> appearPos, int gridNum)
{
	appearPos.push_back(Pos{ x,y });

	// erase first word
	word.erase(0, 1);

	if (word.size() == 0)
		return 1;

	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (vialdPos(x + j, y + i, appearPos) && word[0] == grid[gridNum][y + i][x + j])
			{
				if (visit(x + j, y + i, word, appearPos, gridNum) == 1)
					return 1;
			}

	return 0;
}

/***********************************************************************
// Intent: Check position is viald
// Pre: input two position ,appear position
// Post: return 1 if input position is viald
***********************************************************************/
bool vialdPos(int x, int y, vector<Pos> appearPos)
{
	if (x < 0 || 4 <= x || y < 0 || 4 <= y)
		return false;

	for (int i = 0; i < appearPos.size(); i++)
		if (appearPos[i].x == x && appearPos[i].y == y)
			return false;

	return true;
}