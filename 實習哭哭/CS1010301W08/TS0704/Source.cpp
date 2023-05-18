/***********************************************************************
 * File: Source.cpp
 * Author: »~ÁÚ÷Ÿ
 * Create Date: 2023/4/20
 * Editor: »~ÁÚ÷Ÿ
 * Update Date: 2023/4/20
 * Description: This program is find Levens Distance
 * ***********************************************************************/

#include<iostream>
#include<string>

using namespace std;

// find Levens Distance
int LevensDistance(int, int);
int** dis;
string a, b;

int main()
{
	//input word
	while (getline(cin, a) && getline(cin, b))
	{
		dis = new  int* [a.length() + 1];
		for (int i = 0; i < a.length() + 1; i++)
		{
			dis[i] = new int[b.length() + 1];
		}

		for (int i = 0; i < a.length() + 1; i++)
		{
			for (int j = 0; j < b.length() + 1; j++)
			{
				dis[i][j] = LevensDistance(i, j);
			}
		}

		cout << dis[a.length()][b.length()] << endl;

		// delete memory
		for (int i = 0; i < a.length() + 1; i++)
		{
			delete[] dis[i];
		}
		delete[] dis;
	}
}
 
/***********************************************************************
// Intent: find Levens Distance
// Pre: input to interger
// Post: return Levens Distance
***********************************************************************/
int LevensDistance(int i, int j)
{

	if (i == 0) { return j; }
	if (j == 0) { return i; }

	int max = dis[i - 1][j - 1];

	if (a[i - 1] != b[j - 1]) { max += 1; }

	if (max > dis[i][j - 1] + 1) { max = dis[i][j - 1] + 1; }
	if (max > dis[i - 1][j] + 1) { max = dis[i - 1][j] + 1; }

	return max;
}
