#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int>  nu;
	int a;
	while (cin >> a)
	{
		nu.push_back(a);
	}
	for (int i = 0; i < nu.size(); i++)
	{
		for (int j = 0; j < nu.size() - i - 1; j++)
		{
			if (nu[j] < nu[j + 1])
			{
				int i = nu[j];
				nu[j] = nu[j + 1];
				nu[j + 1] = i;
			}
		}
	}
	int re = 1;
	for (int i = 0; i < nu.size(); i++)
	{
		if (i + 1 < nu.size())
			if (nu[i] == nu[i + 1])
			{
				re++;
				continue;
			}
		cout << nu[i] << '	' << re << endl;
		re = 1;
	}
	return 0;
}








// Name: È~çòÖÙ
// Date: March 14, 2023
// Last Update: March 14, 2023
// Problem statement: This C++ program count the repeat number.

/*
#include<iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>&);
void swapNumber(int&, int&);
int countRepeatNumber(vector<int>, int&);

int main()
{
	vector<int> numberList;
	int registerNumber;
	while (cin >> registerNumber)
	{
		numberList.push_back(registerNumber);
	}
	bubbleSort(numberList);
	cout << "N	count" << endl;
	for (int i = 0; i < numberList.size(); i++)
	{
		cout << numberList[i] << '	';
		cout << countRepeatNumber(numberList, i) + 1;
		cout << endl;
	}
	return 0;
}

void bubbleSort(vector<int>& numberList)
{
	for (int i = 0; i < numberList.size(); i++)
	{
		for (int j = 0; j < numberList.size() - i - 1; j++)
		{
			if (numberList[j] < numberList[j + 1])
			{
				swapNumber(numberList[j], numberList[j + 1]);
			}
		}
	}
}

void swapNumber(int& a, int& b)
{
	int i = a;
	a = b;
	b = i;
}

int countRepeatNumber(vector<int> numberList, int& index)
{
	int repeatTimes = 0;
	while (1)
	{
		if (index + 1 >= numberList.size())
			break;
		if (numberList[index] == numberList[index + 1])
		{
			repeatTimes++;
			index++;
		}
		else
			break;
	}
	return repeatTimes;
}
*/