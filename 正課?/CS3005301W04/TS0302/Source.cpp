#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int main()
{
	ifstream file;
	file.open("grade.txt");
	vector<int> gr;
	int a;
	while (file >> a)
	{
		gr.push_back(a);
	}

	for (int i = 0; i < gr.size(); i++)
	{
		for (int j = 0; j < gr.size() - i - 1; j++)
		{
			if (gr[j] > gr[j + 1])
			{
				int k = 0;
				k = gr[j];
				gr[j] = gr[j + 1];
				gr[j + 1] = k;
			}
		}
	}

	ofstream ans;
	ans.open("grades.Output");
	int re = 0;
	int n = 0;
	for (int i = gr[0]; i <= gr[gr.size() - 1]; i++)
	{
		if (i == gr[n])
		{
			re++;
			while (gr[n] == gr[n + 1])
			{
				re++;
				n++;
				if (n + 1 >= gr.size())
					break;
			}
			n++;
		}
		ans << re << " grade(s) of " << i << endl;
		re = 0;
	}

	return 0;
}





// Name: 葉珧仲
// Date: March 14, 2023
// Last Update: March 14, 2023
// Problem statement: This C++ program sort the stund grades.
/*
#include<iostream>
#include<vector>
#include <fstream>

using namespace std;
void bubbleSort(vector<int>&);
void swapNumber(int&, int& b);
int findNumberOfStudentGrades(vector<int>, int&, int);	//尋找某分數的學生人數
int main()
{
	ifstream gradesFile;
	ofstream gradesOutput;
	gradesOutput.open("grades.Output");
	gradesFile.open("grade.txt");
	if (gradesFile.fail())
	{
		cout << "input file opening failed";
		exit(1);
	}
	vector<int> grades;
	int registerNumber;	//暫存數字
	int index = 0;	//成績的索引
	while (gradesFile >> registerNumber)	//讀入檔案
	{
		grades.push_back(registerNumber);
	}
	bubbleSort(grades);
	for (int i = 0; i <= grades[grades.size() - 1]; i++)	//輸出0~最大成績的人數
	{
		gradesOutput << findNumberOfStudentGrades(grades, index, i);
		gradesOutput << " grade(s) of " << i << endl;
	}
	gradesFile.close();
	gradesOutput.close();
	return 0;
}


void bubbleSort(vector<int>& grades)
{
	for (int i = 0; i < grades.size(); i++)
	{
		for (int j = 0; j < grades.size() - i - 1; j++)
		{
			if (grades[j] > grades[j + 1])
			{
				swapNumber(grades[j], grades[j + 1]);
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

int findNumberOfStudentGrades(vector<int> grades, int& index, int targetGrade)
{
	int numberOfStudentGrade = 0;
	while (1)
	{
		if (grades[index] == targetGrade)
		{
			numberOfStudentGrade++;
		}
		else
		{
			break;
		}
		index++;
		if (index >= grades.size())
			break;
	}
	return numberOfStudentGrade;
}
*/