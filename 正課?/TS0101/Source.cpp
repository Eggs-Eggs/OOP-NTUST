// Name: »~ÁÚ÷Ÿ
// Date: February 23, 2023
// Last Update: February 23, 2023
// Problem statement: This C++ program computes the square root. 

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double nu = 0;
	double gu;
	cout << fixed << setprecision(2);
	while (cin >> nu)
	{
		gu = nu / 2;
		while (true)
		{
			if (gu - (gu + nu / gu) / 2 < 0.01)
			{
				break;
			}
			gu = (gu + nu / gu) / 2;
		}
		cout << gu << endl;
	}
	return 0;
}

/*
int main()
{
	double number;
	double guess;
	while (cin >> number)
	{
		guess = number / 2;
		while (1)
		{
			//ôz≤È’`≤Ó «∑Ò–°Ï∂0.01
			if (-0.01 <= (guess + number / guess) / 2 - guess && (guess + number / guess) / 2 - guess <= 0.01)
			{
				break;
			}
			guess = (guess + number / guess) / 2;
		}
		cout << fixed << setprecision(2) << guess << endl;
	}
	return 0;
}
*/