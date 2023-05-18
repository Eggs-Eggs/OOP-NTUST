/***********************************************************************
 * File: Source.cpp
 * Author: »~ÁÚ÷Ÿ
 * Create Date: 2023/4/20
 * Editor: »~ÁÚ÷Ÿ
 * Update Date: 2023/4/20
 * Description: This program is Shisensho game
 * ***********************************************************************/


#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

// find pair
bool findPair();

// go Right
int visitR(int x, int y);
// go Left
int visitL(int x, int y);
// go Up
int visitU(int x, int y);
// go Down
int visitD(int x, int y);
// check is vaild position
bool checkVaild(int x, int y);

// count transform way
int tran = 0;
// check find pair
bool findMatch = 0;

// map
int num[8][8];

// position
struct sPos
{
	int x = 0;
	int y = 0;
};

sPos pos1, pos2;

int main()
{
	//input
	for (int i = 1; i < 7; i++)
	{
		for (int j = 1; j < 7; j++)
		{
			cin >> num[i][j];
		}
	}

	// set up map
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i == 0 || j == 0 || i == 7 || j == 7)
			{
				num[i][j] = 0;
			}
		}
	}

	while (cin >> pos1.x >> pos1.y >> pos2.x >> pos2.y)
	{

		pos1.x++;
		pos1.y++;
		pos2.x++;
		pos2.y++;

		// find pair
		if (findPair() && num[pos1.y][pos1.x] == num[pos2.y][pos2.x] && !(pos1.x == pos2.x && pos1.y == pos2.y) && num[pos1.y][pos1.x] != 0 && num[pos2.y][pos2.x] != 0)
		{
			cout << "pair matched" << endl;
			num[pos1.y][pos1.x] = 0;
			num[pos2.y][pos2.x] = 0;
		}
		else
			cout << "bad pair" << endl;

		findMatch = 0;
	}
}

/***********************************************************************
// Intent: find pair
// Pre: None
// Post: If find pair ,return 1 .else return 0.
***********************************************************************/
bool findPair()
{

	visitR(pos1.x, pos1.y);
	visitL(pos1.x, pos1.y);
	visitU(pos1.x, pos1.y);
	visitD(pos1.x, pos1.y);

	return findMatch;
}

/***********************************************************************
// Intent: go right
// Pre: None
// Post: None
***********************************************************************/
int visitR(int x, int y)
{
	if (pos2.x == x && pos2.y == y)
	{
		findMatch = 1;
		return 0;
	}
	if ((num[y][x + 1] == 0 || (num[y][x + 1] == num[pos2.y][pos2.x] && pos2.x == x + 1 && pos2.y == y)) && checkVaild(x + 1, y))
		visitR(x + 1, y);
	tran++;
	if (tran < 3)
	{
		if ((num[y][x - 1] == 0 || (num[y][x - 1] == num[pos2.y][pos2.x] && pos2.x == x - 1 && pos2.y == y)) && checkVaild(x - 1, y))
			visitL(x - 1, y);
		if ((num[y - 1][x] == 0 || (num[y - 1][x] == num[pos2.y][pos2.x] && pos2.x == x && pos2.y == y - 1)) && checkVaild(x, y - 1))
			visitU(x, y - 1);
		if ((num[y + 1][x] == 0 || (num[y + 1][x] == num[pos2.y][pos2.x] && pos2.x == x && pos2.y == y + 1)) && checkVaild(x, y + 1))
			visitD(x, y + 1);
	}
	tran--;
	return 0;
}

/***********************************************************************
// Intent: go left
// Pre: None
// Post: None
***********************************************************************/
int visitL(int x, int y)
{
	if (pos2.x == x && pos2.y == y)
	{
		findMatch = 1;
		return 0;
	}
	if ((num[y][x - 1] == 0 || (num[y][x - 1] == num[pos2.y][pos2.x] && pos2.x == x - 1 && pos2.y == y)) && checkVaild(x - 1, y))
		visitL(x - 1, y);
	tran++;
	if (tran < 3)
	{
		if ((num[y][x + 1] == 0 || (num[y][x + 1] == num[pos2.y][pos2.x] && pos2.x == x + 1 && pos2.y == y)) && checkVaild(x + 1, y))
			visitR(x + 1, y);
		if ((num[y - 1][x] == 0 || (num[y - 1][x] == num[pos2.y][pos2.x] && pos2.x == x && pos2.y == y - 1)) && checkVaild(x, y - 1))
			visitU(x, y - 1);
		if ((num[y + 1][x] == 0 || (num[y + 1][x] == num[pos2.y][pos2.x] && pos2.x == x && pos2.y == y + 1)) && checkVaild(x, y + 1))
			visitD(x, y + 1);
	}
	tran--;
	return 0;
}

/***********************************************************************
// Intent: go up
// Pre: None
// Post: None
***********************************************************************/
int visitU(int x, int y)
{
	if (pos2.x == x && pos2.y == y)
	{
		findMatch = 1;
		return 0;
	}
	if ((num[y - 1][x] == 0 || (num[y - 1][x] == num[pos2.y][pos2.x] && pos2.x == x && pos2.y == y - 1)) && checkVaild(x, y - 1))
		visitU(x, y - 1);
	tran++;
	if (tran < 3)
	{
		if ((num[y][x + 1] == 0 || (num[y][x + 1] == num[pos2.y][pos2.x] && pos2.x == x + 1 && pos2.y == y)) && checkVaild(x + 1, y))
			visitR(x + 1, y);
		if ((num[y][x - 1] == 0 || (num[y][x - 1] == num[pos2.y][pos2.x] && pos2.x == x - 1 && pos2.y == y)) && checkVaild(x - 1, y))
			visitL(x - 1, y);
		if ((num[y + 1][x] == 0 || (num[y + 1][x] == num[pos2.y][pos2.x] && pos2.x == x && pos2.y == y + 1)) && checkVaild(x, y + 1))
			visitD(x, y + 1);
	}
	tran--;
	return 0;
}

/***********************************************************************
// Intent: go down
// Pre: None
// Post: None
***********************************************************************/
int visitD(int x, int y)
{
	if (pos2.x == x && pos2.y == y)
	{
		findMatch = 1;
		return 0;
	}

	if ((num[y + 1][x] == 0 || (num[y + 1][x] == num[pos2.y][pos2.x] && pos2.x == x && pos2.y == y + 1)) && checkVaild(x, y + 1))
		visitD(x, y + 1);
	tran++;
	if (tran < 3)
	{
		if ((num[y][x + 1] == 0 || (num[y][x + 1] == num[pos2.y][pos2.x] && pos2.x == x + 1 && pos2.y == y)) && checkVaild(x + 1, y))
			visitR(x + 1, y);
		if ((num[y][x - 1] == 0 || (num[y][x - 1] == num[pos2.y][pos2.x] && pos2.x == x - 1 && pos2.y == y)) && checkVaild(x - 1, y))
			visitL(x - 1, y);
		if ((num[y - 1][x] == 0 || (num[y - 1][x] == num[pos2.y][pos2.x] && pos2.x == x && pos2.y == y - 1)) && checkVaild(x, y - 1))
			visitU(x, y - 1);
	}
	tran--;
	return 0;
}

/***********************************************************************
// Intent: check is vaild position
// Pre: input x and y
// Post: If vaild return 1.
***********************************************************************/
bool checkVaild(int x, int y)
{
	if (x < 0 || 8 <= x || y < 0 || 8 <= y)
		return false;
	else
		return true;
}
