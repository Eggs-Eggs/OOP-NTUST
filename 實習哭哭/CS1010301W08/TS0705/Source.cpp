/***********************************************************************
 * File: Source.cpp
 * Author: »~ÁÚ÷Ÿ
 * Create Date: 2023/4/20
 * Editor: »~ÁÚ÷Ÿ
 * Update Date: 2023/4/20
 * Description: This program is add number
 * ***********************************************************************/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

// string to interger
void stToInt(string&);
// interger to string
void intToSt(string&);

// add
string Add(string, string);
// move right
string Rig(string);
// move left
string Lef(string);

int main()
{
	string a, b;
	int count;

	cin >> count;
	getchar();

	int i = 0;

	cout << "COWCULATIONS OUTPUT" << endl;

	while (cin >> a >> b)
	{

		char com;	//command
		string re;	//result

		stToInt(a);
		stToInt(b);

		re.assign(b);

		bool ch = 0;

		for (int i = 0; i < 3; i++)
		{
			cin >> com;
			switch (com)
			{
			case'A':
				re = Add(a, re);
				break;
			case'R':
				re = Rig(re);
				break;
			case'L':
				re = Lef(re);
				break;
			default:
				break;
			}
		}

		if (re.length() < 8)
			re.insert(0, 8 - re.length(), '0');

		intToSt(re);

		string ans;	//answer

		cin >> ans;

		for (int i = 0; i < re.length() - ans.length(); i++)
			ans.insert(0, 1, 'V');

		if (ans == re)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}

		i++;
		if (i >= count)
			break;
	}
	cout << "END OF OUTPUT";
	return 0;
}

/***********************************************************************
// Intent: sting tranform to interger
// Pre: a string
// Post: None
***********************************************************************/
void stToInt(string& a)
{
	for (int i = 0; i < a.length(); i++)
	{
		switch (a[i])
		{
		case 'V':
			a[i] = '0';
			break;
		case 'U':
			a[i] = '1';
			break;
		case 'C':
			a[i] = '2';
			break;
		case 'D':
			a[i] = '3';
			break;
		default:
			break;
		}
	}
}

/***********************************************************************
// Intent: interger tranform to sting
// Pre: a string
// Post: None
***********************************************************************/
void intToSt(string& a)
{
	for (int i = 0; i < a.length(); i++)
	{
		switch (a[i])
		{
		case '0':
			a[i] = 'V';
			break;
		case '1':
			a[i] = 'U';
			break;
		case '2':
			a[i] = 'C';
			break;
		case '3':
			a[i] = 'D';
			break;
		default:
			break;
		}
	}
}

/***********************************************************************
// Intent: add two number both type are string 
// Pre: two string
// Post: None
***********************************************************************/
string Add(string a, string b)
{
	if (a.length() > b.length())
	{
		b.insert(0, a.length() - b.length(), '0');
	}
	if (a.length() < b.length())
	{
		a.insert(0, b.length() - a.length(), '0');
	}

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	string re;
	int carry = 0;
	int add = 0;

	for (int i = 0; i < a.length(); i++)
	{
		add = ((a[i] - '0') + (b[i] - '0') + carry) % 4;
		carry = ((a[i] - '0') + (b[i] - '0') + carry) / 4;
		re.insert(0, 1, add + '0');
	}
	if (carry != 0)
		re.insert(0, 1, carry + '0');
	return re;
}

/***********************************************************************
// Intent: move a string to right
// Pre: a string
// Post: None
***********************************************************************/
string Rig(string a)
{
	a.erase(a.length() - 1, 1);
	a.insert(0, 1, '0');
	return a;
}

/***********************************************************************
// Intent: move a string to left
// Pre: a string
// Post: None
***********************************************************************/
string Lef(string a)
{
	a.insert(a.length(), 1, '0');
	return a;
}