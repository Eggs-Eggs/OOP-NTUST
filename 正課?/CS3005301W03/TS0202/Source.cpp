#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	ifstream file;
	file.open("scores.txt");
	string rena;
	int resc;
	vector<string> na;
	vector<int> sc;
	while (file >> rena >> resc)
	{
		na.push_back(rena);
		sc.push_back(resc);
	}
	for (int i = 0; i < na.size(); i++)
	{
		for (int j = 0; j < na.size() - i - 1; j++)
		{
			if (sc[j] < sc[j + 1])
			{
				int i = sc[j];
				sc[j] = sc[j + 1];
				sc[j + 1] = i;
				string k = na[j];
				na[j] = na[j + 1];
				na[j + 1] = k;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		cout << na[i] << endl << sc[i] << endl;
	}
	return 0;
}
















// Name: 葉珧仲
// Date: March 8 ,2023
// Last Update: March 8 ,2023
// Problem statement: This C++ program sort the scores.


/*
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void bubbleSort(int allScores[], string allName[], int max);
void switchElement(int& first, int& second);
void switchElement(string& first, string& second);

int main()
{
	string allName[20];
	int allScores[20];
	ifstream scores;
	scores.open("scores.txt");
	int numberOfPeople = 0;
	//讀取檔案
	while (!scores.eof())
	{
		scores >> allName[numberOfPeople];
		scores >> allScores[numberOfPeople];
		numberOfPeople++;
	}
	//泡泡排序
	bubbleSort(allScores, allName, numberOfPeople);
	//輸出前三名
	for (int i = 0; i < 3; i++)
	{
		cout << allName[i] << endl << allScores[i] << endl;
	}
	return 0;
}

void bubbleSort(int allScores[], string allName[], int max)
{
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max - i - 1; j++)
		{
			if (allScores[j] < allScores[j + 1])
			{
				switchElement(allScores[j], allScores[j + 1]);
				switchElement(allName[j], allName[j + 1]);
			}
		}
	}
}


void switchElement(int& first, int& second)
{
	int i;
	i = first;
	first = second;
	second = i;
}

void switchElement(string& first, string& second)
{
	string i;
	i = first;
	first = second;
	second = i;
}
*/