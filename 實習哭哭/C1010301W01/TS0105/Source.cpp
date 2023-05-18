// Name: »~ÁÚ÷Ÿ
// Date: February 23, 2023
// Last Update: February 23, 2023
// Problem statement: This C++ program computes the volume of sphere.

#include<iostream>
#include<iomanip>
#define PI 3.14159265358979323846
using namespace std;

int main()
{
	double radius;
	while (cin >> radius)
	{
		cout << fixed << setprecision(6) << 4.0 / 3.0 * PI * radius * radius * radius << endl;
	}
}