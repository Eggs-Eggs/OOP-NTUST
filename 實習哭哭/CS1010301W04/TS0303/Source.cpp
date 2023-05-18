// Name: »~ÁÚ÷Ÿ
// Date: February 23, 2023
// Last Update: February 23, 2023
// Problem statement: This C++ program output some number. 

#include<iostream>
#include<string>
using namespace std;

int findLenghtOfIntPart(string X);
void outPutChar(int times, char C);

int main()
{
	string X;
	unsigned int M, N;
	char C;

	while (cin >> X >> M >> N >> C)
	{
		if (N == 0)
		{
			outPutChar(M - findLenghtOfIntPart(X), C);
			for (int i = 0; i < findLenghtOfIntPart(X); i++)
			{
				cout << X[i];
			}
		}
		else
		{
			outPutChar(M - findLenghtOfIntPart(X) - N - 1, C);
			for (int i = 0; i < findLenghtOfIntPart(X); i++)		//output int part.
			{
				cout << X[i];
			}

			if (X[findLenghtOfIntPart(X)] != '.')					//output decimal part.
			{
				cout << '.';
				for (int i = 0; i < N; i++)
				{
					if (i + findLenghtOfIntPart(X) < X.size())
					{
						cout << X[i + findLenghtOfIntPart(X)];
					}
					else
					{
						cout << '0';
					}
				}
			}
			else
			{
				for (int i = 0; i <= N; i++)
				{
					if (i + findLenghtOfIntPart(X) < X.size())
					{
						cout << X[i + findLenghtOfIntPart(X)];
					}
					else
					{
						cout << '0';
					}
				}
			}
		}
		cout << endl;
	}
	return 0;
}

/***********************************************************************
// Intent: To find the lenght of interger part.
// Pre: a number it type is string.
// Post: lenght of interger part.
***********************************************************************/
int findLenghtOfIntPart(string X)
{
	int i;
	for (i = 0; i < X.size(); i++)
	{
		if (X[i] == '.')
			break;
	}
	return i;
}

/***********************************************************************
// Intent: To output char.
// Pre: a number it means char output times.
// Post: none.
***********************************************************************/
void outPutChar(int times, char C)
{
	for (int i = 0; i < times; i++)
	{
		cout << C;
	}
}
