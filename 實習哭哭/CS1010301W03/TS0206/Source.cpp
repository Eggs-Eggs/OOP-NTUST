// Name: »~ÁÚ÷Ÿ
// Date: March 9 ,2023
// Last Update: March 9 ,2023
// Problem statement: This C++ program compute the tax.
#include<iostream>
#include<iomanip>
using namespace std;


int main()
{
	float income;
	cout << fixed << setprecision(2);
	while (cin >> income)
	{
		if (income < 750)
			cout << income * 0.01;
		else if (750 <= income && income < 2250)
			cout << 7.5 + (income - 750) * 0.02;
		else if (2250 <= income && income < 3750)
			cout << 37.5 + (income - 2250) * 0.03;
		else if (3750 <= income && income < 5250)
			cout << 82.5 + (income - 3750) * 0.04;
		else if (5250 <= income && income < 7000)
			cout << 142.5 + (income - 5250) * 0.05;
		else if (7000 <= income)
			cout << 230.0 + (income - 7000) * 0.06;
		cout << endl;
	}
	return 0;
}