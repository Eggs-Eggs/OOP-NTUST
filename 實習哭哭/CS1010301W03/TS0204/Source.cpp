// Name: 葉珧仲
// Date: March 9 ,2023
// Last Update: March 9 ,2023
// Problem statement: This C++ program print standard format.
#include<iostream>
#include<string>
using namespace std;

void inputData(string employeesName[], int employeesSalary[], int employeesAward[], int numberOfEmployees);	//輸入員工資料
void outputData(string employeesName[], int employeesSalary[], int employeesAward[], int numberOfEmployees);//輸出員工資料
int findMax(string employeesName[], int numberOfEmployees);	//尋找員工之最
int findMax(int employeesMoney[], int numberOfEmployees);	//尋找員工之最
int findDigits(int number);	//轉換成幾位數
void outputSpace(int i);	//輸出空格

int main()
{
	int numberOfEmployees = 0;
	string* employeesName;
	int* employeesSalary, * employeesAward;
	while (cin >> numberOfEmployees)
	{
		getchar();	//吸收回車鍵
		employeesName = new string[numberOfEmployees];
		employeesSalary = new int[numberOfEmployees];
		employeesAward = new int[numberOfEmployees];
		inputData(employeesName, employeesSalary, employeesAward, numberOfEmployees);	//輸入員工資料
		outputData(employeesName, employeesSalary, employeesAward, numberOfEmployees);	//輸出員工資料
		delete[] employeesName;
		delete[] employeesSalary;
		delete[] employeesAward;
		employeesName = NULL;
		employeesSalary = NULL;
		employeesAward = NULL;
	}
	return 0;
}

void inputData(string employeesName[], int employeesSalary[], int employeesAward[], int numberOfEmployees)
{
	for (int i = 0; i < numberOfEmployees; i++)
	{
		cin >> employeesName[i];
		cin >> employeesSalary[i];
		cin >> employeesAward[i];
		getchar();
	}
}

void outputData(string employeesName[], int employeesSalary[], int employeesAward[], int numberOfEmployees)
{
	int maxLengthName = findMax(employeesName, numberOfEmployees);	//尋找最長的員工名子
	int maxLengthSalary = findMax(employeesSalary, numberOfEmployees);	//尋找最多的薪水
	int maxLengthAward = findMax(employeesAward, numberOfEmployees);	//尋找最多的額外錢錢
	for (int i = 0; i < numberOfEmployees; i++)
	{
		//輸出員工資料
		outputSpace(maxLengthName - employeesName[i].length());	//輸出空格
		cout << employeesName[i];
		cout << '|';
		outputSpace(maxLengthSalary - findDigits(employeesSalary[i]) + 2);
		cout << employeesSalary[i];
		cout << '|';
		outputSpace(maxLengthAward - findDigits(employeesAward[i]) + 2);
		cout << employeesAward[i];
		cout << endl;
	}
}

int findMax(string employeesName[], int numberOfEmployees)
{
	int max = employeesName[0].length();
	for (int i = 0; i < numberOfEmployees; i++)
	{
		if (employeesName[i].length() > max)
		{
			max = employeesName[i].length();
		}
	}
	return max;
}

int findMax(int employeesMoney[], int numberOfEmployees)
{
	int max = employeesMoney[0];
	for (int i = 0; i < numberOfEmployees; i++)
	{
		if (employeesMoney[i] > max)
		{
			max = employeesMoney[i];
		}
	}
	return findDigits(max);	//轉換成幾位數
}

int findDigits(int number)
{
	int i = 0;
	for (i = 0; number != 0; i++)
	{
		number /= 10;
	}
	return i;
}

void outputSpace(int i)
{
	for (i; i > 0; i--)
	{
		cout << ' ';
	}
}