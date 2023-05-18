#include<iostream>
#include<math.h>
#include<string>
using namespace std;

int main()
{
	string w;
	int sq = 0;
	while (cin >> w)
	{
		if ((int)sqrt(w.length()) - sqrt(w.length()) == 0)
			sq = sqrt(w.length());
		else
			sq = sqrt(w.length()) + 1;
		for (int i = 0; i < sq; i++)
		{
			for (int j = i; j < w.length(); j += sq)
			{
				cout << w[j];
			}
			cout << endl;
		}
	}

	return 0;
}
















// Name: 葉珧仲
// Date: March 8 ,2023
// Last Update: March 8 ,2023
// Problem statement: This C++ program decode the message.
/*
#include<iostream>
#include<string>
#include<math.h>

#define numberOfElement 3

using namespace std;

int findNumberN(int length);	//尋找適合的N
void decodeMessage(string code, int numberN);	//解碼文字

int main()
{
	string code[numberOfElement];
	//輸入文字
	for (int i = 0; i < numberOfElement; i++)
	{
		getline(cin, code[i]);
	}
	//解碼文字
	for (int i = 0; i < numberOfElement; i++)
	{
		decodeMessage(code[i], findNumberN(code[i].length()));
	}
	return 0;
}

int findNumberN(int length)
{
	int N = 0;
	if (length == 0)
		return 0;
	while (1)
	{
		if (length <= pow(2, N))
		{
			break;
		}
		N++;
	}
	while (1)
	{
		if (pow(N - 1, 2) >= length)
		{
			return N - 1;
		}
		N++;
	}
}

void decodeMessage(string code, int numberN)
{
	for (int i = 0; i < numberN; i++)
	{
		for (int j = i; j < code.length(); j = j + numberN)
		{
			cout << code[j];
		}
		cout << endl;
	}
}
*/