// Name: »~ÁÚ÷Ÿ
// Date: March 17, 2023
// Last Update: March 17, 2023
// Problem statement: This C++ program compute the CPU calculation big number. 

#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;

int main()
{
	int year = 0;

	while (cin >> year)
	{
		int N = 1;
		double sumOfLogFactorial = 0;
		while (1)
		{
			sumOfLogFactorial += log2(N);
			if ((year / 10 - 190) < log2(sumOfLogFactorial / 4))
				break;
			N++;
		}
		cout << N - 1 << endl;
	}
	return 0;
}
