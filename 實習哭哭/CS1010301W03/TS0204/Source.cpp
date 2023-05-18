// Name: �~����
// Date: March 9 ,2023
// Last Update: March 9 ,2023
// Problem statement: This C++ program print standard format.
#include<iostream>
#include<string>
using namespace std;

void inputData(string employeesName[], int employeesSalary[], int employeesAward[], int numberOfEmployees);	//ݔ��T���Y��
void outputData(string employeesName[], int employeesSalary[], int employeesAward[], int numberOfEmployees);//ݔ���T���Y��
int findMax(string employeesName[], int numberOfEmployees);	//���҆T��֮��
int findMax(int employeesMoney[], int numberOfEmployees);	//���҆T��֮��
int findDigits(int number);	//�D�Q�Ɏ�λ��
void outputSpace(int i);	//ݔ���ո�

int main()
{
	int numberOfEmployees = 0;
	string* employeesName;
	int* employeesSalary, * employeesAward;
	while (cin >> numberOfEmployees)
	{
		getchar();	//���ջ�܇�I
		employeesName = new string[numberOfEmployees];
		employeesSalary = new int[numberOfEmployees];
		employeesAward = new int[numberOfEmployees];
		inputData(employeesName, employeesSalary, employeesAward, numberOfEmployees);	//ݔ��T���Y��
		outputData(employeesName, employeesSalary, employeesAward, numberOfEmployees);	//ݔ���T���Y��
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
	int maxLengthName = findMax(employeesName, numberOfEmployees);	//�������L�ĆT������
	int maxLengthSalary = findMax(employeesSalary, numberOfEmployees);	//��������нˮ
	int maxLengthAward = findMax(employeesAward, numberOfEmployees);	//���������~���X�X
	for (int i = 0; i < numberOfEmployees; i++)
	{
		//ݔ���T���Y��
		outputSpace(maxLengthName - employeesName[i].length());	//ݔ���ո�
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
	return findDigits(max);	//�D�Q�Ɏ�λ��
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