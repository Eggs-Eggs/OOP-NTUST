// Name: »~ÁÚ÷Ÿ
// Date: March 23, 2023
// Last Update: March 23, 2023
// Problem statement: This C++ program computes the volume of Snoopy's house. 

#include<iostream>

using namespace std;

//switch a and b.
void swap(int& a, int& b);
//find the cycle length of Collatz conjecture.
unsigned int findCycleLength(unsigned int number);

int main()
{
	unsigned int i = 0, j = 0;
	unsigned int maximumCycleLength = 0;

	while (cin >> i >> j)
	{
		maximumCycleLength = 0;

		cout << i << " " << j << " ";

		//switch i & j if j is smaller than i
		if (j < i)
			swap(i, j);

		for (int k = i; k <= j; k++)
		{
			int registerNumber = findCycleLength(k);

			//update maximumCycleLength
			if (maximumCycleLength < registerNumber)
				maximumCycleLength = registerNumber;
		}

		cout << maximumCycleLength << endl;
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
// Intent: find the cycle length of Collatz conjecture.
// Pre: one unsigned interger.
// Post: the cycle length of Collatz conjecture.
***********************************************************************/
unsigned int findCycleLength(unsigned int number)
{
	unsigned int cycleLength = 1;
	while (true)
	{
		if (number % 2 == 0)
			number /= 2;
		else
			number = number * 3 + 1;
		cycleLength++;
		if (number == 1)
			break;
	}
	return cycleLength;
}
