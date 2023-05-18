// Name: »~ÁÚ÷Ÿ
// Date: March 23, 2023
// Last Update: March 23, 2023
// Problem statement: This C++ program find the greatest common divisor. 

#include<iostream>

using namespace std;

//switch a and b.
void swap(int& a, int& b);
//find the greatest common divisor.
int findGCD(int a, int b);

int main()
{
	int a = 0, b = 0;

	while (cin >> a >> b)
	{
		if (b > a)
			swap(a, b);

		cout << findGCD(a, b) << endl;
	}

	return 0;
}

/***********************************************************************
// Intent: switch a and b.
// Pre: two interger number.
// Post: none.
***********************************************************************/
void swap(int& a, int& b)
{
	int i = a;
	a = b;
	b = i;
}

/***********************************************************************
// Intent: find the greatest common divisor.
// Pre: two interger number.
// Post: the greatest common divisor.
***********************************************************************/
int findGCD(int a, int b)
{
	for (int i = b; i > 0; i--)
	{
		if (a % i == 0 && b % i == 0)
		{
			return i;
		}
	}
}
