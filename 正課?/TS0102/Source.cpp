// Name: �~����
// Date: February 23, 2023
// Last Update: February 23, 2023
// Problem statement: This C++ program compute HMS. 

#include<iostream>
#include<cstdlib>
using namespace std;

unsigned long long int changeToHour(unsigned long long int time);
unsigned long long int changeToMinute(unsigned long long int time);
unsigned long long int changeToSecond(unsigned long long int time);

int main()
{
	unsigned long long int time;
	while (cin >> time)
	{
		//�D�QС�r
		cout << changeToHour(time) << " hours ";
		//�D�Q���
		cout << changeToMinute(time) << " minutes and ";
		//�D�Q��
		cout << changeToSecond(time) << " seconds" << endl;
	}
}

unsigned long long int changeToHour(unsigned long long int time)
{
	unsigned long long int count;
	count = time / 60;
	count = count / 60;
	return count;
}

unsigned long long int changeToMinute(unsigned long long int time)
{
	unsigned long long int count;
	count = time / 60;
	count = count % 60;
	return count;
}

unsigned long long int changeToSecond(unsigned long long int time)
{
	time = time % 60;
	return time;
}