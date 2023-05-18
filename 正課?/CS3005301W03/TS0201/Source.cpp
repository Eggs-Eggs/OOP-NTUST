#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int to;
	int* st;
	double sum = 0, av = 0, sd = 0;

	while (cin >> to)
	{
		sum = 0;
		st = new int[to];
		for (int i = 0; i < to; i++)
		{
			cin >> st[i];
		}
		for (int i = 0; i < to; i++)
		{
			sum += st[i];
		}
		av = sum / to;
		sum = 0;
		for (int i = 0; i < to; i++)
		{
			sum = sum + pow(st[i] - av, 2);
		}
		sd = sqrt(sum / to);
		cout << av << '	' << sd << endl;
	}

	return 0;
}





























// Name: 葉珧仲
// Date: March 8 ,2023
// Last Update: March 8 ,2023
// Problem statement: This C++ program computes the average and standard deviation.


/*
#include<iostream>
#include<math.h>
using namespace std;

float countAverage(double element[], int numberOfElement);
float countStandardDeviation(double element[], int numberOfElement, float average);

int main()
{
	int numberOfElement = 0;
	double* arrayAddress;
	double average = 0, standardDeviation = 0;
	while(cin >> numberOfElement)
	{
		arrayAddress = new double[numberOfElement];
		//輸入數值
		for (int i = 0; i < numberOfElement; i++)
		{
			cin >> arrayAddress[i];
		}
		//算平均
		average = countAverage(arrayAddress, numberOfElement);
		//算標準差
		standardDeviation = countStandardDeviation(arrayAddress, numberOfElement, average);
		cout << "Average:" << average << "	" << "Standard deviation:" << standardDeviation << endl;
		delete[] arrayAddress;
		arrayAddress = NULL;
	}
	return 0;
}


float countAverage(double element[], int numberOfElement)
{
	float add = 0;
	for (int i = 0; i < numberOfElement; i++)
	{
		add += element[i];
	}
	return add / numberOfElement;
}

float countStandardDeviation(double element[], int numberOfElement, float average)
{
	float add = 0;
	for (int i = 0; i < numberOfElement; i++)
	{
		add += pow(element[i] - average, 2);
	}
	return sqrt(add / (float)numberOfElement);
}
*/